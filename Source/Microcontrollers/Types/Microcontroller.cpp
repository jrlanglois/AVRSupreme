//==============================================================================
Microcontroller::Description::Description() :
    type (Flash),
    isPaged (false),
    pageSize (0),
    numPages (0),
    resetAfterWrites (false),
    memorySize (524288),
    memoryOffset (1024),
    minWriteDelay (10),
    maxWriteDelay (100)
{
}

Microcontroller::Description::Description (const Description& other) :
    type (other.type),
    isPaged (other.isPaged),
    pageSize (other.pageSize),
    numPages (other.numPages),
    resetAfterWrites (other.resetAfterWrites),
    memorySize (other.memorySize),
    memoryOffset (other.memoryOffset),
    minWriteDelay (other.minWriteDelay),
    maxWriteDelay (other.maxWriteDelay)
{
}

//==============================================================================
Microcontroller::Description& Microcontroller::Description::operator= (Description& other)
{
    if (this != &other)
    {
        type                = other.type;
        isPaged             = other.isPaged;
        pageSize            = other.pageSize;
        numPages            = other.numPages;
        resetAfterWrites    = other.resetAfterWrites;
        memorySize          = other.memorySize;
        memoryOffset        = other.memoryOffset;
        minWriteDelay       = other.minWriteDelay;
        maxWriteDelay       = other.maxWriteDelay;
    }

    return *this;
}

//==============================================================================
Microcontroller::Microcontroller()
{
}

Microcontroller::~Microcontroller()
{
}

//==============================================================================
void Microcontroller::calibrate()
{
}