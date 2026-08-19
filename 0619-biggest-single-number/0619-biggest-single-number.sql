# Write your MySQL query statement below
select max(k.l) as num from ( select num as l from MyNumbers group by num having count(*)=1 ) as k
