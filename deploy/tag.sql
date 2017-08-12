-- Deploy sandbox.cppcms:tags to sqlite

BEGIN;

CREATE TABLE tags (
        id         INTEGER   PRIMARY KEY                       ,
        name       TEXT      NOT NULL
);

COMMIT;
