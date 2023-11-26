#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class HocSinh {
private:
    string hoTen;
    float diemVan;
    float diemToan;

public:
    HocSinh() {
        hoTen = "";
        diemVan = 0;
        diemToan = 0;
    }
    HocSinh(string hoTen_, float diemVan_, float diemToan_) {
        hoTen = hoTen_;
        diemVan = diemVan_;
        diemToan = diemToan_;
    }
    void nhap( ) {
        cout << "Nhap ho ten: " ; getline(cin,hoTen);
       do {
	   cout << "Nhap diem van: "; cin>>diemVan;} while (diemVan<0 || diemVan>10);
       do {
	   cout << "Nhap diem toan: " ; cin>>diemToan; }while (diemToan<0|| diemToan>10);
    }
    void xuatHocSinh() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem van: " << diemVan << endl;
        cout << "Diem toan: " << diemToan << endl;
}
    float tinhDTB() {
        return (diemVan + diemToan) / 2;
    }
    void xepLoai() {
        float dtb = tinhDTB();
        cout<<"Diem trung binh la: "<<fixed<<setprecision(2)<<dtb<<endl;
        if (dtb >= 8.0) {
            cout<< "Loai Gioi";
        } else if (dtb >= 7.0) {
            cout<< "Loai Kha";
        } else if (dtb >= 5.0) {
           cout<< "Loai Trung binh";
        } else {
            cout<< "Loai Yeu";
        }
    }
};

int main() {
    HocSinh hs;
    hs.nhap(); 
    hs.xuatHocSinh();
	hs.xepLoai();
	return 0;
}

