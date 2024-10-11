-- https://school.programmers.co.kr/learn/courses/30/lessons/132203
SELECT
    D.DR_NAME,
    D.DR_ID,
    D.MCDP_CD,
    DATE_FORMAT(D.HIRE_YMD, '%Y-%m-%d')
FROM
    DOCTOR AS D
WHERE
    D.MCDP_CD LIKE 'CS' OR D.MCDP_CD LIKE 'GS'
ORDER BY
    D.HIRE_YMD desc, D.DR_NAME asc;
