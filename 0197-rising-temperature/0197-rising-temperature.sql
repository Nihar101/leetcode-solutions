# Write your MySQL query statement below


select distinct w.id as Id from Weather as w left join Weather as we on DATE_SUB(w.recordDate, INTERVAL 1 DAY) =we.recordDate where w.temperature>we.temperature and we.temperature is not  null ;