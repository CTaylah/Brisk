#include "FileHandler.h"

namespace Brisk{ 

    FileHandler::FileHandler()
    {
    }
    std::string FileHandler::fileToString(const std::string filePath)
    {
        std::ifstream inputFileStream;
        inputFileStream.open(filePath);
        if (!inputFileStream.is_open())
        {
            std::cout << "Error: Could not open file \n" + filePath << std::endl;
        }

        std::string outputString;
        std::string line;
        while (std::getline(inputFileStream, line))
        {
            outputString = outputString + line + "\n";
        }

        inputFileStream.close();

        return outputString;
}
}