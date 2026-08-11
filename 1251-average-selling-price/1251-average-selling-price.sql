# Write your MySQL query statement below
select p.product_id, (coalesce(round(
    sum(case

        when p.price is not null and u.units is not null then p.price*u.units
        else 0
        end
        )/sum(
            case
        when p.price is not null and u.units is not null then u.units
        else 0
        end
        ),2),0)
) as average_price from Prices as p
left join UnitsSold as u
 on p.product_id = u.product_id 
 and u.purchase_date>= p.start_date and u.purchase_date<= p.end_date
group by p.product_id

