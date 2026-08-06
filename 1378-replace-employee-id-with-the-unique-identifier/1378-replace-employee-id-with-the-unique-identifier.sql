# Write your MySQL query statement below

select unique_id ,name from Employees as e left join EmployeeUNI as em on em.id=e.id ;
