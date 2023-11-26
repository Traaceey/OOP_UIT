#include <iostream>
using namespace std;
class CTime {
    private:
        int gio, phut, giay;
    public:
        CTime(int =0, int =0, int =0);
        ~CTime(); 
        CTime operator++(int ); // toan tu ++ sau
        CTime operator--(int); // toan tu -- sau
        friend istream& operator>>(istream& is, CTime& time);
        friend ostream& operator<<(ostream& os, CTime& time);
};
CTime::CTime(int a, int b, int c) {
    gio = (a<0|| a>23) ?0:a;
    phut = (b<0|| b>59) ?0:b;
    giay = (c<0||c>59) ?0:c;
}
CTime::~CTime() {
    // destructor
}
CTime CTime::operator++(int t){
    ++giay;
    if(giay>=60){
        giay=0;
        ++phut;
    
    if (phut >=60){
        phut=0;
        ++gio;
        if (gio>=24){
            gio=0;
        }
    }}
    return *this;
}
CTime CTime::operator--(int t){
    --giay;
            if (giay< 0) {
                giay = 59;
                --phut;
                if (phut < 0) {
                    phut = 59;
                    --gio;
                    if (gio < 0) {
                        gio = 23;
                    }
                }
            }
            return *this;
        }
istream& operator>>(istream& is, CTime& time) {
    cout << "Nhap vao gio: ";
    is >> time.gio;
    cout << "Nhap vao phut: ";
    is >> time.phut;
    cout << "Nhap vao giay: ";
    is >> time.giay;
    return is;
}
ostream& operator<<(ostream& os, CTime& time) {
    os << time.gio << ":" << time.phut << ":" << time.giay << endl;
    return os;
}
int main() {
    CTime time;
    cout<<"Nhap vao thoi gian: "<<endl;
    cin>>time;
    cout<<"Thoi gian sau khi nhap la: "<<time<<endl;
    CTime giaycongthem = time++;
    cout<<"Thoi gian sau khi tang 1 giay la: "<<giaycongthem<<endl;

    // Tru 1 giay
    CTime giaytru = time--;
    cout<<"Thoi gian sau khi tru 1 giay la: "<<giaytru<<endl;

    return 0;
}
