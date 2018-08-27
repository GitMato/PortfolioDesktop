#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    projectManager_ = new ProjectManager(this);
    // HTTP GET PROJECTS & TOOLS

    // MAKE OBJECTS OF HTTP RESULTS

    // MAKE UI ELEMENTS OF THE OBJECTS
    try
    {
        projectManager_->getAllProjectsAndTools();

    }
    catch(...)
    {
        qDebug() << "asd";
    }
    // PRESENT THEM IN MAINWINDOW
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionRefresh_triggered()
{
    //ProjectManager::getAllProjectsAndTools();
}
