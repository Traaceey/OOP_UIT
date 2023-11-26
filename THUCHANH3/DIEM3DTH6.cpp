
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
		cout<<", ";
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
int main(){
	cout<<" So diem 3C hien tai la: "<<DIEM3C::GetDem()<<endl;
	DIEM3C d1,d2(1), d3(1,2), d4(1,2,3), *d5= new DIEM3C;
	cout<<"So diem 3C hien tai la: "<<DIEM3C::GetDem()<<endl;
	cout<<"d1: "<<d1<<"\nd2: "<<d2<<"\nd3: "<<d3<<"\nd4: "<<d4<<"\nd5: "<<*d5<<endl;
	cout<<"Nhap lai toa do diem d1: \n";
	cin>>d1;
	cout<<"d1_moi: "<<d1<<endl;

	if (d1.DIEM::KiemTraTrung(d4)) 
		cout<<"d1 va d4 trung hoanh do va tung do\n";
	else 
		cout<<"d1 va d4 khong trung hoanh do va tung do\n";

	if (d1.Kiemtratrung(d4))
		cout<<"d1 va d4 trung hoanh do, tung do va cao do\n";
	else 
		cout<<"d1 va d4 khong trung hoanh do, tung do va cao do\n";

	cout<< "Khoang cach giua d1 va d3 la: "<<d1.Tinhkhoangcach(d3)<<endl;

	d3.Dichuyen(-1,2,3);
	cout <<"d3 sau khi di chuyen la: "<<d3;

	cout<<"Diem d5 la: ";
	d5->Xuat();
	cout<<endl;

	cout<<"Diem doi xung cua d1 la: ";
	d1.TimDoiXung().Xuat();
	cout<<endl;

	cout<<"Nhap toa do cua diem d6: ";
	cin>>d3;
	cout<<endl;

	cout<<"Diem d6 la: "<<d3<<endl;

	cout<<"Chu vi tam giac ABC la: "<<d3.tinhChuvi(d1,d2)<<endl;
	cout<<"Dien tich tam giac ABC la: "<<d3.tinhDientich(d1,d2)<<endl;

	delete d5;
	cout<<"So diem 3C hien tai la: "<<DIEM3C::GetDem()<<endl;

    return 0;}
	