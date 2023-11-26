#include <iostream>
#include <math.h>
using namespace std;
struct PhanSo {
    int tu, mau;
};
int bcnn (int a, int b){
	int max;
if(a>b)  max=a;
else max=b;
int i=max;
int BCNN;
while (1){
if( i%a==0 && i%b==0) {  BCNN = i; break;}
i=i+max;}
return BCNN;}
int UCLN(int x, int y){
    int t;
    while (y!=0){
        t= x%y;
        x=y;
        y=t;
    }
return abs(x);
}
void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do {
        cout << "Nhap mau so: ";
        cin >> ps.mau;
    } while (ps.mau == 0);
}
void nhap2PhanSo(PhanSo &ps1, PhanSo &ps2) {
    cout << "Nhap phan so thu nhat: " << endl;
    nhapPhanSo(ps1);
    cout << "Nhap phan so thu hai: " << endl;
    nhapPhanSo(ps2);
}
void Sosanh(PhanSo &ps1, PhanSo &ps2){
	while (ps2.mau==0); 
if (ps1.mau==ps2.mau){
		if (ps1.tu>ps2.tu) cout<<"Phan so thu nhat "<<ps1.tu<<"/"<<ps1.mau<<" lon hon phan so thu hai "<<ps2.tu<<"/"<<ps2.mau;
		else if (ps1.tu<ps2.tu) cout<<"Phan so thu nhat "<<ps1.tu<<"/"<<ps1.mau<<" lon hon phan so thu hai "<<ps2.tu<<"/"<<ps2.mau;
		else cout<<"Hai phan so" << ps1.tu<<"/"<<ps1.mau <<"bang nhau";}
else {
	int x,y;
	x= ps1.tu*(bcnn(ps1.mau,ps2.mau)/ps1.mau);
	y=ps2.tu*(bcnn(ps1.mau,ps2.mau)/ps2.mau);
	if(x>y) cout<<"Phan so thu nhat "<<ps1.tu<<"/"<<ps1.mau<<" lon hon phan so thu hai "<<ps2.tu<<"/"<<ps2.mau;
	else if(x<y) cout<<"Phan so thu nhat "<<ps1.tu<<"/"<<ps1.mau<<" nho hon phan so thu hai "<<ps2.tu<<"/"<<ps2.mau;
	else cout<<"Hai phan so" << ps1.tu<<"/"<<ps1.mau <<"bang nhau";	} 
	}
int main() {
    PhanSo ps1, ps2;
    nhap2PhanSo(ps1, ps2);
    Sosanh(ps1, ps2);
    return 0;
}

