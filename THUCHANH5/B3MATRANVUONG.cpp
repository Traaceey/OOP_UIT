#include <iostream>
#include <algorithm>

using namespace std;

class MaTranVuong {
    private:
        int n;
        int **p;

    public:
        // Thiết lập không tham số
        MaTranVuong() {
            n = 0;
            p = NULL;
        }

        // Thiết lập truyền tham số n
        MaTranVuong(int n) {
            this->n = n;
            p = new int*[n];
            for(int i = 0; i < n; i++){
                p[i] = new int[n];
            }
        }

        // Thiết lập sao chép
        MaTranVuong(const MaTranVuong &maTranVuong) {
            n = maTranVuong.n;
            p = new int*[n];
            for(int i = 0; i < n; i++) {
                p[i] = new int[n];
            }

            // Sao chép các giá trị phần tử ma trận
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    p[i][j] = maTranVuong.p[i][j];
                }
            }
        }

        // Hủy
        ~MaTranVuong() {
            for(int i = 0; i < n; i++) {
                delete[] p[i];
            }
            delete[] p;
        }

        // Nhập giá trị các phần tử ma trận
        void nhapMaTranVuong() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << "Nhap phan tu tai [" << i << "][" << j << "]: ";
                    cin >> p[i][j];
                }
            }
        }

        // Xuất giá trị các phần tử ma trận
        void xuatMaTranVuong() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout << p[i][j] << "\t";
                }
                cout << endl;
            }
        }

        // Liệt kê giá trị các phần tử lẻ nằm trên đường chéo chính của ma trận
        void lietKePhanTuLeTrenDuongCheoChinh() {
            for(int i = 0; i < n; i++) {
                if(p[i][i] % 2 != 0) {
                    cout << p[i][i] << "\t";
                }
            }
            cout << endl;
        }

        // Đếm số lượng các phần tử có chữ số cuối là 3 nằm trên đường chéo phụ của ma trận
        int demPhanTuCoSoCuoiLa3TrenDuongCheoPhu() {
            int count = 0;
            for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) {
                if(p[i][j] % 10 == 3) {
                    count++;
                }
            }
            return count;
        }

        // Kiểm tra xem có tồn tại phần tử âm ở nửa mảng vuông phía trên đường chéo chính hay không?
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
};

int main() {
    int n;
    int option;
    // Yêu cầu người dùng nhập cấp ma trận vuông
    cout << "Nhap cap cua ma tran vuong: ";
    cin >> n;
    MaTranVuong maTranVuong(n);
    
    while (true) {
        cout << "---------------------------------------------------" << endl;
        cout << "MENU:" << endl;
        cout << "1. Nhap ma tran vuong" << endl;
        cout << "2. Xuat ma tran vuong" << endl;
        cout << "3. Liet ke cac phan tu le tren duong cheo chinh" << endl;
        cout << "4. Dem so phan tu co chu so cuoi la 3 tren duong cheo phu" << endl;
        cout << "5. Kiem tra ton tai phan tu am tren nua ma tran vuong phia tren duong cheo chinh" << endl;
        cout << "6. Tim phan tu chan dau tien tren nua ma tran vuong phia duoi duong cheo phu" << endl;
        cout << "7. Sap xep giam dan cac phan tu tren duong cheo phu" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap tuy chon: ";
        cin >> option;
        
        switch (option) {
            case 1: // Nhập ma trận vuông
                maTranVuong.nhapMaTranVuong();
                break;
            case 2: // Xuất ma trận vuông
                cout << "Ma tran vua nhap: " << endl;
                maTranVuong.xuatMaTranVuong();
                break;
            case 3: // Liệt kê các phần tử lẻ trên đường chéo chính
                cout << "Cac phan tu le tren duong cheo chinh: ";
                maTranVuong.lietKePhanTuLeTrenDuongCheoChinh();
                break;
            case 4: // Đếm số phần tử có chữ số cuối là 3 trên đường chéo phụ
                cout << "So luong cac phan tu co chu so cuoi la 3 tren duong cheo phu: "
                    << maTranVuong.demPhanTuCoSoCuoiLa3TrenDuongCheoPhu() << endl;
                break;
            case 5: // Kiểm tra tồn tại phần tử âm ở nửa mảng vuông phía trên đường chéo chính hay không
                if(maTranVuong.tonTaiPhanTuAmTrenNuaMangVuongTrenDuongCheoChinh()) {
                    cout << "Ton tai phan tu am tren nua mang vuong phia tren duong cheo chinh" << endl;
                } else {
                    cout << "Khong ton tai phan tu am tren nua mang vuong phia tren duong cheo chinh" << endl;
                }
                break;
            case 6: // Tìm phần tử chẵn đầu tiên ở nửa mảng vuông phía dưới đường chéo phụ của ma trận
                int phanTuChanDauTien = maTranVuong.timPhanTuChanDauTienTrenNuaMangVuongDuoiDuongCheoPhu();
                if(phanTuChanDauTien != -1) {
                    cout <<"Phần tử chẵn đầu tiên ở nửa mảng vuông phía dưới đường chéo phụ: " << phanTuChanDauTien << endl;
                } else {
                cout << "Khong ton tai phan tu chan nao tren nua mang vuong phia duoi duong cheo phu" << endl;
                }
                break;
                case 7: // Sắp xếp giảm dần các phần tử trên đường chéo phụ của ma trận
                maTranVuong.sapXepGiamDanTrenDuongCheoPhu();
                cout << "Ma tran sau khi sap xep giam dan cac phan tu tren duong cheo phu: " << endl;
                maTranVuong.xuatMaTranVuong();
                break;
                case 0: // Thoát chương trình
                cout << "Thoat chuong trinh" << endl;
                return 0;
                break;
                default: // Trường hợp chọn tùy chọn không hợp lệ
                cout << "Tuy chon khong ton tai" << endl;
                break;
                }
                }
                return 0;
                }
