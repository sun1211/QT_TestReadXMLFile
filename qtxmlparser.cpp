#include "qtxmlparser.h"

QtXmlParser::QtXmlParser(QWidget *parent)
    : QWidget(parent)
{

}

QtXmlParser::~QtXmlParser()
{

}


bool QtXmlParser::Parse(QString filepath)
{
    QFile file(filepath);

    // Open file
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Warning",
                                              "Failed to open file for reading.", QMessageBox::Ok);
        msgBox->show();
        return false;
    }

    QString errorStr;

    int errorLine;
    int errorColumn;

    QDomDocument doc;

    // Parse file
    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) {
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Warning",
                                              "Failed to parse the file into a DOM tree.", QMessageBox::Ok);
        msgBox->show();
        return false;
    }
    //Get the root element
    QDomNodeList nodeList = doc.elementsByTagName("page");

    m_page.clear();

    for (int i = 0; i < nodeList.count(); i++) {
        QDomElement el = nodeList.at(i).toElement();
        m_page.push_back(ParsePageBlk(el));
    }
    return true;
}

QVector <PageBlk> QtXmlParser::M_Page()
{
    return m_page;
}

PageBlk QtXmlParser::ParsePageBlk(QDomElement &elem)
{
    PageBlk page;

    page.name = elem.attribute("name");

    QDomNodeList nodeList = elem.elementsByTagName("control");

    for (int i = 0; i < nodeList.count(); i++) {
        QDomElement el = nodeList.at(i).toElement();
        page.control.push_back(ParseControlBlk(el));
    }

    return page;
}

ControlBlk QtXmlParser::ParseControlBlk(QDomElement &elem)
{
    ControlBlk control;

    control.type = elem.attribute("type");

    QStringList list = elem.attribute("rect").split(" ");
    control.x = list[0].toInt();
    control.y = list[1].toInt();
    control.w = list[2].toInt();
    control.h = list[3].toInt();

    QDomNodeList nodeList = elem.elementsByTagName("attr");

    for (int i = 0; i < nodeList.count(); i++) {
        QDomElement el = nodeList.at(i).toElement();
        control.attr.push_back(ParseAttrBlk(el));
    }

    return control;
}

AttrBlk QtXmlParser::ParseAttrBlk(QDomElement &elem)
{
    AttrBlk attr;

    attr.name = elem.attribute("name");
    attr.value = elem.attribute("value");

    return attr;
}
