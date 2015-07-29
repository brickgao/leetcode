SELECT DISTINCT Person.Email FROM
Person
WHERE (SELECT COUNT(*) FROM Person as tmp WHERE Person.Email=tmp.Email) >= 2

