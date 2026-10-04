# Write your MySQL query statement below
select p.user_id,count(p.prompt) as prompt_count,Round(avg(p.tokens),2) as avg_tokens
from prompts as p
group by p.user_id
having count(distinct p.tokens)>1 and count(p.prompt)>=3 
order by avg(p.tokens) desc, p.user_id asc 