
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
    return 0;
	/*DIEM d1, d2, d3;
	int chon;
	cout<<"Co "<<d1.Getdem()<<" diem\n";
	cout<<"Co "<<d2.Getdem()<<" deim\n";
	cout<<"d1"; d1.Xuat(); cout<<"\n";
	cout<<"d2"; d2.Xuat(); cout<<")\n";*/
	/*do
	{
		cout<<"------------CHUONG TRINH XU LY DIEM------------\n";
		cout<<"1. Nhap toa do 3 diem \n";
		cout<<"2. Xuat toa do 3 diem\n";
		cout<<"3. Di chuyen 1 diem\n";
		cout<<"4. Kiem tra cac diem trung nhau\n";
		cout<<"5. Tinh khoang cach 2 diem\n";
		cout<<"6. Tim diem doi xung cua 1 diem\n";
		cout<<"7. Tinh chu vi Tam giac qua 3 diem\n";
		cout<<"8. Tinh dien tich Tam giac qua 3 diem\n";
		cout<<"9. Phan loai Tam giac qua 3 diem\n";
		cout<<"0. Thoat chuong trinh\n";
		cout<<"-----------------------------------------------\n";
		cout<<"Moi ban chon: ";
		cin>>chon;
		switch(chon){
			case 0: 
				cout<<" Dang thoat chuong trinh....\n";
				break;
			case 1: 
				cout<<"Nhap toa do diem d1:\n";
				d1.Nhap();
				cout<<"Nhap toa do diem d2:\n";
				d2.Nhap();
				cout<<"Nhap toa do diem d3:\n";
				d3.Nhap();
				break;
			case 2: 
			cout<<"Toa do 3 diem la:\n";
			cout<<"d1 "; d1.Xuat();
			cout<<"d2 "; d2.Xuat();
			cout<<"d3 "; d3.Xuat();
			break;
		case 3: 
			 int diemchon;
			 double dx, dy;
			do {
			 	cout<<"Chon diem can di chuyen: \n";
			 	cout<<"1. Diem d1\n";
			 	cout<<"2. Diem d2\n";
			 	cout<<"3. Diem d3\n";
			 } while (diemchon<1 || diemchon>3);
			 cout<<"Nhap khoang cach ngang, doc can di chuyen diem: \n";
			 cin>>dx>>dy;
			 if (diemchon ==1) d1.DiChuyen(dx, dy);
			 else if (diemchon=2) d2.DiChuyen(dx,dy);
			 else d3.DiChuyen(dx,dy);
			 cout<<"Da di chuyen diem\n";
			 break;
		case 4:
			if (d1.KiemTraTrung(d2))
				if(d1.KiemTraTrung(d3))
					cout<<"3 diem d1, d2, d3 trung nhau\n";
				else cout<<"d1 trung d2\n";
			else if (d1.KiemTraTrung(d3))
				cout<<"d1 trung d3\n";
			else if (d2.KiemTraTrung(d3))
				 cout<<"d2 trung d3\n";
			else 
				cout<<"3 diem d1, d2, d3 khong trung nhau\n";
			break;
		case 5: 
			cout<<"Khoang cach tu diem d1 den d2 la: "<<d1.TinhKhoangCach(d2)<<endl;
			cout<<"Khoang cach tu diem d2 den d3 la: "<<d2.TinhKhoangCach(d3)<<endl;
			cout<<"Khoang cach tu diem d1 den d3 la: "<<d1.TinhKhoangCach(d3)<<endl;
			break;
		case 6: 
		{
			DIEM dxx;
			int diemchon;
			do
			{
				cout<<"Chon diem can tim diem doi xung: \n";
				cout<<"1. Diem d1\n";
			 	cout<<"2. Diem d2\n";
			 	cout<<"3. Diem d3\n";
			 	cin>>diemchon;
			} while (diemchon<1 || diemchon>3);
			if (diemchon==1){
				dxx=d1.TimDoiXung();
				cout<<"d1"; dxx.Xuat(); cout<<"\n";
			}
			else if (diemchon ==2){
				dxx= d2.TimDoiXung();
				cout<<"d2"; dxx.Xuat(); cout<<"\n";
			}
			else {
				dxx=d3.TimDoiXung();
				cout<<"d3"; dxx.Xuat(); cout<<"\n";
			}
		break;
		}
		case 7: 
			if (d1.KiemTraTamGiacHopLe(d2,d3))
				cout<<"Chu vi Tam giac qua 3 diem d1, d2, d3 la: "<<d1.TinhChuViTamGiac(d2,d3)<<endl;
			else
				cout<<"3 diem d1, d2, d3 khong tao thanh Tam giac hop le\n";
			break;
		case 8:
			if (d1.KiemTraTamGiacHopLe(d2,d3))
				cout<<"Dien tich Tam giac qua 3 diem d1, d2, d3 la: "<<d1.TinhDienTichTamGiac(d2,d3)<<endl;
			else 
				cout<<"3 diem d1, d2, d3 khong tao thanh tam giac hop le:\n";
			break;
		case 9:
			if (d1.KiemTraTamGiacHopLe(d2,d3))
				cout<<"Tam giac qua 3 diem d1, d2, d3 la: "<< d1.PhanLoaiTamGiac(d2,d3)<<endl;
			else 
				cout<<"3 diem qua d1, d2, d3 khong tao thanh tam giac hop le\n";
			break;
		default:
			cout<<"Ban chon sai. Moi chon lai\n";
			break;	 
		}}
		while (chon!=0);
	*/
//return 0;	
}

 