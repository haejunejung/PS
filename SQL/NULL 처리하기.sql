-- https://school.programmers.co.kr/learn/courses/30/lessons/59410
-- 동물의 생물 종, 이름, 성별 및 중성화 여부를 아이디 순으로 조회
-- 이름이 없는 경우는 NULL -> "No name"

SELECT 
    ANIMAL_TYPE,
    IFNULL(NAME, "No name") AS NAME,
    SEX_UPON_INTAKE
FROM ANIMAL_INS
