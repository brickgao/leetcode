DELETE tmp1 FROM
Person as tmp1, Person as tmp2
WHERE tmp1.Id > tmp2.Id AND tmp1.Email = tmp2.Email
