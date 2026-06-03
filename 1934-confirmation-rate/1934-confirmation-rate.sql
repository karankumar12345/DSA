# Write your MySQL query statement below
SELECT  si.user_id, ROUND(IFNULL(AVG(co.action="confirmed"),0),2) AS confirmation_rate  FROM Signups si LEFT JOIN Confirmations  co
  ON si.user_id=co.user_id 
  GROUP BY si.user_id

    