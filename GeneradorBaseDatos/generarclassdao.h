#ifndef GENERARCLASSDAO_H
#define GENERARCLASSDAO_H

#include <QString>

class Generarclassdao
{
public:
    Generarclassdao();
    QString generarTextoHeader(QString className);

private:
    QString firstLettertoUpperCase(QString &string);

};

#endif // GENERARCLASSDAO_H
