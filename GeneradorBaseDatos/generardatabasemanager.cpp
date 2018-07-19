#include "generardatabasemanager.h"
#include <QDebug>
#include <QString>

GenerarDatabaseManager::GenerarDatabaseManager()
{

}

QString GenerarDatabaseManager::generarTextoHeader(QString nombrebaseDatos)
{

    QString text;

    text = QString(
        "#ifndef DATABASEMANAGER_H\n"
        "#define DATABASEMANAGER_H\n\n"

        "#include <memory>\n\n"

        "#include <QString>\n\n"

        "class QSqlQuery;\n"
        "class QSqlDatabase;\n\n"


        "const QString DATABASE_FILENAME = \"%1\";\n\n"

        "class DatabaseManager\n"
        "{\n"
        "public:\n"
            "\tstatic DatabaseManager& instance();\n"
            "\t~DatabaseManager();\n\n"
            "\tstatic void debugQuery(const QSqlQuery& query);\n\n"
        "protected:\n"
            "\tDatabaseManager(const QString& path = DATABASE_FILENAME);\n"
        "private:\n"
            "\tstd::unique_ptr<QSqlDatabase> mDatabase;\n\n"
        "public:\n"
            "\tconst AlbumDao albumDao;\n"
            "\tconst PictureDao pictureDao;\n"
        "};\n\n"
        "#endif // DATABASEMANAGER_H\n").arg(nombrebaseDatos);


    return text;
}



QString GenerarDatabaseManager::generarTextoSrc()
{
    QString text;
    text = QString(
                "#include \"DatabaseManager.h\"\n"
                "#include <QSqlDatabase>\n"
                "#include <QDebug>\n"
                "#include <QSqlError>\n"
                "#include <QSqlQuery>\n\n"

                "DatabaseManager&DatabaseManager::instance()\n"
                "{\n"
                    "\tstatic DatabaseManager singleton;\n"
                    "\treturn singleton;\n"
                "}\n\n"

                "DatabaseManager::~DatabaseManager()\n"
                "{\n"
                    "\tmDatabase->close();\n"
                "}\n\n"

                "void DatabaseManager::debugQuery(const QSqlQuery& query)\n"
                "{\n"
                    "\tif (query.lastError().type() == QSqlError::ErrorType::NoError) {\n"
                        "\t\tqDebug() << \"Query OK:\"  << query.lastQuery();\n"
                    "\t} else {\n"
                       "\t\tqWarning() << \"Query KO:\" << query.lastError().text();\n"
                       "\t\tqWarning() << \"Query text:\" << query.lastQuery();\n"
                    "\t}\n"
                "}\n\n"


                "DatabaseManager::DatabaseManager(const QString& path) :\n"
                    "\tmDatabase(new QSqlDatabase(QSqlDatabase::addDatabase(\"QSQLITE\"))),\n"
                "{\n"
                    "\tmDatabase->setDatabaseName(path);\n"

                    "\tbool openStatus = mDatabase->open();\n"
                    "\tqDebug() << \"Database connection: \" << (openStatus ? \"OK\" : \"Error\");\n\n"
                "}\n\n");
    return text;
}
