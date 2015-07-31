SELECT tmp1.Id FROM
Weather as tmp1, Weather as tmp2
WHERE ADDDATE(tmp1.Date, INTERVAL -1 DAY) = tmp2.Date AND tmp1.Temperature > tmp2.Temperature
