#ifndef AVRS_CORE_MACROS_H
#define AVRS_CORE_MACROS_H

//==============================================================================
/** These macros define the C calling convention used as the standard for AVRSupreme calls. */
#if JUCE_MSVC
    #define AVRS_CALLTYPE   __stdcall
    #define AVRS_CDECL      __cdecl
#else
    #define AVRS_CALLTYPE
    #define AVRS_CDECL
#endif

//==============================================================================
#if AVRS_P_IOS || AVRS_P_LINUX || AVRS_P_ANDROID
    /** This will try to break into the debugger if the application is currently being debugged.

        If called by an application that's not being debugged, the behaviour isn't defined:
        it may crash or not, depending on the platform.

        @see sassert()
    */
    #define avrs_breakDebugger      { ::kill (0, SIGTRAP); }
#elif AVRS_USE_INTRINSICS
   #ifndef __INTEL_COMPILER
    #pragma intrinsic (__debugbreak)
   #endif

    #define avrs_breakDebugger      { __debugbreak(); }
#elif AVRS_C_GCC || AVRS_P_MACINTOSH
   #if ! AVRS_NO_INLINE_ASM
    #define avrs_breakDebugger      { asm ("int $3"); }
   #endif
#else
    #define avrs_breakDebugger      { __asm int 3 }
#endif

#ifndef avrs_breakDebugger
    #define avrs_breakDebugger      { }
#endif

//==============================================================================
#if AVRS_P_WINDOWS
#include <Windows.h>
#include <debugapi.h>

static void outputDebugString (const std::wstring& text)
{
    OutputDebugString (text.c_str());
}

static void outputDebugString (const std::string& text)
{
    outputDebugString (std::wstring (text.begin(), text.end()));
}

static bool AVRS_CALLTYPE isRunningUnderDebugger()
{
    return IsDebuggerPresent() != FALSE;
}
#else
    #error TODO
#endif

//==============================================================================
#if AVRS_DEBUG
    /** Writes a string to the standard error stream.

        This is only compiled in a debug build.
    */
    #define DBG(dbgtext)              { std::string tempDbgBuf; tempDbgBuf << dbgtext; outputDebugString (tempDbgBuf); }

    /** This will always cause an assertion failure.

        This is only compiled in a debug build.

        @see sassert
    */
    #define sassertfalse              { if (juce::juce_isRunningUnderDebugger()) avrs_breakDebugger;  }

    /** Platform-independent assertion macro.

        This macro gets turned into a no-op when you're building with debugging turned off, so be
        careful that the expression you pass to it doesn't perform any actions that are vital for the
        correct behaviour of your program!

        @see sassertfalse
    */
    #define sassert(expression)       { if (! (expression)) jassertfalse; }
#else
    #define DBG(dbgtext)
    #define sassertfalse              { }
    #define sassert(a)                { }
#endif

//==============================================================================
#define AVRS_JOIN_MACRO_HELPER(a, b) a ## b
#define AVRS_STRINGIFY_MACRO_HELPER(a) #a

/** A good old-fashioned C macro concatenation helper.

    This combines two items (which may themselves be macros) into a single string,
    avoiding the pitfalls of the ## macro operator.
*/
#define AVRS_JOIN_MACRO(item1, item2) \
    AVRS_JOIN_MACRO_HELPER (item1, item2)

/** A handy C macro for stringifying any symbol, rather than just a macro parameter. */
#define AVRS_STRINGIFY(item) \
    AVRS_STRINGIFY_MACRO_HELPER (item)

//==============================================================================
/** This is a shorthand macro for declaring stubs for a class' copy constructor and operator=.

    For example, instead of:
    @code
    class MyClass
    {
    public:
        //etc...

    private:
        MyClass (const MyClass&);
        MyClass& operator= (const MyClass&);
    };
    @endcode

    You can just write:

    @code
    class MyClass
    {
    public:
        //etc...

    private:
        AVRS_DECLARE_NON_COPYABLE (MyClass)
    };
    @endcode
*/
#define AVRS_DECLARE_NON_COPYABLE(className) \
    private: \
        className (const className&) AVRS_DELETED_FUNCTION; \
        className& operator= (const className&) AVRS_DELETED_FUNCTION;

/** This macro can be added to class definitions to disable the use of new/delete to
    allocate the object on the heap, forcing it to only be used as a stack or member variable.
*/
#define AVRS_PREVENT_HEAP_ALLOCATION \
    private: \
        static void* operator new (size_t) AVRS_DELETED_FUNCTION; \
        static void operator delete (void*) AVRS_DELETED_FUNCTION;

/** This macro should be added to any class or structure that is comprised solely of static methods. */
#define AVRS_DECLARE_UTILITY_CLASS(className) \
    private: \
        className() AVRS_DELETED_FUNCTION; \
        AVRS_DECLARE_NON_COPYABLE(className)

#endif //AVRS_CORE_MACROS_H