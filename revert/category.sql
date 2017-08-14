-- Revert sandbox.cppcms:categories from sqlite

BEGIN;

DROP TABLE 'category';

COMMIT;
