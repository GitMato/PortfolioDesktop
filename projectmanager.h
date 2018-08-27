#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "httpservice.h"
#include "project.h"
#include "tool.h"

#include <vector>
#include <QObject>

class ProjectManager: public QObject
{
    Q_OBJECT

public:
    ProjectManager(QObject *parent);

    // CALL HTTPSERVICE TO MAKE HTTP REQUESTS AND GET THEIR RESULTS


    // FROM THE RESULTS MAKE PROJECT & TOOL OBJECTS

    // GIVE OBJECTS TO MAINWINDOW ( OR MAKE A PROJECTCARD CLASS WHICH IS PRESENTED IN THE MAINWINDOW )
    //std::vector<QObject> getAllProjectsAndTools();
    void getAllProjectsAndTools();

private slots:
    void updateProjectsToolsValue();

private:
    HttpService *httpService_;
};

#endif // PROJECTMANAGER_H
