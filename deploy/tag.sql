-- Deploy sandbox.cppcms:tags to sqlite

BEGIN;

CREATE TABLE 'tag' (
        'id'         INTEGER   PRIMARY KEY                       ,
        'name'       TEXT      NOT NULL
);

COMMIT;
