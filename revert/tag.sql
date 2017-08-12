-- Revert sandbox.cppcms:tags from sqlite

BEGIN;

DROP TABLE tags;

COMMIT;
