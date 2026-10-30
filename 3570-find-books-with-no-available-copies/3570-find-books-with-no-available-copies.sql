# Write your MySQL query statement below
select l.book_id as book_id , title,author,genre,publication_year,count(l.book_id) as current_borrowers  from library_books as l
join borrowing_records as r
on r.book_id = l.book_id and r.return_date is null
group by l.book_id,
    l.title,
    l.author,
    l.genre,
    l.publication_year,
    l.total_copies 
having count(l.book_id)-l.total_copies =0
ORDER BY current_borrowers DESC, title ASC;