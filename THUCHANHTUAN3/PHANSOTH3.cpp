#include <iostream>
using namespace std;
class PHANSO{
    private:
        int ts, ms;
        static int dem;
    public:
        ~PHANSO();
        PHANSO();
        PHANSO(int);
        PHANSO(int, int);
        PHANSO(const PHANSO &);
        //PHANSO (int i=0; i=1);
        void Nhap();
        void Xuat();
        int TimUSCLN(int, int );
        void RutGon();
        int GetTS() const;
        int GetMS() const;
        static int GetDem();
        void SetTS(int );
        void SETMS(int );
        void SetPS(int, int );
        //PHANSO Cong(const PHANSO &);
        //PHANSO operator +(const PHANSO &);
        //friend PHANSO Cong(const PHANSO &, cosnt PHANSO &);
        friend PHANSO operator+(const PHANSO&, const PHANSO&);
        friend PHANSO operator-(const PHANSO&, const PHANSO&);
        friend PHANSO operator*(const PHANSO&, const PHANSO&);
        friend PHANSO operator/(const PHANSO&, const PHANSO&);
        PHANSO operator++();
        PHANSO operator++(int);
        PHANSO operator--();
        PHANSO operator--(int);
        operator double() const;
        friend bool operator==(const PHANSO&, const PHANSO& );
        friend bool operator!=(const PHANSO&, const PHANSO&);
        friend bool operator<(const PHANSO&, const PHANSO&);
        friend bool operator<=(const PHANSO&, const PHANSO&);
        friend bool operator>(const PHANSO&, const PHANSO&);
        friend bool operator>=(const PHANSO&, const PHANSO&);
        friend istream& operator>>(istream&, PHANSO&);
        friend ostream& operator<<(ostream&, PHANSO&);
};
int PHANSO::dem=0;
PHANSO::~PHANSO(){
    dem--;
}
PHANSO::PHANSO():ts(0), ms(1){
    dem++;
}
PHANSO::PHANSO(int ts): ts(ts), ms(1){
    dem++;
}
PHANSO::PHANSO(int ts, int ms):ts(ts), ms(ms){
    dem++;
}
//PHANSO::PHANSO(int ts, int ms): ts(ts), ms(ms){
// dem++:
//}
PHANSO::PHANSO(const PHANSO& ps):  ts(ps.ts), ms(ps.ms){
    dem++;
}
void PHANSO::Nhap(){
    cout<<"Nhap tu so: ";
    cin>>ts;
    do {
        cout<<"Nhap mau so(khac 0): ";
        cin>>ms;
    } while (ms==0);
}
void PHANSO::Xuat(){
    RutGon();
    if (ms<-1) 
        cout<<-ts<<"/"<<-ms;
    else if (ms==0)
        cout<<"Khong chia cho so 0";
    else if (ms==1) 
        cout<<ts;
    else 
        cout<<ts<<"/"<<ms;
}
int PHANSO::TimUSCLN(int a, int b){
    int uscln;
    a=abs(a);
    b=abs(b);
    if (a==0 && b==0)
        uscln =1;
    else if (a==0 || b==0)
        uscln = a+b;
    else {
        // Dung giai Eculide
        while (a!=b){
            if (a>b)
                a-=b;
            else 
                b-=a;
        }
        uscln =a;
    }
    return uscln;
}
void PHANSO::RutGon(){
    int uscln = TimUSCLN(ts, ms);
    ts/=uscln;
    ms/=uscln;
}
int PHANSO::GetTS() const{
    return ts;
}
int PHANSO::GetMS() const {
    return ms;
}
int PHANSO::GetDem()  {
    return dem;
}
void PHANSO::SetTS(int ts)  {
    this->ts=ts;
}
void PHANSO::SETMS(int ms) {
    this->ms=ms;
}
void PHANSO::SetPS(int ts, int ms) {
    this->ts=ts;
    this->ms=ms;
}
/* PHANSO PHANSO::Cong(const PHANSO& ps)
{
    return PHANSO(ts * ps.ms + ms* ps.ts, ms*ps.ms);
}
PHANSO PHANSO::operator+(const PHANSO& ps){
   return PHANSO(ts* ps.ms + ms* ps.ts, ms* ps.ms); 
}
PHANSO Cong(const PHANSO& ps1, const PHANSO& ps2){
    return PHANSO(ps1.ts * ps2.ms + ps1.ms * ps2.ts, ps1.ms * ps2.ms);
}
*/
PHANSO operator+(const PHANSO& ps1, const PHANSO& ps2){
    return PHANSO (ps1.ts * ps2.ms + ps1.ms * ps2.ts, ps1.ms * ps2.ms);
}
PHANSO operator-(const PHANSO& ps1, const PHANSO& ps2){
    return PHANSO(ps1.ts * ps2.ms - ps1.ms * ps2.ts, ps1.ms * ps2.ms);
}
PHANSO operator*(const PHANSO& ps1, const PHANSO& ps2){
    return PHANSO(ps1.ts * ps2.ts, ps1.ms * ps2.ms);
}
PHANSO operator/(const PHANSO& ps1, const PHANSO& ps2){
    return PHANSO(ps1.ts * ps2.ms, ps1.ms * ps2.ts);
}
PHANSO PHANSO::operator++(){
    ts+=ts;
    return *this;
}
PHANSO PHANSO::operator++(int){
    PHANSO pstam(ts,ms);
    ts+=ms;
    return pstam;
}
PHANSO PHANSO::operator--(){
    ts -= ms;
    return *this;
}
PHANSO PHANSO::operator--(int){
    PHANSO pstam(ts, ms);
    ts-=ms;
    return pstam;
}
PHANSO::operator double() const {
    return (double) ts/ms;
}
bool operator==(const PHANSO& ps1, const PHANSO& ps2){
    return ps1.ts * ps2.ms == ps2.ts * ps1.ms;
    //return (double) ps1 == (double) ps2;
}
bool operator!=(const PHANSO& ps1, const PHANSO& ps2){
    return ps1.ts * ps2.ms == ps2.ts * ps1.ms;
    //return (double) ps1 != (double) ps2;
}
bool operator<(const PHANSO& ps1, const PHANSO& ps2){
    return ps1.ts * ps2.ms < ps2.ts * ps1.ms;
    //return (double) ps1 < (double) ps2;
}
bool operator<=(const PHANSO& ps1, const PHANSO& ps2){
    return ps1.ts * ps2.ms <= ps2.ts * ps1.ms;
    //return (double) ps1 <= (double) ps2;
}
bool operator>(const PHANSO& ps1, const PHANSO& ps2){
    return ps1.ts * ps2.ms > ps2.ts * ps1.ms;
    //return (double) ps1 <= (double) ps2;
}
bool operator>=(const PHANSO& ps1, const PHANSO& ps2){
    return ps1.ts * ps2.ms >= ps2.ts * ps1.ms;
    //return (double) ps1 <= (double) ps2;
}
istream& operator>>(istream& is, PHANSO& ps){
    cout<<"Nhap tu so: ";
    is>>ps.ts;
    do 
    {
        cout<<"Nhap mau so (khac 0): ";
        is>>ps.ms;
    } while (ps.ms ==0);
    return is;
    /*Hoac: 
    ps.Nhap();
    return is;
    */
}
ostream& operator<<(ostream& os, PHANSO& ps){
    ps.RutGon();
    if (ps.ms <-1)
        os<<-ps.ts <<"/"<<-ps.ms;
    else if (ps.ms==-1)
        os<<-ps.ts;
    else if (ps.ms ==0) 
        os<<"Khong chia cho so 0";
    else if (ps.ms==1)
        os<<ps.ts;
    else 
        os<<ps.ts<<"/"<<ps.ms;
    return os;
    /* Hoac:
    ps.Xuat();
    return os;
    */
}
int main(){
    PHANSO ps1, ps2(-3), ps3(-2,5), A;
    cout<<"Phan so 1:  "<<ps1<<endl<<"Phan so 2: "<<ps2<<endl<<"Phan so 3: "<<ps3<<endl;
    cout<<"Nhap lai phan so 1, phan so 2, phan so 3: \n";
    cin>>ps1>>ps2>>ps3;
    A = (PHANSO)1 + ++ps2 + ps3-- -(PHANSO)2;
    //ps2=ps2+1; A =1 + ps2 + ps3 -2; ps3 = ps3 -1;
    cout<<"A= "<<A<<endl<<"ps2= "<<ps2 << endl <<"ps3 = "<<ps3<<endl;
    PHANSO B= ps3 + (PHANSO)2;
    cout<<"B= "<<B<<endl;
    if (A=B)
        cout<<A<<" == "<<B<<endl;
    else 
        cout<<A<<" != "<<B<<endl;
    double C = (double)A + 0.5;
    cout<<"C= "<<C<<endl;
}






