#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
class SoPhuc{
	private :
		int thuc, ao;
	public:
		SoPhuc();
		SoPhuc(int , int );
		void setthuc();
		void setao();
		int getthuc();
		int getao();
		void Nhap();
		void Xuat();
		SoPhuc Cong(SoPhuc);
		SoPhuc Tru(SoPhuc);
		SoPhuc Nhan(SoPhuc);
		SoPhuc Chia(SoPhuc);
		~SoPhuc();
};
SoPhuc::SoPhuc(){
	
}
SoPhuc::SoPhuc(int thuc, int ao){
this->thuc=thuc;
this->ao=ao;
}
void SoPhuc::setthuc(){
	this->thuc=thuc;
}
void SoPhuc::setao(){
	this->ao=ao;
}
int SoPhuc::getthuc(){
	return thuc;
}
int SoPhuc::getao(){
	return ao;
}
void SoPhuc::Nhap(){
	cout<<"\nNhap phan thuc: "; cin>>thuc;
	cout<<"Nhap phan ao: "; cin>>ao;
}
void SoPhuc::Xuat(){
	cout<<"("<<thuc<<" , "<<ao<<")";
}
SoPhuc SoPhuc::Cong(SoPhuc sp2){
	SoPhuc tong;
	tong.thuc = thuc+ sp2.thuc;
	tong.ao=  ao + sp2.ao;
	return tong;
}
SoPhuc SoPhuc::Tru(SoPhuc sp2)
{
	SoPhuc hieu;
	hieu.thuc= thuc - sp2.thuc;
	hieu.ao= ao - sp2.ao;
	return hieu;
}
SoPhuc SoPhuc::Nhan(SoPhuc sp2)
{
	SoPhuc tich;
	tich.thuc= thuc * sp2.thuc - ao* sp2.ao;
	tich.ao = thuc * sp2.thuc + ao* sp2.ao;
	return tich;
}
SoPhuc SoPhuc::Chia(SoPhuc sp2)
{
	SoPhuc thuong;
	thuong.thuc= (thuc*sp2.thuc + ao * sp2.ao)/(sp2.thuc * sp2.thuc) + (sp2.ao*sp2.ao);
	thuong.ao= (thuc*sp2.thuc - ao * sp2.ao)/(sp2.thuc * sp2.thuc) + (sp2.ao*sp2.ao);
}
SoPhuc::~SoPhuc(){
	
}
int main(){
	SoPhuc sp1, sp2,cong,tru,nhan,chia;
	cout<<"Nhap cac so phuc: ";
	sp1.Nhap();
	sp2.Nhap();
	cong = sp1.Cong(sp2);
	cout<<"\nTong 2 so phuc: "; cong.Xuat();
	tru = sp1.Tru(sp2);
	cout<<"\nHieu 2 so phuc: "; tru.Xuat();
	nhan = sp1.Nhan(sp2);
	cout<<"\nTich 2 so phuc: "; nhan.Xuat();
	chia = sp1.Chia(sp2);
	cout<<"\nThuong 2 so phuc: "; chia.Xuat();
	return 0;
}
