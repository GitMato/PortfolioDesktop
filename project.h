#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>


class Project
{
public:
    Project();

    void setValues();
    void getProjectInfo();

private:

    uint8_t _id;
    std::string _name;
    std::string _imgUrl;
    std::string _imgAlt;
    std::string _description;
    std::string _details;
    std::vector<uint8_t> _tools;
    std::vector<std::string> _extraimg;
    std::vector<std::string> _extraUrls;

//    id: number;
//    name: string;
//    imgUrl: string;
//    imgAlt: string;
//    description: string;
//    details: string;
//    //tools: Tool[];
//    tools: number[]; // tool ids
//    extraimg: string[];
//    extraUrls: string[];
};

#endif // PROJECT_H
