#######
## 1 ##
#######
SELECT COUNT(*) AS "vorhandene Laender"
FROM country
;

#######
## 2 ##
#######
SELECT COUNT(DISTINCT Continent) AS "Kontinente"
FROM country
;

#######
## 3 ##
#######
SELECT DISTINCT Continent AS "Kontinente"
FROM country
;

#######
## 4 ##
#######

SELECT c.Continent, c.name, c.SurfaceArea
FROM country c
WHERE
	c.SurfaceArea = (
		SELECT MAX(c2.SurfaceArea)
		FROM country c2
		WHERE c2.Continent = c.Continent
	)
;

#######
## 5 ##
#######
SELECT name, SurfaceArea
FROM country
WHERE Continent = 'Europe'
ORDER BY 2 DESC
;

#######
## 6 ##
#######
SELECT Continent, name, SurfaceArea
FROM country
ORDER BY 3 DESC
;

#######
## 7 ##
#######
SELECT name
FROM country
WHERE
	Indepyear <= 0
	OR
	Indepyear IS NULL
;

#######
## 8 ##
#######

SELECT c.Continent, c.name, c.SurfaceArea
FROM country c
WHERE
	c.SurfaceArea = (
		SELECT MAX(c2.SurfaceArea)
		FROM country c2
		WHERE c2.Continent = c.Continent
	)
;

#######
## 9 ##
#######
SELECT name
FROM country
WHERE GovernmentForm = 'Overseas Department of France'
;

########
## 10 ##
########
SELECT name
FROM country
ORDER BY
	LifeExpectancy DESC,
	name ASC
LIMIT 3

########
## 11 ##
########
SELECT
	continent,
	AVG(LifeExpectancy)
FROM country
GROUP BY 1
ORDER BY 2 DESC
LIMIT 1
;

########
## 12 ##
########
SELECT
	continent,
	COUNT(name) AS 'Anzahl'
FROM country
WHERE LifeExpectancy > 75
GROUP BY 1
;
