#include "views/EmployeeView.h"
#include <iostream>
#include <iomanip>
#include <limits>

// 1. Menu quản lý nhân sự
void EmployeeView::displayPersonnelMenu() {
    std::cout << "\n==========================================";
    std::cout << "\n   [ADMIN] - QUAN LY NHAN VIEN";
    std::cout << "\n==========================================";
    std::cout << "\n1. Danh sach nhan vien (Xem luong & Role)";
    std::cout << "\n2. Them nhan vien moi (Nap du cac thong tin)";
    std::cout << "\n3. Cap nhat Quyen / Mat khau";
    std::cout << "\n4. Khoa tai khoan (Cho nghi viec)";
    std::cout << "\n5. Cham cong nhan vien";
    std::cout << "\n0. Quay lai Menu chinh";
    std::cout << "\n------------------------------------------";
    std::cout << "\nLua chon cua ban: ";
}

// 2. Hiển thị danh sách: Thêm cột Giờ Công & Tổng Lương
void EmployeeView::displayEmployeeList(const std::vector<Employee>& employees) {
    std::cout << "\n" << std::left << std::setw(8) << "MA NV"
              << std::setw(18) << "HO TEN"
              << std::setw(12) << "CHUC VU"
              << std::setw(10) << "LUONG/H"
              << std::setw(8)  << "GIO"
              << std::setw(15) << "TONG LUONG"
              << std::setw(12) << "TRANG THAI" << "\n";
    std::cout << std::string(85, '-') << "\n";

    for (const auto& emp : employees) {
        std::string status = emp.isActive() ? "Dang lam" : "Da nghi";
        std::cout << std::left << std::setw(8) << emp.getId()
                  << std::setw(18) << emp.getName()
                  << std::setw(12) << emp.getRole()
                  << std::setw(10) << (long long)emp.getHourlySalary()
                  << std::setw(8)  << emp.getWorkingHours()
                  << std::setw(15) << emp.calculateTotalSalary()
                  << std::setw(12) << status << "\n";
    }
    std::cout << std::string(85, '-') << "\n";
}

// 3. Nhập liệu nhân viên mới
Employee EmployeeView::getInputForNewEmployee() {
    std::string id, name, phone, pass, role;
    double salary;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- THEM NHAN VIEN MOI ---" << std::endl;
    std::cout << "Ma NV moi: "; std::getline(std::cin, id);
    std::cout << "Ho ten: "; std::getline(std::cin, name);
    std::cout << "So dien thoai: "; std::getline(std::cin, phone);
    std::cout << "Mat khau: "; std::getline(std::cin, pass);
    std::cout << "Chuc vu (Admin/Staff/Purchasing): "; std::getline(std::cin, role);

    std::cout << "Muc luong moi gio (hourly rate): ";
    std::cin >> salary;

    return Employee(id, name, phone, pass, role, true, salary, 0);
}

std::string EmployeeView::getInputEmployeeId() {
    std::string id;
    std::cout << "Nhap Ma NV can thuc hien: ";
    std::cin >> id;
    return id;
}

std::string EmployeeView::getInputNewRole() {
    std::string role;
    std::cout << "Nhap Chuc vu moi (Admin/Staff/Purchasing): ";
    std::cin >> role;
    return role;
}

std::string EmployeeView::getInputNewPassword() {
    std::string pass;
    std::cout << "Nhap Mat khau moi: ";
    std::cin >> pass;
    return pass;
}

void EmployeeView::displayMessage(std::string message) {
    std::cout << "=> " << message << "\n";
}