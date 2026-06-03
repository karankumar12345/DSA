# Write your MySQL query statement below
SELECT  * FROM Cinema cn
 where MOD(cn.id , 2) <> 0 AND cn.description  != 'boring' ORDER BY cn.rating DESC;