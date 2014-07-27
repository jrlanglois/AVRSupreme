#include "AVRSupreme_Microcontrollers.h"

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
   #else
    #error Unknown platform!
   #endif

    #include "Misc/SerialPort.cpp"
}