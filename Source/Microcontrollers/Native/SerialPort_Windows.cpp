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
    static std::vector<std::string> listAvailablePorts()
    {
        return std::vector<std::string>();
    }

private:
    //==============================================================================
    AVRS_DECLARE_NON_COPYABLE (Pimpl)
};