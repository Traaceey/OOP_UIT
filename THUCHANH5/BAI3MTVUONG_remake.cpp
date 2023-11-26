#include <iostream>
#include <algorithm>

using namespace std;

class MaTranVuong {
    private:
        int n;
        int **p;

    public:
        MaTranVuong() {
            n = 0;
            p = NULL;
        }

        MaTranVuong(int n) {
            this->n = n;
            p = new int*[n];
            for(int i = 0; i < n; i++){
                p[i] = new int[n];
            }
        }

        MaTranVuong(const MaTranVuong &maTranVuong) {
            n = maTranVuong.n;
            p = new int*[n];
            for(int i = 0; i < n; i++) {
                p[i] = new int[n];
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    p[i][j] = maTranVuong.p[i][j];
                }
            }
        }

        ~MaTranVuong() {
            for(int i = 0; i < n; i++) {
                delete[] p[i];
            }
            delete[] p;
        }

        void nhapMaTranVuong() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << "Nhap phan tu tai [" << i << "][" << j << "]: ";
                    cin >> p[i][j];
                }
            }
        }

        void xuatMaTranVuong() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << p[i][j] << "\t";
                }
                cout << endl;
            }
        }

        void lietKePhanTuLeTrenDuongCheoChinh() {
            for(int i = 0; i < n; i++) {
                if(p[i][i] % 2 != 0) {
                    cout << p[i][i] << "\t";
                }
            }
            cout << endl;
        }

        int demPhanTuCoSoCuoiLa3TrenDuongCheoPhu() {
            int count = 0;
            for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) {
                if(p[i][j] % 10 == 3) {
                    count++;
                }
            }
            return count;
        }

        bool tonTaiPhanTuAmTrenNuaMangVuongTrenDuongCheoChinh() {
            for(int i = 0; i < n-1; i++) {
                for(int j = 0; j < i; j++) {
                    if(p[i][j] < 0) {
                        return true;
                    }
                }
            }
            return false;
        }

        // Tìm phần tử chẵn đầu tiên ở nửa mảng vuông phía dưới đường chéo phụ của ma trận
        int timPhanTuChanDauTienTrenNuaMangVuongDuoiDuongCheoPhu() {
            for(int i = n-1; i > 0; i--) {
                for(int j = n-1; j > n-1-i; j--) {
                    if(p[i][j] % 2 == 0) {
                        return p[i][j];
                    }
                }
            }
            return -1;
        }

        // Sắp xếp giảm dần các phần tử trên đường chéo phụ của ma trận
        void sapXepGiamDanTrenDuongCheoPhu() {
            // Lưu giá trị phần tử trên đường chéo phụ
            int phanTuCheo = 0;
            for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) {
                phanTuCheo = p[i][j];
                // So sánh và hoán đổi các phần tử trên đường chéo phụ giảm dần
                for(int k = 0, l = n-1; k < n && l >= 0; k++, l--) {
                    if(p[k][l] < phanTuCheo) {
                        swap(p[k][l], p[i][j]);
                        phanTuCheo = p[k][l];
                    }
                }
            }
        }
        void phatSinhMaTranTuDong() {
     srand(time(NULL));
    cout << "Nhap vao bac cua ma tran vuong: ";
    cin>>n;
    p = new int*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[n];
        for (int j = 0; j < n; j++) {
            p[i][j] = rand() % 100;
        }
    }
}
};

int main() {
    int n;
    cout << "Nhap cap cua ma tran vuong: ";
    cin >> n;
    MaTranVuong maTranVuong(n);
    maTranVuong.nhapMaTranVuong();
    cout << "Ma tran vua nhap: " << endl;
    maTranVuong.xuatMaTranVuong();
    cout << "Cac phan tu le tren duong cheo chinh: ";
    maTranVuong.lietKePhanTuLeTrenDuongCheoChinh();    
    cout << "So luong cac phan tu co chu so cuoi la 3 tren duong cheo phu: "
        << maTranVuong.demPhanTuCoSoCuoiLa3TrenDuongCheoPhu() << endl;
    if(maTranVuong.tonTaiPhanTuAmTrenNuaMangVuongTrenDuongCheoChinh()) {
        cout << "Ton tai phan tu am tren nua mang vuong phia tren duong cheo chinh" << endl;
    } else {
        cout << "Khong ton tai phan tu am tren nua mang vuong phia tren duong cheo chinh" << endl;
    }
    int phanTuChanDauTien = maTranVuong.timPhanTuChanDauTienTrenNuaMangVuongDuoiDuongCheoPhu();
    if(phanTuChanDauTien != -1) {
        cout << "Phan tu chan dau tien tren nua mang vuong phia duoi duong cheo phu la: " << phanTuChanDauTien << endl;
    } else {
        cout << "Khong ton tai phan tu chan tren nua mang vuong phia duoi duong cheo phu" << endl;
    }
    
    maTranVuong.sapXepGiamDanTrenDuongCheoPhu();
    cout << "Ma tran sau khi duoc sap xep giam dan tren duong cheo phu: " << endl;
    maTranVuong.xuatMaTranVuong();
    

    maTranVuong.phatSinhMaTranTuDong();
    cout<<"Ma tran phat sinh tu dong la: \n";
    maTranVuong.xuatMaTranVuong();

    cout<<"Thoat chuong trinh\n";
    
    return 0;
}