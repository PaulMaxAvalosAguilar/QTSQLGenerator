#include "generarclassdao.h"
#include <QDebug>

Generarclassdao::Generarclassdao()
{

}

QString Generarclassdao::generarTextoHeader(QString className)
{
    QString text;
    text = QString(

            "#ifndef %1DAO_H\n"
            "#define %1EDAO_H\n"

            "#include <memory>\n"
            "#include <vector>\n\n"

            "class QSqlDatabase;\n"
            "class %2;\n\n"

            "class %2Dao\n"
            "{\n"
            "public:\n"
                "\texplicit %2Dao(QSqlDatabase& database);\n"
                "\tvoid init() const;\n\n"

                "\tvoid add%2(%2& %3) const;\n"
                "\tvoid update%2(%2& %3) const;\n"
                "\tvoid remove%2(int %3id) const;\n"
                "\tstd::unique_ptr<%2> get%2(int id) const;\n"
                "\tstd::unique_ptr<std::vector<std::unique_ptr<%2>>> getAll%2s() const;\n\n"

            "private:\n"
                "\tQSqlDatabase& mDatabase;\n"
            "};\n\n"

            "#endif // PICTUREDAO_H\n"


                ).arg(className.toUpper()).arg(firstLettertoUpperCase(className))
            .arg(className.toLower());
    return text;
}

QString Generarclassdao::firstLettertoUpperCase(QString &string)
{

    QString nueva = string;
    if(!nueva.isEmpty()){
    nueva[0]= nueva.at(0).toUpper();
    }
    return nueva;
}
