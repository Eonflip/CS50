CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);


CREATE TABLE houses (
    house TEXT,
    head TEXT,
    PRIMARY KEY(house)
);


CREATE TABLE house_assignment (
    FOREIGN KEY(id),
    FOREIGN KEY(house)
);