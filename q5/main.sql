/*Question 5*/

/*Joana gives Eva the task of generating a report containing three columns: Name, Grade and Value. Joana does not want the names of students who received a grade lower than 8. 
The report must be in descending order by grade, that is, the highest grades are inserted first. 
If there are more than one student with the same grade (8-10) assigned to them, sort those students in particular by their names in alphabetical order. 
Finally, if the grade is less than 8, use "NULL" as the name and list them in grades in descending order. 
If there are more than one student with the same grade (1-7) assigned to them, sort those students in particular by their grades in ascending order.*/

SELECT * FROM students;
SELECT * FROM notes;

UPDATE students
SET name = NULL WHERE value<70;

CREATE VIEW [Report] AS
SELECT students.name, notes.grade,students.value
FROM students,notes
WHERE students.value<=notes.max_value AND students.value>=notes.min_value
ORDER BY value DESC,name ASC;

SELECT * FROM Report;