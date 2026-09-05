# Write your MySQL query statement below
select employee_id from Employees as e 
where e.salary <30000 and e.manager_id 
not in (select distinct employee_id from Employees )
order by employee_id