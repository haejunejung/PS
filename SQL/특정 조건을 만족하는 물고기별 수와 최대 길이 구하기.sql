-- https://school.programmers.co.kr/learn/courses/30/lessons/298519
-- FISH_INFO: ID, FISH_TYPE, LENGTH, TIME
-- 10cm이하일 경우 LEGNTH가 NULL, NULL만 있는 경우는 존재하지 않는다.
-- 평균 길이가 33cm 이상인 물고기들을, 종류별로 분류
-- 잡은 수, 최대 길이, 물고기의 종류 출력
-- 물고기 종류에 대해 오름차순 정렬
-- 10cm이하의 물고기들은 10cm로 취급하여 평균 길이 구하기

-- Solution1
SELECT COUNT(LENGTH) AS FISH_COUNT, MAX(LENGTH) AS MAX_LENGTH, FISH_TYPE
FROM (
    SELECT FISH_TYPE, IFNULL(LENGTH, 10) AS LENGTH
    FROM FISH_INFO
) AS F
GROUP BY FISH_TYPE
HAVING AVG(LENGTH) >= 33
ORDER BY 3

-- Solution2
SELECT COUNT(LENGTH) AS FISH_COUNT, MAX(LENGTH) AS MAX_LENGTH, FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG
    (CASE 
        WHEN LENGTH IS NULL THEN 10
        ELSE LENGTH
    END) >= 33
ORDER BY 3
