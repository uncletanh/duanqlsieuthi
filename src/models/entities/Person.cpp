#include "models/entities/Person.h"

Person::Person(std::string id, std::string name, std::string phone)
    : id(id), name(name), phone(phone) {}

std::string Person::getId() const { return id; }
std::string Person::getName() const { return name; }
std::string Person::getPhone() const { return phone; }

void Person::setName(const std::string& name) { this->name = name; }
void Person::setPhone(const std::string& phone) { this->phone = phone; }//
// Created by admin on 4/10/2026.
//