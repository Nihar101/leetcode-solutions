# Write your MySQL query statement below
(select "Fall" as season , p.category as category, sum(s.quantity) AS total_quantity
, sum(s.quantity*s.price) as total_revenue from sales as s
join products as p
on s.product_id = p.product_id 
where month(s.sale_date) = 09 or month(s.sale_date) =10 or month(s.sale_date)=11
group by p.category
order by sum(s.quantity) desc , sum(s.quantity*s.price) desc
limit 1)
union 
(select "Spring" as season , p.category as category, sum(s.quantity) AS total_quantity ,
sum(s.quantity*s.price) as total_revenue
from sales as s
join products as p
on s.product_id = p.product_id 
where month(s.sale_date) = 03 or month(s.sale_date) =04 or month(s.sale_date)=05
group by p.category
order by sum(s.quantity) desc , sum(s.quantity*s.price) desc
limit 1)
union
(select "Summer" as season , p.category as category, sum(s.quantity) AS total_quantity ,
sum(s.quantity*s.price) as total_revenue
from sales as s
join products as p
on s.product_id = p.product_id 
where month(s.sale_date) = 06 or month(s.sale_date) =07 or month(s.sale_date)=08
group by p.category
order by sum(s.quantity) desc , sum(s.quantity*s.price) desc
limit 1)
union 
(select "Winter" as season , p.category as category, sum(s.quantity) AS total_quantity ,
sum(s.quantity*s.price) as total_revenue
from sales as s
join products as p
on s.product_id = p.product_id 
where month(s.sale_date) = 01 or month(s.sale_date) =12 or month(s.sale_date)=02
group by p.category
order by sum(s.quantity) desc , sum(s.quantity*s.price) desc
limit 1)