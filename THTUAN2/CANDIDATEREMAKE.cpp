// kiem tra ngay thang nam hop le
// testcandidate dung con tro mang dong.
// thiet lap n = 0; con tro tro toi NULL
// 
#include <iostream>
#include <string>
using namespace std;

class Ngaythangnam{
private:
    int d, m, y;

public:
    Ngaythangnam(int d, int m, int y){
        this->d = d;
        this->m = m;
        this->y = y;
    }

    void Setd(int d){
        this->d = d;
    }

    void Setm(int m){
        this->m = m;
    }

    void Sety(int y){
        this->y = y;
    }

    int getd(){
        return d;
    }

    int getm(){
        return m;
    }

    int gety(){
        return y;
    }

    bool Kiemtranamnhuan(int y){
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
            return true;
        }
        return false;
    }

    int Ngaytrongthang(int m, int y){
        int maxday;
        switch (m){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                maxday = 31;
                break;
            case 4: case 6: case 9: case 11:
                maxday = 30;
                break;
            case 2:
                if (Kiemtranamnhuan(y)){
                    maxday = 29;
                }
                else{
                    maxday = 28;
                }
                break;
        }
        return maxday;
    }

    bool KiemtraNgayhople(int d, int m, int y){
        bool Kiemtra = true;
        if (!(y > 0 && m >= 1 && m <= 12 && d >= 1 && d <= Ngaytrongthang(m, y))){
            Kiemtra = false;
        }
        return Kiemtra;
    }

    void Nhap(int d, int m, int y ){
        do {
            cout << "Nhap vao ngay thang nam sinh: ";
            cin >> d >> m >> y;
        } while (!KiemtraNgayhople(d, m, y));
    }

    void Xuat(){
        cout << "Ngay thang nam sinh: " << d << "/" << m << "/" << y;
    }
};
		
class Candidate {
    private:
        string ma, ten ;
        float toan, van, anh;
		int d,m,y;
        Ngaythangnam *ngaysinh;
    public:
        Candidate(string ma = "", string ten = "",  float toan = 0, float van = 0, float anh = 0) {
            this->ma = ma;
            this->ten = ten;
            this->toan = toan;
            this->van = van;
            this->anh = anh;
        }

        float Tongdiem() {
            return toan + van + anh;
        }

        void Xuat() {
            cout << "Ma thi sinh: " << ma << endl;
            cout << "Ten thi sinh: " << ten << endl;
            ngaysinh->Xuat();
            cout << "Diem toan: " << toan << endl;
            cout << "Diem van: " << van << endl;
            cout << "Diem anh: " << anh << endl;
            cout << "Tong diem: " << Tongdiem() << endl;
        }
};

class TestCandidate {
    private:
        Candidate *ds;
        Ngaythangnam *ngaysinh;
        int n;
        
    public:
        TestCandidate() {
            cout << "Nhap so luong thi sinh: ";
            cin >> n;
            ds = new Candidate[n];
            for (int i = 0; i < n; i++) {
                string ma, ten;
                int d,m,y;
                float toan, van, anh;
                cout << "Nhap thong tin thi sinh thu " << i+1 << endl;
                cout << "Ma thi sinh: ";
                cin >> ma;
                cout << "Ten thi sinh: ";
                cin.ignore();
                getline(cin, ten);
                ngaysinh->Nhap();
               do {cout << "Diem toan: ";
                cin >> toan;} while (toan<0|| toan>10);
               do { cout << "Diem van: ";
                cin >> van;} while (van<0 || van>10);
               do {cout << "Diem anh: ";
                cin >> anh;} while (anh<0||anh>10);
                ds[i] = Candidate(ma, ten, toan, van, anh);
            }
        
        }
        void Xuat() {
            cout << "------------DANH SACH THI SINH CO DIEM LON HON 15----------- " << endl;
            for (int i = 0; i < n; i++) {
                if (ds[i].Tongdiem() > 15) {
                    ds[i].Xuat();
                }
            }
        }
};
int main() {
    TestCandidate tc;
    //tc.Xuat();
    return 0;
}

