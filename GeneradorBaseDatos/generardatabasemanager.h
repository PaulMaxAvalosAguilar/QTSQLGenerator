#ifndef GENERARDATABASEMANAGER_H
#define GENERARDATABASEMANAGER_H

#include <QString>

class GenerarDatabaseManager
{
public:
    GenerarDatabaseManager();
    QString generarTextoHeader(QString nombrebaseDatos);
    QString generarTextoSrc();
};

#endif // GENERARDATABASEMANAGER_H
