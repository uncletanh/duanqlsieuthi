#include "models/entities/Customer.h"

// Gọi constructor của class cha (Person) để nó tự gán ID, Name, Phone
Customer::Customer(std::string id, std::string name, std::string phone, int points)
    : Person(id, name, phone), points(points) {
    updateLevel();
}

// Logic phân hạng thành viên
void Customer::updateLevel() {
    if (points >= 1000) memberLevel = "VANG (VIP)";
    else if (points >= 500) memberLevel = "BAC";
    else memberLevel = "DONG";
}

// Trả về thông tin riêng của Customer
int Customer::getPoints() const { return points; }
std::string Customer::getMemberLevel() const { return memberLevel; }

// Khi mua hàng, gọi hàm này để cộng điểm và tự nâng hạng
void Customer::addPoints(int p) {
    points += p;
    updateLevel();
}