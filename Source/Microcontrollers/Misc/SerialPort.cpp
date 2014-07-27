SerialPort::SerialPort() :
    pimpl (new Pimpl())
{
}

SerialPort::~SerialPort()
{
}

//==============================================================================
std::vector<std::string> SerialPort::listAvailablePorts()
{
    return Pimpl::listAvailablePorts();
}