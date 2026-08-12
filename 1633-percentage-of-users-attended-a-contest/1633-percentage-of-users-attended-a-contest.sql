# Write your MySQL query statement below
select contest_id,round(count(r.user_id)/(select count(user_id) from Users),4)*100 as percentage 
from Users as u right join Register as r
on u.user_id = r.user_id 
group by contest_id
order by percentage desc, contest_id asc