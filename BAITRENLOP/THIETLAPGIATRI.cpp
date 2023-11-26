#include <math.h>

#include <iostream>
using namespace std;
class DIEM
{
	private:
		double x,y;
	public: 
	~DIEM();
	DIEM(double = 0, double =0); // ham thiet lap gia tri
	//void SetXY(double);
	double GetX();
	double GetY();
	void Nhap();
	void Xuat();
	
};
DIEM::DIEM(double x , double y){
	this->x=x;
	this->y=y;
}
DIEM::~DIEM(){
	cout<<"Dang huy 1 diem";
}
double DIEM::GetX()
{
	return x;
}
double DIEM::GetY(){
	return y;
}
void DIEM::Nhap(){
	cin>>x>>y;
}
void DIEM::Xuat(){
	cout<<x<<" , "<<y;
}
int main()
{
	int a;
	DIEM d1, *d2=new DIEM(9.35);
cout<<"d1: ";	d1.Xuat();
cout<<"\nd2: ";	d2->Xuat(); cout<<endl;
	return 0;
}
