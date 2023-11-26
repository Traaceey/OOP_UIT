#include<iostream>
#include<math.h>
using namespace std;
struct Phanso
{
	int tu;
	int mau;
};
void NhapPS(Phanso &x)
{
	cout<<"Nhap Tu so: "; cin>>x.tu;
	do
	{
		cout<<"Nhap Mau so: "; 
		cin>>x.mau;
		if(x.mau==0)
			cout<<"Nhap sai, yeu cau nhap lai mau so: ";
	}while(x.mau==0);
}
void XuatPS(Phanso x)
{
	cout<<x.tu<<"/"<<x.mau;
}
int UCLN(int x1, int x2){
    int t;
    while (x2!=0){
        t= x1%x2;
        x1=x2;
        x2=t;
    }
return abs(x1);
}
void TongPS(Phanso x1, Phanso x2)
{
	int tu, mau,tu2,mau2;
	tu = (x1.tu*x2.mau + x1.mau*x2.tu);
	mau = (x1.mau*x2.mau);
	tu2=tu/UCLN(tu,mau);
	mau2=mau/UCLN(tu,mau);
	if (mau2==1) cout<<"\nTong 2 phan so la: "<<tu2;
	else  if (mau2==-1) cout<<"\nTong 2 phan so la: "<<-tu2;
	else if (mau2<0) cout<<"\nTong 2 phan so la: "<<-tu2<<"/"<<-mau2;
	 else cout<<"\nTong 2 phan so la: "<<tu2<<"/"<<mau2;
}
void HieuPS(Phanso  x1, Phanso x2)
{
	int tu, mau,tu2,mau2;
	tu = x1.tu*x2.mau - x1.mau*x2.tu;
	mau = x1.mau*x2.mau;
	tu2=tu/UCLN(tu,mau);
	mau2=mau/UCLN(tu,mau);
	if (mau2==1) cout<<"\nHieu 2 phan so la: "<<tu2;
	else  if (mau2==-1) cout<<"\nHieu 2 phan so la: "<<-tu2;
 	else if (mau2<0) cout<<"\nHieu 2 phan so la: "<<-tu<<"/"<<-mau2;
	 else cout<<"\nHieu 2 phan so la: "<<tu2<<"/"<<mau2;
}
void  TichPS(Phanso x1, Phanso x2)
{
	int tu, mau,tu2,mau2;
	tu = x1.tu * x2.tu;
	mau = x1.mau * x2.mau;
	tu2=tu/UCLN(tu,mau);
	mau2=mau/UCLN(tu,mau);
	if (mau2==1) cout<<"\nTich 2 phan so la: "<<tu2;
	else  if (mau2==-1) cout<<"\nTich 2 phan so la: "<<-tu2;
 	else if (mau2<0) cout<<"\nTich 2 phan so la: "<<-tu<<"/"<<-mau2;
	 else cout<<"\nTich 2 phan so la: "<<tu2<<"/"<<mau2;
}
void ThuongPS(Phanso x1, Phanso x2)
{
	int tu, mau,tu2,mau2;
	tu = x1.tu * x2.mau;
	mau = x1.mau * x2.tu;
	tu2=tu/UCLN(tu,mau);
	mau2=mau/UCLN(tu,mau);
	if (mau2==1) cout<<"\nTich 2 phan so la: "<<tu2;
	else  if (mau2==-1) cout<<"\nTich 2 phan so la: "<<-tu2;
 	else if (mau2<0) cout<<"\nTich 2 phan so la: "<<-tu<<"/"<<-mau2;
	else cout<<"\nTich 2 phan so la: "<<tu2<<"/"<<mau2;
}
int  main() 
{ 
	Phanso ps1, ps2;
	NhapPS(ps1);
	NhapPS(ps2);
 	TongPS(ps1, ps2);
 	HieuPS(ps1, ps2);
	TichPS(ps1, ps2);
 	ThuongPS(ps1, ps2);
	cout<<endl;return 0;
}

