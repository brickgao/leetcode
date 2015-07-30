SELECT t1.Name as Department, t2.Name as Employee, Salary
FROM Department as t1, Employee as t2
WHERE (t2.DepartmentId = t1.Id AND (t2.Salary = (SELECT MAX(Employee.Salary) FROM Employee WHERE Employee.DepartmentId=t2.DepartmentId)))
