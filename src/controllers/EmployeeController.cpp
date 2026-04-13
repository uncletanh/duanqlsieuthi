#include "controllers/EmployeeController.h"
#include <iostream>
#include <string>

// 1. Constructor: Nhận tham chiếu để dùng chung dữ liệu với AuthModel tổng
EmployeeController::EmployeeController(AuthModel& m, EmployeeView& v)
    : model(m), view(v) {}

// 2. Vòng lặp điều hướng chính
void EmployeeController::run() {
    int choice;
    do {
        view.displayPersonnelMenu(); // Hiện Menu quản lý nhân viên

        // Kiểm tra lỗi nhập liệu số
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: // Xem danh sách
                view.displayEmployeeList(model.getAllEmployees());
                break;

            case 2: // Thêm nhân viên mới
                model.addEmployee(view.getInputForNewEmployee());
                view.displayMessage("Da them nhan vien moi vao he thong!");
                break;

            case 3: { // Cập nhật Quyền / Mật khẩu
                std::string id = view.getInputEmployeeId();

                // --- FIX LỖI NHÂN VIÊN MA ---
                bool found = false;
                for (const auto& emp : model.getAllEmployees()) {
                    if (emp.getId() == id) { found = true; break; }
                }

                if (!found) {
                    view.displayMessage("LOI: Khong tim thay nhan vien ma " + id);
                    break; // Dừng luôn, không cho nhập linh tinh nữa
                }
                // ----------------------------

                std::string role = view.getInputNewRole();
                std::string pass = view.getInputNewPassword();
                model.updateEmployee(id, role, pass);
                view.displayMessage("Da cap nhat thong tin nhan vien " + id);
                break;
            }

            case 4: { // Khóa tài khoản (Xóa mềm)
                std::string id = view.getInputEmployeeId();

                // --- FIX LỖI NHÂN VIÊN MA ---
                bool found = false;
                for (const auto& emp : model.getAllEmployees()) {
                    if (emp.getId() == id) { found = true; break; }
                }

                if (!found) {
                    view.displayMessage("LOI: Khong tim thay nhan vien ma " + id);
                    break;
                }
                // ----------------------------

                model.deleteEmployee(id);
                view.displayMessage("Da khoa tai khoan nhan vien " + id);
                break;
            }

            // === THÊM MỚI: PHÍM 5 - CHẤM CÔNG NHÂN VIÊN ===
            case 5: {
                std::string id;
                int hours;
                std::cout << "\n--- CHAM CONG NHAN VIEN ---\n";
                std::cout << "Nhap Ma NV: ";
                std::cin >> id;

                // Kiểm tra xem NV có tồn tại không
                bool found = false;
                for (const auto& emp : model.getAllEmployees()) {
                    if (emp.getId() == id) { found = true; break; }
                }

                if (!found) {
                    view.displayMessage("LOI: Khong tim thay nhan vien ma " + id);
                } else {
                    std::cout << "Nhap so gio lam them: ";
                    std::cin >> hours;

                    // Gọi hàm cập nhật giờ công từ Bộ não (Sẽ viết ở bước sau)
                    model.updateWorkingHours(id, hours);
                    view.displayMessage("Cham cong thanh cong! Da cong them " + std::to_string(hours) + " gio.");
                }
                break;
            }

            case 0:
                view.displayMessage("Dang quay lai Menu chinh...");
                break;

            default:
                view.displayMessage("Lua chon khong hop le!");
                break;
        }
    } while (choice != 0);
}