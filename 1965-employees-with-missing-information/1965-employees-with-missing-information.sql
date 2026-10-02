# Write your MySQL query statement below
select distinct coalesce(k.eid,k.aid) as employee_id from  
(select e.employee_id as eid , a.salary,a.employee_id as aid ,e.name from Employees as e
left join
Salaries as a
on e.employee_id = a.employee_id 
union 
select e.employee_id as eid, a.salary , a.employee_id as aid, e.name from Employees as e
right join 
Salaries as a
on e.employee_id = a.employee_id
) as k
where k.salary is null or k.name is null
order by employee_id