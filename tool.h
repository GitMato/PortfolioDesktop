#ifndef TOOL_H
#define TOOL_H

#include <string>

class Tool
{
public:
    Tool();

    void setValues();
    void getToolInfo();

private:

    uint8_t _id;
    std::string _name;
};

#endif // TOOL_H
