-- Revert sandbox.cppcms:users from sqlite

BEGIN;

DROP TABLE users;

COMMIT;
