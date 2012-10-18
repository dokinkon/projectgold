
#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotSceneSelectionChanged();
    void updateActions();

private:
    struct Private;
    QScopedPointer<Private> m_pvt;
};

#endif
