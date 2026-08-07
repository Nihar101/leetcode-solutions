# Write your MySQL query statement below

select a.machine_id as machine_id, ROUND(AVG(b.timestamp - a.timestamp), 3) as processing_time
from Activity as a 
join Activity b on a.machine_id = b.machine_id and a.process_id = b.process_id
and a.activity_type!= b.activity_type and a.activity_type!= 'end'
group by (a.machine_id)
