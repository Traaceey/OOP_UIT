#include <iostream>
#include <math.h>
using namespace std;
#define epsilon 0.0000000001
#define PI 3.141592
// #define PI atan(1) * 4
class DIEM
{
protected:
    double x, y;
    static int dem;

public:
    ~DIEM();
    DIEM(double = 0, double = 0);
    DIEM(const DIEM &);
    double GetX() const;
    double GetY() const;
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    bool KiemTraTrung(const DIEM &) const;
    double TinhKhoangCach(const DIEM &) const;
    DIEM TimDoiXung() const;
    bool KiemTraTamGiacHopLe(const DIEM &, const DIEM &) const;
    double TinhChuViTamGiac(const DIEM &, const DIEM &) const;
    double TinhDienTichTamGiac(const DIEM &, const DIEM &) const;
    string PhanLoaiTamGiac(const DIEM &, const DIEM &) const;
    friend istream &operator>>(istream &, DIEM &);
    friend ostream &operator<<(ostream &, const DIEM &);
};
int DIEM::dem = 0;
DIEM::~DIEM()
{

    cout << "Da huy 1 DIEM 2C => con " << --dem << " diem 2C\n";
}
DIEM::DIEM(double x, double y) : x(x), y(y)
{
    cout << "Da tao 1 diem 2C => co " << ++dem << " diem 2C\n";
    // this->x=x;
    // this->y=y;
}
DIEM::DIEM(const DIEM &d) : x(d.x), y(d.y)
{
    cout << "Da tao 1 diem 2C => co " << ++dem << " diem 2C\n";
}
double DIEM::GetX() const
{
    return x;
}
double DIEM::GetY() const
{
    return y;
}
int DIEM::GetDem()
{
    return dem;
}
void DIEM::SetX(double x)
{
    this->x = x;
}
void DIEM::SetY(double y)
{
    this->y = y;
}
void DIEM::SetXY(double x, double y)
{
    this->x = x;
    this->y = y;
}
void DIEM::Nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}
void DIEM::Xuat() const
{
    cout << "(" << x << " , " << y << ")";
}
void DIEM::DiChuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}
bool DIEM::KiemTraTrung(const DIEM &d) const
{
    return x == d.x && y == d.y;
}
double DIEM::TinhKhoangCach(const DIEM &d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
DIEM DIEM::TimDoiXung() const
{
    return DIEM(-x == 0 ? x : -x, -y == 0 ? y : -y);
}
bool DIEM::KiemTraTamGiacHopLe(const DIEM &d1, const DIEM &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}
double DIEM::TinhChuViTamGiac(const DIEM &d1, const DIEM &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return KiemTraTamGiacHopLe(d1, d2) ? a + b + c : 0;
}
double DIEM::TinhDienTichTamGiac(const DIEM &d1, const DIEM &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return KiemTraTamGiacHopLe(d1, d2) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}
string DIEM::PhanLoaiTamGiac(const DIEM &d1, const DIEM &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    string chuoikq = " ";
    if (!KiemTraTamGiacHopLe(d1, d2))
        chuoikq = "Tam giac khong hop le";
    else if (a == b && b == c)
        chuoikq = "Tam giac deu";
    else if (a == b || b == c || c == a)
        if (abs(a * a + b * -c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
            chuoikq = "Tam giac vuong can";
        else
            chuoikq = " Tam giac can";
    else if (abs(a * a + b * -c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
        chuoikq = "Tam giac vuong";
    else
        chuoikq = "Tam giac thuong";
    return chuoikq;
}
istream &operator>>(istream &is, DIEM &d)
{
    d.Nhap();
    return is;
}
ostream &operator<<(ostream &os, DIEM &d)
{
    d.Xuat();
    return os;
}
class HINHTRON : public DIEM
{
private:
    double R;
    static int dem;

public:
    HINHTRON(double = 0, double = 0, double = 1);
    HINHTRON(DIEM, double = 1);
    ~HINHTRON();
    double GetR();
    void SetR(double);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const HINHTRON &) const;
    double TinhChuVi() const;
    double TinhDienTich() const;
    friend istream &operator>>(istream &, HINHTRON &);
    friend ostream &operator<<(ostream &, HINHTRON &);
};
int HINHTRON::dem = 0;
HINHTRON::~HINHTRON()
{
    cout << "Da Huy 1 Hinh Trong\n";
    dem--;
}
HINHTRON::HINHTRON(double x, double y, double R) : DIEM(x, y)
{
    SetR(R);
    dem++;
}
HINHTRON::HINHTRON(DIEM O, double R) : DIEM(O)
{
    SetR(R);
    dem++;
}
int HINHTRON::GetDem()
{
    return dem;
}
double HINHTRON::GetR()
{
    return R;
}
void HINHTRON::SetR(double R)
{
    while (R <= 0)
    {
        cout << "Nhap lai ban kinh R>0: ";
        cin >> R;
    }
    this->R = R;
}
void HINHTRON::Nhap()
{
    cout << " Nhap toa do tam O:\n";
    DIEM::Nhap();
    do
    {
        cout << "Nhap ban kinh R>0: ";
        cin >> R;
    } while (R <= 0);
}
void HINHTRON::Xuat() const
{
    cout << "Hinh tron ban kinh R = " << R << " tam O la ";
    DIEM::Xuat();
    cout << "Chu vi la " << TinhChuVi() << ", Dien tich la " << TinhDienTich() << endl;
}
bool HINHTRON::KiemTraTrung(const HINHTRON &ht) const
{
    return DIEM::KiemTraTrung(ht) && R == ht.R;
}
double HINHTRON::TinhChuVi() const
{
    return 2 * PI * R;
}
double HINHTRON::TinhDienTich() const
{
    return PI * R * R;
}
istream &operator>>(istream &is, HINHTRON &ht)
{
    ht.Nhap();
    return is;
}
ostream &operator<<(ostream &os, HINHTRON &ht)
{
    ht.Xuat();
    return os;
}
int main()
{
    cout << "So hinh tron hien tai la: " << HINHTRON::GetDem() << endl;
    HINHTRON ht1, ht2(DIEM(1, 2), 3), *ht3 = new HINHTRON;
    cout << "So hinh tron hien tai la: " << HINHTRON::GetDem() << endl;
    cout << ht1 << ht2 << *ht3 << endl;
    cout << "Nhap lai hinh tron 3:\n";
    cin >> *ht3;
    cout << "Hinh tron 3 moi la: " << *ht3 << endl;
    ht3->DiChuyen(-1, 1);
    cout << "Hinh tron 3 sau khi di chuyen (-1,1) la: " << *ht3 << endl;
    delete ht3;
    cout << "So hinh tron hien tai la: " << HINHTRON::GetDem() << endl;
    system("pause");
    return 0;
}