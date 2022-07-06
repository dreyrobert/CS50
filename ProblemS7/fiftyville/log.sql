-- The crime took place on July 28, 2021, took place on Humphrey Street.

SELECT description FROM crime_scene_reports
WHERE month=7 AND day=28 AND year=2021 AND street='Humphrey Street';
-- Duck took place at 10:15am at Humphrey Street bakery. 3 witnesses. Littering took place at 16:36, no witnesses.

SELECT transcript, name FROM interviews
WHERE month=7 AND day=28 AND year=2021;
-- Eugene: Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- Emma: I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.

SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND MINUTE>=15 AND minute<=25
AND activity='exit';
-- Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year=2021 AND month=7 AND day=28 AND atm_location='Leggett Street' AND transaction_type='withdraw';
-- Bruce, Diana, Iman, Luca

SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
    SELECT id FROM flights
    WHERE year=2021 AND month=7 AND day=29 AND origin_airport_id = (
        SELECT id FROM airports
        WHERE city='Fiftyville')
        ORDER BY hour, minute
        LIMIT 1);
-- Bruce, Luca

SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year=2021 AND month=7 AND day=28 AND duration < 60;
-- Bruce is the THIEF HEHEHEHEHE

SELECT city FROM airports
WHERE id = (
    SELECT destination_airport_id FROM flights
    WHERE year=2021 AND month=7 AND day=29 AND origin_airport_id = (
        SELECT id FROM  airports
        WHERE city='Fiftyville')
    ORDER BY hour, minute
    LIMIT 1);
-- New York

SELECT phone_number FROM people WHERE name='Bruce';
-- (367) 555-5533

SELECT name FROM people WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year=2021 AND month=7 AND day=28 AND duration<60 AND caller='(367) 555-5533');
-- Robin