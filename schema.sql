CREATE TABLE Users (
    username TEXT PRIMARY KEY,
    pin TEXT NOT NULL,
    name_first TEXT NOT NULL,
    name_last TEXT, NOT NULL
    home_long REAL, NOT NULL
    home_lat REAL NOT NULL
);

CREATE TABLE Weather_Data (
    username TEXT FOREIGN KEY REFERENCES Users(username),
    time DATETIME, NOT NULL
    data_long REAL,
    data_lat REAL,
    noise REAL,
    dust REAL,
    temp REAL,
    humidity REAL,
    wind REAL,
);
