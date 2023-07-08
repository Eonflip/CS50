SELECT TOP 5 movies.title
FROM movies
JOIN stars ON movies.id = stars.movies_id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY movies.title DESC;