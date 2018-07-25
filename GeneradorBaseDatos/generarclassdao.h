#ifndef GENERARCLASSDAO_H
#define GENERARCLASSDAO_H

#include <QString>
#include <deque>

class Generarclassdao
{
public:

    enum DataTypes{
        TEXT,
        NUMERIC,
        INTEGER,
        REAL,
        BLOB,
    };

    Generarclassdao();
    QString generarTextoHeader(QString className);
    QString generarTextoSrc(QString className,
                            std::deque<QString> &nombres,
                            std::deque<QString> &tipos);
    QString generadorTablas(std::deque<QString> &nombres,
                            std::deque<QString> &tipos);
    QString generadorInsert(std::deque<QString> &nombres);
    QString generadorUpdate(std::deque<QString> &nombres);
    QString generadorAsignacion(std::deque<QString> &nombres,
                                std::deque<QString> &tipos,
                             QString className);


private:
    QString firstLettertoUpperCase(QString &string);

};

#endif // GENERARCLASSDAO_H
