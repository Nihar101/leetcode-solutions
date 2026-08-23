# Write your MySQL query statement below
select employee_id , department_id from Employee as e
where e.primary_flag = "Y"
union 
select employee_id , department_id from Employee as k
group by k.employee_id 
having count(*)=1
