#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu_so; // tử số
    int mau_so; // mẫu số

public:
    // Hàm khởi tạo
    PhanSo() {
        tu_so = 0;
        mau_so = 1;
    }
    PhanSo(int ts){
        tu_so=ts;
        mau_so=1;
    }

    PhanSo(int ts, int ms = 1) {
        tu_so = ts;
        mau_so = ms;
        rut_gon();
    }

    // Hàm nhập phân số từ bàn phím
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu_so;
        cout << "Nhap mau so: ";
        cin >> mau_so;
        rut_gon();
    }

    // Hàm xuất phân số ra màn hình
    void xuat() const {
        cout << tu_so << "/" << mau_so;
    }

    // Hàm tìm ước chung lớn nhất của 2 số
    int UCLN(int a, int b) const {
        a = abs(a);
        b = abs(b);
        if (b == 0) {
            return a;
        }
        return UCLN(b, a % b);
    }

    // Hàm rút gọn phân số
    void rut_gon() {
        int ucln = UCLN(tu_so, mau_so);
        tu_so /= ucln;
        mau_so /= ucln;
        if (mau_so < 0) {
            tu_so = -tu_so;
            mau_so = -mau_so;
        }
    }

    // Toán tử cộng 2 phân số
    PhanSo operator+(const PhanSo& ps) const {
        int ts = tu_so*ps.mau_so + ps.tu_so*mau_so;
        int ms = mau_so*ps.mau_so;
        return PhanSo(ts, ms);
    }
};

int main() {
    PhanSo a;
    PhanSo b(1,2);
    PhanSo c(3);
    a=b+c;
    a.xuat();
    return 0;
}
