//
// Created by admin on 4/10/2026.
//

#ifndef DUANQLSIEUTHI_FILEHANDLER_H
#define DUANQLSIEUTHI_FILEHANDLER_H
#pragma once
#include <string>
#include <vector>

class FileHandler {
public:
    // Đọc toàn bộ file, trả về danh sách các dòng
    static std::vector<std::string> readLines(const std::string& filepath);

    // Ghi đè toàn bộ dữ liệu vào file
    static bool writeLines(const std::string& filepath, const std::vector<std::string>& lines);

    // Ghi thêm 1 dòng vào cuối file (Dùng để ghi Log)
    static bool appendLine(const std::string& filepath, const std::string& line);

    // Cắt 1 chuỗi thành nhiều phần tử (Dùng để tách file CSV theo dấu phẩy)
    static std::vector<std::string> split(const std::string& str, char delimiter = ',');
};
#endif //DUANQLSIEUTHI_FILEHANDLER_H