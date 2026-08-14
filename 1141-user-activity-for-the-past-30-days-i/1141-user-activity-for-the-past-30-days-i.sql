# Write your MySQL query statement below
select a.activity_date as day ,count(distinct user_id) as active_users 
from Activity as a
group by a.activity_date 
having a.activity_date> "2019-07-27"-  Interval 30 day 
and a.activity_date<= "2019-07-27"

