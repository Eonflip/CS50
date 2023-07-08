SELECT people.name
FROM people
JOIN stars AS sd ON people.id = sd.person_id
JOIN movies AS md ON sd.movie_id = md.id
JOIN stars AS sk ON md.id = sk.movie_id
JOIN people AS kb ON sk.person_id = kb.id
WHERE kb.name = 'Kevin Bacon' AND kb.birth = 1958 AND people.name <> 'Kevin Bacon';