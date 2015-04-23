## 1
## Listen Sie die Länder mit ihren Sprachen auf, und ob sie 'offiziel' oder 'nicht offiziel' sind.
## Aufsteigend sortiert nach Landname.
## Offizielle Sprachen sollen vor den nicht offiziellen Sprachen gezeigt werden.
## Aufsteigend sortiert nach Sprache.
SELECT
  co.Name AS 'Land',
  cola.Language AS 'Sprache',
  IF (cola.IsOfficial = 'T', 'Offiziel', 'Nicht offiziel') AS 'Offiziel?'
FROM
  country AS co
  INNER JOIN countryLanguage AS cola ON (cola.CountryCode = co.Code)
ORDER BY
  1 ASC,
  3 DESC,
  2 ASC
;

## 2
## Listen Sie auf, wie viele Personen jeder Sprache sprechen.
## Absteigend sortiert nach Bürgeranzahl.
SELECT
  cola.Language AS 'Sprache',
  SUM(co.Population) AS 'Personen'
FROM
  country AS co
  INNER JOIN countryLanguage AS cola ON (cola.CountryCode = co.Code)
GROUP BY 1
ORDER BY
  2 DESC,
  1 ASC
;

## 3
## Listen Sie auf, wie viele Städte per Regierungsform gibt.
## Absteigend sortiert nach Städteanzahl.
SELECT
  co.GovernmentForm AS 'Regierungsform',
  COUNT(ci.Name) AS 'Städte'
FROM
  country AS co
  INNER JOIN city AS ci ON (ci.CountryCode = co.Code)
GROUP BY 1
ORDER BY
  2 DESC,
  1 ASC
;

## 4
## Listen Sie die Bürgeranzahl jeder Hauptstadt mit ihren offiziellen Sprachen.
## Aufsteigend sortiert nach Stadtname und Sprachen.
