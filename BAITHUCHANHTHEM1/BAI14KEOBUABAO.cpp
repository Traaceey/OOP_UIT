#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
int n;
//Keo=1; bua=2; bao=3;
cout<<"Moi ban chon: \n";
cout<<"1.Keo\n"<<"2.Bua\n"<<"3.Bao\n";
cin>>n;
while (n!=1 && n!=2 && n!=3) cout<<"Moi chon lai: ";
srand(time(NULL));
int m= rand()%3+1;
if (n==1) cout<<"Ban chon keo\n";
if (n==2) cout<<"Ban chon bua\n";
if (n==3) cout<<"Ban chon bao\n";
if (m==1) cout<<"May chon keo\n";
if (m==2) cout<<"May chon bua\n";
if (m==3) cout<<"May chon bao\n";
if  (n==m) cout<<"Hoa";
if (n==1 && m==2) cout<<"May thang\n";
if (n==1 && m==3) cout<<"Ban thang\n";
if (n==2 && m==1) cout<<"Ban thang\n";
if (n==2 && m==3) cout<<"May thang\n";
if (n==3 && m==1) cout<<"May thang\n";
if (n==3 && m==2) cout<<"Ban thang\n";
return 0;
}

