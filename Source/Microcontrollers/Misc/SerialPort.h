#ifndef AVRS_MICROCONTROLLERS_SERIAL_PORT_H
#define AVRS_MICROCONTROLLERS_SERIAL_PORT_H

class SerialPort
{
public:
    SerialPort();

    ~SerialPort();

    //==============================================================================
    static std::vector<std::string> listAvailablePorts();

private:
    //==============================================================================
    class Pimpl;
    ScopedPointer<Pimpl> pimpl;

    //==============================================================================
    AVRS_DECLARE_NON_COPYABLE (SerialPort)
};

#endif //AVRS_MICROCONTROLLERS_SERIAL_PORT_H