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

class DIEM3C:public DIEM{
	protected:
		double z;
		static int dem;
	public: 
		~DIEM3C();
		DIEM3C(double =0, double = 0, double =0);
		DIEM3C(const DIEM3C&);
		double GetZ() const ;
		void setZ(double);
		void setXYZ(double, double, double);
		static int getDem();
		void Nhap();
		void Xuat() const ;
		bool Kiemtratrung(const DIEM3C&) const ;
		void Dichuyen(double, double, double);
		double Tinhkhoangcach(const DIEM3C&) const;
		DIEM3C TimDoiXung() const;
		float tinhChuvi(DIEM3C &, DIEM3C &);
		float tinhDientich(DIEM3C&, DIEM3C &);
		friend istream& operator>>(istream&, DIEM3C&);
		friend ostream& operator<<(ostream&, const DIEM3C&);
};
	int DIEM3C ::dem=0;
	DIEM3C::~DIEM3C(){
		cout<<"Da huy 1 diem 3C => con "<<--dem<<" diem 3C\n";
	}
	DIEM3C::DIEM3C(double x, double y, double z):DIEM(x,y), z(z){
		x=y=x=0;
		cout<<"Da tao 1 diem 3C => Co "<<++dem<<" diem 3C\n";
	}
	DIEM3C::DIEM3C(const DIEM3C& d3c):DIEM(d3c.x,d3c.y), z(d3c.z){
		cout<<"Da tao 1 diem 3C => Co "<<++dem<< " diem 3C\n";
	}
	double DIEM3C::GetZ() const {
		return z;
	}
	void DIEM3C::setZ(double z){
		this->z=z;
	}
	void DIEM3C::setXYZ(double x, double y, double z){
		SetXY(x,y);
		setZ(z);
	}
	int DIEM3C::getDem(){
		return dem;
	}
	void DIEM3C::Nhap(){
		DIEM::Nhap();
		cout<<" Nhap cao do: ";
		cin>>z;
	}
	void DIEM3C::Xuat() const {
		DIEM::Xuat();
		cout<<", "<<z;
	}
	bool DIEM3C::Kiemtratrung(const DIEM3C & d3c) const {
		return x==d3c.x && y==d3c.y && z==d3c.z;
	}
	void DIEM3C::Dichuyen(double dx, double dy, double dz){
		DIEM::DiChuyen(dx,dy); // call the parent class's method
		z += dz; // update z
	}
	double DIEM3C::Tinhkhoangcach(const DIEM3C& d3c) const {
		return sqrt(pow(x-d3c.x , 2)+ pow (y-d3c.y,2) + pow(z-d3c.z,2));
	}
	DIEM3C DIEM3C::TimDoiXung() const {
		return DIEM3C(-x==0 ? x : -x , -y==0?y:-y , -z==0 ? z:-z);
	}
	istream& operator>>(istream& is, DIEM3C& d3c){
		d3c.DIEM::Nhap();
		cout<<"Nhap cao do: ";
		is>>d3c.z;
		return is;
	}
	ostream& operator<<(ostream& os, const DIEM3C& d3c){
		d3c.DIEM::Xuat();
		cout<<", "<<d3c.z;
		return os;
	}
	float DIEM3C::tinhChuvi(DIEM3C &b, DIEM3C &c){
		float AB = TinhKhoangCach(b);
		float AC = TinhKhoangCach(c);
		float BC = b.TinhKhoangCach(c);
		return AB + AC + BC;
}

	float DIEM3C::tinhDientich(DIEM3C &b, DIEM3C &c){
	float AB = TinhKhoangCach(b);
		float AC = TinhKhoangCach(c);
		float BC = b.TinhKhoangCach(c);
		float p = tinhChuvi(b,c)/2;
		return sqrt(p*(p-AB)*(p-AC)*(p-BC));
}

class DIEMMAU3C:public DIEM3C{
	protected:
		int r,g, b;
		static int dem;
	public:
		~DIEMMAU3C();
		DIEMMAU3C(double =0, double =0, double =0, int =0, int =0, int =0);
		int getR()const;
		int getG()const;
		int getB()const;
		void SetR(int);
		void SetG(int);
		void SetB(int);
		void setRGB(int, int, int);
		static int getDem();
		void Nhap();
		void Xuat() const ;
		bool Kiemtratrung(const DIEMMAU3C&) const;
		friend istream& operator>>(istream& is, DIEMMAU3C&);
		friend ostream& operator<<(ostream& os, const DIEMMAU3C&);
};
int DIEMMAU3C::dem = 0; 
DIEMMAU3C::~DIEMMAU3C(){
	cout<<"Da huy 1 diem mau 3C => con "<<--dem<<" diem mau 3C\n";
}
DIEMMAU3C::DIEMMAU3C(double x, double y, double z, int r, int g, int b): DIEM3C (x,y,z), r(r), g(g), b(b){
	setRGB(r,g,b);
	cout<<"Da tao 1 diem mau 3C => co "<<++dem<<" diem mau 3C\n";
}
int DIEMMAU3C::getR() const {
	return r;
}
int DIEMMAU3C::getG() const {
	return g;
}
int DIEMMAU3C::getB() const {
	return b;
}
void DIEMMAU3C::SetR(int r){
	while (r<0||r>225){
		cout<<"Nhap lai thong so mau Red tu 0 den 225: ";
		cin>>r;
	}
	this->r=r;
}
void DIEMMAU3C::SetG(int g){
	while (g<0||g>225){
		cout<<"Nhap lai thong so mau Green tu 0 den 225: ";
		cin>>g;
	}
	this->g=g;
}
void DIEMMAU3C::SetB(int b){
	while (b<0||b>225){
		cout<<"Nhap lai thong so mau Red tu 0 den 225: ";
		cin>>b;
	}
	this->b=b;
}
void DIEMMAU3C::setRGB(int r, int g, int b){
	SetR(r);
	SetG(g);
	SetB(b);
}
int DIEMMAU3C::getDem(){
	return dem;
}
void DIEMMAU3C::Nhap(){
	DIEM3C::Nhap();
	do {
		cout<<"Nhap 3 thong so mau RGB tu 0 den 255: ";
		cin>>r>>g>>b;
	} while (r<0 || r>255 || g<0 || g>255 || b<0 || b>255);
}
void DIEMMAU3C::Xuat() const {
	DIEM3C::Xuat();
	cout<<" - Mau RGB (" <<r<<", "<<g<<", "<<b<<")";
}
bool DIEMMAU3C::Kiemtratrung(const DIEMMAU3C& dm3c) const {
	return DIEM3C::Kiemtratrung(dm3c) && r==dm3c.r && g==dm3c.g && b== dm3c.b ;
}
istream& operator>>(istream& is,DIEMMAU3C& dm3c){
	dm3c.DIEM3C::Nhap();
	do {
		cout<<"Nhap 3 thong so mau RGB tu 0 den 255: ";
		is>>dm3c.r>>dm3c.g>>dm3c.b;
	} while (dm3c.r<0 || dm3c.r>255 || dm3c.g<0 || dm3c.g>255 || dm3c.b<0 || dm3c.b>255);
	return is;
}
ostream& operator<<(ostream& os,const DIEMMAU3C& dm3c){
	dm3c.DIEMMAU3C::Xuat();
	os<<" - Mau RGB("<<dm3c.r<<", "<<dm3c.g<<", "<<dm3c.b<<")";
	return os;
}

int main(){
	cout<<"So diem mau 3C hien tai la: "<<DIEMMAU3C::getDem()<<endl;
	DIEMMAU3C d1,d2(1), d3(1,2), d4(1,2,3), d5 (1,2,3,0), d6(1,2,3,0,50), d7(1,2,3,0,50,-100), *d8=new DIEMMAU3C;
	cout<<"So diem mau 3C hien tai la: "<<DIEMMAU3C::getDem()<<endl;
	cout<<"d1: "<<d1<<"\nd2: "<<d2<<"\nd3: "<<d3<<"\nd4: "<<d4<<"\nd5: "<<d5<<"\nd6: "<<d6<<"\nd7: "<<d7<<"\nd8: "<<*d8<<endl;

	cout<<"Nhap lai toa do diem mau 3C d1: \n";
	cin>>d1;
	cout<<"d1_moi: "<<d1<<endl;

	if (d1.DIEM::KiemTraTrung(d7))
		cout<<"d1 va d7 trung hoanh do va tung do\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do, tung do\n";

	if (d1.DIEM3C::KiemTraTrung(d7))
		cout<<"d1 va d7 trung hoanh do, tung do va cao do\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do, tung do va cao do\n";

	if (d1.DIEMMAU3C::Kiemtratrung(d7))
		cout<<"d1 va d7 trung hoanh do, tung do, cao do va mau\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do, tung do, cao do va mau\n";
	delete d8;
	cout<<"So diem 3C hien tai la: "<<DIEM3C::getDem()<<endl;
    return 0;
    }   