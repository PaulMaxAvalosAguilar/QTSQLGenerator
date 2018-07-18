#include "generardatabasemanager.h"
#include <QDebug>
#include <QString>

GenerarDatabaseManager::GenerarDatabaseManager()
{

}

QString GenerarDatabaseManager::generarTextoHeader(QString nombrebaseDatos)
{

    QString texto;

    texto = QString(
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

    return texto;

}
