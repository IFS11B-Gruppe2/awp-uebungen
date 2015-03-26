use `wawi_klein`;

#######
## 1 ##
#######
SELECT *
FROM artikel
;
SELECT *
FROM kunden
;

#######
## 2 ##
#######
SELECT A_Bez, A_VK, A_Bestand - A_MinBestand
FROM artikel
ORDER BY 3 DESC
;

#######
## 3 ##
#######
SELECT *
FROM artikel
WHERE A_Art = 'Monitor'
;

#######
## 4 ##
#######
SELECT *
FROM artikel
WHERE
	A_Art = 'Monitor'
	AND
	A_VK < 150
;

#######
## 5 ##
#######
SELECT A_Art, MAX(A_VK), MIN(A_VK), AVG(A_VK)
FROM artikel
GROUP BY 1
;

#######
## 6 ##
#######
SELECT A_Art, MAX(A_VK), MIN(A_VK), AVG(A_VK)
FROM artikel
GROUP BY 1
HAVING AVG(A_VK) > 100
;

#######
## 7 ##
#######
SELECT AVG(A_VK)
FROM artikel
;

#######
## 8 ##
#######
SET @price_average = (SELECT AVG(A_VK) FROM artikel);

SELECT *
FROM artikel
WHERE A_VK > @price_average
ORDER BY A_VK DESC
;

#######
## 9 ##
#######
SELECT A_Art, COUNT(A_Nr)
FROM artikel
GROUP BY 1
;

########
## 10 ##
########
SELECT a.A_Bez, a.A_Art, a.A_VK
FROM artikel a
WHERE
	a.A_VK > (
		SELECT AVG(a2.A_VK)
		FROM artikel a2
		WHERE a2.A_Art = a.A_Art
	)
;

########
## 11 ##
########
SELECT DISTINCT k.*
FROM
	kunden k
	JOIN bestellungen b ON (b.K_Nr = k.K_Nr)
WHERE b.B_Erledigt = 0
;

########
## 12 ##
########
SELECT *
FROM
	kunden k
	JOIN bestellungen b ON (b.K_Nr = k.K_Nr)
ORDER BY k.K_Name ASC
;

########
## 13 ##
########
SELECT a.*, bd.B_Menge
FROM
	artikel a
	JOIN bestelldetails bd ON (bd.A_Nr = a.A_Nr)
WHERE a.A_Art = 'Laserdrucker'
;

########
## 14 ##
########
SELECT k.K_Name, k.K_Vorname, bd.A_Nr, bd.B_Menge
FROM
	kunden k
	JOIN bestellungen b ON (b.K_Nr = k.K_Nr)
	JOIN bestelldetails bd ON (bd.B_Nr = b.B_Nr)
WHERE b.B_Erledigt = 0
;

########
## 15 ##
########
SELECT k.*
FROM
	kunden k
	JOIN bestellungen b ON (b.K_Nr = k.K_Nr)
	JOIN bestelldetails bd ON (bd.B_Nr = b.B_Nr)
	JOIN artikel a ON (a.A_Nr = bd.A_Nr)
WHERE
	a.A_Art = 'CD-ROM'
	AND
	a.A_VK > 150/1.95583
;

########
## 16 ##
########
SELECT k.K_Name, k.K_Vorname, k.K_PLZ, k.K_Ort, a.A_Art, a.A_VK
FROM
	kunden k
	JOIN bestellungen b ON (b.K_Nr = k.K_Nr)
	JOIN bestelldetails bd ON (bd.B_Nr = b.B_Nr)
	JOIN artikel a ON (a.A_Nr = bd.A_Nr)
WHERE
	k.K_PLZ BETWEEN 80000 AND 89999
;

########
## 17 ##
########
SELECT k.K_Name, k.K_Vorname, a.A_Bez, a.A_Nr
FROM
	kunden k
	JOIN bestellungen b ON (b.K_Nr = k.K_Nr)
	JOIN bestelldetails bd ON (bd.B_Nr = b.B_Nr)
	JOIN artikel a ON (a.A_Nr = bd.A_Nr)
WHERE
	b.B_Erledigt = 0
	AND
	a.A_Bez LIKE 'M%'
;
