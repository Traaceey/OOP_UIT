
#include <iostream>
#include <math.h>
using namespace std;
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


class DIEM3CMAU :public DIEM3C, public MAU{
    private:
       static int dem;
    public:
    ~DIEM3CMAU();
    DIEM3CMAU(double=0, double=0, double=0, int=0, int=0 , int=0 );
    static int getDem();
    void Nhap();
    void Xuat() const ;
    bool Kiemtratrung(const DIEM3CMAU& dm) const ;
    friend istream& operator>>(istream&, DIEM3CMAU& );
    friend ostream& operator<<(ostream&, const DIEM3CMAU& );
};
int DIEM3CMAU::dem=0;
DIEM3CMAU::~DIEM3CMAU(){
    cout<<"Da huy 1 diem sau => con "<<--dem<<" diem mau\n";
}

DIEM3CMAU::DIEM3CMAU(double x, double y,double z, int r, int g, int b):DIEM3C(x,y,z) , MAU(r,g,b){
    cout<<"Da tao 1 mau => co "<<++dem<<" mau\n";
}
int DIEM3CMAU::getDem(){
    return dem;
}
void DIEM3CMAU::Nhap(){
    DIEM3C::Nhap();
    MAU::Nhap();
}
void DIEM3CMAU::Xuat() const {
    DIEM3C::Xuat();
    MAU::Xuat();
}
bool DIEM3CMAU::Kiemtratrung(const DIEM3CMAU& dm) const {
    return DIEM3C::KiemTraTrung(dm) && MAU::Kiemtratrung(dm);
}
istream& operator>>(istream& is, DIEM3CMAU& dm){
    dm.Nhap();
    return is;
}
ostream& operator<<(ostream& os, const DIEM3CMAU& dm){
    dm.Xuat();
    return os;
}

int main(){
    cout<<"So diem mau 2C hien tai la: "<<DIEM3CMAU::getDem()<<endl;
    DIEM3CMAU d1, d2(1), d3 (1,2), d4(1,2,100), d5(1,2,50,150), d6 (1,2,3,50,150), d7(1,2,3,4,50,150), *d8= new DIEM3CMAU;
    cout<<"So diem mau 2C hien tai la: "<<DIEM3CMAU::getDem()<<endl;
    cout<<"d1: "<<d1<<"\nd2: "<<d2<<"\nd3: "<<d3<<"\nd4: "<<d4<<"\nd5: "<<d5<<"\nd6: "<<d6<<"\nd7: "<<d7<<"\nd8: "<<*d8<<endl;
    
	cout<<"Nhap lai toa do diem 2C d1: \n";
	cin>>d1;
	cout<<"d1_moi: "<<d1<<endl;

	if (d1.DIEM::KiemTraTrung(*d8))
		cout<<"d1 va d7 trung hoanh do va tung do\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do va tung do\n";
	
	if (d1.MAU::Kiemtratrung(*d8))
		cout<<"d1 va d7 trung  mau\n";
	else 
		cout<<"d1 va d7 khong trung mau\n";

	if (d1.Kiemtratrung(*d8))
		cout<<"d1 va d7 trung hoanh do, tung do va mau\n";
	else 
		cout<<"d1 va d7 khong trung hoanh do, tung do va mau\n";

	delete d8;
	cout<<"So diem mau 2C hien tai la: "<<DIEM3CMAU::getDem()<<endl;
	return 0;
}
