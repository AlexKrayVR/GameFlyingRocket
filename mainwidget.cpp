#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    scene = new Scene(this);
    scene->setSceneRect(0,0,875,490);

    ui->graphicsView->setScene(scene);

}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_Start_clicked()
{
    scene->startGame();
}
