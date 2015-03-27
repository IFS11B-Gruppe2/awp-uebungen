#######
## 1 ##
#######
SELECT name
FROM indikationen
ORDER BY 1 ASC
;

#######
## 2 ##
#######
SELECT
	Ort,
	Nachname,
	Vorname
FROM patienten
WHERE
	`Alter` >= 90
	AND
	Geschlecht = 'W'
	AND
	Ort LIKE 'N%'
ORDER BY 2 ASC
;

#######
## 3 ##
#######
SELECT *
FROM patienten
WHERE Ort = 'New York'
ORDER BY `Alter` DESC
;

#########
## 4.1 ##
#########
SELECT
	h.Art,
	p.Vorname,
	p.Nachname
FROM
	patienten p
	JOIN haustiere h ON (h.Nr_Patient = p.NR)
WHERE h.Art = 'Hund'
;

#########
## 4.2 ##
#########
SELECT
	p.Vorname,
	p.Nachname
FROM patienten p
WHERE
	p.NR IN (
		SELECT h.Nr_Patient
		FROM haustiere h
		WHERE h.Art = 'Hund'
	)
;

#######
## 5 ##
#######
SELECT DISTINCT
	p.NR,
	h.Art,
	p.Vorname,
	p.Nachname
FROM
	patienten p
	JOIN haustiere h ON (h.Nr_Patient = p.NR)
WHERE h.Art = 'Hund'
;

#######
## 6 ##
#######
SELECT
	p.Nachname,
	i.Name AS 'Krankheit'
FROM
	patienten p
	JOIN patienten_indikationen ip ON (ip.Nr_Patient = p.NR)
	JOIN indikationen i ON (i.Nr = ip.Nr_Indikation)
ORDER BY 2 ASC
;

#######
## 7 ##
#######
SELECT
	p.Nachname,
	i.Name AS 'Krankheit'
FROM
	patienten p
	JOIN patienten_indikationen ip ON (ip.Nr_Patient = p.NR)
	JOIN indikationen i ON (i.Nr = ip.Nr_Indikation)
ORDER BY 2 ASC
;

#######
## 8 ##
#######
SELECT
	Geschlecht,
	AVG(`Alter`)
FROM patienten
GROUP BY 1
;

#######
## 9 ##
#######
SELECT
	Art,
	COUNT(DISTINCT Nr_Patient)
FROM haustiere
GROUP BY 1
;
