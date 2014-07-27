#include "AVRSMasterHeader.h"

//==============================================================================
class Console
{
public:
    static void printMessage (const char* message)
    {
        std::cout << message << std::endl;
    }

    static void printMessage (const std::string& message)
    {
        std::cout << message.c_str() << std::endl;
    }

    static void printMessage (const std::wstring& message)
    {
        std::cout << message.c_str() << std::endl;
    }

    static void pause()
    {
        getchar();
    }

    static void printHelp()
    {
        printMessage ("Things");
        printMessage ("More Things");
    }

private:
    AVRS_DECLARE_UTILITY_CLASS (Console)
};

//==============================================================================
int main()
{
    Console::printHelp();

    const std::vector<std::string> result (SerialPort::listAvailablePorts());

    for (const std::string& s : result)
        Console::printMessage (s);

    Console::pause();
    return 0;
}