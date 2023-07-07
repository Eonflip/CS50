SELECT title, AVG(ratings.rating) AS avg_rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating IS NOT NULL
ORDER BY ratings.rating DESC
