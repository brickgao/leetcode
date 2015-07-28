SELECT Employee.NAME FROM
Employee, Employee as tmp
WHERE Employee.ManagerId = tmp.Id and Employee.Salary > tmp.Salary
