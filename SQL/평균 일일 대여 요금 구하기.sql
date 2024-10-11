-- https://school.programmers.co.kr/learn/courses/30/lessons/151136
SELECT
    ROUND (AVG (C.DAILY_FEE), 0) AS AVERAGE_FEE
FROM
    CAR_RENTAL_COMPANY_CAR AS C
GROUP BY
    C.CAR_TYPE
HAVING
    C.CAR_TYPE LIKE 'SUV';
