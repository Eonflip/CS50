SELECT people.name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = 