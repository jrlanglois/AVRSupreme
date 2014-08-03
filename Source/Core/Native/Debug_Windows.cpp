#if AVRS_P_WINDOWS
#include <Windows.h>
#include <debugapi.h>

void outputDebugString (const std::wstring& text)
{
    OutputDebugString (text.c_str());
}

void outputDebugString (const std::string& text)
{
    outputDebugString (std::wstring (text.begin(), text.end()));
}

bool AVRS_CALLTYPE isRunningUnderDebugger()
{
    return IsDebuggerPresent() != FALSE;
}
#endif