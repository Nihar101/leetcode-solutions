# Write your MySQL query statement below
select p.product_id , "store1" as store , p.store1 as price
from Products as p
where p.store1 is not null
union
select k.product_id , "store2" as store , k.store2 as price
from Products as k
where k.store2 is not null
union
select l.product_id , "store3" as store , l.store3 as price
from Products as l
where l.store3 is not null 


