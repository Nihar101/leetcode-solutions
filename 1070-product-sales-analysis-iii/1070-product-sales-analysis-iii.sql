# Write your MySQL query statement below

select sd.product_id as product_id, sd.year as first_year,sd.quantity as quantity
,sd.price  as price from Sales as sd
join (select product_id, min(year) as first_year from Sales 
group by product_id ) as h
on h.first_year = sd.year and h.product_id = sd.product_id
