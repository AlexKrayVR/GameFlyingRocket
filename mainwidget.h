#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include"scene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_Start_clicked();

private:
    Ui::MainWidget *ui;
    Scene* scene;
};
#endif // MAINWIDGET_H
