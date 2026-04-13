#ifndef DUANQLSIEUTHI_STRINGUTILS_H
#define DUANQLSIEUTHI_STRINGUTILS_H

#pragma once
#include <string>

class StringUtils {
public:
    // Chuyển toàn bộ chuỗi UTF-8 sang chữ thường (Dùng cho Tìm kiếm - Ignore Case)
    static std::string toLowerCase(const std::string& input);

    // Chuyển chuỗi UTF-8 sang định dạng Viết hoa chữ cái đầu (Title Case)
    // VD: "ngUYỄn văN a" -> "Nguyễn Văn A"
    static std::string toTitleCase(const std::string& input);
};

#endif //DUANQLSIEUTHI_STRINGUTILS_H
