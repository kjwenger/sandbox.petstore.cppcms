-- Revert sandbox.cppcms:pets from sqlite

BEGIN;

DROP TABLE 'pet';

COMMIT;
