# Write your MySQL query sta
select (select distinct 
salary   from Employee as e
order by salary desc
limit 1 offset 1 
)as SecondHighestSalary
