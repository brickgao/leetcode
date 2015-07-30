SELECT t1.Name as Department, t2.Name as Employee, Salary
FROM Department as t1, Employee as t2
WHERE t1.Id = t2.DepartmentId AND
      (SELECT COUNT(DISTINCT(Employee.Salary)) FROM Employee
       WHERE Employee.DepartmentId=t1.Id AND Salary > t2.Salary) < 3
ORDER by t2.DepartmentId, t2.Salary DESC
