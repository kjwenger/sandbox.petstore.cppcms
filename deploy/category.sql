-- Deploy sandbox.cppcms:categories to sqlite

BEGIN;

CREATE TABLE 'category' (
        'id'         INTEGER   PRIMARY KEY                       ,
        'name'       TEXT      NOT NULL
);

COMMIT;
