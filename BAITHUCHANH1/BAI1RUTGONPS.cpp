
#include<iostream>

using namespace std;

class PhanSo {
    private: 
        int ts,ms;
        static int dem;
    public:
    /*PhanSo();
    PhanSo(int);
    PhanSo(int, int);*/
   PhanSo(int=0, int =1);
   ~PhanSo();
   int  Gettu();
   int Getmau();
   static int Getdem(); //khong cho thay doi gia tri dem
    void Settu(int )    ;
    void Setmau(int );
    void Settumau(int, int );
    void SetPhanSo(int, int);
    void Nhap();
    void Xuat();
    

};
int PhanSo::dem=0;
PhanSo::~PhanSo(){
    cout<<"Da huy 1 phan so => con "<<--dem<< " diem\n";	
}
/*PhanSo::PhanSo() : ts(0), ms(1){
   dem++;
}
PhanSo::PhanSo(int ts): ts(ts), ms(1) {
    dem++;
}
PhanSo::PhanSo(int ms) : ts(0), ms(ms){
    dem++;
}*/
PhanSo::PhanSo(int ts, int ms): ts(ts), ms(ms){
    dem++;
}
int PhanSo::Gettu(){
    return ts;
}
int PhanSo::Getmau(){
    return ms;
}
int PhanSo::Getdem(){
    return dem;
}
void PhanSo::Settu(int ts){
    this->ts=ts;
}
void PhanSo::Settumau(int ms, int ts){
    this->ms=ms;
    this->ts=ts;
}
void PhanSo::SetPhanSo(int ts, int ms){
    Settu(ts);
    Setmau(ms);
}
void PhanSo::Nhap(){
    cout<<"Nhap vao tu so: \n";
    cin>>ts;
    do {
        cout<<"Nhap vao mau so (khac 0): \n"; cin>>ms;
    }
}
int UCLN(int a, int b) {
    if(b==0) return a;
    return UCLN(b, a%b);
}

void RutGonPhanSo(PhanSo &ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau==1) cout<<"Phan so la: "<<ps.tu;
	else if (ps.mau==-1) cout<<"Phan so la: "<<-ps.tu;
	else if (ps.mau<0) cout<<"Phan so la: "<<-ps.tu<<"/"<<-ps.mau;
	else cout<<"Phan so la: "<<ps.tu<<"/"<<ps.mau;
}
void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do {
        cout << "Nhap mau so: ";
        cin >> ps.mau;
    } while (ps.mau == 0);
}
int main() {
    PhanSo ps; 
	nhapPhanSo(ps);  
    RutGonPhanSo(ps);    
    return 0;
}
PHANSO PHANSO::operator+(const PHANSO& ps)
{
    return PHANSO (ts * ps.ms + ms*ps.ts, ms*ps.ms);
}


