#include "generarclassdao.h"
#include <QDebug>

Generarclassdao::Generarclassdao()
{

}

QString Generarclassdao::generarTextoHeader(QString className)
{
    QString text;
    text = QString(

            "#ifndef %2DAO_H\n"
            "#define %2DAO_H\n"

            "#include <memory>\n"
            "#include <vector>\n"
            "#include <QObject>\n\n"

            "class QSqlDatabase;\n"
            "class %1;\n\n"

            "class %1Dao : public QObject\n"
            "{\n\n"

            "Q_OBJECT\n\n"

            "public:\n"
                "\texplicit %1Dao(QSqlDatabase& database);\n"
                "\tvoid init() const;\n\n"

                "\tvoid addRecord(%1& record);\n"
                "\tvoid updateRecord(%1& record);\n"
                "\tvoid removeRecord(int recordId);\n"
                "\tstd::unique_ptr<std::vector<std::unique_ptr<%1>>> getAllRecords() const;\n\n"
                "\tstd::unique_ptr<std::vector<std::unique_ptr<%1>>> getRecord(int recordId) const;\n\n\n"

            "signals:\n"
                "\tvoid addedRecord();\n"
                "\tvoid updatedRecord();\n"
                "\tvoid removedRecord();\n\n"

            "private:\n"
                "\tQSqlDatabase& mDatabase;\n"
            "};\n\n"

            "#endif // PICTUREDAO_H\n"


                ).arg(className).arg(className.toUpper());            ;
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
                "\tQObject(),\n"
                "\tmDatabase(database)\n"
            "{\n"
            "}\n\n"

            "void %1Dao::init() const\n"
            "{\n"
                "\tif (!mDatabase.tables().contains(\"%1\")) {\n"
                    "\t\tQSqlQuery query(mDatabase);\n"
                    "\t\tquery.exec(\"CREATE TABLE %1 (id INTEGER PRIMARY KEY AUTOINCREMENT, %3)\");\n"
                    "\t\tDatabaseManager::debugQuery(query);\n"
                "\t}\n"
            "}\n\n"

            "void %1Dao::addRecord(%1& record)\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"INSERT INTO %1 %4"
                "\tquery.exec();\n"
                "\trecord.setId(query.lastInsertId().toInt());\n"
                "\tDatabaseManager::debugQuery(query);\n"
                "\temit addedRecord();\n"
            "}\n\n"

            "void %1Dao::updateRecord(%1& record)\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"UPDATE %1 %5"
                "\tquery.bindValue(\":id\", record.getId());\n"
                "\tquery.exec();\n"
                "\tDatabaseManager::debugQuery(query);\n"
                "\temit updatedRecord();\n"
            "}\n\n"

            "void %1Dao::removeRecord(int recordId)\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"DELETE FROM %1 WHERE id = (:id)\");\n"
                "\tquery.bindValue(\":id\", recordId);\n"
                "\tquery.exec();\n"
                "\tDatabaseManager::debugQuery(query);\n"
                "\temit removedRecord();\n"
            "}\n\n"

            "unique_ptr<vector<unique_ptr<%1>>> %1Dao::getAllRecords() const\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery(\"SELECT * FROM %1\");\n"
                "\tquery.exec();\n"
                "\tDatabaseManager::debugQuery(query);\n"
                "\tunique_ptr<vector<unique_ptr<%1>>> list(new vector<unique_ptr<%1>>());\n"
                "\twhile(query.next()) {\n"
                    "\t\tunique_ptr<%1> %2(new %1());\n"
                    "\t\t%2->setId(query.value(\"id\").toInt());\n"
                    "%6"
                    "\t\tlist->push_back(move(%2));\n"
                "\t}\n"
                "\treturn list;\n"
            "}\n\n"
            ""
            "unique_ptr<vector<unique_ptr<%1>>> %1Dao::getRecord(int recordId) const\n"
            "{\n"
                "\tQSqlQuery query(mDatabase);\n"
                "\tquery.prepare(\"SELECT * FROM %1 WHERE id = (:id)\");\n"
                "\tquery.bindValue(\":id\", recordId);\n"
                "\tquery.exec();\n"
                "\tDatabaseManager::debugQuery(query);\n"
                "\tunique_ptr<vector<unique_ptr<%1>>> list(new vector<unique_ptr<%1>>());\n"
                "\twhile(query.next()) {\n"
                    "\t\tstd::unique_ptr<%1> %2(new %1());\n"
                    "\t\t%2->setId(query.value(\"id\").toInt());\n"
                    "%6"
                    "\t\tlist->push_back(move(%2));\n"
                "\t}\n"
                "\treturn list;\n"
            "}\n"

            ).arg(className).arg(className.toLower())
                .arg(generadorTablas(nombres,tipos))
                .arg(generadorInsert(nombres))
                .arg(generadorUpdate(nombres))
                .arg(generadorAsignacion(nombres,
                                         tipos,
                                         className));
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

    texto.append(")\");\n");


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

    texto.append(") WHERE  id = (:id)\");\n");

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

QString Generarclassdao::generadorAsignacion(std::deque<QString> &nombres,
                                          std::deque<QString> &tipos,
                                          QString className)
{
    QString texto;

    for(uint i = 0; i< nombres.size(); i++){

        texto.append("\t\t");

        texto.append(className.toLower());
        texto.append("->");
        texto.append("set");
        texto.append(firstLettertoUpperCase(nombres.at(i)));
        texto.append("(query.value(\"");
        texto.append(nombres.at(i));
        texto.append("\")");

        if(tipos.at(i) == "TEXT" ){
            texto.append(".toString()");
        }else if (tipos.at(i) == "NUMERIC") {
            texto.append(".toBool()");
        }else if (tipos.at(i) == "INTEGER"){
            texto.append(".toInt()");
        }else if (tipos.at(i) == "REAL") {
            texto.append(".toDouble()");
        } else if (tipos.at(i) == "BLOB"){
            texto.append(".toByteArray()");
        }

        texto.append(");\n");
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
