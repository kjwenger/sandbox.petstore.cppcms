-- Deploy sandbox.cppcms:orders to sqlite

BEGIN;

CREATE TABLE orders (
        id         INTEGER   PRIMARY KEY                       ,
        petId      INTEGER   NOT NULL                          ,
        quantity   INTEGER   NOT NULL                          ,
        shipDate   DATETIME  NOT NULL DEFAULT CURRENT_TIMESTAMP,
        status     TEXT      NOT NULL                          ,
        complete   INTEGER   NOT NULL DEFAULT 0
);

COMMIT;
