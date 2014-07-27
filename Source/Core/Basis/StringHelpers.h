#ifndef AVRS_CORE_STRING_HELPERS_H
#define AVRS_CORE_STRING_HELPERS_H

class StringHelpers
{
public:
    //==============================================================================
    template<typename ValueType>
    static std::string toString (ValueType value)
    {
        std::ostringstream ws;
        ws << value;
        return ws.str();
    }

    template<>
    static std::string toString (std::wstring text)
    {
        return std::string (text.begin(), text.end());
    }

    //==============================================================================
    template<typename ValueType>
    static std::wstring toWideString (ValueType value)
    {
        std::wostringstream ws;
        ws << value;
        return ws.str();
    }

    template<>
    static std::wstring toWideString (std::string text)
    {
        return std::wstring (text.begin(), text.end());
    }

private:
    //==============================================================================
    AVRS_DECLARE_UTILITY_CLASS (StringHelpers)
};

#endif //AVRS_CORE_STRING_HELPERS_H