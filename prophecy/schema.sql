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
    student_id INTEGER,
    house_name TEXT,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_name) REFERENCES students(house)
);