
 #include <iostream>
#include <math.h>
using namespace std;
#define epsilon 0.0000000001
 class DIEM{
 	private:
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
		friend istream &operator>>(istream&, DIEM &);
		friend ostream &operator>>(ostream&, const DIEM&);
 };
int DIEM::dem=0;
DIEM::~DIEM(){
	//cout<<"Da huy 1 DIEM => con "<<--dem<< " diem\n";	
	// cout<<"Da huy 1 DIEM => con "<<--dem<< "diem\n";	
	dem--;
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
	cout<<x<<" , "<<y;
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
istream &operator>>(istream &is, DIEM &d){
	d.Nhap();
	return is;
}
ostream &operator<<(ostream &os, DIEM &d){
	d.Xuat();
	return os;
}
class TAMGIAC {
	private: 
		DIEM A,B,C;
		static int dem;
	public:
		~TAMGIAC();
		TAMGIAC();
		TAMGIAC(const DIEM&, const DIEM&, const DIEM&);
		TAMGIAC (double, double, double, double, double ,double);
		DIEM GetA() const ;
		DIEM GetB() const ;
		DIEM GetC() const ;
		static int GetDem();
		void SetA(const DIEM&);
		void SetB(const DIEM&);
		void SetC(const DIEM&);
		void SetABC(const DIEM&, const DIEM&, const DIEM&);
		void Nhap();
		void Xuat() const ;
		bool KiemTraHopLe() const ;
		string PhanLoai() const ;
		double TinhChuVi() const ;
		double TinhDienTich() const;
		friend istream &operator>>(istream&, TAMGIAC&);
		friend ostream &operator<<(ostream&, TAMGIAC&);
};
int TAMGIAC::dem=0;
TAMGIAC::~TAMGIAC(){
	cout<<"Da huy 1 tam giac => con "<<--dem<< " tam giac\n";	
	// cout<<"Da huy 1 DIEM => con "<<--dem<< "diem\n";	
	}
TAMGIAC::TAMGIAC() : A(0,0), B(1,0), C(0,1) {
	dem++;
}
/*Hoặc:
TAMGIAC::TAMGIAC(){
	A.SetXY(0,0);
	B.SetXY(1,0);
	C.SetXY(0,1);
	dem++;
}*/
TAMGIAC::TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C){
	if (!KiemTraHopLe())
		Nhap();
	dem++;
}
/*Hoặc:
TAMGIAC:: TAMGIAC(const DIEM& A, const DIEM& B, const DIEM& C){
	this->A=A;
	this->B=B;
	this->C=C;
	if (KiemTraHopLe())
		Nhap();
	dem++;
}*/
TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC ,double yC): A(xA, yA), B(xB,yB), C(xC, yC){
	if (!KiemTraHopLe())
		Nhap();
	dem++;
}
/*Hoặc:
TAMGIAC::TAMGIAC(double xA, double yA, double xB, double yB, double xC ,double yC) {
	A.SetXY(xA,yA);
	B.SetXY(xB,yB);
	C.SetXY(xC,yC);
	if (!KiemTraHopLe())
		Nhap();
	dem++;
}*/
DIEM TAMGIAC::GetA() const{
	return A;
}
DIEM TAMGIAC::GetB() const{
	return B;
}
DIEM TAMGIAC::GetC() const{
	return C;
}
int TAMGIAC::GetDem(){
	return dem;
}
void TAMGIAC::SetA(const DIEM& A){
	this->A=A;
	while (!KiemTraHopLe())
	{
		cout<<"Nhap toa do dinh A: \n";
		this->A.Nhap();
	}
}
void TAMGIAC::SetB(const DIEM& B){
	this->B=B;
	while (!KiemTraHopLe())
	{
		cout<<"Nhap toa do dinh B: \n";
		this->B.Nhap();
	}
}
void TAMGIAC::SetC(const DIEM& C){
	this->C=C;
	while (!KiemTraHopLe())
	{
		cout<<"Nhap toa do dinh C: \n";
		this->C.Nhap();
	}
}
void TAMGIAC::SetABC (const DIEM&A, const DIEM&B, const DIEM&C){
	SetA(A);
	SetB(B);
	SetC(C);
}
void TAMGIAC::Nhap(){
	do {
		cout<<"Nhap toa do 3 dinh tam giac: \n";
		A.Nhap();
		B.Nhap();
		C.Nhap();
	} while (!KiemTraHopLe());
}
void TAMGIAC::Xuat() const {
	cout<<"Tam giac qua 3 diem\n";
	cout<<"A("; A.Xuat(); cout<<") "; 
	cout<<"B("; B.Xuat(); cout<<") ";
	cout<<"C("; C.Xuat(); cout<<") "; 
	cout<<"=> Phan loai: "<<PhanLoai();
	cout<<"\n Dien tich: "<<TinhDienTich();
	cout<<"\t Chu vi: "<<TinhChuVi()<<endl;
}
bool TAMGIAC::KiemTraHopLe() const {
	return A.KiemTraTamGiacHopLe(B,C);
}
string TAMGIAC::PhanLoai() const {
	return A.PhanLoaiTamGiac(B,C);
}
double TAMGIAC::TinhChuVi() const {
	return A.TinhChuViTamGiac(B,C);
}
double TAMGIAC::TinhDienTich() const {
	return A.TinhDienTichTamGiac(B,C);
}
istream &operator>>(istream &is, TAMGIAC &tg){
	do {
		cout<<"Nhap toa do 3 dinh tam giac: \n";
		tg.Nhap();
	} while (!tg.KiemTraHopLe());
	return is;
}
ostream &operator<<(ostream &os, TAMGIAC &tg){
	tg.Xuat();
	return os;
}
int main(){
	cout<<"Co "<<DIEM::GetDem()<<" diem\n";
	cout<<"Co "<< TAMGIAC::GetDem()<<" \n";
	DIEM A, B(3), C(0,4);
	TAMGIAC tg1, tg2(A,B,C), tg3(0,4,-3,0,3,0);
	cout<<"Co "<<DIEM::GetDem()<<" diem\n";
	cout<<"Co "<<TAMGIAC::GetDem()<<" ";
	tg1.Xuat();
	tg2.Xuat();
	tg3.Xuat();
    return 0;}
	