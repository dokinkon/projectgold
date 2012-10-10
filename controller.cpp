#include "controller.h"
#include "model/basemodel.h"

struct Controller::Private
{
    QGraphicsScene* mindMapScene;
    QGraphicsScene* actionDependenceScene;
    model::BaseModel* model;

    Private()
        : mindMapScene(NULL)
        , actionDependenceScene(NULL)
        , model(NULL)
    {
    }
};

Controller::Controller(QObject *parent)
    : QObject(parent)
    , m_pvt(new Private)
{
    m_pvt->mindMapScene = new QGraphicsScene(this);
    m_pvt->actionDependenceScene = new QGraphicsScene(this);
}

Controller::~Controller()
{
    delete m_pvt;
}

QGraphicsScene* Controller::mindMapScene() const
{
    return m_pvt->mindMapScene;
}

QGraphicsScene* Controller::actionDependenceScene() const
{
    return m_pvt->actionDependenceScene;
}

void Controller::setModel(model::BaseModel* model)
{
    m_pvt->model = model;
}

void Controller::createArchievement()
{
    //assert(m_pvt->model);

	//model::AchivementPtr ach = m_pvt->model->createAchivement(tr("[no name achivement]"));
	//view::Achivement* item = new view::Achivement( ach );

	//m_scene -> addItem( item );

}

void Controller::createAction()
{

}
