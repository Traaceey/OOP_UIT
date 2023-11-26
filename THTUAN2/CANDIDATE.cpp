// kiem tra ngay thang nam hop le
// testcandidate dung con tro mang dong.
// thiet lap n = 0; con tro tro toi NULL
// 
#include <iostream>
#include <string>
using namespace std;

class Candidate {
    private:
        string ma, ten ;
        float toan, van, anh;
		int birth;
    public:
        Candidate(string ma = "", string ten = "", int birth = 0, float toan = 0, float van = 0, float anh = 0) {
            this->ma = ma;
            this->ten = ten;
            this->birth=birth;
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
            cout << "Ngay thang nam sinh: " << birth<<endl;
            cout << "Diem toan: " << toan << endl;
            cout << "Diem van: " << van << endl;
            cout << "Diem anh: " << anh << endl;
            cout << "Tong diem: " << Tongdiem() << endl;
        }
};
//class Ngaythangnam(){
//	private: 
//}
class TestCandidate {
    private:
        Candidate *ds;
        int n;

    public:
        TestCandidate() {
            cout << "Nhap so luong thi sinh: ";
            cin >> n;
            ds = new Candidate[n];
            for (int i = 0; i < n; i++) {
                string ma, ten;
                int birth;
                float toan, van, anh;
                cout << "Nhap thong tin thi sinh thu " << i+1 << endl;
                cout << "Ma thi sinh: ";
                cin >> ma;
                cout << "Ten thi sinh: ";
                cin.ignore();
                getline(cin, ten);
                cout << "Ngay sinh (dd/mm/yyyy): ";
                cin >> birth;
                cout << "Diem toan: ";
                cin >> toan;
                cout << "Diem van: ";
                cin >> van;
                cout << "Diem anh: ";
                cin >> anh;
                ds[i] = Candidate(ma, ten, birth, toan, van, anh);
            }
        }

        void Xuat() {
            cout << "Cac thi sinh co tong diem lon hon 15: " << endl;
            for (int i = 0; i < n; i++) {
                if (ds[i].Tongdiem() > 15) {
                    ds[i].Xuat();
                }
            }
        }
};
int main() {
    TestCandidate tc;
    tc.Xuat();
    return 0;
}

