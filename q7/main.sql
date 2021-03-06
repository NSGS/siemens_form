/*Question 7*/

/*Information about pets is kept in two separate tables:

TABLE dogs
id INTEGER NOT NULL PRIMARY KEY,
name VARCHAR(50) NOT NULL

TABLE cats
id INTEGER NOT NULL PRIMARY KEY,
name VARCHAR(50) NOT NULL

Write an SQL query that select all distinct pet names.*/

CREATE VIEW distinct_names AS
SELECT name FROM dogs
UNION
SELECT name from cats;

SELECT * FROM distinct_names;