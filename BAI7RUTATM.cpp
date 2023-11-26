#include <iostream>
#include <math.h>
using namespace std;
int main(){
int t,x,y,z,k;
cout<<"Nhap lai so tien can doi: ";
	cin>>t;
while (t<50000 || t%50000!=0){
	cout<<"Nhap lai so tien can doi: ";
	cin>>t;
} 
	x=t/500000;
	t=t%500000;
 	y= t/200000;
	t=t%200000;
	z = t/100000;
	t=t%100000;
k= t/50000;
	t=t%50000;
cout<<"So to 500k: "<<x<<" to\n";
cout<<"So to 200k: "<<y<<" to\n";
cout<<"So to 100k: "<<z<<" to\n";
cout<<"So to 50k: "<<k<<" to\n";
return 0;}

