SELECT movies.title
FROM movies
JOIN stars AS sd ON movies.id = sd.movie_id
JOIN people AS jd ON sd.person_id = jd.id AND jd.name = 'Johnny Depp'
JOIN stars AS sh ON movies.id = sh.movie_id
JOIN stars AS hc ON sh.person_id = hc.id AND hc.name = 'Helena Bonham Carter';