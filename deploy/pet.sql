-- Deploy sandbox.cppcms:pets to sqlite

BEGIN;

CREATE TABLE pets (
        id         INTEGER   PRIMARY KEY,
        category   INTEGER   NOT NULL   ,
        name       TEXT      NOT NULL   ,
        photoUrls  TEXT      NOT NULL   ,
        tags       TEXT      NOT NULL   ,
        status     INTEGER   NOT NULL   ,

        FOREIGN KEY(category) REFERENCES categories(id)
);

COMMIT;
