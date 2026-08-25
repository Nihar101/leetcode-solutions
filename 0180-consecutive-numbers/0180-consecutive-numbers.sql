# Write your MySQL query statement below
select distinct l.num as ConsecutiveNums from Logs  as l
join Logs as lo
on (l.id-1 = lo.id and l.num = lo.num) or (l.id-2 = lo.id and l.num = lo.num )
group by l.id
having count(*) >=2
