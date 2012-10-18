#include "baseview.h"
#include <QtGui>
#include <QtCore>

namespace view {


struct BaseView::Private
{
};

BaseView::BaseView(QWidget *parent)
    : QWidget(parent)
    , m_pvt(new Private)
{
}

BaseView::~BaseView()
{
}

}

