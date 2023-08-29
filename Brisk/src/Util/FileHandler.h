
#pragma once

#include <iostream>
#include <fstream>
#include <string>


namespace Brisk{

class FileHandler
{
public:
    FileHandler();
    std::string fileToString(std::string filePath);
};

}