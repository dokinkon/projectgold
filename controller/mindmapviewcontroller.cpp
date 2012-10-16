#include "controller/mindmapviewcontroller.h"

struct MindMapViewController::Private
{

};

MindMapViewController::MindMapViewController(QObject* parent)
    : ViewController(parent)
    , m_pvt(new Private)
{

}
MindMapViewController::~MindMapViewController()
{
    delete m_pvt;
}
