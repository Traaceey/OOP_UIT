#include <iostream>
using namespace std;

class DaThucBacNhat {
private:
    float a, b; // hệ số a và b của đa thức

public:
    // Hàm khởi tạo với luôn khác 0
    DaThucBacNhat(float a, float b) {
        this->a = a;
        this->b = b;
    }

    // Hàm nhập đa thức từ bàn phím
    void Nhap(){
        cout << "Nhap he so a: ";
        cin >> a;
        while (a == 0) {
            cout << "He so a phai khac 0. Nhap lai: ";
            cin >> a;
        }
        cout << "Nhap he so b: ";
        cin >> b;
    }

    // Hàm xác định giá trị đa thức tại x
    float tinh_gia_tri(float x) const {
        return a*x+b;
    }

    // Hàm tìm nghiệm đa thức
    float tim_nghiem() const {
        return -b/a;
    }

    // Toán tử cộng 2 đa thức bậc nhất
    DaThucBacNhat operator+(const DaThucBacNhat& dt) const {
        return DaThucBacNhat(a+dt.a, b+dt.b);
    }

    // Hàm xuất đa thuc
    void Xuat() const {
        if (a == 1) {
            cout << "x";
        } else if (a == -1) {
            cout << "-x";
        } else {
            cout << a << "x";
        }
        if (b > 0) {
            cout << " + " << b;
        } else if (b < 0) {
            cout << " - " << -b;
        }
    }
};

int main() {
    DaThucBacNhat F1(0, 0);
    cout << "Nhap thong tin cho F1(x): ";
    F1.Nhap();
    cout << "F1(x) = ";
    F1.Xuat();
    cout << endl;

    float x = 0;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri cua F1 tai x = " << x << " la: " << F1.tinh_gia_tri(x) << endl;
    cout << "Nghiem cua F1 la: " << F1.tim_nghiem() << endl;

    DaThucBacNhat F2(0, 0);
    cout << "Nhap thong tin cho F2(x): ";
    F2.Nhap();
    cout << "F2(x) = ";
    F2.Xuat();
    cout << endl;

    DaThucBacNhat Tong = F1 + F2;
    cout << "Tong 2 da thuc F1 va F2 la: ";
    Tong.Xuat();
    cout << endl;

    return 0;
}
