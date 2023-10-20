-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Φιλοξενητής: 127.0.0.1
-- Χρόνος δημιουργίας: 13 Ιαν 2021 στις 22:17:59
-- Έκδοση διακομιστή: 10.4.17-MariaDB
-- Έκδοση PHP: 8.0.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Βάση δεδομένων: `cs360_3660`
--

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `administrator`
--

CREATE TABLE `administrator` (
  `SID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `administrator`
--

INSERT INTO `administrator` (`SID`) VALUES
(1001),
(1002);

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `attend`
--

CREATE TABLE `attend` (
  `SID` int(11) NOT NULL,
  `DAY` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `attend`
--

INSERT INTO `attend` (`SID`, `DAY`) VALUES
(2001, '2021-01-12'),
(2002, '2021-01-12'),
(2003, '2021-01-12'),
(2007, '2021-01-12'),
(2008, '2021-01-12'),
(2009, '2021-01-12'),
(2013, '2021-01-12'),
(2014, '2021-01-12'),
(2015, '2021-01-12'),
(2019, '2021-01-12'),
(2020, '2021-01-12'),
(2021, '2021-01-12'),
(2025, '2021-01-12'),
(2026, '2021-01-12'),
(2027, '2021-01-12'),
(3001, '2021-01-12'),
(3002, '2021-01-12'),
(3003, '2021-01-12'),
(3004, '2021-01-12'),
(1001, '2021-01-12');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `doctor`
--

CREATE TABLE `doctor` (
  `SID` int(11) NOT NULL,
  `YEARS` int(11) NOT NULL,
  `SPECIALTY` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `doctor`
--

INSERT INTO `doctor` (`SID`, `YEARS`, `SPECIALTY`) VALUES
(2001, 10, 'PATHOLOGIST'),
(2002, 8, 'PATHOLOGIST'),
(2003, 17, 'PATHOLOGIST'),
(2004, 22, 'PATHOLOGIST'),
(2005, 32, 'PATHOLOGIST'),
(2006, 5, 'PATHOLOGIST'),
(2007, 15, 'CARDIOLOGIST'),
(2008, 4, 'CARDIOLOGIST'),
(2009, 33, 'CARDIOLOGIST'),
(2010, 24, 'CARDIOLOGIST'),
(2011, 7, 'CARDIOLOGIST'),
(2012, 15, 'CARDIOLOGIST'),
(2013, 14, 'ANESTHISIOLOGIST'),
(2014, 16, 'ANESTHISIOLOGIST'),
(2015, 22, 'ANESTHISIOLOGIST'),
(2016, 28, 'ANESTHISIOLOGIST'),
(2017, 10, 'ANESTHISIOLOGIST'),
(2018, 3, 'ANESTHISIOLOGIST'),
(2019, 19, 'UROLOGIST'),
(2020, 4, 'UROLOGIST'),
(2021, 9, 'UROLOGIST'),
(2022, 7, 'UROLOGIST'),
(2023, 18, 'UROLOGIST'),
(2024, 23, 'UROLOGIST'),
(2025, 35, 'INFECTIOUS DISEASE EXPERT'),
(2026, 11, 'INFECTIOUS DISEASE EXPERT'),
(2027, 22, 'INFECTIOUS DISEASE EXPERT'),
(2028, 33, 'INFECTIOUS DISEASE EXPERT'),
(2029, 16, 'INFECTIOUS DISEASE EXPERT'),
(2030, 26, 'INFECTIOUS DISEASE EXPERT');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `duty`
--

CREATE TABLE `duty` (
  `SID` int(11) NOT NULL,
  `DAY` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `duty`
--

INSERT INTO `duty` (`SID`, `DAY`) VALUES
(2001, '2021-01-12'),
(2002, '2021-01-12'),
(2003, '2021-01-12'),
(2007, '2021-01-12'),
(2008, '2021-01-12'),
(2009, '2021-01-12'),
(2013, '2021-01-12'),
(2014, '2021-01-12'),
(2015, '2021-01-12'),
(2019, '2021-01-12'),
(2020, '2021-01-12'),
(2021, '2021-01-12'),
(2025, '2021-01-12'),
(2026, '2021-01-12'),
(2027, '2021-01-12'),
(3001, '2021-01-12'),
(3002, '2021-01-12'),
(3003, '2021-01-12'),
(3004, '2021-01-12'),
(1001, '2021-01-12');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `examines`
--

CREATE TABLE `examines` (
  `SID` int(11) NOT NULL,
  `DAY` date NOT NULL,
  `AMKA` int(11) NOT NULL,
  `TYPE` varchar(50) NOT NULL,
  `RESULT` varchar(300) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `examines`
--

INSERT INTO `examines` (`SID`, `DAY`, `AMKA`, `TYPE`, `RESULT`) VALUES
(1001, '2021-01-12', 9001, 'COVID-19', 'POSITIVE'),
(2002, '2021-01-12', 9002, 'COVID-19', 'NEGATIVE'),
(1002, '2021-01-12', 9003, 'AIMATOLOGIKES', 'FUSIOLOGIKES'),
(1004, '2021-01-12', 9004, 'COVID-19', 'POSITIVE'),
(1004, '2021-01-12', 9004, 'AIMATOLOGIKES', '9002'),
(1001, '2021-01-12', 9005, 'COVID-19', 'AUXIMENA LEUKA');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `medicine`
--

CREATE TABLE `medicine` (
  `MID` int(11) NOT NULL,
  `TYPE` varchar(30) NOT NULL,
  `USAGES` varchar(60) DEFAULT NULL,
  `NAME` varchar(40) NOT NULL,
  `MG` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `medicine`
--

INSERT INTO `medicine` (`MID`, `TYPE`, `USAGES`, `NAME`, `MG`) VALUES
(150317, 'PILL', 'MUCOSAL FUNCTION', 'VISCOFLU', ' '),
(152373, 'PILL', 'VITAMIN B12 B6 B11', 'NEUROBION', ' '),
(174932, 'PILL', 'HEARTBURN', 'DULCOGAS', '125mg Simethicone'),
(462189, 'INHALE', 'ASTHMA', 'SYMBICORT', '160mg VOUDESONIDI'),
(465218, 'PILL', 'PAINKILLER', 'NAPROSYN', '1000mg NAPROXEN'),
(473492, 'PILL', 'ANTIPIRETIC', 'ALGOFREN', '600mg IVUPROFEN'),
(640932, 'INHALE', 'ASTHMA', 'FLIXOTIDE', '200mg FLUTICASONE'),
(659323, 'PILL', 'ASTHMA', 'APILONE', '500mg CELLULOSE'),
(749290, 'CREAM', 'BURN', 'PROFLAMINE', ' '),
(948521, 'VACCINE', 'PAINKILLER', 'VOLTAREN', '500mg');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `nurse`
--

CREATE TABLE `nurse` (
  `SID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `nurse`
--

INSERT INTO `nurse` (`SID`) VALUES
(3001),
(3002),
(3003),
(3004),
(3005),
(3006),
(3007),
(3008),
(3009),
(3010),
(3011);

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `patient`
--

CREATE TABLE `patient` (
  `ACCESS` int(11) NOT NULL,
  `NAME` varchar(30) NOT NULL,
  `SURNAME` varchar(30) NOT NULL,
  `PHONE` bigint(20) NOT NULL,
  `EMAIL` varchar(255) DEFAULT NULL,
  `INSURANCE` varchar(100) DEFAULT NULL,
  `AMKA` bigint(20) NOT NULL,
  `BIRTHDAY` date DEFAULT NULL,
  `ADDRESS` varchar(255) DEFAULT NULL,
  `CHRONICCO` varchar(300) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `patient`
--

INSERT INTO `patient` (`ACCESS`, `NAME`, `SURNAME`, `PHONE`, `EMAIL`, `INSURANCE`, `AMKA`, `BIRTHDAY`, `ADDRESS`, `CHRONICCO`) VALUES
(1, 'GIWRGOS', 'TADE', 6969696969, 'GIWRGOS@YAHOO.GR', 'ETHNIKI ASFALISTIKI', 9001, '1997-01-17', 'ETHNIKIS ANTISTASEWS', 'XAP'),
(1, 'GIANNIS', 'TADE', 6969696969, 'GIANNIS@YAHOO.GR', 'ETHNIKI ASFALISTIKI', 9002, '1997-01-17', 'ETHNIKIS ANTISTASEWS', 'ASTHMA'),
(1, 'KWSTAS', 'TADE', 6969696969, 'KWSTAS@YAHOO.GR', 'NONE', 9003, '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(1, 'SWTIRIS', 'TADE', 6969696969, 'SWTIRIS@YAHOO.GR', 'ETHNIKI ASFALISTIKI', 9004, '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(1, 'PETROS', 'TADE', 6969696969, 'PETROS@YAHOO.GR', 'ETHNIKI ASFALISTIKI', 9005, '1997-01-17', 'ETHNIKIS ANTISTASEWS', 'ASTHMA'),
(1, 'DIMITRIS', 'TADE', 6969696969, 'DIMITRIS@YAHOO.GR', 'NONE', 9006, '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(1, 'KATERINA', 'TADE', 6969696969, 'KATERINA@YAHOO.GR', 'ETHNIKI ASFALISTIKI', 9007, '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(1, 'MARIA', 'TADE', 6969696969, 'MARIA@YAHOO.GR', 'NONE', 9008, '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(1, 'ISIDWRA', 'TADE', 6969696969, 'ISIDWRA@YAHOO.GR', 'ETHNIKI ASFALISTIKI', 9009, '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' ');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `prescribe`
--

CREATE TABLE `prescribe` (
  `SID` int(11) NOT NULL,
  `DAY` date NOT NULL,
  `MID` int(11) NOT NULL,
  `PID` varchar(250) NOT NULL,
  `AMKA` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `prescribe`
--

INSERT INTO `prescribe` (`SID`, `DAY`, `MID`, `PID`, `AMKA`) VALUES
(1001, '2021-01-12', 150317, '150317100120210112', 9003),
(1002, '2021-01-12', 150317, '150317100220210112', 9001),
(1004, '2021-01-12', 150317, '150317100420210112', 9002),
(2001, '2021-01-12', 150317, '150317200120210112', 9005),
(2002, '2021-01-12', 150317, '150317200220210112', 9001),
(1004, '2021-01-12', 462189, '462189100420210112', 9002);

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `staff`
--

CREATE TABLE `staff` (
  `SID` int(11) NOT NULL,
  `ACCESS` int(11) NOT NULL,
  `NAME` varchar(30) NOT NULL,
  `SURNAME` varchar(30) NOT NULL,
  `PHONE` bigint(20) NOT NULL,
  `EMAIL` varchar(255) NOT NULL,
  `BIRTHDAY` date NOT NULL,
  `ADDRESS` varchar(255) NOT NULL,
  `NOTES` varchar(300) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `staff`
--

INSERT INTO `staff` (`SID`, `ACCESS`, `NAME`, `SURNAME`, `PHONE`, `EMAIL`, `BIRTHDAY`, `ADDRESS`, `NOTES`) VALUES
(1001, 9, 'GIWRGOS', 'MITSOS', 6978372792, 'csd3660@CSD.UOC.GR', '1997-01-17', 'ETHNIKIS ANTISTASEWS', 'SUNEDRIO STIS 19/2'),
(1002, 9, 'THEMIS', 'MITSOS', 1111223344, '1002@CSD.UOC.GR', '1993-09-04', 'HRAKLIO', ' '),
(2001, 3, 'STELIOS', 'KATIS', 2134743832, '1003@CSD.UOC.GR', '1799-02-19', 'AUGOUSTOU', ' '),
(2002, 3, 'STAMATIS', 'ENAS', 9321656421, '1004@CSD.UOC.GR', '1337-06-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(2003, 3, 'MARIA', 'DELOGLOU', 6763126813, '1005@CSD.UOC.GR', '1963-03-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2004, 3, 'DIMITRIS', 'BAKU', 3612813783, '1006@CSD.UOC.GR', '1978-02-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2005, 3, 'GIWRGOS', 'MITAKIDIS', 7859378219, '1007@CSD.UOC.GR', '1957-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2006, 3, 'GIWRGOS', 'KAPIOS', 6978372792, '1008@CSD.UOC.GR', '1977-01-17', 'ETHNIKIS ANTISTASEWS', 'SUNEDRIO STIS 16/2'),
(2007, 3, 'AKIS', 'MPAKOULIS', 1111223344, '1009@CSD.UOC.GR', '1987-01-01', 'HRAKLIO', ' '),
(2008, 3, 'GIANNIS', 'PLOUTARXOS', 2134743832, '1010@CSD.UOC.GR', '1993-02-19', 'AUGOUSTOU', ' '),
(2009, 3, 'KWSTAS', 'DYOS', 9321656421, '1011@CSD.UOC.GR', '1989-01-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(2010, 3, 'ISMINI', 'KARPEROU', 6763126813, '1012@CSD.UOC.GR', '1985-03-16', 'ETHNIKIS ANTISTASEWS', ' '),
(2011, 3, 'DIMITRIS', 'PAPAIOANNOY', 3612813783, '1013@CSD.UOC.GR', '1967-01-10', 'ETHNIKIS ANTISTASEWS', ' '),
(2012, 3, 'SOFOKLIS', 'MPEKAS', 7859378219, '1014@CSD.UOC.GR', '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2013, 3, 'STELIOS', 'KATIS', 2134743832, '1003@CSD.UOC.GR', '1799-02-19', 'AUGOUSTOU', ' '),
(2014, 3, 'STAMATIS', 'ENAS', 9321656421, '1004@CSD.UOC.GR', '1337-06-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(2015, 3, 'MARIA', 'DELOGLOU', 6763126813, '1005@CSD.UOC.GR', '1963-03-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2016, 3, 'DIMITRIS', 'BAKU', 3612813783, '1006@CSD.UOC.GR', '1978-02-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2017, 3, 'GIWRGOS', 'MITAKIDIS', 7859378219, '1007@CSD.UOC.GR', '1957-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2018, 3, 'GIWRGOS', 'KAPIOS', 6978372792, '1008@CSD.UOC.GR', '1977-01-17', 'ETHNIKIS ANTISTASEWS', 'SUNEDRIO STIS 16/2'),
(2019, 3, 'AKIS', 'MPAKOULIS', 1111223344, '1009@CSD.UOC.GR', '1987-01-01', 'HRAKLIO', ' '),
(2020, 3, 'GIANNIS', 'PLOUTARXOS', 2134743832, '1010@CSD.UOC.GR', '1993-02-19', 'AUGOUSTOU', ' '),
(2021, 3, 'KWSTAS', 'DYOS', 9321656421, '1011@CSD.UOC.GR', '1989-01-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(2022, 3, 'ISMINI', 'KARPEROU', 6763126813, '1012@CSD.UOC.GR', '1985-03-16', 'ETHNIKIS ANTISTASEWS', ' '),
(2023, 3, 'DIMITRIS', 'PAPAIOANNOY', 3612813783, '1013@CSD.UOC.GR', '1967-01-10', 'ETHNIKIS ANTISTASEWS', ' '),
(2024, 3, 'SOFOKLIS', 'MPEKAS', 7859378219, '1014@CSD.UOC.GR', '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2025, 3, 'GIANNIS', 'PLOUTARXOS', 2134743832, '1010@CSD.UOC.GR', '1993-02-19', 'AUGOUSTOU', ' '),
(2026, 3, 'KWSTAS', 'DYOS', 9321656421, '1011@CSD.UOC.GR', '1989-01-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(2027, 3, 'ISMINI', 'KARPEROU', 6763126813, '1012@CSD.UOC.GR', '1985-03-16', 'ETHNIKIS ANTISTASEWS', ' '),
(2028, 3, 'DIMITRIS', 'PAPAIOANNOY', 3612813783, '1013@CSD.UOC.GR', '1967-01-10', 'ETHNIKIS ANTISTASEWS', ' '),
(2029, 3, 'SOFOKLIS', 'MPEKAS', 7859378219, '1014@CSD.UOC.GR', '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(2030, 3, 'STELIOS', 'KATIS', 2134743832, '1003@CSD.UOC.GR', '1799-02-19', 'AUGOUSTOU', ' '),
(3001, 2, 'STAMATIS', 'ENAS', 9321656421, '1004@CSD.UOC.GR', '1337-06-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(3002, 2, 'MARIA', 'DELOGLOU', 6763126813, '1005@CSD.UOC.GR', '1963-03-17', 'ETHNIKIS ANTISTASEWS', ' '),
(3003, 2, 'DIMITRIS', 'BAKU', 3612813783, '1006@CSD.UOC.GR', '1978-02-17', 'ETHNIKIS ANTISTASEWS', ' '),
(3004, 2, 'GIWRGOS', 'MITAKIDIS', 7859378219, '1007@CSD.UOC.GR', '1957-01-17', 'ETHNIKIS ANTISTASEWS', ' '),
(3005, 2, 'GIWRGOS', 'KAPIOS', 6978372792, '1008@CSD.UOC.GR', '1977-01-17', 'ETHNIKIS ANTISTASEWS', 'SUNEDRIO STIS 16/2'),
(3006, 2, 'AKIS', 'MPAKOULIS', 1111223344, '1009@CSD.UOC.GR', '1987-01-01', 'HRAKLIO', ' '),
(3007, 2, 'GIANNIS', 'PLOUTARXOS', 2134743832, '1010@CSD.UOC.GR', '1993-02-19', 'AUGOUSTOU', ' '),
(3008, 2, 'KWSTAS', 'DYOS', 9321656421, '1011@CSD.UOC.GR', '1989-01-17', 'ETHNIKIS ANTISTASEWS', 'ARRWSTOS'),
(3009, 2, 'ISMINI', 'KARPEROU', 6763126813, '1012@CSD.UOC.GR', '1985-03-16', 'ETHNIKIS ANTISTASEWS', ' '),
(3010, 2, 'DIMITRIS', 'PAPAIOANNOY', 3612813783, '1013@CSD.UOC.GR', '1967-01-10', 'ETHNIKIS ANTISTASEWS', ' '),
(3011, 2, 'SOFOKLIS', 'MPEKAS', 7859378219, '1014@CSD.UOC.GR', '1997-01-17', 'ETHNIKIS ANTISTASEWS', ' ');

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `takes`
--

CREATE TABLE `takes` (
  `AMKA` int(11) NOT NULL,
  `MID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Άδειασμα δεδομένων του πίνακα `takes`
--

INSERT INTO `takes` (`AMKA`, `MID`) VALUES
(9003, 150317),
(9001, 150317),
(9001, 150317),
(9002, 462189),
(9002, 150317),
(9005, 150317);

--
-- Ευρετήρια για άχρηστους πίνακες
--

--
-- Ευρετήρια για πίνακα `administrator`
--
ALTER TABLE `administrator`
  ADD PRIMARY KEY (`SID`);

--
-- Ευρετήρια για πίνακα `doctor`
--
ALTER TABLE `doctor`
  ADD PRIMARY KEY (`SID`);

--
-- Ευρετήρια για πίνακα `medicine`
--
ALTER TABLE `medicine`
  ADD PRIMARY KEY (`MID`);

--
-- Ευρετήρια για πίνακα `nurse`
--
ALTER TABLE `nurse`
  ADD PRIMARY KEY (`SID`);

--
-- Ευρετήρια για πίνακα `patient`
--
ALTER TABLE `patient`
  ADD PRIMARY KEY (`AMKA`);

--
-- Ευρετήρια για πίνακα `prescribe`
--
ALTER TABLE `prescribe`
  ADD PRIMARY KEY (`PID`);

--
-- Ευρετήρια για πίνακα `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`SID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
