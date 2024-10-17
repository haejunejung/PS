-- https://school.programmers.co.kr/learn/courses/30/lessons/284528
-- HR_DEPARTMENT, 
-- HR_EMPLOYEES,
-- HR_GRADE,

-- 사원별 성과금 정보 조회
-- 평가 점수별 등급과 등급에 따른 성과금 정보가 주어질 때, 사번, 성명, 평가 등급, 성과금을 조회
-- 평가등급은 GRADE, 성과금은 BONUS로 출력
-- 사번 기준으로 오름차순 정렬

SELECT 
    EMP_NO,
    EMP_NAME,
    (CASE
        WHEN AVG_SCORE >= 96 THEN "S"
        WHEN AVG_SCORE >= 90 THEN "A"
        WHEN AVG_SCORE >= 80 THEN "B"
        ELSE "C"
    END) AS GRADE,
    (CASE
        WHEN AVG_SCORE >= 96 THEN SAL * 0.20
        WHEN AVG_SCORE >= 90 THEN SAL * 0.15
        WHEN AVG_SCORE >= 80 THEN SAL * 0.10
        ELSE 0
    END) AS BONUS
FROM (
    SELECT E.EMP_NO, E.DEPT_ID, E.EMP_NAME, E.SAL, AVG(G.SCORE) AS AVG_SCORE
    FROM HR_EMPLOYEES AS E
    JOIN HR_GRADE AS G ON E.EMP_NO = G.EMP_NO
    GROUP BY E.EMP_NO
) AS R
ORDER BY 1
