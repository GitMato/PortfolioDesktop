#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H

#include <vector>
#include <string>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QDebug>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


class HttpService: public QObject
{
    Q_OBJECT

public:
    HttpService(QObject *parent = nullptr);
    //~HttpService();

    void getProjects_Tools();
    void getProjects();
    void getTools();
    std::vector<QJsonObject> getAllProjectsValue();
    std::vector<QJsonObject> getAllToolsValue();

signals:
    void variablesReady();


private slots:
    void managerProjectsFinished(QNetworkReply *reply);
    void managerToolsFinished(QNetworkReply *reply);
    void setVariablesReady();

private:

    int variableReadyCount_;
    QNetworkAccessManager *managerForProjects_;
    QNetworkAccessManager *managerForTools_;
    QNetworkRequest *projectsRequest_;
    QNetworkRequest *toolsRequest_;
    std::vector<QJsonObject> allProjects_;
    std::vector<QJsonObject> allTools_;
};

#endif // HTTPSERVICE_H
