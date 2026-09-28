# Write your MySQL query statement below
select k.name as Department ,r.name as Employee , r.salary as Salary
 from (select max(e.salary) as salary, d.id as id , d.name as name from  Employee as e
join Department as d
on d.id = e.departmentId 
group by d.id) as k
join Employee as r 
on k.salary = r.salary and r.departmentId = k.id 
