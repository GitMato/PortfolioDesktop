#include "projectmanager.h"



ProjectManager::ProjectManager(QObject *parent): QObject(parent)
{
    httpService_ = new HttpService();

    QObject::connect(httpService_, SIGNAL(variablesReady()),
        this, SLOT(updateProjectsToolsValue()));
}

//std::vector<QObject*> ProjectManager::getAllProjectsAndTools(){
void ProjectManager::getAllProjectsAndTools(){

    //std::vector<QObject> *projects = new std::vector<QObject>();
    // CALL HTTPSERVICE TO MAKE HTTP REQUESTS AND GET THEIR RESULTS
    httpService_->getProjects_Tools();



    // FROM THE RESULTS MAKE PROJECT & TOOL OBJECTS

    // GIVE OBJECTS TO MAINWINDOW ( OR MAKE A PROJECTCARD CLASS WHICH IS PRESENTED IN THE MAINWINDOW )
    //    return *projects;
}

void ProjectManager::updateProjectsToolsValue()
{
    std::vector<QJsonObject> projects = httpService_->getAllProjectsValue();
    std::vector<QJsonObject> tools = httpService_->getAllToolsValue();
    qDebug() << "Variables updated!";
}

//In Qt and in C++ there's no NSObject. So there is no direct alternative.
//What you should use is then depends on what you want to do.
//If you want to store value-types and pass them to scripts, you should use QVariantList.
//If you want to to store widgets, you should use one of the Qt template container and store pointers, for example QList<QWidget*>.
//More general case for non-gui elements is container with QObject*.
