#include "models/entities/Product.h"

// 1. CẬP NHẬT CONSTRUCTOR: Nhận đầy đủ 11 thuộc tính (thêm costPrice ở vị trí số 4)
Product::Product(std::string id, std::string name, std::string category, double costPrice, double price, int quantity,
                 bool active, std::string nsx, std::string hsd, std::string lastCheck, std::string note)
    : id(id), name(name), category(category), costPrice(costPrice), price(price), quantity(quantity),
      active(active), productionDate(nsx), expiryDate(hsd), lastChecked(lastCheck), note(note) {}

// --- Nhóm hàm Lấy thông tin (Getters) ---
std::string Product::getId() const { return id; }
std::string Product::getName() const { return name; }
std::string Product::getCategory() const { return category; }

// <== THÊM MỚI: Trả về giá nhập
double Product::getCostPrice() const { return costPrice; }

double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
bool Product::isActive() const { return active; }

// Getters cho quản lý hạn dùng và kiểm định
std::string Product::getProductionDate() const { return productionDate; }
std::string Product::getExpiryDate() const { return expiryDate; }
std::string Product::getLastChecked() const { return lastChecked; }
std::string Product::getNote() const { return note; }

// --- Nhóm hàm Cập nhật thông tin (Setters) ---
void Product::setName(const std::string& newName) { name = newName; }
void Product::setCategory(const std::string& newCategory) { category = newCategory; }

// <== THÊM MỚI: Cập nhật giá nhập mới
void Product::setCostPrice(double newCostPrice) { costPrice = newCostPrice; }

void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
void Product::setActive(bool status) { active = status; }

// Setters cho quản lý hạn dùng và kiểm định
void Product::setProductionDate(const std::string& nsx) { productionDate = nsx; }
void Product::setExpiryDate(const std::string& hsd) { expiryDate = hsd; }
void Product::setLastChecked(const std::string& checkDate) { lastChecked = checkDate; }
void Product::setNote(const std::string& newNote) { note = newNote; }