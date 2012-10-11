#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <QUndoCommand>

class CreateAchievementCommand : public QUndoCommand
{
public:
    void redo();
    void undo();
private:
    struct Private;
    Private* m_pvt;
};

class DeleteAchievementCommand : public QUndoCommand
{
public:
    void redo();
    void undo();
private:
    struct Private;
    Private* m_pvt;
};

class CreateActionCommand : public QUndoCommand
{
public:
    void redo();
    void undo();
private:
    struct Private;
    Private* m_pvt;
};

class DeleteActionCommand : public QUndoCommand
{
public:
    void redo();
    void undo();
};


#endif
