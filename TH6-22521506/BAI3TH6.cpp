#include <iostream>
#include <math.h>
using namespace std;
#define epsilon 0.0000000001
 class DIEM{
 	protected:
 		double x,y;
		static int dem; 
 	public: 
 		~DIEM();
 		DIEM(double = 0, double =0);
		DIEM(const DIEM&);
 		double GetX() const;
 		double GetY() const;
 		void SetX(double );
 		void SetY(double);
 		void SetXY(double, double);
		static int GetDem();
 		void Nhap();
 		void Xuat() const ;
 		void DiChuyen (double, double);
 		bool KiemTraTrung(const DIEM&) const;
 		double TinhKhoangCach (const DIEM&) const;
 		DIEM TimDoiXung() const;
 		bool KiemTraTamGiacHopLe (const DIEM&, const DIEM&) const;
 		double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
 		double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
 		string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
 };
int DIEM::dem=0;
DIEM::~DIEM(){
	cout<<"Da huy 1 DIEM => con "<<--dem<< " diem\n";	
	// cout<<"Da huy 1 DIEM => con "<<--dem<< "diem\n";	
	}
DIEM::DIEM(double x, double y) : x(x), y(y) {
	dem ++;
	//this->x=x;
	//this->y=y;
	}
DIEM::DIEM(const DIEM& d) : x(d.x), y(d.y) {
		dem++;
	}
double DIEM::GetX() const {
	return x;
	}
double DIEM::GetY() const {
	return y;
}
int DIEM::GetDem() {
	return dem;
}
void DIEM::SetX(double x){
	this->x=x;
}
void DIEM::SetY(double y){
	this->y=y;
}
void DIEM::SetXY(double x, double y){
	this->x=x;
	this->y=y;
}
void DIEM::Nhap(){
	cout<<"Nhap hoanh do: "; cin>>x;
	cout<<"Nhap tung do: "; cin>>y;
}
void DIEM::Xuat() const {
	cout<<x<<", "<<y;
}
void DIEM::DiChuyen(double dx, double dy){
	x+=dx;
	y+=dy;
}
bool DIEM::KiemTraTrung(const DIEM& d) const{
	return x==d.x && y==d.y;
} 
double DIEM::TinhKhoangCach(const DIEM& d) const {
	return sqrt(pow(x- d.x,2)+ pow (y-d.y,2));
}
DIEM DIEM::TimDoiXung()  const{
	return DIEM(-x==0?x:-x, -y==0?y:-y);
}
bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const{
	double a= this->TinhKhoangCach(d1);
	double b= d1.TinhKhoangCach(d2);
	double c= d2.TinhKhoangCach(*this);
return a>0 && b>0 && c>0 && a+b>c && b+c>a && a+c>b;
}
double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const {
	double a= this->TinhKhoangCach(d1);
	double b= d1.TinhKhoangCach(d2);
	double c= d2.TinhKhoangCach(*this);
	return KiemTraTamGiacHopLe(d1,d2) ? a+b+c: 0;
}
double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const {
	double a= this->TinhKhoangCach(d1);
	double b= d1.TinhKhoangCach(d2);
	double c= d2.TinhKhoangCach(*this);
	double p = (a+b+c)/2;
	return KiemTraTamGiacHopLe(d1,d2) ? sqrt(p*(p-a)*(p-b)*(p-c)) : 0;
}
string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const{
	double a= this->TinhKhoangCach(d1);
	double b= d1.TinhKhoangCach(d2);
	double c= d2.TinhKhoangCach(*this);
	string chuoikq = " ";
	if (!KiemTraTamGiacHopLe(d1,d2)) chuoikq= "Tam giac khong hop le";
	else if (a==b&& b==c)
		chuoikq="Tam giac deu";
	else if (a==b || b==c || c==a)
		if (abs(a*a+b*-c*c)<= epsilon || abs(a*a+c*c-b*b)<=epsilon || abs(b*b+c*c-a*a)<= epsilon )
			chuoikq="Tam giac vuong can";
		else chuoikq = " Tam giac can"; 	
	else if (abs(a*a+b*-c*c)<= epsilon || abs(a*a+c*c-b*b)<=epsilon || abs(b*b+c*c-a*a)<= epsilon )
		chuoikq="Tam giac vuong";
	else chuoikq="Tam giac thuong";
	return chuoikq;
}
class MAU{
    private:
        int r,g,b;
        static int dem;
    public:
        ~MAU();
        MAU(int=0, int =0, int =0);
        MAU(const MAU&);
        int getR() const;
        int getG() const;
        int getB() const;
        static int getDem();
        void setR(int);
        void setG(int);
        void setB(int);
        void setRGB(int, int, int);
        void Nhap();
        void Xuat() const;
        bool Kiemtratrung (const MAU&) const;
        friend istream& operator>>(istream&, MAU&);
        friend ostream& operator<<(ostream&,const  MAU&);
};
int MAU::dem=0;
MAU::~MAU(){
    cout<<"Da uy 1 mau => con "<<--dem<<" mau\n";
}
MAU::MAU(int r, int g, int b){
    setRGB(r,g,b);
    cout<<"Da tao 1 mau => co "<<++dem<<" mau\n";
}
MAU::MAU(const MAU& m){
    setRGB(m.r, m.g, m.b);
    cout<<"Da tao 1 mau => co "<<++dem<<" mau\n";
}
int MAU::getR() const {
    return r;
}
int MAU::getG() const {
    return g;
}
int MAU::getB() const {
    return b;
}
int MAU::getDem(){
    return dem;
}
void MAU::setR(int r){
	while (r<0 || r>255)
	{
		cout<<"Nhap lai thong so mau Red tu 0 den 255: ";
		cin>>r;
	}
	this->r=r;
}
void MAU::setG(int g){
	while (g<0 || g>255)
	{
		cout<<"Nhap lai thong so mau Green tu 0 den 255: \n";
		cin>>g;
	}
	this->g=g;
}
void MAU::setB(int b){
	while (b<0 || b>255)
	{
		cout<<"Nhap lai thong so mau Blue tu 0 den 255: \n";
		cin>>b;
	}
	this->b=b;
}
void MAU::setRGB(int r, int g, int b){
	setR(r);
	setG(g);
	setB(b);
}
void MAU::Nhap(){
    do {
		cout<<"Nhap 3 thong so mau RGB tu 0 den 255: ";
		cin>>r>>g>>b;
	} while (r<0 || r>255 || g<0 || g>255 || b<0 || b>255);
}
void MAU::Xuat() const {
    cout<<" - Mau RGB("<<r<<", "<<g<<", "<<b<<")";
}
bool MAU::Kiemtratrung(const MAU& m) const {
    return r== m.r && g==m.g && b==m.b;
}
istream& operator>>(istream& is, MAU& m){
    do {
        cout<<"Nhap 3 thong so mau RGB tu 0 den 255: ";
        is>>m.r>>m.g>>m.b;
    }
     while (m.r<0 || m.r> 255 || m.g <0 || m.g >255 || m.b<0 || m.b>255);
    return is;
}
ostream& operator<<(ostream& os, const MAU& m){
    os<<" - Mau RGB("<<m.r<<", "<<m.g<<", "<<m.b<<")";
    return os;
}

class DIEMMAU :public DIEM, public MAU{
    private:
       static int dem;
    public:
    ~DIEMMAU();
    DIEMMAU(double=0, double=0, int=0, int=0 , int=0 );
    static int getDem();
    void Nhap();
    void Xuat() const ;
    bool Kiemtratrung(const DIEMMAU& dm) const ;
    friend istream& operator>>(istream&, DIEMMAU& );
    friend ostream& operator<<(ostream&, const DIEMMAU& );
};
int DIEMMAU::dem=0;
DIEMMAU::~DIEMMAU(){
    cout<<"Da huy 1 diem sau => con "<<--dem<<" diem mau\n";
}

DIEMMAU::DIEMMAU(double x, double y, int r, int g, int b):DIEM(x,y) , MAU(r,g,b){
    cout<<"Da tao 1 mau => co "<<++dem<<" mau\n";
}
int DIEMMAU::getDem(){
    return dem;
}
void DIEMMAU::Nhap(){
    DIEM::Nhap();
    MAU::Nhap();
}
void DIEMMAU::Xuat() const {
    DIEM::Xuat();
    MAU::Xuat();
}
bool DIEMMAU::Kiemtratrung(const DIEMMAU& dm) const {
    return DIEM::KiemTraTrung(dm) && MAU::Kiemtratrung(dm);
}
istream& operator>>(istream& is, DIEMMAU& dm){
    dm.Nhap();
    return is;
}
ostream& operator<<(ostream& os, const DIEMMAU& dm){
    dm.Xuat();
    return os;
}

int main(){
    cout<<"So diem mau 2C hien tai la: "<<DIEMMAU::getDem()<<endl;
    DIEMMAU d1, d2(1), d3 (1,2), d4(1,2,100), d5(1,2,50,150), d6 (1,2,50,150,256), *d7= new DIEMMAU;
    cout<<"So diem mau 2C hien tai la: "<<DIEMMAU::getDem()<<endl;
    cout<<"d1: "<<d1<<"\nd2: "<<d2<<"\nd3: "<<d3<<"\nd4: "<<d4<<"\nd5: "<<d5<<"\nd6: "<<d6<<"\nd7: "<<*d7<<endl;
    
	cout<<"Nhap lai toa do diem 2C d1: \n";
	cin>>d1;
	cout<<"d1_moi: "<<d1<<endl;

	if (d1.DIEM::KiemTraTrung(*d7))
		cout<<"d1 va d7 trung hoanh do va tung do\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do va tung do\n";
	
	if (d1.MAU::Kiemtratrung(*d7))
		cout<<"d1 va d7 trung  mau\n";
	else 
		cout<<"d1 va d7 khong trung mau\n";

	if (d1.Kiemtratrung(*d7))
		cout<<"d1 va d7 trung hoanh do, tung do va mau\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do, tung do va mau\n";

	delete d7;
	cout<<"So diem mau 2C hien tai la: "<<DIEMMAU::getDem()<<endl;
	return 0;
}