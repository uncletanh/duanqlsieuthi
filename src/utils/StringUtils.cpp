#include "utils/StringUtils.h"
#include <locale>
#include <codecvt>
#include <cwctype>

std::string StringUtils::toLowerCase(const std::string& input) {
    try {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(input);
        for (wchar_t& c : wide) {
            c = std::towlower(c);
        }
        return converter.to_bytes(wide);
    } catch (...) {
        return input; // Fallback
    }
}

std::string StringUtils::toTitleCase(const std::string& input) {
    try {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(input);
        bool newWord = true;
        for (wchar_t& c : wide) {
            if (std::iswspace(c)) {
                newWord = true;
            } else if (newWord) {
                c = std::towupper(c);
                newWord = false;
            } else {
                c = std::towlower(c);
            }
        }
        return converter.to_bytes(wide);
    } catch (...) {
        return input; // Fallback
    }
}
