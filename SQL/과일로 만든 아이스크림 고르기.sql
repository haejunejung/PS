-- https://school.programmers.co.kr/learn/courses/30/lessons/133025
SELECT
    F.FLAVOR
FROM
    FIRST_HALF AS F
JOIN
    ICECREAM_INFO AS I
ON
    F.FLAVOR = I.FLAVOR
WHERE
    INGREDIENT_TYPE LIKE 'fruit_based' AND TOTAL_ORDER > 3000
ORDER BY
    TOTAL_ORDER desc
