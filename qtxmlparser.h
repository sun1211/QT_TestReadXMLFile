#ifndef QTXMLPARSER_H
#define QTXMLPARSER_H

#include <QWidget>

#include <QFile>
#include <QTextStream>

#include <QDomDocument>
#include <QDomElement>
#include <QDomText>

#include <QString>
#include <QDebug>
#include <QMessageBox>

typedef struct tag_AttrBlk
{
    QString name;
    QString value;
}AttrBlk, *pAttrBlk;

typedef struct tag_ControlBlk
{
    QString type;
    int x, y;
    int w, h;
    QVector<AttrBlk> attr;
}ControlBlk, *pControlBlk;

typedef struct tag_PageBlk
{
    QString name;
    QVector<ControlBlk> control;
}PageBlk, *pPageBlk;

class QtXmlParser : public QWidget
{
    Q_OBJECT

public:
    explicit QtXmlParser(QWidget *parent = 0);
    ~QtXmlParser();

    bool Parse(QString filepath);
    QVector <PageBlk> M_Page();


private:
    PageBlk ParsePageBlk(QDomElement &elem);
    ControlBlk ParseControlBlk(QDomElement &elem);
    AttrBlk ParseAttrBlk(QDomElement &elem);

    QVector <PageBlk> m_page;
};

#endif // QTXMLPARSER_H

