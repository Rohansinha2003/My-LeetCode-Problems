# Write your MySQL query statement below
SELECT product_id, first_year, quantity, price 
FROM
(SELECT product_id as p_id, min(year) as first_year
FROM Sales
GROUP BY product_id) as first_year_table
LEFT JOIN Sales ON p_id = product_id and year = first_year
;
