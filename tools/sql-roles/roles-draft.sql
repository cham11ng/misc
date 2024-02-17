EXEC sp_addrolemember N'db_datareader', N'dev';

CREATE USER dev FOR LOGIN dev;

sp_helpuser;

GRANT EXECUTE ON schema::dbo TO dev;
