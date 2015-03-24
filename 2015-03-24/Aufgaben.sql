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
