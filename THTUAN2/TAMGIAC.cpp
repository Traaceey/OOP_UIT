#include <iostream> 
#include <math.h>
#include <string.h>
using namespace std;
#define epsilon 0.0000000001
class Tamgiac{
    private: float  a,b,c;
    public:
        Tamgiac(float = 1, float = 1, float = 1);
        ~Tamgiac();
        void Seta(float );
        void Setb(float);
        void Setc(float );
        void Setabc(float, float, float);
        float Geta();
        float Getb();
        float Getc();   
        void Nhap();
        void Xuat();
        bool KiemTraTamGiacHople();
        void PhanloaiTamgiac( );
        float TinhchuviTamgiac();
        float TinhdientichTamgiac();

};
Tamgiac::~Tamgiac(){
    //cout<<"Da huy tam giac\n";
}
Tamgiac::Tamgiac(float a, float b, float c){
    this->a=a;
    this->b=b;
    this->c=c;
}
float Tamgiac::Geta(){
    return a; 
}
float Tamgiac:: Getb(){
    return b;
}
float Tamgiac:: Getc(){
    return c;
}
void Tamgiac::Seta(float a){
    this->a=a;
}
void Tamgiac::Setb(float b){
    this->b=b;
}
void Tamgiac::Setc(float c){
    this->c=c;
}
void Tamgiac:: Setabc(float a, float b, float c){
    this->a=a;
    this->b=b;
    this->c=c;
}


void Tamgiac::Nhap(){
    cout<<"Nhap do dai 3 canh tam giac: "<<endl;
    cin>>a>>b>>c;
}
void Tamgiac::Xuat(){
    cout<<"3 canh cua tam giac la: "<<a<<" "<<b<<" "<<c<<endl;
}

bool Tamgiac:: KiemTraTamGiacHople(){
    if (a+c>c &&  a+b>b && b+c>a) return 1;
    return 0;
}
void Tamgiac::PhanloaiTamgiac(){
	if (!KiemTraTamGiacHople()) cout<<"Tam giac khong hop le\n";
	else if (a==b&& b==c)
		cout<<"Tam giac deu\n";
	else if (a==b || b==c || c==a){
		if (abs(a*a+b*b-c*c)<= epsilon || abs(a*a+c*c-b*b)<=epsilon || abs(b*b+c*c-a*a)<= epsilon )
			cout<<"Tam giac vuong can\n";
		else cout<<" Tam giac can\n"; 	}
	else if (abs(a*a+b*b-c*c)<= epsilon || abs(a*a+c*c-b*b)<=epsilon || abs(b*b+c*c-a*a)<= epsilon )
		cout<< "Tam giac vuong\n";
	else cout<<"Tam giac thuong\n";
}
float Tamgiac:: TinhchuviTamgiac(){
    return a+b+c;
}
float Tamgiac:: TinhdientichTamgiac(){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
    Tamgiac tg;
    int chon;
    do{
        cout<<"\n-------------------CHUONG TRINH TAM GIAC-------------------\n";
        cout<<"1. Nhap vao 3 canh tam giac\n";
        cout<<"2. Xuat 3 canh tam giac\n";
        cout<<"3. Kiem tra tam giac hop le\n";
        cout<<"4. Phan loai tam giac\n";
        cout<<"5. Tinh chu vi tam giac\n";
        cout<<"6. Tinh dien tich tam giac\n";
        cout<<"0. Thoat chuong trinh\n";
        cout<<"--------------------------------\n";
        cout<<"Moi ban chon\n";
        cin>>chon;
    switch(chon){
        case 0:
            cout<<"Dang thoat chuong trinh\n";
            break;
        case 1:
            tg.Nhap();
            break;
        case 2:
            tg.Xuat();
            break;
        case 3:
            if (tg.KiemTraTamGiacHople()==1) cout<<"Tam giac hop le\n";
            else cout<<"Tam giac khong hop le\n";
            break;
        case 4:
            tg.PhanloaiTamgiac();
            break;
        case 5:
            cout<<"Chu vi tam giac: "<<tg.TinhchuviTamgiac()<<endl;
            break;
        case 6:
            cout<<"Dien tich tam giac: "<<tg.TinhdientichTamgiac()<<endl;
        default:
            cout<<"Ban chon sai. Moi chon lai: "<<endl;
            break;
                }
    }
    while (chon!=0);
    
    return 0;
}