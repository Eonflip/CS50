-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First I want to get an idea of what the crime_scene_report reads for clues
SELECT *
FROM crime_scene_reports

-- After some clues it looks like 3 people had something to say about this theft let's get interviews from that day
SELECT *
FROM interviews
WHERE year = 2021 AND day = 28 AND month = 7;

-- Chasing the first lead I want to find out what ATM transactions happened on Leggett Street on the day of the robbery
SELECT *
FROM atm_transactions
WHERE year = 2021 AND day = 28 AND month = 7 AND atm_location = 'Leggett Street';

-- Let's find out about some security logs
SELECT *
FROM bakery_security_logs
WHERE year = 2021 AND day = 28 AND month = 7;

-- Let's find out what the earliest flight out of Fiftyville is
SELECT *
FROM flights
WHERE year = 2021 AND day = 28 AND month = 7 AND origin_airport_id = 8;

-- Just kidding let's find which airport is in fiftyville
SELECT *
FROM airports
WHERE city = 'Fiftyville';

-- Lets find out what kind of phone calls 