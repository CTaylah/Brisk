#include "Brisk.h"
#include <iostream>

class Sandbox : public Brisk::Application
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }

    void run()
    {
        int a = 6;
        logger.getClientLogger()->trace(6);
        while(true)
        { ; } 
    }

};

int main()
{
    Sandbox* sandbox = new Sandbox();
    sandbox->run();
    delete(sandbox);
    return 0;
}