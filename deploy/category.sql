-- Deploy sandbox.cppcms:categories to sqlite

BEGIN;

CREATE TABLE categories (
        id         INTEGER   PRIMARY KEY                       ,
        name       TEXT      NOT NULL
);

COMMIT;
