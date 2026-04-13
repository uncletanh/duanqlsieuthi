//
// Created by admin on 4/10/2026.
//

#ifndef DUANQLSIEUTHI_PERSON_H
#define DUANQLSIEUTHI_PERSON_H
#pragma once
#include <string>

class Person {
protected: // Dùng protected để các class con có thể sử dụng được
    std::string id;
    std::string name;
    std::string phone;

public:
    Person(std::string id, std::string name, std::string phone);
    virtual ~Person() = default; // Luôn cần Destructor ảo khi dùng kế thừa

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getPhone() const;

    // Setters
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
};
#endif //DUANQLSIEUTHI_PERSON_H