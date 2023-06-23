
#pragma once

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "tinygltf/tiny_gltf.h"

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