-- https://school.programmers.co.kr/learn/courses/30/lessons/164673

-- 2022년 10월에 작성된
-- 게시글 제목, 게시글 ID, 댓글 ID, 댓글 작성자 ID, 댓글 내용, 댓글 작성일
-- 댓글 작성일 기준으로 오름차순 정렬, 게시글 제목 기준으로 오름차순 정렬

SELECT
    B.TITLE,
    B.BOARD_ID,
    R.REPLY_ID,
    R.WRITER_ID,
    R.CONTENTS,
    DATE_FORMAT(R.CREATED_DATE, '%Y-%m-%d') AS CREATED_DATE
FROM
    USED_GOODS_BOARD AS B
JOIN
    USED_GOODS_REPLY AS R
ON
    B.BOARD_ID = R.BOARD_ID
WHERE
    B.CREATED_DATE >= '2022-10-01' AND B.CREATED_DATE < '2022-11-01'
ORDER BY
    CREATED_DATE asc, TITLE asc;
