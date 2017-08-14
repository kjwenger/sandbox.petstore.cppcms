-- Revert sandbox.cppcms:orders from sqlite

BEGIN;

DROP TABLE 'order';

COMMIT;
