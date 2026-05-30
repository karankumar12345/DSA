# Write your MySQL query statement below

SELECT 
   pr.product_name as product_name, 
   sa.year as year ,
   sa.price as price  
   FROM Sales sa 
    INNER JOIN 
    Product pr 
    ON 
    sa.product_id=pr.product_id