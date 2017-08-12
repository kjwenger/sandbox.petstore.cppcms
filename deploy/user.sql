-- Deploy sandbox.cppcms:users to sqlite

BEGIN;

CREATE TABLE users (
        id         INTEGER   PRIMARY KEY,
        username   TEXT      NOT NULL   ,
        firstName  TEXT      NOT NULL   ,
        lastName   TEXT      NOT NULL   ,
        email      TEXT      NOT NULL   ,
        password   TEXT      NOT NULL   ,
        phone      TEXT                 ,
        userStatus INTEGER   NOT NULL
);

COMMIT;
