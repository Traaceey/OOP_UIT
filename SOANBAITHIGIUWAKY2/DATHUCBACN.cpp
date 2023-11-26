#include <iostream>
using namespace std;

const int MAXN = 100; // Số lượng hệ số tối đa của đa thức

class Dathucbacn {
  int bac; // Bậc của đa thức
  int heso[MAXN+1]; // Lưu trữ hệ số của đa thức
public:
  Dathucbacn(int bac = 0) { // Hàm khởi tạo với bậc n và các hệ số ban đầu bằng 0
    this->bac = bac;
    for (int i = 0; i <= MAXN; i++)
      heso[i] = 0;
  }

  friend istream& operator>>(istream &is, Dathucbacn &p) { // Hàm nhập đa thức
    cout<<"Nhap bac cua da thuc: ";
    is>>p.bac;
    cout << "Nhap he so cua da thuc: \n";
    for (int i = p.bac; i >= 0; i--){
        cout<<"Nhap he so cua x^"<<i<<": ";
        is >> p.heso[i];
    }
    return is;
  }
friend ostream& operator<<(ostream& os, const Dathucbacn& p) {
   for(int i=p.bac; i>=0; i--) {
        if(p.heso[i] == 0) {
            continue;
        }
        else if (i == 0) {
            os << p.heso[i];
        }
        else if (i == 1) {
            if (p.heso[i] == 1) {
                os << "x";
            }
            else if (p.heso[i] == -1) {
                os << "-x";
            }
            else if (p.heso[i] > 0) {
                os<< p.heso[i] << "x";
            }
            else {
                os << "- " << -p.heso[i] << "x";
            }
        }
        else if (p.heso[i] == 1) {
            os << "x^" << i;
        }
        else if (p.heso[i] == -1) {
            os << "-x^" << i;
        }
        else if (p.heso[i] > 0) {
            os << p.heso[i] << "x^" << i;
        }
        else {
            os << "- " << -p.heso[i] << "x^" << i;
        }
        
        if(i != 0 && p.heso[i-1] != 0) {
            if (p.heso[i-1] > 0) {
                os << " + ";
            }
            else {
                os << " - ";
            }
        }
    }

    // Kiểm tra kết quả cuối cùng là dạng -x^a + b
    if (p.bac == 1 && p.heso[1] == -1 && p.heso[0] != 0) {
        os << " + " << p.heso[0];
    }

    return os;
}



friend Dathucbacn operator+(const Dathucbacn& A, const Dathucbacn& B) { // Toán tử cộng
Dathucbacn C(max(A.bac, B.bac));
for (int i = 0; i <= C.bac; i++)
C.heso[i] = A.heso[i] + B.heso[i];
return C;
}

friend Dathucbacn operator-(const Dathucbacn& A, const Dathucbacn& B){ // Toán tử trừ
Dathucbacn C(max(A.bac, B.bac));
for (int i = 0; i <= C.bac; i++)
C.heso[i] = A.heso[i] - B.heso[i];
return C;
}

friend Dathucbacn operator*(const Dathucbacn& A, const Dathucbacn& B) { // Toán tử nhân
Dathucbacn C(A.bac + B.bac);
for (int i = 0; i <= A.bac; i++) {
for (int j = 0; j <= B.bac; j++) {
C.heso[i+j] += A.heso[i] * B.heso[j];
}
}
return C;
}

friend Dathucbacn operator/(Dathucbacn& A, Dathucbacn& B) { // Toán tử chia
if (B.bac == 0 && B.heso[0] == 0) {
cout << "\nKhong the chia cho da thuc bac 0." << endl;
return Dathucbacn();
} else if (A.bac < B.bac) {
return Dathucbacn();
} else {
Dathucbacn C(A.bac - B.bac);
for (int i = A.bac; i >= B.bac; i--) {
int j = i - B.bac;
if (A.heso[i] % B.heso[B.bac] != 0) {
cout << "\nKhong the chia het." << endl;
return Dathucbacn();
}
int k = A.heso[i] / B.heso[B.bac];
C.heso[j] = k;
for (int l = 0; l <= B.bac; l++) {
A.heso[j + l] -= k * B.heso[l];
}
}
return C;
}
}

};

int main() {
Dathucbacn A, B; // Khởi tạo 2 đa thức A và B với 2 bậc khác nhau
cout << "Nhap da thuc A:\n";
cin >> A;
cout << "Da thuc da nhap: \n";
cout << A;
cout << "\nNhap da thuc B:\n";
cin >> B;
cout << "Da thuc da nhap: \n";
cout << B;
Dathucbacn C = A + B; // Tính C = A + B
cout << "\nTong hai da thuc la:\n" << C;

Dathucbacn D = A - B;
cout << "\nHieu hai da thuc la: \n";
cout << D;
Dathucbacn E = A * B;
cout << "\nTich hai da thuc la: \n";
cout << E;
Dathucbacn F = A / B;
cout << "\nThuong hai da thuc la: \n";
cout << F;
return 0;
}