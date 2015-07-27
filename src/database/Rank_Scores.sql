SELECT Scores.Score,
        (SELECT count(*) FROM (SELECT distinct Score From Scores) as tmp WHERE tmp.Score >= Scores.Score) as Rank
FROM Scores
ORDER BY Score DESC
