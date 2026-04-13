#include "utils/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::string> FileHandler::readLines(const std::string& filepath) {
    std::vector<std::string> lines;
    std::ifstream file(filepath);
    if (!file.is_open()) return lines; // Nếu chưa có file thì trả về mảng rỗng
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    file.close();
    return lines;
}

bool FileHandler::writeLines(const std::string& filepath, const std::vector<std::string>& lines) {
    std::ofstream file(filepath);
    if (!file.is_open()) return false;
    for (const auto& line : lines) file << line << "\n";
    file.close();
    return true;
}

bool FileHandler::appendLine(const std::string& filepath, const std::string& line) {
    std::ofstream file(filepath, std::ios::app);
    if (!file.is_open()) return false;
    file << line << "\n";
    file.close();
    return true;
}

std::vector<std::string> FileHandler::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) tokens.push_back(token);
    return tokens;
}//
// Created by admin on 4/10/2026.
//