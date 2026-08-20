# Write your MySQL query statement below


select c.customer_id as customer_id from Customer as c 
group by c.customer_id 
having count(distinct c.product_key)= (select count(*) from Product as k) 