#include <iostream>
#include <cmath>

using namespace std;

class Mang1C {
  private:
    int n;
    int *a;
  public:
    Mang1C() {
        n = 0;
        a = nullptr;
        srand(time(NULL));
    }

    Mang1C(int n) {
        this->n = n;
        a = new int[n];
    }

    Mang1C(const Mang1C &b) {
        n = b.n;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = b.a[i];
        }
    }

    ~Mang1C() {
        if (a != nullptr) {
            delete[] a;
        }
    }

    void nhap() {
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan tu thu " << i + 1 << ": ";
            cin >> a[i];
        }
    }

    void xuat() {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) {
              cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    bool KiemTraSoNguyenTo(int number) {
        if (number < 2) return false;
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    void lietKeSoNguyenTo() {
        cout << "Cac so nguyen to trong mang la: ";
        bool foundPrime = false;
        for (int i = 0; i < n; i++) {
            if (KiemTraSoNguyenTo(a[i])) {
                cout << a[i] << " ";
                foundPrime = true;
            }
        }
        if (!foundPrime) {
            cout << "Khong co";
        }
        cout << endl;
    }

    bool KiemTraSoChinhPhuong(int number) {
        int root = sqrt(number);
        return root * root == number;
    }

    void demSoChinhPhuong() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (KiemTraSoChinhPhuong(a[i])) {
                count++;
            }
        }
        cout << "Co " << count << " so chinh phuong trong mang: \n" ;
        for (int i=0; i<n; i++){
            if (KiemTraSoChinhPhuong(a[i])) cout<<a[i]<<" "<<endl;
        }
    }
    
    bool KiemTraSoHoanThien(int number) {
        if (number < 2) return false;
        int sum = 1;
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) {
                sum += i;
                if (i != number/i) {
                    sum += number/i;
                }
            }
        }
        return sum == number;
    }

    void tinhTongSoHoanThien() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (KiemTraSoHoanThien(a[i])) {
                sum += a[i];
            }
        }
        cout << "Tong cac so hoan thien trong mang la: " << sum << endl;
    }

    bool KiemTraSoDoiXung(int number) {
        int reverseNumber = 0, originalNumber = number;
        while (originalNumber != 0) {
            reverseNumber = reverseNumber * 10 + originalNumber % 10;
            originalNumber /= 10;
        }
        return number == reverseNumber;
    }

    void tinhTBCongSoDoiXung() {
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (KiemTraSoDoiXung(a[i])) {
                sum += a[i];
                count++;
            }
        }
        cout << "TB cong cac so doi xung la: " << (count > 0 ? (double) sum / count : 0) << endl;
    }

    bool KiemTraSoLe() {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                return false;
            }
        }
        return true;
    }

    void kiemTraToanLe() {
        if (KiemTraSoLe()) {
            cout << "Mang toan le" << endl;
        } else {
            cout << "Mang khong toan le" << endl;
        }
    }

    void timMinChan() {
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0 && a[i] < min) {
                min = a[i];
            }
        }
        if (min == INT_MAX) {
            cout << "Khong co so chan trong mang" << endl;
        } else {
            cout << "So chan be nhat trong mang la: " << min << endl;
        }
    }

    void sapXepTang() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

    void sapXepGiam() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

    void xoaPhanTu(int pos) {
        if (pos < 0 || pos >= n) {
            cout << "Vi tri khong hop le" << endl;
            return;
        }
        int *newA = new int[n - 1];
        for (int i = 0, j = 0; i < n; i++) {
            if (i != pos) {
                newA[j++] = a[i];
            }
        }
        delete[] a;
        a = newA;
        n--;
    }

    void themPhanTu(int pos, int value) {
        if (pos < 0 || pos > n) {
            cout << "Vi tri khong hop le" << endl;
            return;
        }
        int *newA = new int[n + 1];
        for (int i = 0, j = 0; i < n; i++, j++) {
            if (j == pos) {
                newA[j] = value;
                i--;
            } else {
                newA[j] = a[i];
            }
        }
        if (pos == n) {
            newA[pos] = value;
        }
        delete[] a;
        a = newA;
        n++;
    }

    void timKiem(int value) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == value) {
cout << "Gia tri " << value << " xuat hien tai vi tri " << i << endl;
found = true;
}
}
if (!found) {
cout << "Khong tim thay gia tri " << value << " trong mang" << endl;
}
}
    void phatSinhTuDong(int n) {
        if (a != nullptr) {
            delete[] a; // Giải phóng bộ nhớ cũ nếu có
        }
        a = new int[n]; // Cấp phát bộ nhớ động cho mảng
        for (int i = 0; i < n; i++) {
            a[i] = rand(); // Phát sinh ngẫu nhiên giá trị các phần tử
            cout<<a[i]<<" ";
        }
        this->n = n;
    }
};
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    Mang1C a(n);

    int choice;
    do {
        cout << "\n===========CHUONG TRINH LAM VIEC VOI MANG 1 CHIEU===========" << endl;
        cout << "Menu: " << endl;
        cout << "1. Nhap mang" << endl;
        cout << "2. Xuat mang" <<endl;
        cout << "3. Liet ke so nguyen to" << endl;
        cout << "4. Dem so chinh phuong" << endl;
        cout << "5. Tinh tong so hoan thien" << endl;
        cout << "6. Tinh trung binh cong so doi xung" << endl;
        cout << "7. Kiem tra toan le" << endl;
        cout << "8. Tim gia tri nho nhat chan" << endl;
        cout << "9. Sap xep mang tang dan" << endl;
        cout << "10. Sap xep mang giam dan" << endl;
        cout << "11. Xoa phan tu tai vi tri bat ky" << endl;
        cout << "12. Them phan tu vao vi tri bat ky" << endl;
        cout << "13. Tim kiem phan tu" << endl;
        cout << "14. Phat sinh mang moi" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Da thoat chuong trinh\n";
                break;
            case 1:
                a.nhap();
                break;
            case 2:
                a.xuat();
                break;
            case 3:
                a.lietKeSoNguyenTo();
                break;
            case 4:
                a.demSoChinhPhuong();
                break;
            case 5:
                a.tinhTongSoHoanThien();
                break;
            case 6:
                a.tinhTBCongSoDoiXung();
                break;
            case 7:
                a.kiemTraToanLe();
                break;
            case 8:
                a.timMinChan();
                break;
            case 9:
                cout << "Mang sau khi sap xep tang: ";
                a.sapXepTang();
                a.xuat();
                break;
            case 10:
                cout << "Mang sau khi sap xep giam: ";
                a.sapXepGiam();
                a.xuat();
                break;
            case 11:
                int xoa;
                cout << "Nhap vi tri phan tu can xoa: ";
                cin >> xoa;
                a.xoaPhanTu(xoa);
                cout << "Mang sau khi xoa phan tu tai vi tri " << xoa << ": ";
                a.xuat();
                break;
            case 12:
                int pos, them;
                cout << "Nhap vi tri can them: ";
                cin >> pos;
                cout << "Nhap phan tu can them: ";
                cin >> them;
                a.themPhanTu(pos, them);
                cout << "Mang sau khi them phan tu " << them << " vao vi tri " << pos << ": ";
                a.xuat();
                break;
            case 13:
                int tim;
                cout << "Nhap gia tri can tim: ";
                cin >> tim;
                a.timKiem(tim);
                break;
            case 14:
                int add;
                cout << "Nhap so phan tu cua mang phat sinh them: ";
                cin >> add;
                cout << "Mang phat sinh them la: ";
                a.phatSinhTuDong(add);
                a.xuat();
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai" << endl;
        }

    } while (choice != 0);

    return 0;
}
