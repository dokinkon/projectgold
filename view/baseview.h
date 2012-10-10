#ifndef BASEVIEW_H
#define BASEVIEW_H

#include "fwdeclaration.h"
#include <QWidget>

namespace view {

class BaseView : public QWidget
{
    Q_OBJECT
public:
    explicit BaseView(QWidget *parent = 0);
    virtual ~BaseView();
    void setModel(model::BaseModel*);
    model::BaseModel* model() const;
    
signals:
    
public slots:
    void refreshContent(int, const QList<model::Item*>&);

private:
    virtual void refreshContentImpl(int, const QList<model::Item*>&);

    struct Private;
    Private* m_pvt;
    
};

} // namespace


#endif // BASEVIEW_H
