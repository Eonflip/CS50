SELECT AVG(ratings.rating) AS avg_rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id