#include <iostream>
using namespace std;
class CTime {
    private:
        int gio, phut, giay;
    public:
        CTime(int =0, int =0, int =0);
        ~CTime();
        CTime operator+(int &);
        CTime operator-(int &);
        CTime operator-(CTime&);
        CTime operator++(int );
        CTime operator--(int);
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
CTime CTime::operator+(int& t) {
    CTime t1;
    t1.gio= this->gio;
    t1.phut=this->phut;
    t1.giay=this->giay;
    t1.giay = t1.giay + t;
    return t1;
}
CTime CTime::operator-(int &t){
    CTime t2;
    t2.gio=this->gio;
    t2.phut=this->phut;
    t2.giay=this->giay;
    t2.giay= t2.giay - t;
    while (t2.giay<=0){
        t2.giay = 60 + t2.giay;
        t2.phut--;
    }
    while (t2.phut <=0){
        t2.phut = 60+t2.phut;
        t2.gio --;
    }
    if (t2.gio <= 0) t2.gio=0;
    return t2;
}
CTime CTime::operator-(CTime &t){
    CTime t3;
    t3.gio= this->gio - t.gio;
    t3.phut=this->phut - t.phut;
    t3.giay=this->giay - t.giay;
    while (t3.giay<=0){
        t3.giay = 60+ t3.giay;
        t3.phut--;
    }
    while (t3.phut<=0){
        t3.phut = 60+ t3.phut;
        t3.gio--;
    }
    if (t3.gio <=0) t3.gio=0;
    return t3; 
}
CTime CTime::operator++(int t){
    giay++;
    return *this;
}
CTime CTime::operator--(int t){
    giay--;
    if (giay==0){
        giay=59;
        phut--;
    }
    if (phut==0){
        phut=59;
        gio--;
    }
    if(gio<=0) gio=0;
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

    // Nhap vao gia tri can cong
    cout<<"Nhap vao giay cong them: ";
    int giaycong;
    cin>>giaycong;
    CTime Cong = time + giaycong;
    cout<<"Thoi gian sau khi cong them la: "<<Cong<<endl;

    // Nhap vao gia tri can tru
    cout<<"Nhap vao giay tru di: ";
    int giaytru;
    cin>>giaytru;
    CTime Tru = time - giaytru;
    cout<<"Thoi gian sau khi tru la: "<<Tru<<endl;

    // Nhap vao 2 thoi gian can tru
    cout<<"Nhap vao thoi gian muon tru: "<<endl;
    CTime thgiantru;
    cin>>thgiantru;
    cout<<"Du lieu vua nhap la: "<<thgiantru<<endl;
    CTime CTimeSpan = time - thgiantru;
    cout<<"Ket qua tru 2 thoi gian: "<<CTimeSpan<<endl;

    // Tang 1 giay
    CTime giaycongthem = time++;
    cout<<"Thoi gian sau khi tang 1 giay la: "<<giaycongthem<<endl;

    // Tru 1 giay
    CTime giaytrudi = time--;
    cout<<"Thoi gian sau khi tru 1 giay la: "<<giaytrudi<<endl;

    return 0;
}
