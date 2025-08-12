# Write your MySQL query statement below
select  s.year , s.price , p.product_name
from sales s
join product p
on s.product_id = p.product_id