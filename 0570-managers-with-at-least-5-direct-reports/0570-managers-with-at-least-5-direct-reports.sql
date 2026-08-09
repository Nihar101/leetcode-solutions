# Write your MySQL query statement below
select e.name from Employee as e 
join Employee as o on e.id= o.managerId
group by e.id
having count(*)>=5;