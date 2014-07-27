#ifndef AVRS_ARCHITECTURE_PLATFORM_DEFINITIONS_H
#define AVRS_ARCHITECTURE_PLATFORM_DEFINITIONS_H

#if defined (WIN32) || defined (_WIN32) || defined (__WIN32__) || defined (__WINDOWS__) || defined (__TOS_WIN__)
    #define AVRS_P_32BIT        1
    #define AVRS_P_WINDOWS      1
#elif defined (WIN64) || defined (_WIN64) || defined (__WIN64) || defined (_WIN64_) || defined (__WIN64__)
    #define AVRS_P_64BIT        1
    #define AVRS_P_WINDOWS      1
#elif defined (linux) || defined (__linux) || defined (__linux__)
    #define AVRS_P_LINUX        1
#elif defined (macintosh) || defined (Macintosh) || (defined (__APPLE__))
    #define AVRS_P_MACINTOSH    1
#elif defined (TARGET_OS_IPHONE) || defined (TARGET_IPHONE_SIMULATOR))
    #define AVRS_P_IOS          1
    #define AVRS_P_IPHONE       1
#elif defined (ANDROID)
    #define AVRS_P_ANDROID      1
#else
    #error "AVRS does not support this operating system!"
#endif

#endif //AVRS_ARCHITECTURE_PLATFORM_DEFINITIONS_H