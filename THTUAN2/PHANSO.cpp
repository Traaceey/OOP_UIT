#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
using namespace std;
class PhanSo{
	private: 
		int tuso,mauso;
	public:
		PhanSo();
		PhanSo(int  , int );
		int gettuso();
		int getmauso();
		void settumau(int =0, int =0);
		void Nhap();
		void Xuat();
		int UCLN(int a, int b);
		void Rutgon();
		PhanSo Cong(PhanSo);
		PhanSo Tru(PhanSo);
		PhanSo Nhan(PhanSo);
		PhanSo Chia(PhanSo);
		~PhanSo();
};
  PhanSo::PhanSo(){
 
 }
 PhanSo:: PhanSo (int tuso, int mauso){
 	this->tuso=tuso;
 	this->mauso=mauso;
 }
 int PhanSo::gettuso(){
 	return tuso;
 }
 int PhanSo::getmauso(){
 	return mauso;
 }
 void PhanSo::settumau(int tu, int mau){
 	this->tuso=tuso;
 	this->mauso=mauso;
 }
 void PhanSo::Nhap(){
 	cout<<"Nhap tu so: "; cin>>tuso;
 	do {
	 	cout<<"Nhap mau so: "; cin>>mauso;
	 	if (mauso==0) cout<<"Mau so khong hop le. Nhap lai: \n";
 		}
 	while (mauso==0);
 }
 void PhanSo::Xuat(){
 	int uc=UCLN(tuso,mauso);
 	if (mauso<0){
 	tuso=-tuso; mauso=-mauso;}
	else {
		tuso=tuso; mauso=mauso;	
	}
	 tuso=tuso/abs(uc);
	 mauso=mauso/abs(uc);
	if (mauso==0) cout<<"Ket qua khong hop le";
	else if (mauso==1) cout<<tuso<<endl;
	else  if (mauso==-1) cout<<-tuso<<endl;
 	else if (mauso<0) cout<<-tuso<<"/"<<-mauso<<endl;
	else cout<<tuso<<"/"<<mauso<<endl;
 }
 int PhanSo::UCLN(int a, int b){
 	a= abs(a);
 	b=abs(b);
 	while (a!=0 && b!=0)
 	{
 		if (a>b)
 		{
 			a=a-b;
		 }
		else 
		{
			b=b-a;
		}
	 }
	if (a==0)
	{ 
	return b;
	}
	else 
	{
		return a;
	}
 }
 void PhanSo::Rutgon()
 {
 	int uc=UCLN(tuso,mauso);
 	if (mauso<0){
 	tuso=-tuso; mauso=-mauso;}
	else {
		tuso=tuso; mauso=mauso;	
	}
 	cout<<tuso/abs(uc)<<"/"<<mauso/abs(uc)<<endl;
}
PhanSo PhanSo::Cong(PhanSo ps2)
{
	PhanSo tong;
	tong.tuso = tuso*ps2.mauso + mauso*ps2.tuso;
	tong.mauso= mauso*ps2.mauso;
	return tong;
}
PhanSo PhanSo::Tru(PhanSo ps2){
	PhanSo hieu;
	hieu.tuso= tuso*ps2.mauso - mauso*ps2.tuso;
	hieu.mauso= mauso*ps2.mauso;
	return hieu;
}
PhanSo PhanSo::Nhan(PhanSo ps2)
{
	PhanSo tich;
	tich.tuso= tuso*ps2.tuso;
	tich.mauso= mauso*ps2.mauso;
	return tich;
}
PhanSo PhanSo::Chia(PhanSo ps2)
{   
	PhanSo thuong;
	thuong.tuso= tuso*ps2.mauso;
	thuong.mauso= mauso*ps2.tuso;
	return thuong;
}
 PhanSo::~PhanSo(){
 	
 }
 int main(){
 	PhanSo ps1(0,1), ps2(0,1), cong, tru, nhan, chia;
	int chon;
    do {
		cout<<"\n----------------CHUONG TRINH TINH PHAN SO----------------\n";
		cout<<"1. Nhap 2 phan so\n";
		cout<<"2. Xuat 2 phan so\n";
		cout<<"3. Cong 2 phan so\n";
		cout<<"4. Tru 2 phan so\n";
		cout<<"5. Nhan 2 phan so\n";
		cout<<"6. Chia 2 phan so\n";
		cout<<"0. Thoat chuong trinh\n";
		cout<<"--------------------------\n";
		cout<<"Moi chon: \n";
		cin>>chon;
		switch(chon){
			case 0:
				cout<<"Dang thoat chuong trinh\n";
				break;
			case 1:
				cout<<"Nhap cac phan so: "<<endl;
				ps1.Nhap();
				ps2.Nhap();
				break;
			case 2:
				cout<<"Xuat 2 phan so: \n";
				ps1.Xuat();
				ps2.Xuat();
				break;
			case 3:
				cong = ps1.Cong(ps2);
 				cout<<"Tong 2 phan so: "; cong.Xuat();
				break;
			case 4:
				tru=ps1.Tru(ps2);
 	            cout<<"\nHieu 2 phan so: "; tru.Xuat();
				break;
			case 5:
				nhan = ps1.Nhan(ps2);
  				cout<<"\nNhan 2 phan so: "; nhan.Xuat();
				break;
			case 6:
				chia = ps1.Chia(ps2);	
 				cout<<"\nChia 2 phan so: "; chia.Xuat();
				break;
			default:
				cout<<"\nChon sai. Moi chon lai: \n";
				break;
		}
	} while (chon!=0);
	return 0;
 }
 
