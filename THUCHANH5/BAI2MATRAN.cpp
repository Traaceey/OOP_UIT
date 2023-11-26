#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;
class MaTran {
    private:
        
        int **p;
    public:
    int sd, sc;
        MaTran() {
            sd = 0;
            sc = 0;
            p = NULL;
        }
        MaTran(int d, int c) {
            sd = d;
            sc = c;
            p = new int*[sd];
            for(int i = 0; i < sd; i++) {
                p[i] = new int[sc];
            }
            for(int i = 0; i < sd; i++) {
                for(int j = 0; j < sc; j++) {
                    p[i][j] = 0;
                }
            }
        }
        MaTran(const MaTran &mt) {
            sd = mt.sd;
            sc = mt.sc;
            p = new int*[sd];
            for(int i = 0; i < sd; i++) {
                p[i] = new int[sc];
            }
            for(int i = 0; i < sd; i++) {
                for(int j = 0; j < sc; j++) {
                    p[i][j] = mt.p[i][j];
                }
            }
        }
        ~MaTran() {
            for(int i = 0; i < sd; i++) {
                delete [] p[i];
            }
            delete [] p;
        }
        void nhapMaTran() {
            do {
                cout << "Nhap so dong: ";
                cin >> sd;
            } while(sd <= 0);
            do {
                cout << "Nhap so cot: ";
                cin >> sc;
            } while(sc <= 0);
            p = new int*[sd];
            for(int i = 0; i < sd; i++) {
                p[i] = new int[sc];
            }
            for(int i = 0; i < sd; i++) {
                for(int j = 0; j < sc; j++) {
                    cout << "Nhap phan tu [" << i << "][" << j << "]: ";
                    cin >> p[i][j];
                }
            }
        }
        void xuatMaTran() {
             if(p == NULL) {
        cout << "Ma tran chua duoc khoi tao!" << endl;
        return;
    }
            for(int i = 0; i < sd; i++) {
                for(int j = 0; j < sc; j++) {
                    cout << p[i][j] << " ";
                }
                cout << endl;
            }
        }
        bool soNguyenTo(int n) {
            if(n < 2) {
                return false;
            }
            for(int i = 2; i <= sqrt(n); i++) {
                if(n % i == 0) {
                    return false;
                }
            }
            return true;
        }
        bool soChinhPhuong(int n) {
            int s = sqrt(n);
            return s*s == n;
        }
        void lietKeSoNguyenTo() {
            int dem = 0;
            for(int i = 0; i < sd; i++) {
                for(int j = 0; j < sc; j++) {
                    if(soNguyenTo(p[i][j])) {
                        cout << p[i][j] << " ";
                        dem++;
                    }
                }
            }
            if(dem == 0) {
                cout << "Khong co so nguyen to trong ma tran.";
            }
        }
        void demSoChinhPhuong() {
            int dem = 0;
            for(int i = 0; i < sd; i++) {
                for(int j = 0; j < sc; j++) {
                    if(soChinhPhuong(p[i][j])) {
                        dem++;
                    }
                }
            }
            cout << "So luong cac phan tu la so chinh phuong la: " << dem << endl;
        }
        int tinhTongSoHoanThienTrenDongK(int k) {
            if (k>sd || k<=0){
                cout<<"So dong khong hop le. Nhap lai!\n";
                return 0;
            }
            int tong = 0;
            for(int i = 0; i < sc; i++) {
                if(p[k-1][i] > 0 && p[k-1][i] != 1) {
                    int sum = 1;
                    for(int j = 2; j <= p[k-1][i]/2; j++) {
                        if(p[k-1][i] % j == 0) {
                            sum += j;
                        }
                    }
                    if(sum == p[k-1][i]) {
                        tong += sum;
                    }
                }
            }
            return tong;
        }
        bool soDoiXung(int n) {
            int ss = 0;
            int temp = n;
            while(temp > 0) {
                ss = ss*10 + temp%10;
                temp /= 10;
            }
            return ss == n;
        }
        float tinhTrungBinhCotK(int k) {
            if (k>sc || k<=0){
                cout<<"So dong khong hop le. Nhap lai!\n";
                return 0;
            }
            int tong = 0;
            int dem = 0;
            for(int i = 0; i < sd; i++) {
                if(soDoiXung(p[i][k-1])) {
                    tong += p[i][k-1];
                    dem++;
                }
            }
            return dem != 0 ? (float)tong/(float)dem : -1;
        }
        int sapXepTangDanDongK(int k) {
            if (k>sd || k<=0){
                cout<<"So dong khong hop le. Nhap lai!\n";
                return 0;
            }
            for(int i = 0; i < sc; i++) {
                for(int j = i+1; j < sc; j++) {
                    if(p[k-1][i] > p[k-1][j]) {
                        int temp = p[k-1][i];
                        p[k-1][i] = p[k-1][j];
                        p[k-1][j] = temp;
                    }
                }
            }
        }
        void phatSinhMaTranTuDong() {
     srand(time(NULL));
    cout << "Nhap vao so dong: ";
    cin >> sd;
    cout << "Nhap vao so cot: ";
    cin >> sc;
    p = new int*[sd];
    for (int i = 0; i < sd; i++) {
        p[i] = new int[sc];
        for (int j = 0; j < sd; j++) {
            p[i][j] = rand() % 100;
        }
    }
}

};

using namespace std;

int main() {
    MaTran mt;

    int chon;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Nhap ma tran" << endl;
        cout << "2. Xuat ma tran" << endl;
        cout << "3. Liet ke cac so nguyen to trong ma tran" <<endl;
        cout << "4. Dem so phan tu la so chinh phuong trong ma tran" << endl;
        cout << "5. Tinh tong cac phan tu hoan thien tren dong k" << endl;
        cout << "6. Tinh trung binh cong cac phan tu doi xung tren cot k" << endl;
        cout << "7. Sap xep cac phan tu tren dong k theo thu tu tang dan" << endl;
        cout << "8. Phat sinh ma tran tu dong" << endl;
        cout << "0. Ket thuc chuong trinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch(chon) {
            case 0:
                cout<<"Ket thuc chuong trinh!"<<endl;
                break;
            case 1: 
                mt.nhapMaTran();
                break;
            case 2:
                mt.xuatMaTran();
                break;
            case 3:
                mt.lietKeSoNguyenTo();
                break;
            case 4:
                mt.demSoChinhPhuong();
                break;
            case 5:
                int dk;
                do{
                cout << "Nhap dong k: ";
                cin >> dk;
                if (dk>mt.sd||dk<=0) {
                    cout<<"Dong khong hop le. Nhap lai\n";
                }
                } while (dk>mt.sd||dk<=0);
                cout << "Tong cac phan tu hoan thien tren dong " << dk << " la: " << mt.tinhTongSoHoanThienTrenDongK(dk) <<endl;
                break;
            case 6:
                int ck;
                do{
                cout << "Nhap cot k: ";
                cin >> ck;
                if (ck>mt.sd||ck<=0) {
                    cout<<"Dong khong hop le. Nhap lai\n";
                }
                } while (ck>mt.sd||ck<=0);
                mt.sapXepTangDanDongK(ck);
                cout << "Trung binh cong cac phan tu doi xung tren cot " << ck << " la: " << mt.tinhTrungBinhCotK(ck) << endl;
                break;
            case 7:
                int dongk;
                 do{
                cout << "Nhap dong k: ";
                cin >> dongk;
                if (dongk>mt.sd||dongk<=0) {
                    cout<<"Dong khong hop le. Nhap lai\n";
                }
                } while (dongk>mt.sd||dongk<=0);
                mt.sapXepTangDanDongK(dongk);
                cout << "Ma tran sau khi sap xep la: " <<endl;
                mt.xuatMaTran();
                break;
            case 8:
                mt.phatSinhMaTranTuDong();
                cout << "Ma tran ngau nhien duoc phat sinh la: " << endl;
                mt.xuatMaTran();
                break;
            default:
                cout<<"Lua chon khong hop le. Vui long chon lai!"<<endl;
                break;
        }
    } while(chon != 0);

    return 0;
}
//DONE