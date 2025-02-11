/*
**  SSIS_hotfix_uninstall.SQL
**  Patch uninstall script for the SSIS server catalog (SSISDB).
*/

PRINT '------------------------------------------------------'
PRINT 'Starting execution of SSIS_HOTFIX_UNINSTALL.SQL       '
PRINT '------------------------------------------------------'

DECLARE @run_script BIT
SET @run_script=1

DECLARE @ssis_database_name SYSNAME
SET @ssis_database_name = N'SSISDB'

-- Check whether SSISDB exists
IF(DB_ID(@ssis_database_name) IS NULL)
BEGIN
    SET @run_script=0
    PRINT 'Database SSISDB does not exist in current SQL Server instance'
END

-- Check whether SSISDB is online
IF @run_script <> 0
BEGIN
	DECLARE @state_online SYSNAME
	SET @state_online = 'ONLINE'
	SELECT @state_online = UPPER(@state_online COLLATE SQL_Latin1_General_CP1_CI_AS)

	IF NOT EXISTS (SELECT state_desc FROM master.sys.databases WHERE name = @ssis_database_name AND
										 UPPER(state_desc COLLATE SQL_Latin1_General_CP1_CI_AS) LIKE @state_online)
	BEGIN
		SET @run_script=0    
		PRINT 'WARNING! The database SSISDB is not ONLINE. SSIS_HOTFIX_INSTALL.SQL will not be applied. Please run the script manually after the upgrade.'
	END
END

-- Check whether SSISDB is corrupted
IF @run_script <> 0
BEGIN
	IF OBJECT_ID (N'SSISDB.internal.catalog_properties', N'U') IS NULL
	BEGIN
		SET @run_script=0
		PRINT 'Database SSISDB is missing the catalog properties table. The database may be corrupted, or it is not an SSIS Catalog.'
	END
END

IF  @run_script = 0
BEGIN
	PRINT 'Database SSISDB was not patched.'
END
ELSE
BEGIN
	PRINT 'Start applying SSIS_HOTFIX_UNINSTALL changes'

	DECLARE @rawCmd NVARCHAR(MAX), @cmd NVARCHAR(MAX)
	
	DECLARE  @targetVersion NVARCHAR(256)
	SELECT @targetVersion = CONVERT(NVARCHAR,SERVERPROPERTY(N'ProductVersion'))

	--------------------------------------------------------------------------------------------
	---------****** Add more version handlers here for future CU versions *****-----------------
	--------------------------------------------------------------------------------------------

	--Version handler for PCU1
	--1. drop the old SP
	IF OBJECT_ID (N'SSISDB.[catalog].[create_execution]', N'P') IS NOT NULL
	BEGIN
		SET @rawCmd = N'DROP PROCEDURE [catalog].[create_execution]'
		SET @cmd = N'EXEC SSISDB.dbo.sp_executesql @statement=N''' + @rawCmd + ''''
		EXEC sp_executesql @cmd

		PRINT 'Stored procedure [catalog].[create_execution] has been dropped.'
	END

	--2. create the new SP
	IF OBJECT_ID (N'SSISDB.[catalog].[create_execution]', N'P') IS NULL
	BEGIN
		SET @rawCmd = N'
		CREATE PROCEDURE [catalog].[create_execution]
			@folder_name nvarchar(128), 
			@project_name nvarchar(128), 
			@package_name nvarchar(260), 
			@reference_id bigint = null, 
			@use32bitruntime bit = 0, 
			@execution_id bigint output
		WITH EXECUTE AS ''''AllSchemaOwner''''
		AS
			SET NOCOUNT ON
    
    
			DECLARE @caller_id     int
			DECLARE @caller_name   [internal].[adt_sname]
			DECLARE @caller_sid    [internal].[adt_sid]
			DECLARE @suser_name    [internal].[adt_sname]
			DECLARE @suser_sid     [internal].[adt_sid]
    
			EXECUTE AS CALLER
				EXEC [internal].[get_user_info]
					@caller_name OUTPUT,
					@caller_sid OUTPUT,
					@suser_name OUTPUT,
					@suser_sid OUTPUT,
					@caller_id OUTPUT;
          
          
				IF(
					EXISTS(SELECT [name]
							FROM sys.server_principals
							WHERE [sid] = @suser_sid AND [type] = ''''S'''')  
					OR
					EXISTS(SELECT [name]
							FROM sys.database_principals
							WHERE ([sid] = @caller_sid AND [type] = ''''S'''')) 
					)
				BEGIN
					RAISERROR(27123, 16, 1) WITH NOWAIT
					RETURN 1
				END
			REVERT
    
			IF(
					EXISTS(SELECT [name]
							FROM sys.server_principals
							WHERE [sid] = @suser_sid AND [type] = ''''S'''')  
					OR
					EXISTS(SELECT [name]
							FROM sys.database_principals
							WHERE ([sid] = @caller_sid AND [type] = ''''S'''')) 
					)
			BEGIN
					RAISERROR(27123, 16, 1) WITH NOWAIT
					RETURN 1
			END
    
			DECLARE @created_time datetimeoffset
			DECLARE @return_value   int
			DECLARE @operation_id  bigint
			DECLARE @result     bit
			DECLARE @environment_id bigint
			DECLARE @environment_found bit
    
			IF (@folder_name IS NULL OR @project_name IS NULL 
					OR @package_name IS NULL OR @use32bitruntime IS NULL)
			BEGIN
				RAISERROR(27138, 16 , 1) WITH NOWAIT 
				RETURN 1 
			END
    
			BEGIN TRY
        
				SET @created_time = SYSDATETIMEOFFSET()
				EXEC @return_value = [internal].[insert_operation] 
								200,  
								@created_time,          
								20,    
								NULL,                     
								@project_name,          
								1,  
								null,                   
								null,                   
								@caller_sid,            
								@caller_name,           
								null,                   
								null,                   
								null,                   
								@operation_id OUTPUT  
				IF @return_value <> 0
					RETURN 1;

        
				EXECUTE AS CALLER
					EXEC @return_value = [internal].[init_object_permissions] 4, @operation_id, @caller_id
				REVERT 
               
				IF @return_value <> 0
				BEGIN
            
					RAISERROR(27153, 16, 1) WITH NOWAIT
					RETURN 1
				END 
        
				SET @execution_id = @operation_id
 
			END TRY
			BEGIN CATCH
				UPDATE [internal].[operations] 
					SET 
						[end_time]  = SYSDATETIME(),
						[status]    = 4
					WHERE operation_id    = @operation_id;
				THROW;
			END CATCH

			DECLARE @sqlString              nvarchar(1024)
			DECLARE @key_name               [internal].[adt_name]
			DECLARE @certificate_name       [internal].[adt_name]
			DECLARE @encryption_algorithm   nvarchar(255)
    
			DECLARE @env_key_name               [internal].[adt_name]
			DECLARE @env_certificate_name       [internal].[adt_name]
    
			DECLARE @project_key_name               [internal].[adt_name]
			DECLARE @project_certificate_name       [internal].[adt_name]
    
			SET @encryption_algorithm = (SELECT [internal].[get_encryption_algorithm]())
    
			IF @encryption_algorithm IS NULL
			BEGIN
				RAISERROR(27156, 16, 1, ''''ENCRYPTION_ALGORITHM'''') WITH NOWAIT
			END


    
			SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
    
    
    
			DECLARE @tran_count INT = @@TRANCOUNT;
			DECLARE @savepoint_name NCHAR(32);
			IF @tran_count > 0
			BEGIN
				SET @savepoint_name = REPLACE(CONVERT(NCHAR(36), NEWID()), N''''-'''', N'''''''');
				SAVE TRANSACTION @savepoint_name;
			END
			ELSE
				BEGIN TRANSACTION;                                                                                      
			BEGIN TRY

				DECLARE @project_id bigint
				DECLARE @version_id bigint
        
        
				EXECUTE AS CALLER
					SELECT @project_id = projs.[project_id],  
							@version_id = projs.[object_version_lsn]
						FROM [catalog].[projects] projs INNER JOIN [catalog].[folders] fds
						ON projs.[folder_id] = fds.[folder_id] INNER JOIN [catalog].[packages] pkgs
						ON projs.[project_id] = pkgs.[project_id] 
						WHERE fds.[name] = @folder_name AND projs.[name] = @project_name
						AND pkgs.[name] = @package_name
				REVERT
        
				IF (@project_id IS NULL)
				BEGIN
					RAISERROR(27146, 16, 1) WITH NOWAIT
				END
        
        
				EXECUTE AS CALLER   
					SET @result =  [internal].[check_permission] 
						(
							2,
							@project_id,
							3
							) 
				REVERT
        
				IF @result = 0
				BEGIN
					RAISERROR(27178, 16, 1, @project_name) WITH NOWAIT
				END

        
        
				DECLARE @environment_name nvarchar(128)
				DECLARE @environment_folder_name nvarchar(128)
				DECLARE @reference_type char(1)
        
        
				IF(@reference_id IS NOT NULL)
				BEGIN
            
					EXECUTE AS CALLER
						SELECT @environment_name = environment_name,
								@environment_folder_name = environment_folder_name,
								@reference_type = reference_type
						FROM [catalog].[environment_references]
						WHERE project_id = @project_id AND reference_id = @reference_id
					REVERT
					IF (@environment_name IS NULL)
					BEGIN
						RAISERROR(27208, 16, 1, @reference_id) WITH NOWAIT
					END                                                     
            
            
					SET @environment_found = 1
					IF (@reference_type = ''''A'''')
					BEGIN
						SELECT @environment_id = envs.[environment_id]
						FROM [internal].[folders] fds INNER JOIN [internal].[environments] envs
						ON fds.[folder_id] = envs.[folder_id]
						WHERE envs.[environment_name] = @environment_name AND fds.[name] = @environment_folder_name
					END
					ELSE IF (@reference_type = ''''R'''')
					BEGIN
						SELECT @environment_id = envs.[environment_id]
						FROM  [internal].[projects] projs INNER JOIN [internal].[environments] envs
						ON projs.[folder_id] = envs.[folder_id]
						WHERE envs.[environment_name] = @environment_name AND projs.[project_id] = @project_id
					END
					IF (@environment_id IS NULL)
					BEGIN
						SET @environment_found = 0
					END
            
					EXECUTE AS CALLER
						SET @result =  [internal].[check_permission]
							(
								3,
								@environment_id,
								1
								)
					REVERT
					IF @result = 0
					BEGIN
						SET @environment_found = 0
					END
					IF @environment_found = 0
					BEGIN
						RAISERROR(27182 , 16 , 1, @environment_name) WITH NOWAIT
					END
            
            
            
					IF EXISTS 
					(
						SELECT params.[parameter_name]
						FROM [internal].[environments] envs INNER JOIN [internal].[environment_variables] vars
						ON envs.[environment_id] = vars.[environment_id] INNER JOIN [catalog].[object_parameters] params
						ON vars.[name] = params.[referenced_variable_name] 
						WHERE params.[value_type] = ''''R'''' AND params.[data_type] <> vars.[type] 
						AND params.[project_id] = @project_id
						AND (params.[object_type] = 20
						OR (params.[object_name] = @package_name
						AND params.[object_type] = 30))
						AND envs.[environment_id] = @environment_id          
					)
					BEGIN
						RAISERROR(27148, 16, 1) WITH NOWAIT
					END 
            
            
					IF EXISTS 
					(
						SELECT params.[parameter_name]
						FROM [internal].[environment_variables] vars INNER JOIN [catalog].[object_parameters] params
						ON vars.[name] = params.[referenced_variable_name] 
						WHERE params.[value_type] = ''''R'''' AND params.[data_type] = vars.[type] 
						AND params.[sensitive] =0 AND vars.[sensitive] = 1
						AND params.[project_id] = @project_id
						AND (params.[object_type] = 20
						OR (params.[object_name] = @package_name
						AND params.[object_type] = 30))
						AND vars.[environment_id] = @environment_id          
					)
					BEGIN
						RAISERROR(27221, 16, 1) WITH NOWAIT
					END 
				END   
        
				UPDATE [internal].[operations]
					SET [object_id] = @project_id
					WHERE [operation_id] = @operation_id
				IF @@ROWCOUNT <> 1
				BEGIN
					RAISERROR(27112, 16, 1, N''''operations'''') WITH NOWAIT
				END    
        
        
				DECLARE @architecture nvarchar(255)

				EXEC master..xp_regread ''''HKEY_LOCAL_MACHINE'''',
								''''System\CurrentControlSet\Control\Session Manager\Environment'''',
								''''PROCESSOR_ARCHITECTURE'''',
								@architecture  OUTPUT
        
				IF @architecture = ''''x86''''
				BEGIN
					SET @use32bitruntime = 1
				END
        
        
				INSERT into [internal].[executions]
							(
								execution_id,
								folder_name,
								project_name,
								package_name,
								reference_id,
								reference_type,
								environment_folder_name,
								environment_name,
								project_lsn,
								executed_as_sid,
								executed_as_name,
								use32bitruntime
							)
					VALUES (
								@operation_id,              
								@folder_name,               
								@project_name,              
								@package_name,              
								@reference_id,
								@reference_type,        
								@environment_folder_name,
								@environment_name,
								@version_id,                
								@caller_sid,            
								@caller_name,           
								@use32bitruntime                    
							)
        
        
				SET @key_name = ''''MS_Enckey_Exec_''''+CONVERT(varchar,@execution_id)
				SET @certificate_name = ''''MS_Cert_Exec_''''+CONVERT(varchar,@execution_id)
        
				SET @sqlString = ''''CREATE CERTIFICATE '''' + @certificate_name + '''' WITH SUBJECT = ''''''''ISServerCertificate''''''''''''
        
				IF  NOT EXISTS (SELECT [name] FROM [sys].[certificates] WHERE [name] = @certificate_name)
					EXECUTE sp_executesql @sqlString 
        
				SET @sqlString = ''''CREATE SYMMETRIC KEY '''' + @key_name +'''' WITH ALGORITHM = '''' 
									+ @encryption_algorithm + '''' ENCRYPTION BY CERTIFICATE '''' + @certificate_name
        
				IF  NOT EXISTS (SELECT [name] FROM [sys].[symmetric_keys] WHERE [name] = @key_name)
					EXECUTE sp_executesql @sqlString 
        
				SET @sqlString = ''''OPEN SYMMETRIC KEY '''' + @key_name 
						+ '''' DECRYPTION BY CERTIFICATE '''' + @certificate_name  
					EXECUTE sp_executesql @sqlString
                   
        
				IF @environment_id IS NOT NULL
				BEGIN
					SET @env_key_name = ''''MS_Enckey_Env_''''+CONVERT(varchar,@environment_id)
					SET @env_certificate_name = ''''MS_Cert_Env_''''+CONVERT(varchar,@environment_id)
            
					SET @sqlString = ''''OPEN SYMMETRIC KEY '''' + @env_key_name 
							+ '''' DECRYPTION BY CERTIFICATE '''' + @env_certificate_name  
						EXECUTE sp_executesql @sqlString        
				END
        
        
				SET @project_key_name = ''''MS_Enckey_Proj_''''+CONVERT(varchar,@project_id)
				SET @project_certificate_name = ''''MS_Cert_Proj_''''+CONVERT(varchar,@project_id)

				SET @sqlString = ''''OPEN SYMMETRIC KEY '''' + @project_key_name 
						+ '''' DECRYPTION BY CERTIFICATE '''' + @project_certificate_name  
					EXECUTE sp_executesql @sqlString  

        
            
				INSERT INTO [internal].[execution_parameter_values]
				(  
					[execution_id], 
					[object_type], 
					[parameter_data_type], 
					[parameter_name], 
					[parameter_value],
					[sensitive_parameter_value],
					[base_data_type], 
					[sensitive], 
					[required], 
					[value_set], 
					[runtime_override]
				)
				SELECT  @execution_id, 
						[object_type], 
						[parameter_data_type], 
						[parameter_name],
						[default_value], 
						NULL, 
						[base_data_type],
						[sensitive], 
						[required], 
						[value_set], 
						0
				FROM [internal].[object_parameters] 
				WHERE [project_id] = @project_id 
				AND ([object_type] = 20 
				OR ([object_name] = @package_name 
				AND [object_type] = 30))
				AND sensitive = 0 
				AND [value_type] = ''''V'''' 
				AND [project_version_lsn] = @version_id
             
				INSERT INTO [internal].[execution_parameter_values]
				(  
					[execution_id], 
					[object_type], 
					[parameter_data_type], 
					[parameter_name], 
					[parameter_value],
					[sensitive_parameter_value],
					[base_data_type], 
					[sensitive], 
					[required], 
					[value_set], 
					[runtime_override]
				)
				SELECT  @execution_id, 
						[object_type], 
						[parameter_data_type], 
						[parameter_name], 
						NULL, 
						ENCRYPTBYKEY(KEY_GUID(@key_name), DECRYPTBYKEY(sensitive_default_value)),
						[base_data_type],
						[sensitive], 
						[required], 
						[value_set], 
						0
				FROM [internal].[object_parameters] 
				WHERE [project_id] = @project_id 
				AND ([object_type] = 20 
				OR ([object_name] = @package_name 
				AND [object_type] = 30))
				AND sensitive = 1 
				AND [value_type] = ''''V'''' 
				AND [project_version_lsn] = @version_id    
        
        
				DECLARE @server_logging_level [NVARCHAR](256)

				SELECT @server_logging_level = [property_value] 
				FROM [internal].[catalog_properties]
				WHERE [property_name] = ''''SERVER_LOGGING_LEVEL'''' 
        
				DECLARE @bitfalse bit
				SET @bitfalse = 0
        
				INSERT INTO [internal].[execution_parameter_values]
				(
					[execution_id], 
					[object_type], 
					[parameter_data_type], 
					[parameter_name], 
					[parameter_value],
					[base_data_type],
					[sensitive], 
					[required], 
					[value_set], 
					[runtime_override]
				)
				VALUES 
				(
					@execution_id,
					50,
					''''Boolean'''',
					''''DUMP_ON_ERROR'''',
					CONVERT(sql_variant,@bitfalse),
					''''bit'''',
					0,
					0,
					1,
					0
				),
				(
					@execution_id,
					50,
					''''Boolean'''',
					''''DUMP_ON_EVENT'''',
					CONVERT(sql_variant,@bitfalse),
					''''bit'''',
					0,
					0,
					1,
					0
				),
				(
					@execution_id,
					50,
					''''String'''',
					''''DUMP_EVENT_CODE'''',
					CONVERT(sql_variant,''''0''''),
					''''nvarchar'''',
					0,
					0,
					1,
					0
				),
				(
					@execution_id,
					50,
					''''Int32'''',
					''''LOGGING_LEVEL'''',
					CONVERT(sql_variant,CONVERT(INT,@server_logging_level)),
					''''int'''',
					0,
					0,
					1,
					0
				),
				(
					@execution_id,
					50,
					''''String'''',
					''''CALLER_INFO'''',
					null,
					''''nvarchar'''',
					0,
					0,
					1,
					0
				),
				(
					@execution_id,
					50,
					''''Boolean'''',
					''''SYNCHRONIZED'''',
					CONVERT(sql_variant,@bitfalse),
					''''bit'''',
					0,
					0,
					1,
					0
				)

        
				IF @environment_id IS NOT NULL
				BEGIN
					INSERT INTO [internal].[execution_parameter_values]
					(  
						[execution_id], 
						[object_type], 
						[parameter_data_type], 
						[parameter_name], 
						[parameter_value],
						[sensitive_parameter_value], 
						[base_data_type],
						[sensitive], 
						[required], 
						[value_set], 
						[runtime_override]
					)
					SELECT  @execution_id, 
							params.[object_type], 
							params.[parameter_data_type], 
							params.[parameter_name],
							vars.[value], 
							NULL, 
							vars.[base_data_type],
							params.[sensitive], 
							params.[required], 
							params.[value_set], 
							0
					FROM [internal].[object_parameters] params 
					INNER JOIN [internal].[environment_variables] vars
						ON params.[referenced_variable_name] = vars.[name] 
					WHERE params.[project_id] = @project_id 
					AND (params.[object_type] = 20
					OR (params.[object_name] = @package_name 
					AND params.[object_type] = 30))
					AND vars.[sensitive] = 0 
					AND params.[value_type] = ''''R'''' 
					AND params.[project_version_lsn] = @version_id
					AND vars.[environment_id] = @environment_id
            
					INSERT INTO [internal].[execution_parameter_values]
					(  
						[execution_id], 
						[object_type], 
						[parameter_data_type], 
						[parameter_name], 
						[parameter_value],
						[sensitive_parameter_value],
						[base_data_type], 
						[sensitive], 
						[required], 
						[value_set], 
						[runtime_override]
					)
					SELECT  @execution_id, 
							params.[object_type], 
							params.[parameter_data_type], 
							params.[parameter_name],
							NULL, 
							ENCRYPTBYKEY(KEY_GUID(@key_name), DECRYPTBYKEY(vars.[sensitive_value])), 
							vars.[base_data_type],
							vars.[sensitive], 
							params.[required], 
							params.[value_set], 
							0
					FROM [internal].[object_parameters] params 
					INNER JOIN [internal].[environment_variables] vars
						ON params.[referenced_variable_name] = vars.[name] 
					WHERE params.[project_id] = @project_id 
					AND (params.[object_type] = 20
					OR (params.[object_name] = @package_name 
					AND params.[object_type] = 30))
					AND vars.[sensitive] = 1 
					AND params.[value_type] = ''''R'''' 
					AND params.[project_version_lsn] = @version_id        
					AND vars.[environment_id] = @environment_id
            
					SET @sqlString = ''''CLOSE SYMMETRIC KEY ''''+ @env_key_name
						EXECUTE sp_executesql @sqlString
				END
        
        
				UPDATE [internal].[execution_parameter_values]
				SET [sensitive_parameter_value] = EncryptByKey(KEY_GUID(@key_name),CONVERT(varbinary(4000),CONVERT(datetime2,parameter_value))),
				[parameter_value] = NULL
				WHERE [execution_id] = @operation_id 
				AND [sensitive] = 1 
				AND [parameter_value] IS NOT NULL
				AND [sensitive_parameter_value] IS NULL 
				AND [parameter_data_type] = ''''datetime''''
        
				UPDATE [internal].[execution_parameter_values]
				SET [sensitive_parameter_value] = EncryptByKey(KEY_GUID(@key_name),CONVERT(varbinary(4000),CONVERT(decimal(38,18),parameter_value))),
				[parameter_value] = NULL
				WHERE [execution_id] = @operation_id 
				AND [sensitive] = 1 
				AND [parameter_value] IS NOT NULL
				AND [sensitive_parameter_value] IS NULL 
				AND ([parameter_data_type] = ''''double'''' OR [parameter_data_type] = ''''single'''' OR [parameter_data_type] = ''''decimal'''')
        
				UPDATE [internal].[execution_parameter_values]
				SET [sensitive_parameter_value] = EncryptByKey(KEY_GUID(@key_name),CONVERT(varbinary(4000),[parameter_value])),
				[parameter_value] = NULL
				WHERE [execution_id] = @operation_id 
				AND [sensitive] = 1 
				AND [parameter_value] IS NOT NULL
				AND [sensitive_parameter_value] IS NULL 
				AND [parameter_data_type] NOT IN (''''datetime'''', ''''double'''', ''''single'''', ''''decimal'''')  
        
              
        
				INSERT INTO [internal].[execution_parameter_values]
				(  
					[execution_id], 
					[object_type], 
					[parameter_data_type], 
					[parameter_name], 
					[parameter_value],
					[sensitive_parameter_value],
					[base_data_type], 
					[sensitive], 
					[required], 
					[value_set], 
					[runtime_override]
				)
				SELECT  @execution_id,
						objParams.[object_type], 
						objParams.[parameter_data_type], 
						objParams.[parameter_name],
						NULL, 
						NULL,
						NULL, 
						objParams.[sensitive], 
						objParams.[required], 
						0, 
						0
				FROM 
				(SELECT [object_type], 
						[parameter_data_type], 
						[parameter_name],
						[sensitive], 
						[required]
				FROM [internal].[object_parameters]
				WHERE [project_id] = @project_id 
				AND [object_type] = 20
				AND [value_type] = ''''R'''' 
				AND [project_version_lsn] = @version_id) objParams
				LEFT JOIN
				(SELECT [object_type],[parameter_name]
					FROM [internal].[execution_parameter_values] 
					WHERE [execution_id] = @operation_id) exeParams
					ON objParams.[object_type] = exeParams.[object_type]
					AND objParams.[parameter_name] = exeParams.[parameter_name] COLLATE SQL_Latin1_General_CP1_CS_AS
				WHERE exeParams.[parameter_name] IS NULL
        
            
				INSERT INTO [internal].[execution_parameter_values]
				(  
					[execution_id], 
					[object_type], 
					[parameter_data_type], 
					[parameter_name], 
					[parameter_value],
					[sensitive_parameter_value],
					[base_data_type], 
					[sensitive], 
					[required], 
					[value_set], 
					[runtime_override]
				)
				SELECT  @execution_id,
						objParams.[object_type], 
						objParams.[parameter_data_type], 
						objParams.[parameter_name],
						NULL, 
						NULL,
						NULL, 
						objParams.[sensitive], 
						objParams.[required], 
						0, 
						0
				FROM 
				(SELECT [object_type], 
						[parameter_data_type], 
						[parameter_name],
						[sensitive], 
						[required]
				FROM [internal].[object_parameters]
				WHERE [project_id] = @project_id 
				AND [object_type] = 30
				AND [value_type] = ''''R'''' 
				AND [project_version_lsn] = @version_id
				AND [object_name] = @package_name) objParams
				LEFT JOIN
				(SELECT [object_type],[parameter_name]
					FROM [internal].[execution_parameter_values] 
					WHERE [execution_id] = @operation_id) exeParams
					ON objParams.[object_type] = exeParams.[object_type]
					AND objParams.[parameter_name] = exeParams.[parameter_name] COLLATE SQL_Latin1_General_CP1_CS_AS
				WHERE exeParams.[parameter_name] IS NULL;
        
        
        
				WITH UnsetParameters AS
				(
					SELECT [execution_id],[object_type],[parameter_name],[parameter_value],[value_set]
					FROM [internal].[execution_parameter_values] 
					WHERE [sensitive] = 0 AND [required] = 0 AND [value_set] = 0
					AND [execution_id] = @operation_id
				)
				UPDATE exeparams
					SET [parameter_value] = objparams.[design_default_value]
					FROM UnsetParameters AS exeparams INNER JOIN [internal].[object_parameters] objparams
					ON exeparams.[parameter_name] = objparams.[parameter_name] COLLATE SQL_Latin1_General_CP1_CS_AS
					AND exeparams.[object_type] = objparams.[object_type] 
					AND exeparams.[value_set] = objparams.[value_set]
					WHERE 
					(objparams.[object_type] = 20 OR 
					(objparams.[object_type] = 30 AND objparams.[object_name] = @package_name))
					AND objparams.[project_id] = @project_id 
					AND objparams.[project_version_lsn] = @version_id;

        
               
        
				SET @sqlString = ''''CLOSE SYMMETRIC KEY ''''+ @key_name
					EXECUTE sp_executesql @sqlString
        
				SET @sqlString = ''''CLOSE SYMMETRIC KEY ''''+ @project_key_name
					EXECUTE sp_executesql @sqlString       
        
    
				IF @tran_count = 0
					COMMIT TRANSACTION;                                                                                 
			END TRY
    
			BEGIN CATCH
        
				IF @tran_count = 0 
					ROLLBACK TRANSACTION;
        
				ELSE IF XACT_STATE() <> -1
					ROLLBACK TRANSACTION @savepoint_name;                                                                           
				UPDATE [internal].[operations] SET 
					[end_time]  = SYSDATETIMEOFFSET(),
					[status]    = 4
					WHERE operation_id    = @operation_id;
				THROW;
			END CATCH
    
			RETURN 0 '

			SET @cmd = N'EXEC SSISDB.dbo.sp_executesql @statement=N''' + @rawCmd + ''''
			EXEC sp_executesql @cmd
			PRINT 'Stored procedure [catalog].[create_execution] has been recreated.'
		END

		--3. grant the permission on new one
		IF OBJECT_ID (N'SSISDB.[catalog].[create_execution]', N'P') IS NOT NULL
		BEGIN
			SET @rawCmd = N'GRANT EXECUTE ON [catalog].[create_execution] TO [PUBLIC]'
			SET @cmd = N'EXEC SSISDB.dbo.sp_executesql @statement=N''' + @rawCmd + ''''
			EXEC sp_executesql @cmd
			PRINT 'Permissions on [catalog].[create_execution] has been granted.'
		END

		--3.1 ADD Noncluster index for SSISDB
		PRINT 'Remove Noncluster Index in SSISDB'
	
		IF EXISTS (SELECT * FROM SSISDB.sys.indexes WHERE name = 'IX_OperationMessages_Operation_id'  AND object_id = OBJECT_ID('SSISDB.internal.operation_messages'))
		DROP INDEX IX_OperationMessages_Operation_id ON SSISDB.internal.operation_messages

		IF EXISTS (SELECT * FROM SSISDB.sys.indexes WHERE name = 'IX_ExecutableStatistics_Execution_id'  AND object_id = OBJECT_ID('SSISDB.internal.executable_statistics'))
		DROP INDEX IX_ExecutableStatistics_Execution_id ON SSISDB.internal.executable_statistics

		IF EXISTS (SELECT * FROM SSISDB.sys.indexes WHERE name = 'Unique_sequence_id'  AND object_id = OBJECT_ID('SSISDB.internal.execution_component_phases'))
		DROP INDEX Unique_sequence_id ON SSISDB.internal.execution_component_phases

		CREATE NONCLUSTERED INDEX [Unique_sequence_id] 
		ON [SSISDB].[internal].[execution_component_phases] 
		(
			[sequence_id] ASC
		)

		IF EXISTS (SELECT * FROM SSISDB.sys.indexes WHERE name = 'IX_EventMessages_Operation_id'  AND object_id = OBJECT_ID('SSISDB.internal.event_messages'))
		DROP INDEX IX_EventMessages_Operation_id ON SSISDB.internal.event_messages

		IF EXISTS (SELECT * FROM SSISDB.sys.indexes WHERE name = 'IX_EventMessageContext_Operation_id'  AND object_id = OBJECT_ID('SSISDB.internal.event_message_context'))
		DROP INDEX IX_EventMessageContext_Operation_id ON SSISDB.internal.event_message_context

		--Finally, update the schema build number to server's build number
		SET @cmd = 'UPDATE [SSISDB].[internal].[catalog_properties] SET property_value = N''' + @targetVersion + ''' WHERE property_name = N''SCHEMA_BUILD'''
		EXEC sp_executesql @cmd
		PRINT 'Schema build in SSISDB has been updated to ' + @targetVersion
END

PRINT '------------------------------------------------------'
PRINT 'Execution of SSIS_HOTFIX_UNINSTALL.SQL completed'
PRINT '------------------------------------------------------'
GO

