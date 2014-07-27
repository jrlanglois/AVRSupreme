#ifndef AVRS_ARCHITECTURE_COMPILER_DEFINITIONS_H
#define AVRS_ARCHITECTURE_COMPILER_DEFINITIONS_H

//==============================================================================
#ifndef __cplusplus //Checks to see if we're using a C++ compiler
    #error "You must use a C++ compiler to use the AVRSupreme!"
#endif

//==============================================================================
#if defined (_MSC_VER)
    #define AVRS_C_VS                               1

   #if (_MSC_VER < 1600) //Older, shit, version of Visual Studio is being used
    #define AVRS_C_VS_7_OR_EARLIER                  1
   #endif

   #if AVRS_P_64BIT || ! AVRS_C_VS_7_OR_EARLIER
    #define AVRS_USE_INTRINSICS 1
   #endif

   #if (_MSC_VER >= 1600) //Visual Studio 2010
    #define AVRS_COMPILER_SUPPORTS_NULLPTR          1
    #define JUCE_COMPILER_SUPPORTS_MOVE_SEMANTICS   1
   #endif

   #if (_MSC_VER >= 1700) //Visual Studio 2012
    #define AVRS_COMPILER_SUPPORTS_OVERRIDE         1
    #define AVRS_COMPILER_SUPPORTS_FINAL            1
   #endif

   #if (_MSC_VER >= 1800) //Visual Studio 2013
    #define AVRS_COMPILER_SUPPORTS_NOEXCEPT         1
   #endif

    //Shut Visual Studio up about defining keywords
    #define _ALLOW_KEYWORD_MACROS                   1
#elif defined (__GNUC__)
    #define AVRS_C_GCC                              1

   #if (__GNUC__ >= 4)
    #define AVRS_COMPILER_SUPPORTS_NULLPTR          1
   #endif

   #if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407
    #define AVRS_DELETED_FUNCTION = delete
   #endif
#elif defined (__INTEL_COMPILER) || defined (__ICC) || defined (__ECC) || defined (__ICL)
    #define AVRS_C_INTEL                            1

   #if (__INTEL_COMPILER >= 1210)
    #define AVRS_COMPILER_SUPPORTS_NULLPTR          1
   #endif
#elif defined (__MINGW32__)
    #define AVRS_C_MING32                           1
#elif defined (__MINGW64__)
    #define AVRS_C_MING64                           1
#elif defined (__llvm__)
    #define AVRS_C_CLANG                            1

    #if __has_feature
       #if __has_feature (cxx_nullptr)
        #define AVRS_COMPILER_SUPPORTS_NULLPTR      1
       #endif

       #if __has_feature (cxx_noexcept)
        #define AVRS_COMPILER_SUPPORTS_NOEXCEPT     1
       #endif

       #if __has_feature (cxx_override_control)
        #define AVRS_COMPILER_SUPPORTS_OVERRIDE     1
       #endif

       #if __has_feature (cxx_noexcept)
        #define AVRS_COMPILER_SUPPORTS_FINAL        1
       #endif

       #if __has_feature (cxx_deleted_functions)
        #define AVRS_DELETED_FUNCTION = delete
       #endif

       #if __has_feature (cxx_rvalue_references)
        #define AVRS_COMPILER_SUPPORTS_MOVE_SEMANTICS 1
       #endif
    #endif
#elif defined (__TURBOC__)
    #define AVRS_C_TURBOC                           1
#else
    #error "AVRSupreme does not support your compiler!"
#endif

//==============================================================================
#ifndef AVRS_COMPILER_SUPPORTS_NULLPTR
    #define nullptr (0)
#endif

#ifndef AVRS_COMPILER_SUPPORTS_NOEXCEPT
    #define noexcept throw()
#endif

#ifndef AVRS_COMPILER_SUPPORTS_OVERRIDE
    #define override
#endif

#ifndef AVRS_COMPILER_SUPPORTS_FINAL
    #define final
#endif

#ifndef AVRS_DELETED_FUNCTION
    #define AVRS_DELETED_FUNCTION
#endif

#ifndef AVRS_COMPILER_SUPPORTS_MOVE_SEMANTICS
    #define AVRS_COMPILER_SUPPORTS_MOVE_SEMANTICS 0
#endif

//==============================================================================
#if defined (DEBUG) || defined (_DEBUG) || ! (defined (NDEBUG) || defined (_NDEBUG))
    #define AVRS_DEBUG 1
#endif

#if ! (defined (DEBUG) || defined (_DEBUG) || defined (NDEBUG) || defined (_NDEBUG))
    #define AVRS_BROKEN_DEBUG_MESSAGE "Neither NDEBUG or DEBUG have been defined! You should set one of these to make it clear whether this is a release build."

   #if AVRS_C_VS
    #pragma message AVRS_BROKEN_DEBUG_MESSAGE
   #else
    #warning AVRS_BROKEN_DEBUG_MESSAGE
   #endif

    #undef AVRS_BROKEN_DEBUG_MESSAGE
#endif

#endif //AVRS_ARCHITECTURE_COMPILER_DEFINITIONS_H