#include "httpservice.h"

HttpService::HttpService(QObject *parent): QObject(parent)
{
    managerForProjects_ = new QNetworkAccessManager(this);
    managerForTools_ = new QNetworkAccessManager(this);
    projectsRequest_ = new QNetworkRequest();
    toolsRequest_ = new QNetworkRequest();

    variableReadyCount_ = 0;

    QObject::connect(managerForProjects_, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(managerProjectsFinished(QNetworkReply*)));

    QObject::connect(managerForTools_, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(managerToolsFinished(QNetworkReply*)));
}

//HttpService::~HttpService(){}

void HttpService::getProjects_Tools()
{
    this->getProjects();
    this->getTools();
}


// Setup QNetworkManager with header and Url. Also, Do a GET request.
void HttpService::getProjects()
{
    qDebug() << "httpService::getProjects()";


    projectsRequest_->setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    projectsRequest_->setUrl(QUrl("https://portfolio-mato-api.herokuapp.com/api/projects"));
    //qDebug() << projectsRequest_->header(QNetworkRequest::ContentTypeHeader);
    managerForProjects_->get(*projectsRequest_);
}

// Setup QNetworkManager with header and Url. Also, Do a GET request.
void HttpService::getTools()
{
    qDebug() << "httpService::getTools()";

    toolsRequest_->setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    toolsRequest_->setUrl(QUrl("https://portfolio-mato-api.herokuapp.com/api/tools"));
    //qDebug() << projectsRequest_->header(QNetworkRequest::ContentTypeHeader);
    managerForTools_->get(*toolsRequest_);
}

std::vector<QJsonObject> HttpService::getAllProjectsValue()
{
    return allProjects_;
}

std::vector<QJsonObject> HttpService::getAllToolsValue()
{
    return allTools_;
}

// Handle Http GET Request response.
void HttpService::managerProjectsFinished(QNetworkReply *reply)
{
    qDebug() << "managerProjectsFinished method entered";

    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    // clear projects before refreshing
    allProjects_.clear();

    QString answer = reply->readAll();

    QJsonDocument jsonReply = QJsonDocument::fromJson(answer.toUtf8());

    if (jsonReply.isArray()){
        qDebug() << "json is array.";

        QJsonArray array = jsonReply.array();

        // add jsonObjects to allProjects_ vector.
        for (int i = 0; i < array.size(); i++){
            qDebug() << array[i].toObject();
            allProjects_.push_back(array[i].toObject());
        }
    }
    variableReadyCount_++;
    setVariablesReady();

}

// Handle Http GET Request response.
void HttpService::managerToolsFinished(QNetworkReply *reply)
{
    qDebug() << "managerToolsFinished method entered";

    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    // clear projects before refreshing
    allTools_.clear();

    QString answer = reply->readAll();

    QJsonDocument jsonReply = QJsonDocument::fromJson(answer.toUtf8());

    if (jsonReply.isArray()){
        qDebug() << "json is array.";

        QJsonArray array = jsonReply.array();

        // add jsonObjects to allTools_ vector.
        for (int i = 0; i < array.size(); i++){
            qDebug() << array[i].toObject();
            allTools_.push_back(array[i].toObject());
        }
    }
    variableReadyCount_++;
    setVariablesReady();
}

// Emit variablesReady() -signal (connected in projectmanager)
void HttpService::setVariablesReady()
{

    if (this->variableReadyCount_ >= 2){
        emit variablesReady();
    }
};


