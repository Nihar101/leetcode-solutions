# Write your MySQL query statement below
select CONCAT(YEAR(trans_date), '-', lpad(MONTH(trans_date),2,'0'))as month ,country ,
count(id) as trans_count,count(
    case
    when state = "approved" then 1
    end
) as approved_count, sum(amount) as trans_total_amount ,
sum(
    case 
    when state = "approved" then amount
    else 0
    end
) as approved_total_amount from Transactions
group by year(trans_date),month(trans_date), country