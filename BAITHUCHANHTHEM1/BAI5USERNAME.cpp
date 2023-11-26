#include <iostream>
using namespace std;
int main(){
	string mk = "UIT2023";
	string username = "N120";
	string ps,un;
	cout<<"Nhap username\n";
	cin>>un;
	cout<<"Nhap password: ";
	cin>>ps;
	if (username == un && mk==ps) cout<<"Xin chao "<<username;
	else {
	int i=1; while (i<3){
		cout<<"Nhap lai password: ";
		cin>>ps;
		if (mk==ps) {
			cout<<"Xin chao "<<username; break;}
		else i++;} 
		 if (i>=3)cout<<"Loi";
	}
	return 0;}


