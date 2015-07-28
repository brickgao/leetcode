SELECT DISTINCT tmp.Num FROM
(SELECT Num,
    CASE
        WHEN @record = Num then @cnt := @cnt + 1
        WHEN @record <> @record := Num then @cnt := 1
    END as n
    FROM Logs
) as tmp, (SELECT @cnt := 0, @record := (SELECT Num FROM Logs LIMIT 0, 1)) as ttmp
WHERE tmp.n >= 3



