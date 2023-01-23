#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileHandler
{
public:
    FileHandler();
    std::string fileToString(std::string filePath);
};