-- 코드를 입력하세요
SELECT YEAR(B.SALES_DATE) YEAR, MONTH(B.SALES_DATE) MONTH, COUNT(DISTINCT B.USER_ID) PUCHASED_USERS,
ROUND(COUNT(DISTINCT B.USER_ID) / 
    (
        SELECT COUNT(*)
        FROM USER_INFO A 
        WHERE A.JOINED LIKE "2021%"
    )
, 1) PUCHASED_RATIO
FROM USER_INFO A
JOIN ONLINE_SALE B ON A.USER_ID = B.USER_ID 
WHERE A.JOINED LIKE "2021%" 
GROUP BY MONTH;
