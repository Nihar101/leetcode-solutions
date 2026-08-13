# Write your MySQL query statement below
select round(count(
    case
    when d.customer_pref_delivery_date = d.order_date then 1
    end
)/count(d.customer_id),4)*100
as immediate_percentage 
from Delivery as d
join  (select min(order_date) as order_date,customer_id from Delivery group by customer_id) as k 
on k.customer_id = d.customer_id and k.order_date = d.order_date  