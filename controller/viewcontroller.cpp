#include "controller/viewcontroller.h"


struct ViewController::Private
{

};

ViewController::ViewController(QObject* parent)
    : QObject(parent)
    , m_pvt(new Private)
{

}

ViewController::~ViewController()
{
    delete m_pvt;
}
