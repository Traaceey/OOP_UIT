#include <iostream>
using namespace std;
void Nhap(int &g, int &p, int &giay){
  do {cout<<"Nhap gio: \n"; cin>>g;} while (g<0 || g>18);
  do {cout<<"Nhap phut: \n"; cin>>p;} while (p<0 || p>60);
  do {cout<<"Nhap giay: \n"; cin>>giay;} while (giay<0 || giay>60);
 }
void Thoigianvaolam(int g, int p, int giay){
cout<<"Nhap thoi gian vao lam: ";
Nhap(g,p,giay);
}
void Thoigiantanlam(int g, int p, int giay){
	cout<<"Nhap thoi gian tan lam: ";
	Nhap(g,p,giay);
	}
void Tinhtien(int t, int &g, int &p, int &giay){
	if (g<12)
int main(){
	int g, p, giay;
	Thoigianvaolam(g,p,giay);
	Thoigiantanlam(g,p,giay);
	return 0;
}
	
