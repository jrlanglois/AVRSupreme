#ifndef AVRS_MICROCONTROLLERS_STK500_H
#define AVRS_MICROCONTROLLERS_STK500_H

class STK500 : public Microcontroller
{
public:
    STK500()
    {
    }

    //==============================================================================
    std::string getName() const override
    {
        return "Atmel STK500 Version 1.x";
    }

    std::string getSetupInformation() override
    {
        return std::string();
    }

    void fillDescription (Description& description) override
    {
        description.isPaged = true;
    }

    //==============================================================================
    std::string initialise() override
    {
        return std::string();
    }

    std::string shutdown() override
    {
        return std::string();
    }

private:
    //==============================================================================
    AVRS_DECLARE_NON_COPYABLE (STK500)
};

#endif //AVRS_MICROCONTROLLERS_STK500_H