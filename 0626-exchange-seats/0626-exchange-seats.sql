# Write your MySQL query statement below
select s.id as id,t.student as student from Seat as s
join Seat as t 
on s.id= t.id-1
where s.id%2 = 1
union
select s.id as id,t.student as student from Seat as s
join Seat as t 
on s.id= t.id+1
where s.id%2 = 0
UNION
SELECT id, student
FROM Seat
WHERE id = (SELECT MAX(id) FROM Seat)
  AND id % 2 = 1

order by id  


