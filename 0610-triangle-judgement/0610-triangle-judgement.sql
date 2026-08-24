# Write your MySQL query statement below
select x,y,z, "Yes" as triangle from Triangle as t
where (t.x<t.y+t.z) and (t.y<t.z+t.x) and (t.z<t.x +t.y)
union 
select x,y,z, "No" as triangle from Triangle as t
where (t.x>=t.y+t.z) or (t.y>=t.z+t.x) or (t.z>=t.x +t.y)

