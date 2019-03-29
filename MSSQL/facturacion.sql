-- phpMyAdmin SQL Dump
-- version 4.7.0
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 29-03-2019 a las 16:54:47
-- Versión del servidor: 5.7.17
-- Versión de PHP: 7.1.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `facturacion`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `administrador`
--

CREATE TABLE `administrador` (
  `Id` int(11) NOT NULL,
  `Ci` int(11) NOT NULL,
  `Nombre` varchar(50) NOT NULL,
  `Apellidos` varchar(50) NOT NULL,
  `Usuario` varchar(50) NOT NULL,
  `Password` varchar(50) NOT NULL,
  `Admin` tinyint(1) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `administrador`
--

INSERT INTO `administrador` (`Id`, `Ci`, `Nombre`, `Apellidos`, `Usuario`, `Password`, `Admin`) VALUES
(1, 13270047, 'Brandon', 'Trimer', 'Trimer', 'Trimer001', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `categoria`
--

CREATE TABLE `categoria` (
  `Id` int(11) NOT NULL,
  `Nombre` varchar(50) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cliente`
--

CREATE TABLE `cliente` (
  `Id` int(11) NOT NULL,
  `Nit` int(11) NOT NULL,
  `Nombre` int(11) NOT NULL,
  `Apellidos` varchar(50) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `factura`
--

CREATE TABLE `factura` (
  `Id` int(11) NOT NULL,
  `FechaVenta` date NOT NULL,
  `CantidadTotal` int(11) NOT NULL,
  `PrecioTotal` double NOT NULL,
  `Id_administrador` int(11) NOT NULL,
  `Id_cliente` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto`
--

CREATE TABLE `producto` (
  `Id` int(11) NOT NULL,
  `Nombre` varchar(50) NOT NULL,
  `Color` varchar(50) NOT NULL,
  `Marca` varchar(50) NOT NULL,
  `Longitud` double NOT NULL,
  `Precio` double NOT NULL,
  `Stock` int(11) NOT NULL,
  `Imagen` varchar(50) NOT NULL,
  `Id_categoria` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto_factura`
--

CREATE TABLE `producto_factura` (
  `id_producto_factura` int(11) NOT NULL,
  `id_producto` int(11) NOT NULL,
  `id_factura` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `administrador`
--
ALTER TABLE `administrador`
  ADD PRIMARY KEY (`Id`);

--
-- Indices de la tabla `categoria`
--
ALTER TABLE `categoria`
  ADD PRIMARY KEY (`Id`);

--
-- Indices de la tabla `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`Id`);

--
-- Indices de la tabla `factura`
--
ALTER TABLE `factura`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `Id_Administrador` (`Id_administrador`),
  ADD UNIQUE KEY `Id_cliente` (`Id_cliente`);

--
-- Indices de la tabla `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `Id_Categoria` (`Id_categoria`);

--
-- Indices de la tabla `producto_factura`
--
ALTER TABLE `producto_factura`
  ADD PRIMARY KEY (`id_producto_factura`),
  ADD UNIQUE KEY `id_producto` (`id_producto`),
  ADD UNIQUE KEY `id_factura` (`id_factura`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
