#include "views/EmployeeView.h"
#include "utils/InputUtils.h"
#include <iostream>
#include <iomanip>
#include <limits>

// 1. Menu quản lý nhân sự
void EmployeeView::displayPersonnelMenu() {
    std::cout << "\n==========================================";
    std::cout << "\n   [ADMIN] - QUẢN LÝ NHÂN VIÊN";
    std::cout << "\n==========================================";
    std::cout << "\n1. Danh sách nhân viên (Xem lương & Role)";
    std::cout << "\n2. Thêm nhân viên mới (Nạp đủ các thông tin)";
    std::cout << "\n3. Cập nhật Quyền / Mật khẩu";
    std::cout << "\n4. Khóa tài khoản (Cho nghỉ việc)";
    std::cout << "\n5. Chấm công nhân viên";
    std::cout << "\n6. Mở khóa tài khoản";
    std::cout << "\n0. Quay lại Menu chính";
    std::cout << "\n------------------------------------------\n";
}

// 2. Hiển thị danh sách: Thêm cột Giờ Công & Tổng Lương
void EmployeeView::displayEmployeeList(const std::vector<Employee>& employees) {
    std::cout << "\n" << std::left << std::setw(8) << "MÃ NV"
              << std::setw(20) << "HỌ TÊN"
              << std::setw(15) << "SĐT"
              << std::setw(12) << "CHỨC VỤ"
              << std::setw(12) << "TÌNH TRẠNG"
              << std::setw(10) << "GIỜ CÔNG"
              << "TỔNG LƯƠNG (VNĐ)\n";
    std::cout << std::string(100, '-') << "\n";

    for (const auto& emp : employees) {
        std::string status = emp.isActive() ? "Dang lam" : "Bi khoa";
        // Lương gộp = Giờ công * Lương Cơ Bản theo Giờ
        long long totalSalary = emp.getWorkingHours() * (long long)emp.getHourlySalary();

        std::cout << std::left << std::setw(8) << emp.getId()
                  << std::setw(20) << emp.getName().substr(0, 19) // Cắt bớt nếu tên dài
                  << std::setw(15) << emp.getPhone()
                  << std::setw(12) << emp.getRole()
                  << std::setw(12) << status
                  << std::setw(10) << emp.getWorkingHours()
                  << totalSalary << "\n";
    }
    std::cout << std::string(100, '-') << "\n";
}

// 3. Nhập liệu nhân viên mới
Employee EmployeeView::getInputForNewEmployee(std::string id) {
    std::string name, phone, pass, role;
    double salary;

    std::cout << "\n--- THÊM NHÂN VIÊN MỚI ---" << std::endl;
    std::cout << "(Gõ '-1' hoặc 'CANCEL' để hủy tiến trình)\n";

    name = InputUtils::getValidName("Họ tên: ");
    if (name == "CANCEL") return Employee("", "", "", "", "", false, 0, 0);

    phone = InputUtils::getValidPhone("Số điện thoại: ");
    if (phone == "CANCEL") return Employee("", "", "", "", "", false, 0, 0);

    pass = InputUtils::getValidString("Mật khẩu: ");
    if (pass == "CANCEL") return Employee("", "", "", "", "", false, 0, 0);

    role = InputUtils::getValidString("Chức vụ (Admin/Staff/Purchasing): ");
    if (role == "CANCEL") return Employee("", "", "", "", "", false, 0, 0);

    salary = InputUtils::getValidDouble("Lương cơ bản trên 1 giờ (VNĐ): ", 0.0);
    if (salary < 0) return Employee("", "", "", "", "", false, 0, 0);

    return Employee(id, name, phone, pass, role, true, salary, 0);
}

std::string EmployeeView::getInputEmployeeId() {
    return InputUtils::getValidString("Nhập mã Nhân Viên: ");
}

std::string EmployeeView::getInputNewRole() {
    return InputUtils::getValidString("Nhập chức vụ mới (Admin/Staff/Purchasing): ");
}

std::string EmployeeView::getInputNewPassword() {
    return InputUtils::getValidString("Nhập mật khẩu mới: ");
}

void EmployeeView::displayMessage(std::string message) {
    std::cout << "=> [Thông báo]: " << message << "\n";
}