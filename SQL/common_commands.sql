CREATE DATABASE Chaplin_Theatres;
DROP DATABASE Chaplin_Theatres;

CREATE TABLE movies
(
id			int,
title		varchar(50),
genre		varchar(15),
duration	int
);

DROP TABLE movies;


ALTER TABLE movies
ADD COLUMN ratings int;

ALTER TABLE movies
DROP COLUMN ratings;


INSERT INTO advertisements
VALUES (1,'Poster','Paper',20);

UPDATE advertisements
SET category='Television'
WHERE category='Commercial';