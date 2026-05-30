# Write your MySQL query statement below

SELECT vs.customer_id as customer_id ,COUNT(*) AS count_no_trans  FROM Visits vs LEFT JOIN Transactions ts ON vs.visit_id=ts.visit_id WHERE ts.transaction_id IS NULL GROUP BY vs.customer_id