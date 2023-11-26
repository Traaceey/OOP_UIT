#include <iostream>
using namespace std;
int main(){
int a[1000]; int n;
cout<<"Nhap vao so thap phan: ";
cin>>n;
int i=0;
while (n>0){
a[i] = n%2;
n=n/2;
i++;}
cout<<"So nhi phan la: ";
for (int j=i-1; j>=0; j--) cout<<a[j];
return 0;
}

