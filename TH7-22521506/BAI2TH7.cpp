#include <bits/stdc++.h>
#include <iomanip> 
using namespace std;
class Nhanvien{
    protected:
        string Hoten;
        int ngaysinh;
        int thangsinh;
        int namsinh;
        double Luong;
    public:
        Nhanvien(string Hoten="", int ngaysinh=0,int thangsinh=0, int namsinh=0, double Luong=0);
        ~Nhanvien();
        string getHoten();
        int getngaysinh();
        int getthangsinh();
        int getnamsinh();
        double getLuong();
        bool KTngaythangnam();
        void setHoten(string Hoten);
        void setngaysinh(int ngaysinh);
        void setthangsinh(int thangsinh);
        void setnamsinh(int namsinh);
        void setLuong(double Luong);
        virtual void Nhap();
        virtual void Xuat() const ;
        virtual double TinhLuong()=0;
};

class NVVP :public Nhanvien{
    private:
        int Songaylam;
    public:
        NVVP(string Hoten="", int ngaysinh=0,int thangsinh=0, int namsinh=0, double Luong=0, int Songaylam =0);
        ~NVVP();
        int getSongaylam();
        void setSongaylam(int Songaylam);
        void Nhap();
        void Xuat() const ;
        double TinhLuong();
};

class NVSX: public Nhanvien{
    private:
        int Sosp;
        float luongcb;
    public:
        NVSX(string Hoten="", int ngaysinh=0,int thangsinh=0, int namsinh=0, double Luong=0, int Sosp=0, float luongcb=0);
        ~NVSX();
        int getSosp();
        float getluongcb();
        void setSosp(int Sosp);
        void setluongcb(float luongcb);
        void Nhap();
        void Xuat()const;  
        double TinhLuong();
};

Nhanvien::Nhanvien(string Hoten,int ngaysinh,int thangsinh, int namsinh, double Luong){
    this->Hoten=Hoten;
    this->ngaysinh=ngaysinh;
    this->thangsinh=thangsinh;
    this->namsinh=namsinh;
    this->Luong=Luong;
}
Nhanvien::~Nhanvien(){};
void Nhanvien::setHoten(string Hoten){
    this->Hoten=Hoten;
}
void Nhanvien::setngaysinh(int ngaysinh){
    this->ngaysinh=ngaysinh;
} 
void Nhanvien::setthangsinh(int thangsinh){
    this->thangsinh=thangsinh;
}
void Nhanvien::setnamsinh(int namsinh){
    this->namsinh=namsinh;
}
void Nhanvien::setLuong(double Luong){
    this->Luong=Luong;
}
string Nhanvien::getHoten(){
    return Hoten;
}
int Nhanvien::getngaysinh(){
    return ngaysinh;
}
int Nhanvien::getthangsinh(){
    return thangsinh;
}
int Nhanvien::getnamsinh(){
    return namsinh;
}
double Nhanvien::getLuong(){
    return Luong;
}
bool Nhanvien::KTngaythangnam(){
    if (ngaysinh < 1 || thangsinh < 1 || thangsinh > 12 || namsinh < 1900 || namsinh > 2023) {
        return false;
    }
    if (thangsinh == 2) {
        if ((namsinh % 4 == 0 && namsinh % 100 != 0) || namsinh % 400 == 0) {
            if (ngaysinh > 29) {
                return false;
            }
        } else {
            if (ngaysinh > 28) {
                return false;
            }
        }
    } else if (thangsinh == 4 || thangsinh == 6 || thangsinh == 9 || thangsinh == 11) {
        if (ngaysinh > 30) {
            return false;
        }
    } else {
        if (ngaysinh > 31) {
            return false;
        }
    }
    return true;
}

void Nhanvien::Nhap() {
    cin.ignore();
    cout << "Ho ten nhan vien: ";
    getline(cin, Hoten);
    do {
        cout << "Nhap ngay/thang/nam sinh: ";
        cin >> ngaysinh >> thangsinh >> namsinh;
        if (!KTngaythangnam()) {
            cout << "Ngay thang nam sinh khong hop le. Vui long nhap lai.\n";
        }
    } while (!KTngaythangnam());
}

void Nhanvien::Xuat()const {
    cout<<"\nHo va ten: "<<Hoten<<endl;
    cout<<"Ngay/ thang/ nam sinh: "<<ngaysinh<<"/"<<thangsinh<<"/"<<namsinh<<endl;
}
NVVP::NVVP(string Hoten, int ngaysinh, int thangsinh, int namsinh, double Luong, int Songaylam){
    this->Songaylam=Songaylam;
}
NVVP::~NVVP(){}
int NVVP::getSongaylam(){
    return Songaylam;
}
void NVVP::setSongaylam(int Songaylam){
    this->Songaylam=Songaylam;
}
void NVVP::Nhap(){
    Nhanvien::Nhap();
    cout<<"Nhap vao so ngay lam viec: "; cin>>Songaylam;
   

}
void NVVP::Xuat()const {
    Nhanvien::Xuat();
    cout<<"So ngay lam viec: "<<Songaylam;
     cout<<"\nTien luong duoc nhan: "<<fixed<<setprecision(0)<<Luong<<endl;
}
double NVVP::TinhLuong(){
Luong = Songaylam*100000;
return Luong;
}

NVSX::NVSX(string Hoten, int ngaysinh, int thangsinh, int namsinh, double Luong, int Sosp, float luongcb){
    this->Sosp=Sosp;
    this->luongcb= luongcb;
}
NVSX::~NVSX(){}
int NVSX::getSosp(){
    return Sosp;
}
float NVSX::getluongcb(){
    return luongcb;
}
void NVSX::setSosp(int Sosp){
    this->Sosp=Sosp;
}
void NVSX::setluongcb(float luongcb){
    this->luongcb=luongcb;
}
void NVSX::Nhap(){
    Nhanvien::Nhap();
    cout<<"Nhap vao muc luong co ban: ";
    cin>>luongcb;
    cout<<"Nhap vao so san pham da lam duoc: ";
    cin>>Sosp;
}
void NVSX::Xuat() const {
    cout<< "\nNhan vien san xuat: ";
    Nhanvien::Xuat();
    cout<<"So san pham: "<<Sosp<<endl;
    cout<<"Tien luong duoc nhan: "<<fixed<<setprecision(0)<<Luong<<endl;
}
double NVSX::TinhLuong(){
    Luong = luongcb + Sosp * 5000;
    return Luong;
}

int main(){
    int m,n;
    cout<<"Nhap so nhan vien van phong: ";
    cin>>n;
    NVVP **Nvvanphong = new NVVP*[n];
    for (int i=0; i<n; i++){
        Nvvanphong[i]= new NVVP();
        Nvvanphong[i]->Nhap();
        Nvvanphong[i]->setLuong(Nvvanphong[i]->TinhLuong());
    }

   cout<<"\nNhap so nhan vien san xuat: ";
   cin>>m;
   NVSX **Nvsanxuat = new NVSX*[m];

   for (int i=0; i<m; i++){
   Nvsanxuat[i]= new NVSX();
    Nvsanxuat[i]->Nhap();
    Nvsanxuat[i]->setLuong(Nvsanxuat[i]->TinhLuong());
   } 

   cout<<"\n=====================================\n";
   cout<<"Danh sach nhan vien:\n";
   for (int i=0; i<n; i++){
    Nvvanphong[i]->Xuat();
   }
   for (int i=0; i<m;i++){
    Nvsanxuat[i]->Xuat();
   }

   for (int i=0; i<n;i++){
    delete Nvvanphong[i];
   }
   delete[] Nvsanxuat;
   return 0;
}

   