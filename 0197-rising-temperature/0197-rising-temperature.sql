# Write your MySQL query statement below
SELECT we1.id FROM Weather we1 JOIN Weather we2 on DATEDIFF(we1.recordDate,we2.recordDate)=1 WHERE we1.temperature>we2.temperature;