#include <iostream>
#include <math.h>
using namespace std;
class PTB1
{
private: 
    double a,b;
    void Giai();
public: 
    PTB1();
    PTB1(double);
    PTB1(double, double);
    void Nhap();
    void Xuat(); 
};
PTB1::PTB1(){
    a=b=0;
}
PTB1::PTB1(double b){
    a=0;
    this->b=b;
}
PTB1::PTB1(double a, double b){
    this->a=a;
    this->b=b;
}
void PTB1::Nhap(){
    cout<<"Nhap 2 he so a,b: ";
    cin>>a>>b;
}
void PTB1::Giai(){
    if (a==0) 
        if (b==0)
            cout<<"PT VSN";
        else 
            cout<<"PT VN";
    else cout<<"PT co nghiem x= "<< -b/a;
}
void PTB1::Xuat(){
    cout<<"PTB1: "<<a<<"x+ "<<b<<" =0 => ";
    Giai();
    cout<<endl;
}
class PTB2{
    private:
        double a,b,c;
        void Giai();
    public:
        PTB2();
        PTB2(double);
        PTB2(double, double);
        PTB2(double, double, double);
        void Nhap();
        void Xuat();
};
PTB2::PTB2(){
    a=b=c=0;
}
PTB2::PTB2(double c){
    a=b=0;
    this->c=c;
}
PTB2::PTB2(double b, double c){
    a=0;
    this->b=b;
    this->c=c;
}
PTB2::PTB2(double a, double b, double c){
    this->a=a;
    this->b=b;
    this->c=c;
}
void PTB2::Nhap(){
    cout<<"Nhap 3 he so a, b, c: ";
    cin>>a>>b>>c;
}
void PTB2::Giai(){
    if (a==0){
        PTB1 ptb1(b,c);
        ptb1.Xuat();
    }
    else {
        double delta = b*b - 4*a*c;
        if (delta<0) 
            cout<<"PTVN vi delta <0";
        else if (delta==0)
            cout<<"PT co nghiem kep x1 = x2 = "<<-b/(2*a); 
        else 
            cout<<"PT co hai nghiem phan biet x1 = "<<(-b - sqrt(delta))/(2*a)<<" x2 = "<<
            (-b - sqrt(delta))/(2*a);
    }
}
void PTB2::Xuat(){
    cout<<"PTB2: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0 =>";
    Giai();
    cout<<endl;
}
int main(){
    PTB2* pt;
    int n;
    do {
        cout<<"Nhap so PT: ";
        cin>>n;
    } while (n<=0);
    pt = new PTB2[n];
    for (int i=0; i<n; i++){
        cout<<"Nhap PT thu: "<<i+1<<": \n";
        pt[i].Nhap();
    }
    for (int i=0; i<n; i++)
        pt[i].Xuat();
    return 0;
}
