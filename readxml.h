#ifndef READXML_H
#define READXML_H

#include <QWidget>
#include <QDebug>
#include <QtCore>

#include "qtxmlparser.h"

class ReadXML : public QWidget
{
    Q_OBJECT

public:
    ReadXML(QWidget *parent = 0);
    ~ReadXML();
private:
    QVector <PageBlk> m_page;

};

#endif // READXML_H
