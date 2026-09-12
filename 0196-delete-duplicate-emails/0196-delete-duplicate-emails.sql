# Write your MySQL query statement below
delete from person as p
where id not in (
    select id from (select min(k.id) as id from person as k 
    group by k.email ) as t
)