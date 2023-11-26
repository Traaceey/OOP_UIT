#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

class SoPhuc{
    private :
        double thuc, ao;
        
    public:
        SoPhuc(double t = 0 , double a = 0 ){
            thuc = t;
            ao = a;
        }
        
        void Nhap();
        void Xuat();

        friend SoPhuc operator+(const SoPhuc&, const SoPhuc&);
        friend SoPhuc operator-(const SoPhuc&, const SoPhuc&);
        friend SoPhuc operator*(const SoPhuc&, const SoPhuc&);
        friend SoPhuc operator/(const SoPhuc&, const SoPhuc&);
        
        friend bool operator==(const SoPhuc&, const SoPhuc&);
        friend bool operator!=(const SoPhuc&, const SoPhuc&);
        friend bool operator<(const SoPhuc&, const SoPhuc&);
        friend bool operator<=(const SoPhuc&, const SoPhuc&);
        friend bool operator>(const SoPhuc&, const SoPhuc&);
        friend bool operator>=(const SoPhuc&, const SoPhuc&);
        
        friend istream& operator>>(istream&, SoPhuc&);
        friend ostream& operator<<(ostream&, SoPhuc&);
        
        ~SoPhuc();
};

void SoPhuc::Nhap(){
    cout << "Nhap phan thuc: ";
    cin >> thuc;
    cout << "Nhap phan ao: ";
    cin >> ao;
}

void SoPhuc::Xuat(){
    if (thuc == 0 && ao == 0){
        cout << "0";
    } else if (thuc != 0 && ao == 0){
        cout << thuc;
    } else if (thuc == 0 && ao != 0){
        if (ao > 0) {
            cout << ao << "i";
        } else {
            cout << "- " << abs(ao) << "i";
        }
    } else {
        if (ao > 0) {
            cout << thuc << " + " << ao << "i";
        } else {
            cout << thuc << " - " << abs(ao) << "i";
        }
    }
}

SoPhuc::~SoPhuc(){
    
}

SoPhuc operator+(const SoPhuc& sp1, const SoPhuc& sp2){
    return SoPhuc(sp1.thuc + sp2.thuc, sp1.ao + sp2.ao);
}

SoPhuc operator-(const SoPhuc& sp1, const SoPhuc& sp2){
    return SoPhuc(sp1.thuc - sp2.thuc, sp1.ao - sp2.ao);
}

SoPhuc operator*(const SoPhuc& sp1, const SoPhuc& sp2){
    return SoPhuc(sp1.thuc*sp2.thuc - sp1.ao*sp2.ao, sp1.thuc*sp2.ao + sp1.ao*sp2.thuc);
}

SoPhuc operator/(const SoPhuc& sp1, const SoPhuc& sp2){
    double tu = sp1.thuc*sp2.thuc + sp1.ao*sp2.ao;
    double mau = sp2.thuc*sp2.thuc + sp2.ao*sp2.ao;
    double t1 = sp1.ao*sp2.thuc - sp1.thuc*sp2.ao;

    return SoPhuc(tu/mau, t1/mau);
}

bool operator==(const SoPhuc& sp1, const SoPhuc& sp2){
    return (sp1.thuc == sp2.thuc) && (sp1.ao == sp2.ao);
}

bool operator!=(const SoPhuc& sp1, const SoPhuc& sp2){
    return !(sp1 == sp2);
}

bool operator>(const SoPhuc& sp1, const SoPhuc& sp2){
    double abs1 = sqrt(sp1.thuc*sp1.thuc + sp1.ao*sp1.ao);
    double abs2 = sqrt(sp2.thuc*sp2.thuc + sp2.ao*sp2.ao);
    return abs1 > abs2;
}

bool operator>=(const SoPhuc& sp1, const SoPhuc& sp2){
    return (sp1 == sp2) || (sp1 > sp2);
}

bool operator<(const SoPhuc& sp1, const SoPhuc& sp2){
    double abs1 = sqrt(sp1.thuc*sp1.thuc + sp1.ao*sp1.ao);
    double abs2 = sqrt(sp2.thuc*sp2.thuc + sp2.ao*sp2.ao);
    return abs1 < abs2;
}

bool operator<=(const SoPhuc& sp1, const SoPhuc& sp2){
    return (sp1 == sp2) || (sp1 < sp2);
}

istream& operator>>(istream& is, SoPhuc& sp){
    cout << "Nhap phan thuc:";
    is >> sp.thuc;
    cout << "Nhap phan ao:";
    is >> sp.ao;
    return is;
}

ostream& operator<<(ostream &os, SoPhuc& sp){
    sp.Xuat();
    return os;
}

int main(){
    SoPhuc sp1, sp2;
    cout << "Nhap so phuc thu 1: " << endl;
    cin >> sp1;
    cout << "So phuc thu 1 co dang: ";
    sp1.Xuat();
    cout << endl;

    cout << "Nhap so phuc thu 2: " << endl;
    cin >> sp2;
    cout << "So phuc thu 2 co dang: ";
    sp2.Xuat();
    cout << endl;

    cout << "\nCac phep toan voi 2 so phuc tren: " << endl;

    SoPhuc Cong = sp1 + sp2;
    cout << sp1 << " + " << sp2 << " = " << Cong << endl;

    SoPhuc Tru = sp1 - sp2;
    cout<<sp1<<" - "<<sp2<<" = "<<Tru<<endl;

    SoPhuc Nhan = sp1 * sp2;
cout << sp1 << " * " << sp2 << " = " << Nhan << endl;

SoPhuc Chia = sp1 / sp2;
cout << sp1 << " / " << sp2 << " = " << Chia << endl;

cout << "\nSo sanh 2 so phuc: "<<endl;
if(sp1 == sp2){
    cout << sp1 << " bang " << sp2 << endl;
} else {
    cout << sp1 << " khac " << sp2 << endl;
}

if(sp1 != sp2){
    cout << sp1 << " khac " << sp2 << endl;
} else {
    cout << sp1 << " bang " << sp2 << endl;
}

if(sp1 > sp2){
    cout << sp1 << " lon hon " << sp2 << endl;
} else if(sp1 < sp2) {
    cout << sp1 << " nho hon " << sp2 << endl;
} else {
    cout << sp1 << " bang " << sp2 << endl;
}

if(sp1 >= sp2){
    cout << sp1 << " lon hon hoac bang " << sp2 << endl;
} else {
    cout << sp1 << " nho hon " << sp2 << endl;
}

if(sp1 <= sp2){
    cout << sp1 << " nho hon hoac bang " << sp2 << endl;
} else {
    cout << sp1 << " lon hon " << sp2 << endl;
}

getch();
return 0;
}
