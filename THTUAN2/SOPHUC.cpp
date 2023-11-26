#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
class SoPhuc{
	private :
		double thuc, ao;
	public:
		SoPhuc(double = 0 , double = 0 );
		void setthuc();
		void setao();
		int getthuc();
		int getao();
		void Nhap();
		void Xuat();
		friend SoPhuc operator+(const SoPhuc&, const SoPhuc&);
		friend SoPhuc operator-(const SoPhuc&, const SoPhuc&);
		friend SoPhuc operator*(const SoPhuc&, const SoPhuc&);
		friend SoPhuc operator/(const SoPhuc&, const SoPhuc&);
		/*SoPhuc Cong(SoPhuc);
		SoPhuc Tru(SoPhuc);
		SoPhuc Nhan(SoPhuc);
		SoPhuc Chia(SoPhuc);*/
		friend bool operator==(const SoPhuc&, const SoPhuc&);
		friend bool operator!=(const SoPhuc&, const SoPhuc&);
		friend bool operator<(const SoPhuc&, const SoPhuc&);
		friend bool operator<=(const SoPhuc&, const SoPhuc&);
		friend bool operator>(const SoPhuc&, const SoPhuc&);
		friend bool operator>=(const SoPhuc&, const SoPhuc&);
		friend istream& operator>>(istream&, SoPhuc&);
		friend ostream& operator<<(ostream&, SoPhuc&);
		~SoPhuc();
};
SoPhuc::SoPhuc(double thuc, double ao){
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
SoPhuc operator+(const SoPhuc& sp1, const SoPhuc& sp2){
	return SoPhuc(sp1.thuc + sp2.thuc, sp1.ao+sp2.thuc );
}
SoPhuc operator-(const SoPhuc& sp1, const SoPhuc& sp2){
	return SoPhuc(sp1.thuc - sp2.thuc, sp1.ao + sp2.ao);
}
SoPhuc operator*(const SoPhuc& sp1, const SoPhuc& sp2){
	return SoPhuc(sp1.thuc*sp2.thuc - sp1.ao*sp2.ao, sp1.thuc*sp2.ao + sp1.ao * sp2.thuc );
}
SoPhuc operator/(const SoPhuc& sp1, const SoPhuc& sp2){
	return SoPhuc((sp1.thuc*sp2.thuc + sp1.ao*sp2.ao)/(sp2.thuc*sp2.thuc + sp2.ao* sp2.ao), (sp1.ao*sp2.thuc + sp1.thuc * sp2.ao)/(sp2.thuc*sp2.thuc + sp2.ao* sp2.ao));
}
void SoPhuc::Nhap(){
	cout<<"\nNhap phan thuc: "; cin>>thuc;
	cout<<"Nhap phan ao: "; cin>>ao;
}
void SoPhuc::Xuat(){
	cout<<"("<<thuc<<" , "<<ao<<")";
}
/*SoPhuc SoPhuc::Cong(SoPhuc sp2){
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
}*/
SoPhuc::~SoPhuc(){
	
}
int main(){
	SoPhuc sp1, sp2,cong,tru,nhan,chia;
	int chon;
	/*do{
		cout<<"\n---------------CHUONG TRINH TINH SO PHUC---------------\n";
		cout<<"1. Nhap vao toa do so phuc\n"; 
		cout<<"2. Xuat ra toa do so phuc\n";
		cout<<"3. Cong 2 so phuc\n";
		cout<<"4. Tru 2 so phuc\n";
		cout<<"5. Nhan 2 so phuc\n";
		cout<<"6. Chia 2 so phuc\n";
		cout<<"0. Thoat chuong trinh\n";		
		cout<<"----------------------------------------------------------\n";
		cout<<"Moi ban chon: ";
		cin>>chon;
	    switch(chon){
			case 0:
				cout<<"Dang thoat chuong trinh\n";
				break;
			case 1:
				cout<<"Nhap cac so phuc: ";
				//sp1.Xuat();
				sp1.Nhap();
				sp2.Nhap();
				break;
			case 2:
				cout<<"Cac so phuc la: \n";
				sp1.Xuat();
				sp2.Xuat();
				break;
			case 3:
				cong = sp1.Cong(sp2);
				cout<<"\nTong 2 so phuc: "; cong.Xuat();
				break;
			case 4:
				tru = sp1.Tru(sp2);
				cout<<"\nHieu 2 so phuc: "; tru.Xuat();
				break;
			case 5:
				nhan = sp1.Nhan(sp2);
				cout<<"\nTich 2 so phuc: "; nhan.Xuat();
				break;
			case 6:
				chia = sp1.Chia(sp2);
				cout<<"\nThuong 2 so phuc: "; chia.Xuat();
				break;
			default :
				cout<<"Ban chon sai. Moi chon lai\n";
				break;	 
		}
	} while (chon!=0);*/ 
	return 0;
}
