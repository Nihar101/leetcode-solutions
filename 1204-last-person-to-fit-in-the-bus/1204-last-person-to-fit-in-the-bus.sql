# Write your MySQL query statement below
select person_name from 
(select person_name, sum(weight) over(order by turn) as weight_till from Queue ) as e
where e.weight_till <=1000 
order by e.weight_till desc
limit 1