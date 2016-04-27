#include "readxml.h"

ReadXML::ReadXML(QWidget *parent)
    : QWidget(parent)
{
    QtXmlParser *LoadXML = new QtXmlParser();
    if(LoadXML->Parse("/sdcard/Demo1.xml")){
        qDebug() << "load oke";
        m_page = LoadXML->M_Page();

            for(int i = 0; i < m_page.size(); i++){
                qDebug() << "name: "<<m_page.at(i).name;
                for(int j = 0; j < m_page.at(i).control.size(); j++){
                    qDebug() << "   type:" << m_page.at(i).control.at(j).type;
                }
            }
    }
}

ReadXML::~ReadXML()
{

}
