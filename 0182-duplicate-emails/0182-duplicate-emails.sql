# Write your MySQL query statement below
select DISTINCT p.email  as Email 
from Person as p
join Person as n
on n.email = p.email and n.id != p.id
