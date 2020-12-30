SELECT title FROM movies
INNER JOIN ratings
ON movies.id = ratings.movie_id
INNER JOIN stars
ON ratings.movie_id = stars.movie_id
INNER JOIN people
ON stars.person_id = people.id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;