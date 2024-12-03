-- SQL file to initialize the database schema

CREATE TABLE IF NOT EXISTS shifts (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    location TEXT NOT NULL,
    startTime TEXT NOT NULL,
    endTime TEXT NOT NULL,
    numEmployees INTEGER NOT NULL,
    amountEarned REAL NOT NULL
);
