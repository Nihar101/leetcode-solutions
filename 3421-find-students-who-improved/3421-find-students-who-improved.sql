# Write your MySQL query statement below
select e.student_id as student_id , e.subject as subject , e.score as first_score,
l.score as latest_score from (
    select s.student_id , s.subject , s.exam_date , s.score 
    from Scores as s
    where (s.student_id,s.subject,s.exam_date) in (
        select k.student_id,k.subject,min(k.exam_date) from Scores as k
        group by k.student_id , k.subject 
    )
) as e
join (
    select s.student_id , s.subject , s.exam_date , s.score 
    from Scores as s
    where (s.student_id,s.subject,s.exam_date) in (
        select k.student_id,k.subject,max(k.exam_date) from Scores as k
        group by k.student_id , k.subject 
    )
) as l
on e.student_id = l.student_id 
and e.subject = l.subject 
and e.exam_date <l.exam_date 
and e.score <l.score
order by e.student_id, e.subject