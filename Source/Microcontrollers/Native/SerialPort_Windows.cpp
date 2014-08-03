class SerialPort::Pimpl
{
public:
    Pimpl()
    {
    }

    ~Pimpl()
    {
    }

    //==============================================================================
    /*
        GetCommState
        DCB
    */

    //==============================================================================
    static std::vector<std::string> listAvailablePorts()
    {
        enum { MaxNumCOMPorts = 256 };

        std::vector<std::string> names;

        for (int i = 0; i < MaxNumCOMPorts; ++i)
        {
            const COMPort port (i);

            if (port.isOpened())
                names.push_back (port.name.c_str());
        }

        return names;
    }

private:
    //==============================================================================
    class COMPort
    {
    public:
        COMPort (int comPortIndex) :
            index (comPortIndex),
            name ("COM"),
            port (nullptr)
        {
            name += StringHelpers::toString (index);

            port = CreateFile (StringHelpers::toWideString (name).c_str(),  
                               GENERIC_READ | GENERIC_WRITE,                //Desired access should be read & write
                               0,                                           //COM port must be opened in non-sharing mode
                               nullptr,                                     //Don't care about the security
                               OPEN_EXISTING,                               //IMPORTANT: Must use OPEN_EXISTING for a COM port
                               0,                                           //Usually overlapped but non-overlapped for existance test
                               nullptr);                                    //Always nullptr for a general purpose COM port
        }

        ~COMPort()
        {
            if (isOpened())
                CloseHandle (port);
        }

        bool isOpened() const noexcept { return port == NO_ERROR; }

        const int index;
        std::string name;
        HANDLE port;

    private:
        AVRS_DECLARE_NON_COPYABLE (COMPort)
    };

    //==============================================================================
    AVRS_DECLARE_NON_COPYABLE (Pimpl)
};