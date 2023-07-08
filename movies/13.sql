SELECT people.name
FROM people
JOIN stars AS sd ON people.id = sd.person_id
JOIN movies AS md ON sd.movie_id = md.id AND 