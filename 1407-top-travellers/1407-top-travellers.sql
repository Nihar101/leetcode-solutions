# Write your MySQL query statement below
select u.name as name , sum(
    case 
        when k.distance is null then 0
        else k.distance
    end
) as travelled_distance  from Users as u
left join Rides as k
on k.user_id = u.id 
group by u.id 
order by sum(k.distance) desc, u.name 