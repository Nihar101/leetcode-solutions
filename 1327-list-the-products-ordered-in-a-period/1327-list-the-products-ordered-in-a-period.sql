# Write your MySQL query statement below
select product_name as product_name , k.unit as unit from Products as p  join (
select sum(unit) as unit, product_id from Orders
where month(order_date) = "02" and year(order_date) = "2020"
group by product_id 
having sum(unit) >=100) as k on k.product_id = p.product_id


