#include "AVRSupreme_Microcontrollers.h"

#if AVRS_P_WINDOWS
    #include <Windows.h>
#elif AVRS_P_LINUX
    #error
#elif AVRS_P_MACINTOSH
    #error
#elif AVRS_P_IOS
    #error
#elif AVRS_P_ANDROID
    #error
#endif

namespace avrs
{
   #if AVRS_P_WINDOWS
    #include "Native/SerialPort_Windows.cpp"
   #elif AVRS_P_LINUX
    #include "Native/SerialPort_Linux.cpp"
   #elif AVRS_P_MACINTOSH
    #include "Native/SerialPort_MacOSX.cpp"
   #elif AVRS_P_IOS
    #include "Native/SerialPort_iOS.cpp"
   #elif AVRS_P_ANDROID
    #include "Native/SerialPort_Android.cpp"
   #endif

    #include "Misc/SerialPort.cpp"
    #include "Types/Microcontroller.cpp"
}