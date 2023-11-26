#include <iostream>
using namespace std;
int main (){
	float dtb;
	cout<<"Nhap vao diem trung binh: ";
	cin>>dtb;
	while (dtb<0 || dtb>10 ) cout<<"Nhap lai diem trung binh: "; 
	if (dtb>=9) cout<<"Xuat sac";
	else if (dtb >=8) cout<<"Gioi";
	else if (dtb >=7 ) cout<<"Kha";
	else if (dtb >=5 ) cout<<"Trung binh";
	else cout<<"Yeu";
return 0;
}

