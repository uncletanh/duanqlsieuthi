//
// Created by admin on 4/10/2026.
//

#ifndef DUANQLSIEUTHI_PRODUCT_H
#define DUANQLSIEUTHI_PRODUCT_H

#pragma once
#include <string>

class Product {
private:
    // --- Nhóm thông tin cơ bản ---
    std::string id;
    std::string name;
    std::string category;
    double costPrice;           // <== THÊM MỚI: Giá nhập gốc (Giá vốn)
    double price;               // Giá bán ra cho khách
    int quantity;
    bool active;

    // --- Nhóm thông tin quản lý hạn dùng ---
    std::string productionDate; // Ngày sản xuất (YYYY-MM-DD)
    std::string expiryDate;     // Hạn sử dụng (Ngày cụ thể hoặc "None")
    std::string lastChecked;    // Ngày nhân viên kiểm tra độ tươi gần nhất
    std::string note;           // Ghi chú (VD: "Hang dong goi", "Su dung khi con tuoi")

public:
    // CẬP NHẬT: Constructor đầy đủ 11 tham số (thêm costPrice vào trước price)
    Product(std::string id, std::string name, std::string category, double costPrice, double price, int quantity,
            bool active, std::string nsx, std::string hsd, std::string lastCheck, std::string note);

    // --- Nhóm Getters (Lấy thông tin) ---
    std::string getId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getCostPrice() const; // <== THÊM MỚI: Lấy giá gốc
    double getPrice() const;
    int getQuantity() const;
    bool isActive() const;

    std::string getProductionDate() const;
    std::string getExpiryDate() const;
    std::string getLastChecked() const;
    std::string getNote() const;

    // --- Nhóm Setters (Sửa thông tin) ---
    void setName(const std::string& newName);
    void setCategory(const std::string& newCategory);
    void setCostPrice(double newCostPrice); // <== THÊM MỚI: Cập nhật giá gốc
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void setActive(bool status);

    void setProductionDate(const std::string& nsx);
    void setExpiryDate(const std::string& hsd);
    void setLastChecked(const std::string& checkDate);
    void setNote(const std::string& newNote);
};

#endif //DUANQLSIEUTHI_PRODUCT_H