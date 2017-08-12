-- Revert sandbox.cppcms:pets from sqlite

BEGIN;

DROP TABLE pets;

COMMIT;
