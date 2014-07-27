#ifndef AVRS_ARCHITECTURE_DEFINITIONS_H
#define AVRS_ARCHITECTURE_DEFINITIONS_H

#if defined (i386) || defined (__i386) || defined (__i386__) || defined (_X86_) || defined (_M_IX86) || defined (_M_X86)
    #define AVRS_A_X86       1
#elif defined (__amd64__) || defined (__amd64) || defined (_M_X64) || defined (_M_AMD64) || defined (__x86_64__) || defined (__x86_64)
    #define AVRS_A_X64       1
#elif defined (__ia64__) || defined (_IA64) || defined (__IA64__) || defined (__ia64) || defined (_M_IA64) || defined (__itanium__)
    #define AVRS_A_ITANIUM   1
#elif defined (__powerpc) || defined (__powerpc__) || defined (__POWERPC__) || defined (__ppc__) || defined (_M_PPC) || defined (_ARCH_PPC)
    #define AVRS_A_POWERPC   1
#elif defined (_ARM) || defined (__arm__) || defined (__TARGET_ARCH_ARM)
    #define AVRS_A_ARM       1
#elif defined (mips) || defined (__mips__) || defined (__MIPS__)
    #define AVRS_A_MIPS      1
#else
    #error "AVRSupreme does not currently support your CPU architecture!"
#endif

//==============================================================================
#if defined (_BIG_ENDIAN) || defined (__BIG_ENDIAN__) || defined (AVRS_A_POWERPC) || defined (AVRS_A_ITANIUM) || defined (AVRS_A_ARM)
    #define AVRS_E_BIG_ENDIAN     1
#elif defined (_LITTLE_ENDIAN) || defined (__LITTLE_ENDIAN__) || defined (AVRS_A_X86) || defined (AVRS_A_X64)
    #define AVRS_E_LITTLE_ENDIAN  1
#else
    #error "You must setup AVRSupreme to check for endianness correctly at compile time."
#endif

#endif //AVRS_ARCHITECTURE_DEFINITIONS_H