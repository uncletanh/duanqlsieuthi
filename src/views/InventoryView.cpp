#include "views/InventoryView.h"
#include "utils/DateUtils.h"
#include <iostream>
#include <iomanip>
#include <limits>

// 1. Menu dành cho quản lý (Toàn quyền)
void InventoryView::displayAdminMenu() {
    std::cout << "\n==========================================";
    std::cout << "\n   [ADMIN] - HE THONG QUAN LY KHO";
    std::cout << "\n==========================================";
    std::cout << "\n1. Xem danh sach san pham dang ban";
    std::cout << "\n2. Nhap hang moi (Tich hop tinh HSD)";
    std::cout << "\n3. Cap nhat Gia & So luong";
    std::cout << "\n4. Ngung kinh doanh (Co chon ly do)";
    std::cout << "\n5. Tim kiem san pham (ID/Ten/Nganh)";
    std::cout << "\n6. Sap xep danh sach (Nganh & Ma SP)";
    std::cout << "\n7. Loc hang sap het / Het han su dung";
    std::cout << "\n8. Kiem tra do tuoi (Hang tuoi song)";
    std::cout << "\n9. THANH TOAN HOA DON (Ban hang)";
    std::cout << "\n10. DANG KY KHACH HANG MOI (The VIP)";
    std::cout << "\n11. BAO CAO TAI CHINH & LOI NHUAN";
    std::cout << "\n0. Quay lai Menu chinh";
    std::cout << "\n------------------------------------------";
    std::cout << "\nLua chon cua ban: ";
}

// 2. Menu dành cho nhân viên bán hàng (Staff)
void InventoryView::displayStaffMenu() {
    std::cout << "\n==========================================";
    std::cout << "\n   [STAFF] - THONG TIN KHO HANG";
    std::cout << "\n==========================================";
    std::cout << "\n1. Xem danh sach san pham";
    std::cout << "\n5. Tim kiem san pham";
    std::cout << "\n7. Xem hang CAN DATE (De dan tem KM)";
    std::cout << "\n8. Kiem tra do tuoi (Hang ngay)";
    std::cout << "\n9. THANH TOAN HOA DON";
    std::cout << "\n10. DANG KY KHACH HANG MOI";
    std::cout << "\n0. Quay lai Menu chinh";
    std::cout << "\n------------------------------------------";
    std::cout << "\nLua chon cua ban: ";
}

// 3. Menu dành cho nhân viên nhập kho (Purchasing)
void InventoryView::displayPurchasingMenu() {
    std::cout << "\n==========================================";
    std::cout << "\n   [PURCHASING] - QUAN LY NHAP KHO";
    std::cout << "\n==========================================";
    std::cout << "\n1. Xem danh sach san pham";
    std::cout << "\n2. Nhap hang moi (Tu dong tinh HSD)";
    std::cout << "\n3. Cap nhat Gia & So luong (Nhap kho)";
    std::cout << "\n5. Tim kiem san pham";
    std::cout << "\n6. Loc hang het han / sap het";
    std::cout << "\n0. Quay lai Menu chinh";
    std::cout << "\n------------------------------------------";
    std::cout << "\nLua chon cua ban: ";
}

// 4. Hiển thị danh sách sản phẩm
void InventoryView::displayProductList(const std::vector<Product>& products, bool isManager) {
    std::cout << "\n" << std::left << std::setw(8) << "MA SP"
              << std::setw(18) << "TEN SAN PHAM"
              << std::setw(12) << "NGANH";

    if (isManager) {
        std::cout << std::setw(10) << "GIA GOC";
    }

    std::cout << std::setw(10) << "GIA BAN"
              << std::setw(5) << "SL"
              << std::setw(12) << "HAN SD"
              << "GHI CHU\n";

    int dashWidth = isManager ? 90 : 80;
    std::cout << std::string(dashWidth, '-') << "\n";

    int count = 0;
    for (const auto& p : products) {
        if (p.isActive()) {
            std::cout << std::left << std::setw(8) << p.getId()
                      << std::setw(18) << p.getName().substr(0, 17)
                      << std::setw(12) << p.getCategory();

            if (isManager) {
                std::cout << std::setw(10) << (long long)p.getCostPrice();
            }

            std::cout << std::setw(10) << (long long)p.getPrice()
                      << std::setw(5) << p.getQuantity()
                      << std::setw(12) << p.getExpiryDate()
                      << p.getNote() << "\n";
            count++;
        }
    }
    if (count == 0) std::cout << "   (Kho trong hoac khong tim thay san pham)\n";
    std::cout << std::string(dashWidth, '-') << "\n";
}

// 5. NHẬP HÀNG MỚI - ĐÃ SỬA LỖI ĐỊNH DANH ĐỒ TƯƠI
Product InventoryView::getInputForNewProduct() {
    std::string id, name, cat, nsx, hsd, note;
    double price, costPrice;
    int qty, opt;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- NHAP HANG MOI ---" << std::endl;
    std::cout << "Ma SP: "; std::getline(std::cin, id);
    std::cout << "Ten SP: "; std::getline(std::cin, name);
    std::cout << "Nganh hang: "; std::getline(std::cin, cat);

    std::cout << "Gia Nhap (Gia von): "; std::cin >> costPrice;
    std::cout << "Gia Ban (Niem yet): "; std::cin >> price;

    std::cout << "So luong: "; std::cin >> qty;
    std::cout << "Ngay san xuat (YYYY-MM-DD): "; std::cin >> nsx;

    std::cout << "Chon kieu Han su dung:\n";
    std::cout << "1. Nhap ngay cu the (YYYY-MM-DD)\n";
    std::cout << "2. Nhap so ngay su dung (Tu dong tinh)\n";
    std::cout << "3. Hang tuoi (Dung khi con tuoi)\n";
    std::cout << "Chon: "; std::cin >> opt;

    if (opt == 1) {
        std::cout << "Nhap Han SD: "; std::cin >> hsd;
        note = "Hang dong goi";
    } else if (opt == 2) {
        int days;
        std::cout << "So ngay su dung ke tu NSX: "; std::cin >> days;
        hsd = DateUtils::addDays(nsx, days);
        note = "Hang che bien";
    } else {
        hsd = "None";
        // QUAN TRỌNG: Sửa từ "Su dung khi con tuoi" thành "tuoi"
        // để đồng bộ với thuật toán lọc tại InventoryModel
        note = "tuoi";
    }

    // Mẹo nhỏ: Để sản phẩm hiện ra ngay ở mục kiểm tra đồ tươi sau khi nhập,
    // Trang có thể sửa 'today' thành một ngày trong quá khứ (VD: "2000-01-01")
    // Nhưng đúng nghiệp vụ thì ngày kiểm định mới nhất chính là ngày nhập hàng hôm nay.
    std::string today = DateUtils::getCurrentDate();

    return Product(id, name, cat, costPrice, price, qty, true, nsx, hsd, today, note);
}

// 6. Các hàm hỗ trợ khác
int InventoryView::getInputForDeleteReason() {
    int reason;
    std::cout << "\n--- LY DO NGUNG KINH DOANH ---" << std::endl;
    std::cout << "1. San pham het han su dung\n";
    std::cout << "2. Hang bi hu hong, vo nat\n";
    std::cout << "3. Ly do khac (Doi mau ma/Ngung nhap)\n";
    std::cout << "Lua chon: "; std::cin >> reason;
    return reason;
}

void InventoryView::displayMessage(std::string message) {
    std::cout << "=> [Thong bao]: " << message << "\n";
}

void InventoryView::displayDiscountedProducts(const std::vector<Product>& products) {
    std::cout << "\n--- DANH SACH HANG CAN DATE (DI DAN TEM KHUYEN MAI) ---\n";
    std::cout << std::left << std::setw(8) << "MA SP"
              << std::setw(20) << "TEN SAN PHAM"
              << std::setw(12) << "GIA BAN"
              << std::setw(15) << "HAN SU DUNG"
              << "LOAI TEM CAN DAN\n";
    std::cout << std::string(75, '-') << "\n";

    int count = 0;
    std::string today = DateUtils::getCurrentDate();

    for (const auto& p : products) {
        int daysLeft = DateUtils::getDaysDifference(today, p.getExpiryDate());
        std::string discountTag;

        if (daysLeft <= 3) discountTag = "[GIAM 50% - MUA 1 TANG 1]";
        else if (daysLeft <= 7) discountTag = "[GIAM 20%]";
        else discountTag = "[GIAM GIA]";

        std::cout << std::left << std::setw(8) << p.getId()
                  << std::setw(20) << p.getName().substr(0, 19)
                  << std::setw(12) << (long long)p.getPrice()
                  << std::setw(15) << p.getExpiryDate()
                  << discountTag << "\n";
        count++;
    }

    if (count == 0) std::cout << "   (Tuyet voi! Khong co san pham nao can phai dan tem)\n";
    std::cout << std::string(75, '-') << "\n";
}

Customer InventoryView::getInputForNewCustomer() {
    std::string id, name, phone;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- DANG KY KHACH HANG THANH VIEN ---" << std::endl;
    std::cout << "Ma khach hang (VD: KH02): "; std::getline(std::cin, id);
    std::cout << "Ho ten khach hang: "; std::getline(std::cin, name);
    std::cout << "So dien thoai: "; std::getline(std::cin, phone);
    return Customer(id, name, phone, 0);
}

void InventoryView::displayRevenueReport(long long totalRevenue, int totalItemsSold, long long totalProfit) {
    std::cout << "\n==========================================";
    std::cout << "\n      BAO CAO TAI CHINH SIEU THI";
    std::cout << "\n==========================================";
    std::cout << "\nTong san pham da ban: " << totalItemsSold;
    std::cout << "\nTong doanh thu ban  : " << totalRevenue << " VND";
    std::cout << "\nTONG LOI NHUAN      : " << totalProfit << " VND";
    std::cout << "\n==========================================\n";
    std::cout << "Nhan Enter de tiep tuc...";
    std::cin.ignore();
    std::cin.get();
}