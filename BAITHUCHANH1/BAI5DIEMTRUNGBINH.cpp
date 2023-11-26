#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Sinhvien{
	float toan,van;
	string Hoten;
};
void Nhap( Sinhvien &sv){
	cout<<"Nhap vao ho va ten: ";
	getline(cin,sv.Hoten);
	do {cout<<"Nhap vao diem van: ";
	cin>>sv.van;} while (sv.van<0 || sv.van>10);
	do {cout<<"Nhap vao diem toan: ";
	cin>>sv.toan;
	} while (sv.toan<0|| sv.toan>10 );}
void Xeploai(Sinhvien &sv){
	float dtb = (sv.van +sv.toan)/2;
	cout<<"Diem trung binh: "<<fixed<<setprecision (2)<<dtb<<"\n";
	cout<<"Xep loai: ";
	if (dtb>=9) cout<<"Xuat sac";
	else if (dtb >=8) cout<<"Gioi";
	else if (dtb >=7 ) cout<<"Kha";
	else if (dtb >=5 ) cout<<"Trung binh";
	else cout<<"Yeu";
	
		}
int main(){
	Sinhvien sv;
	Nhap( sv);
	Xeploai(sv);
	return 0;
}

