#ifndef AVRS_MICROCONTROLLERS_MICROCONTROLLER_H
#define AVRS_MICROCONTROLLERS_MICROCONTROLLER_H

class Microcontroller
{
public:
    Microcontroller()
    {
    }

    virtual ~Microcontroller()
    {
    }

    //==============================================================================
    struct Description
    {
    public:
        Description()
        {
        }

        Description (const Description& other)
        {
        }

        //==============================================================================
        enum Type
        {
            Flash = 0,
            EEPROM
        };

        //==============================================================================
        Type type;

        bool isPaged;
        int pageSize;           //< In bytes
        int numPages;

        bool resetAfterWrites;

        int memorySize;         //< In bytes
        uint32 memoryOffset;    //< In bytes

        int minWriteDelay;      //< In microseconds
        int maxWriteDelay;      //< In microseconds

    private:
        //==============================================================================
    };

    //==============================================================================
    virtual std::string getName() const = 0;

    virtual std::string getSetupInformation() = 0;

    virtual void fillDescription (Description& description) = 0;

    //==============================================================================
    virtual std::string initialise() = 0;

    virtual std::string shutdown() = 0;

    virtual void calibrate()
    {
    }

protected:
    //==============================================================================

private:
    //==============================================================================
    AVRS_DECLARE_NON_COPYABLE (Microcontroller)
};

#endif //AVRS_MICROCONTROLLERS_MICROCONTROLLER_H