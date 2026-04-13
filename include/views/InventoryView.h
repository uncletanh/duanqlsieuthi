#ifndef DUANQLSIEUTHI_INVENTORYVIEW_H
#define DUANQLSIEUTHI_INVENTORYVIEW_H

#pragma once
#include "models/entities/Product.h"
#include "models/entities/Customer.h"
#include <vector>
#include <string>

class InventoryView {
public:
    // Menu điều khiển cho 3 Role (Admin, Staff, Purchasing)
    void displayAdminMenu();
    void displayStaffMenu();
    void displayPurchasingMenu();

    // CẬP NHẬT: Hiển thị danh sách (Có thêm bool isManager để ẩn/hiện Giá Nhập)
    void displayProductList(const std::vector<Product>& products, bool isManager = false);

    // CẬP NHẬT: Nhập hàng mới (Sẽ yêu cầu nhập đủ 11 tham số)
    Product getInputForNewProduct();

    // Hàm chọn lý do khi hủy hàng
    int getInputForDeleteReason();

    void displayMessage(std::string message);

    // --- Tính năng Khuyến mãi cận Date ---
    void displayDiscountedProducts(const std::vector<Product>& products);

    // ==========================================
    // MỚI: Quản lý Khách hàng & Báo cáo
    // ==========================================

    // 1. Lấy thông tin từ bàn phím để đăng ký khách hàng mới
    Customer getInputForNewCustomer();

    // 2. CẬP NHẬT: Hiển thị bảng tổng kết doanh thu & LỢI NHUẬN
    void displayRevenueReport(long long totalRevenue, int totalItemsSold, long long totalProfit);
};

#endif