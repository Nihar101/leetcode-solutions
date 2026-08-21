# Write your MySQL query statement below
select e.employee_id as employee_id , e.name as name, count(*) as reports_count,round(avg(k.age)) as average_age 
from Employees as e
join Employees as k
on k.reports_to= e.employee_id
group by e.employee_id 
order by e.employee_id