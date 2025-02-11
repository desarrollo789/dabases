USE [master]
GO
/****** Object:  Database [facturacion]    Script Date: 3/28/2019 3:09:02 AM ******/
CREATE DATABASE [facturacion]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'facturacion', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.PRUEBAS\MSSQL\DATA\facturacion.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'facturacion_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.PRUEBAS\MSSQL\DATA\facturacion_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [facturacion] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [facturacion].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [facturacion] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [facturacion] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [facturacion] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [facturacion] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [facturacion] SET ARITHABORT OFF 
GO
ALTER DATABASE [facturacion] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [facturacion] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [facturacion] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [facturacion] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [facturacion] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [facturacion] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [facturacion] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [facturacion] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [facturacion] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [facturacion] SET  DISABLE_BROKER 
GO
ALTER DATABASE [facturacion] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [facturacion] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [facturacion] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [facturacion] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [facturacion] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [facturacion] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [facturacion] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [facturacion] SET RECOVERY FULL 
GO
ALTER DATABASE [facturacion] SET  MULTI_USER 
GO
ALTER DATABASE [facturacion] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [facturacion] SET DB_CHAINING OFF 
GO
ALTER DATABASE [facturacion] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [facturacion] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [facturacion] SET DELAYED_DURABILITY = DISABLED 
GO
EXEC sys.sp_db_vardecimal_storage_format N'facturacion', N'ON'
GO
USE [facturacion]
GO
/****** Object:  Table [dbo].[Administrador]    Script Date: 3/28/2019 3:09:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Administrador](
	[id_administrador] [int] IDENTITY(1,1) NOT NULL,
	[password] [varchar](max) NOT NULL,
	[ci] [int] NULL,
	[nombre] [varbinary](max) NULL,
	[apellido_pat] [varbinary](max) NULL,
	[apellido_mat] [varchar](max) NULL,
	[admin] [bit] NOT NULL,
	[usuario] [varbinary](50) NOT NULL,
 CONSTRAINT [PK_Administrador] PRIMARY KEY CLUSTERED 
(
	[id_administrador] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Carro]    Script Date: 3/28/2019 3:09:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Carro](
	[id_carro] [int] NOT NULL,
	[id_producto] [int] NOT NULL,
	[id_factura] [int] NOT NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Categoria]    Script Date: 3/28/2019 3:09:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Categoria](
	[id_categoria] [int] IDENTITY(1,1) NOT NULL,
	[Nombre] [int] NULL,
 CONSTRAINT [PK_Categoria] PRIMARY KEY CLUSTERED 
(
	[id_categoria] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Cliente]    Script Date: 3/28/2019 3:09:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Cliente](
	[id_cliente] [int] IDENTITY(1,1) NOT NULL,
	[nombre] [varchar](max) NULL,
	[apellido_pat] [varchar](max) NULL,
	[apellido_mat] [varchar](max) NULL,
	[nit] [int] NOT NULL,
 CONSTRAINT [PK_Cliente] PRIMARY KEY CLUSTERED 
(
	[id_cliente] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Factura]    Script Date: 3/28/2019 3:09:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Factura](
	[id_factura] [int] IDENTITY(1,1) NOT NULL,
	[id_cliente] [int] NOT NULL,
	[serie] [int] NULL,
	[sucursal] [int] NULL,
	[precio_total] [float] NULL,
	[fecha_venta] [date] NULL,
	[cantidad_total] [int] NULL,
 CONSTRAINT [PK_Factura] PRIMARY KEY CLUSTERED 
(
	[id_factura] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Producto]    Script Date: 3/28/2019 3:09:03 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Producto](
	[id_producto] [int] IDENTITY(1,1) NOT NULL,
	[id_categoria] [int] NOT NULL,
	[nombre] [varchar](max) NULL,
	[precio] [float] NULL,
	[stock] [int] NULL,
	[imagen] [varchar](max) NULL,
 CONSTRAINT [PK_Producto] PRIMARY KEY CLUSTERED 
(
	[id_producto] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Index [IX_Producto]    Script Date: 3/28/2019 3:09:03 AM ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_Producto] ON [dbo].[Producto]
(
	[id_categoria] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Categoria]  WITH CHECK ADD  CONSTRAINT [FK_Categoria_Categoria] FOREIGN KEY([id_categoria])
REFERENCES [dbo].[Producto] ([id_categoria])
GO
ALTER TABLE [dbo].[Categoria] CHECK CONSTRAINT [FK_Categoria_Categoria]
GO
USE [master]
GO
ALTER DATABASE [facturacion] SET  READ_WRITE 
GO
