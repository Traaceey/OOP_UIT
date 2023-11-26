#include <iostream>
#include <math.h>
using namespace std;
#define PI atan(1) * 4
#define epsilon 0.0000000001

class DIEM
{
private:
    double x, y;
    static int dem;

public:
    ~DIEM();
    DIEM(double = 0, double = 0);
    double GetX() const;
    double GetY() const;
    static int GetDem();
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    bool KiemTraTrung(const DIEM &) const;
    double TinhKhoangCach(const DIEM &) const;
    DIEM TimDiemDoiXung() const;
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
    dem--;
    // cout<<"Da huy 1 diem => con "<<--dem<< " diem\n";
}
DIEM::DIEM(double xx, double yy)
{
    x = xx;
    y = yy;
    dem++;
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
    SetX(x);
    SetY(y);
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
    cout << "(" << x << " , " << y << " )";
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
DIEM DIEM::TimDiemDoiXung() const
{
    return DIEM(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
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
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return KiemTraTamGiacHopLe(d1, d2) ? a + b + c : 0;
}
double DIEM::TinhDienTichTamGiac(const DIEM &d1, const DIEM &d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return KiemTraTamGiacHopLe(d1, d2) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}
string DIEM::PhanLoaiTamGiac(const DIEM &d1, const DIEM &d2) const
{
    string kq;
    if (!KiemTraTamGiacHopLe(d1, d2))
        kq = "Tam giac khong hop le";
    else
    {
        double a = TinhKhoangCach(d1);
        double b = d1.TinhKhoangCach(d2);
        double c = d2.TinhKhoangCach(*this);
        if (a == b && b == c)
            kq = "Tam giac deu";
        else if (a == b || b == c || c == a)
            if (abs(a * a + b * -c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
                kq = "Tam giac vuong can";
            else
                kq = " Tam giac can";
        else if (abs(a * a + b * -c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
            kq = "Tam giac vuong";
        else
            kq = "Tam giac thuong";
    }
    return kq;
}
istream &operator>>(istream &is, DIEM &d)
{
    d.Nhap();
    return is;
}
ostream &operator<<(ostream &os, const DIEM &d)
{
    d.Xuat();
    return os;
}
class HCN
{
private:
    DIEM A, B;
    static int dem;

public:
    ~HCN();
    HCN(DIEM = DIEM(), DIEM = DIEM());
    DIEM GetA() const;
    DIEM GetB() const;
    void SetA(DIEM);
    void SetB(DIEM);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    double TinhChuVi() const;
    double TinhDienTich() const;
    bool KiemTraHopLe() const;
    friend istream &operator>>(istream &, HCN &);
    friend ostream &operator<<(ostream &, const HCN &);
};

int HCN::dem = 0;
HCN::~HCN()
{
    dem--;
}
HCN::HCN(DIEM AA, DIEM BB)
{
    A = AA;
    B = BB;
    dem++;
}
DIEM HCN::GetA() const
{
    return A;
}
DIEM HCN::GetB() const
{
    return B;
}
void HCN::SetA(DIEM AA)
{
    A = AA;
}
void HCN::SetB(DIEM BB)
{
    B = BB;
}
int HCN::GetDem()
{
    return dem;
}
void HCN::Nhap()
{
    do
    {
        cout << "Nhap toa do 2 dinh A va B cua hinh chu nhat:\n";
        cout << "Nhap toa do dinh A:\n";
        cin >> A;
        cout << "Nhap toa do dinh B:\n";
        cin >> B;
        if (A.GetX() == B.GetX() || A.GetY() == B.GetY())
        {
            cout << "2 diem da nhap khong phai la 2 dinh cua hinh chu nhat. Hay nhap lai!\n";
        }
    } while (A.GetX() == B.GetX() || A.GetY() == B.GetY());
}
void HCN::Xuat() const
{
    cout << "2 dinh A va B cua hinh chu nhat la: \n";
    cout << "Dinh A: " << A << "\n";
    cout << "Dinh B: " << B << "\n";
}
void HCN::DiChuyen(double dx, double dy)
{
    A.DiChuyen(dx, dy);
    B.DiChuyen(dx, dy);
}
double HCN::TinhChuVi() const
{
    double a = abs(A.GetX() - B.GetX());
    double b = abs(A.GetY() - B.GetY());
    return 2 * (a + b);
}
double HCN::TinhDienTich() const
{
    double a = abs(A.GetX() - B.GetX());
    double b = abs(A.GetY() - B.GetY());
    return a * b;
}
bool HCN::KiemTraHopLe() const
{
    return A.GetX() != B.GetX() && A.GetY() != B.GetY();
}
istream &operator>>(istream &is, HCN &h)
{
    h.Nhap();
    return is;
}
ostream &operator<<(ostream &os, const HCN &h)
{
    h.Xuat();
    return os;
}
int main()
{
    DIEM A, B;

    cout << "Nhap toa do diem A:\n ";
    cin >> A;
    cout << "Nhap toa do diem B:\n ";
    cin >> B;

    HCN hcn(A, B);

    cout << "Chu vi hinh chu nhat: " << hcn.TinhChuVi() << endl;
    cout << "Dien tich hinh chu nhat: " << hcn.TinhDienTich() << endl;
    return 0;
}