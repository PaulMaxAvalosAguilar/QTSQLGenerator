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
            "#define %1DAO_H\n"

            "#include <memory>\n"
            "#include <vector>\n\n"

            "class QSqlDatabase;\n"
            "class %2;\n\n"

            "class %2Dao\n"
            "{\n"
            "public:\n"
                "\texplicit %2Dao(QSqlDatabase& database);\n"
                "\tvoid init() const;\n\n"

                "\tvoid addRecord(%2& record) const;\n"
                "\tvoid updateRecord(%2& record) const;\n"
                "\tvoid removeRecord(int recordId) const;\n"
                "\tstd::unique_ptr<%2> getRecord(int recordId) const;\n"
                "\tstd::unique_ptr<std::vector<std::unique_ptr<%2>>> getAllRecords() const;\n\n"

            "private:\n"
                "\tQSqlDatabase& mDatabase;\n"
            "};\n\n"

            "#endif // PICTUREDAO_H\n"


                ).arg(className.toUpper()).arg(className)
            ;
    return text;
}

QString Generarclassdao::generarTextoSrc(QString className,
                                         std::deque<QString> &nombres,
                                         std::deque<QString> &tipos)
{
    QString text;
        text = QString(

            "#include \"%2dao.h\"\n"
            "#include <QSqlDatabase>\n"
            "#include <QSqlQuery>\n"
            "#include <QVariant>\n\n"

            "#include \"%2.h\"\n"
            "#include \"databasemanager.h\"\n\n"

            "using namespace std;\n\n"

            "%1Dao::%1Dao(QSqlDatabase& database) :\n"
                "mDatabase(database)\n"
            "{\n"
            "}\n\n"

            "void %1Dao::init() const\n"
            "{\n"
                "\tif (!mDatabase.tables().contains(\"%1\")) {\n"
                    "\t\tQSqlQuery query(mDatabase);\n"
                    "\t\tquery.exec(\"CREATE TABLE %1 (id INTEGER PRIMARY KEY AUTOINCREMENT, %3\");\n"
                    "\t\tDatabaseManager::debugQuery(query);\n"
                "\t}\n"
            "}\n\n"

            "void %1Dao::addRecord(%1& record) const\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"INSERT INTO %1 %4"
                "\tquery.exec();\n"
                "\trecord.setId(query.lastInsertId().toInt());\n"
                "\tDatabaseManager::debugQuery(query);\n"
            "}\n\n"

            "void %1Dao::updateRecord(%1& record) const\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"UPDATE %1 %5"
                "\tquery.bindValue(\":id\", album.getId());\n"
                "\tquery.exec();\n"
                "\tDatabaseManager::debugQuery(query);\n"
            "}\n\n"

            "void %1Dao::removeRecord(int recordId) const\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"DELETE FROM %1 WHERE id = (:id)\");\n"
                "\tquery.bindValue(\":id\", recordId);\n"
                "\tquery.exec();\n"
                "\tDatabaseManager::debugQuery(query);\n"
            "}\n\n"

            "std::unique_ptr<%1> %1Dao::getRecord(int recordId) const\n"
            "{\n"

            "}\n\n"

            "unique_ptr<vector<unique_ptr<%1>>> %1Dao::getAllRecords() const\n"
            "{\n"
                "\tQSqlQuery query(\"SELECT * FROM %1\", mDatabase);\n"
                "\tquery.exec();\n"
                "\tunique_ptr<vector<unique_ptr<%1>>> list(new vector<unique_ptr<%1>>());\n"
                "\twhile(query.next()) {\n"
                    "\t\tunique_ptr<Album> album(new %1());\n"
                    "\t\talbum->setId(query.value(\"id\").toInt());\n"
                    "\t\talbum->setName(query.value(\"name\").toString());\n"
                    "\t\tlist->push_back(move(album));\n"
                "\t}\n"
                "\treturn list;\n"
            "}\n"
            ).arg(className).arg(className.toLower())
                .arg(generadorTablas(nombres,tipos))
                .arg(generadorInsert(nombres))
                .arg(generadorUpdate(nombres));
        return text;
}

QString Generarclassdao::generadorTablas(std::deque<QString> &nombres, std::deque<QString> &tipos)
{
    QString texto;
    for(uint i = 0; i < nombres.size(); i++){

        texto.append(nombres.at(i));
        texto.append(" ");
        texto.append(tipos.at(i));
        if(i != (nombres.size()-1)){
            texto.append(",");
        }
    }

    return texto;
}

QString Generarclassdao::generadorInsert(std::deque<QString> &nombres)
{
    QString texto;
    texto.append("(");
    for(uint i = 0; i< nombres.size(); i++){
        texto.append(nombres.at(i));
        if(i != (nombres.size())-1){
            texto.append(",");
        }
    }
    texto.append(")");

    texto.append(" ");
    texto.append(" VALUES ");
    texto.append(" ");
    texto.append("(");

    for(uint i = 0; i< nombres.size(); i++){
        texto.append(":");
        texto.append(nombres.at(i));
        if(i != (nombres.size())-1){
            texto.append(",");
        }
    }

    texto.append(");\n");


    for(uint i = 0; i< nombres.size(); i++){
        texto.append("\tquery.bindValue(\":");
        texto.append(nombres.at(i));
        texto.append("\"");
        texto.append(",");
        texto.append(" ");
        texto.append("record");
        texto.append(".get");
        texto.append(firstLettertoUpperCase(nombres.at(i)));
        texto.append("());\n");
    }

    return texto;
}

QString Generarclassdao::generadorUpdate(std::deque<QString> &nombres)
{

    QString texto;

    texto.append("(");
    for(uint i = 0; i< nombres.size(); i++){
        texto.append(nombres.at(i));
        if(i != (nombres.size())-1){
            texto.append(",");
        }
    }

    texto.append(") = (");

    for(uint i = 0; i< nombres.size(); i++){
        texto.append(":");
        texto.append(nombres.at(i));
        if(i != (nombres.size())-1){
            texto.append(",");
        }
    }

    texto.append(") WHERE  id = (:id);\n");

    for(uint i = 0; i< nombres.size(); i++){
        texto.append("\tquery.bindValue(\":");
        texto.append(nombres.at(i));
        texto.append("\"");
        texto.append(",");
        texto.append(" ");
        texto.append("record");
        texto.append(".get");
        texto.append(firstLettertoUpperCase(nombres.at(i)));
        texto.append("());\n");
    }

    return texto;
}

QString Generarclassdao::firstLettertoUpperCase(QString &string)
{

    QString nueva = string;
    if(!nueva.isEmpty()){
    nueva[0]= nueva.at(0).toUpper();
    }
    return nueva;
}
