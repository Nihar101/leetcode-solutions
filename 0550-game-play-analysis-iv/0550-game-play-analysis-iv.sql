# Write your MySQL query statement below
select round(count(a.player_id)/(select count(distinct player_id) from Activity),2) as fraction  
from Activity as a
join (select player_id , min(event_date) as event_date from Activity 
group by player_id) as la
on a.player_id = la.player_id and a.event_date = la.event_date+INTERVAL 1 DAY
