SELECT max(Salary) FROM Employee
WHERE Salary < (SELECT max(Salary) FROM Employee)
