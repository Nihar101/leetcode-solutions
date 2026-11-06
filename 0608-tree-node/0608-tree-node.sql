# Write your MySQL query statement below
select distinct  a.id as id ,
 (
    case 
    when a.p_id is null then "Root"
    when b.p_id is null then "Leaf"
    else "Inner"
    end
) as type
from Tree as a
left join Tree as b 
on a.id= b.p_id
