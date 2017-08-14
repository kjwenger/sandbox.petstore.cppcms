-- Verify sandbox.cppcms:users on sqlite

BEGIN;

SELECT
        'id'                              ,
        'username'                        ,
        'firstName'                       ,
        'lastName'                        ,
        'email'                           ,
        'password'                        ,
        'phone'                           ,
        'userStatus'
FROM
        'user'
WHERE
        0;

ROLLBACK;
