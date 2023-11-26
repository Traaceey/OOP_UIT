#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Sinhvien{
    protected:
        string Maso, Hoten, Khoa;
        float DTB;
    public:
        Sinhvien(string Maso="", string Hoten="", string Khoa="",float DTB=0);
        ~Sinhvien();
        string getMaso();
        string getHoten();
        string getKhoa();
        float getDTB();
        void setHoten(string Hoten);
        void setKhoa(string Khoa);
        void setDTB(float DTB);
        virtual void Nhap();
        virtual void Xuat() const ;
        virtual float getDRL(); // chỉ dành cho sinh viên chính quy
        virtual int getSBV(); // chỉ dành cho sinh viên liên thông
        virtual void setDRL(float drl); // chỉ dành cho sinh viên chính quy
        virtual void setSBV(int sbv); // chỉ dành cho sinh viên liên thông
};

class SinhvienChinhquy:public Sinhvien{
    private:
        float DRL;
    public:
        SinhvienChinhquy(string Maso="", string Hoten="", string Khoa="", float DTB=0,float DRL=0);
        ~SinhvienChinhquy();
        float getDRL();
        void setDRL(float DRL);
        void Nhap();
        void Xuat() const ;
};

class SinhvienLienthong:public Sinhvien{
    private:
        int SBV;
    public:
        SinhvienLienthong(string Maso="", string Hoten="", string Khoa="", float DTB=0,int SBV=0);
        ~SinhvienLienthong();
        int getSBV();
        void setSBV(int SBV);
        void Nhap();
        void Xuat() const;
};

class TruongDH{
    private:
        int n, m; //n: số lượng sinh viên chính quy, m: số lượng sinh viên liên thông
        SinhvienChinhquy *svCQ;
        SinhvienLienthong *svLT;
    public:
        TruongDH();
        ~TruongDH();
        void NhapDS();
        void XuatDS()const ;
        void Lietke_SVCQ_DRL100();
        int Dem_SVLT_khong_nghi_buoi();
        double Tinh_Tong_Hocbong();
        float Tinh_DTB_SVCQ_co_Hocbong();
        bool Kiemtra_SVLT_DTBtren9_khongnghibuoi();
        void Tim_SVCQ_DTBcao_nhat();
        void Sapxep_DanhSach_Tangdan();
        void Them_Sinhvien();
        void Xoa_Sinhvien();
};

Sinhvien::Sinhvien(string Maso, string Hoten, string Khoa, float DTB){
    this->Maso=Maso;
    this->Hoten=Hoten;
    this->Khoa=Khoa;
    this->DTB=DTB;
}

Sinhvien::~Sinhvien(){}

    string Sinhvien::getMaso(){
    return Maso;
}

string Sinhvien::getHoten(){
    return Hoten;
}

string Sinhvien::getKhoa(){
    return Khoa;
}

float Sinhvien::getDTB(){
    return DTB;
}

void Sinhvien::setHoten(string Hoten){
    this->Hoten=Hoten;
}

void Sinhvien::setKhoa(string Khoa){
    this->Khoa=Khoa;
}

void Sinhvien::setDTB(float DTB){
    this->DTB=DTB;
}

void Sinhvien::Nhap(){
    cin.ignore();
    cout<<"Nhap ma so sinh vien: ";
    getline(cin,Maso); 
    cout<<"Nhap ho ten sinh vien: ";
    getline(cin,Hoten); 
    cout<<"Nhap khoa cua sinh vien: ";
    getline(cin,Khoa); 
    cout<<"Nhap diem trung binh cua sinh vien: ";
    cin>>DTB; 
    while(DTB<0 || DTB>10.0) {
        cout<<"Nhap sai.Moi nhap lai DTB: ";
        cin>>DTB;
}}

void Sinhvien::Xuat ()const{
    cout<<"Thong tin sinh vien:\n";
    cout<<"Ma so: "<<Maso<<endl;
    cout<<"Ho ten: "<<Hoten<<endl;
    cout<<"Khoa: "<<Khoa<<endl;
    cout<<"Diem trung binh: "<<DTB<<endl;
}

float Sinhvien::getDRL(){
    return -1;
}

int Sinhvien::getSBV(){
    return -1;
}

void Sinhvien::setDRL(float DRL){};

void Sinhvien::setSBV(int SBV){};

SinhvienChinhquy::SinhvienChinhquy(string Maso, string Hoten, string Khoa, float DTB, float DRL):Sinhvien(Maso,Hoten,Khoa,DTB){
    this->DRL = DRL;
}

SinhvienChinhquy::~SinhvienChinhquy(){}

    float SinhvienChinhquy::getDRL(){
    return DRL;
}

void SinhvienChinhquy::setDRL(float DRL){
    this->DRL=DRL;
}

void SinhvienChinhquy::Nhap(){
    Sinhvien::Nhap();
    cout<<"Nhap diem ren luyen: ";
    cin>>DRL; 
    while (DRL<0|| DRL>100) {
    cout<<"Nhap sai. Moi nhap lai DRL: ";
    cin>>DRL;
}
}

void SinhvienChinhquy::Xuat() const{
    Sinhvien::Xuat();
    cout<<"Diem ren luyen: "<<DRL<<endl;
}

SinhvienLienthong::SinhvienLienthong(string Maso, string Hoten, string Khoa, float DTB, int SBV):Sinhvien(Maso,Hoten,Khoa,DTB){
    this->SBV=SBV;
}

SinhvienLienthong::~SinhvienLienthong(){}

    int SinhvienLienthong::getSBV(){
    return SBV;
}

void SinhvienLienthong::setSBV(int SBV){
    this->SBV=SBV;
}

void SinhvienLienthong::Nhap(){
    Sinhvien::Nhap();
    cout<<"Nhap so buoi nghi cua sinh vien: ";
    cin>>SBV;
    while (SBV<0){
    cout<<"Nhap sai. Moi nhap lai SBV: ";
    cin>>SBV;
}
}

void SinhvienLienthong::Xuat()const{
    Sinhvien::Xuat();
    cout<<"So buoi nghi: "<<SBV<<endl;
}

TruongDH::TruongDH(){
    n = 0;
    m = 0;
    svCQ = NULL;
    svLT = NULL;
    }

TruongDH::~TruongDH(){
    delete [] svCQ;
    delete [] svLT;
}

void TruongDH::NhapDS(){
    cout<<"Nhap so luong sinh vien chinh quy: ";
    cin>>n;
    svCQ = new SinhvienChinhquy[n];
    for(int i=0;i<n;i++){
    cout<<"Nhap thong tin sinh vien "<<i+1<<endl;
    svCQ[i].Nhap();
    }
    cout<<"Nhap so luong sinh vien lien thong: ";
    cin>>m;
    svLT = new SinhvienLienthong[m];
    for(int i=0;i<m;i++){
    cout<<"Nhap thong tin sinh vien "<<i+1<<endl;
    svLT[i].Nhap();
}
}

void TruongDH::XuatDS() const{
    cout<<"Danh sach sinh vien chinh quy:\n";
    for(int i=0;i<n;i++){
    svCQ[i].Xuat();
    cout<<endl;
    }
    cout<<"Danh sach sinh vien lien thong:\n";
    for(int i=0;i<m;i++){
    svLT[i].Xuat();
    cout<<endl;
}
}

void TruongDH::Lietke_SVCQ_DRL100(){
    bool check = false;
    cout<<"Danh sach sinh vien chinh quy co diem ren luyen 100:\n";
    for(int i=0;i<n;i++){
    if(svCQ[i].getDRL() == 100){
    svCQ[i].Xuat();
    cout<<endl;
    check = true;
    }
    }
    if(!check){
    cout<<"Khong co sinh vien chinh quy nao co diem ren luyen 100\n";
}
}

int TruongDH::Dem_SVLT_khong_nghi_buoi(){
    int count = 0;
    for(int i=0;i<m;i++){
    if(svLT[i].getSBV() == 0){
    count++;
    }
    }
    return count;
}

double TruongDH::Tinh_Tong_Hocbong(){
    double tong = 0;
    for(int i=0;i<n;i++){
    if(svCQ[i].getDRL()>=85){
    if(svCQ[i].getDTB()>=7.5 && svCQ[i].getDTB()<8.5){
    tong += 1000000;
    }
    else if(svCQ[i].getDTB()>=8.5 && svCQ[i].getDTB()<9.5){
    tong += 1200000;
    }
    else if(svCQ[i].getDTB()>=9.5){
    tong += 1500000;
    }
    }
    }
    for(int i=0;i<m;i++){
    if(svLT[i].getSBV()<=3){
    if(svLT[i].getDTB()>=7 && svLT[i].getDTB()<8){
    tong += 1000000;
    }
    else if(svLT[i].getDTB()>=8 && svLT[i].getDTB()<9){
    tong += 1200000;
    }
    else if(svLT[i].getDTB()>=9){
    tong += 1500000;
    }
    }
    }
    return tong;
}

float TruongDH::Tinh_DTB_SVCQ_co_Hocbong(){
    float tongDTB = 0;
    int count = 0;
    for(int i=0;i<n;i++){
    if(svCQ[i].getDRL()>=85){
    if(svCQ[i].getDTB()>=7.5 && svCQ[i].getDTB()<8.5){
    tongDTB += svCQ[i].getDTB();
    count++;
    }
    else if(svCQ[i].getDTB()>=8.5 && svCQ[i].getDTB()<9.5){
    tongDTB += svCQ[i].getDTB();
    count++;
    }
    else if(svCQ[i].getDTB()>=9.5){
    tongDTB += svCQ[i].getDTB();
    count++;
    }
    }
    }
    if(count == 0){
    return -1;
    }
    return tongDTB/count;
}

bool TruongDH::Kiemtra_SVLT_DTBtren9_khongnghibuoi(){
    for(int i=0;i<m;i++){
    if(svLT[i].getDTB()>=9 && svLT[i].getSBV() == 0){
    return true;
    }
    }
    return false;
}

void TruongDH::Tim_SVCQ_DTBcao_nhat(){
    float maxDTB = 0;
    for(int i=0;i<n;i++){
    if(svCQ[i].getDTB()>maxDTB){
    maxDTB = svCQ[i].getDTB();
    }
    }
    cout<<"Danh sach sinh vien chinh quy co diem trung binh cao nhat:\n";
    for(int i=0;i<n;i++){
    if(svCQ[i].getDTB() == maxDTB){
    svCQ[i].Xuat();
    cout<<endl;
}
}
}

void TruongDH::Sapxep_DanhSach_Tangdan(){
    for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
    if(svCQ[i].getMaso() > svCQ[j].getMaso()){
    SinhvienChinhquy tmp = svCQ[i];
    svCQ[i] = svCQ[j];
    svCQ[j] = tmp;
    }
    }
    }
    for(int i=0;i<m-1;i++){
    for(int j=i+1;j<m;j++){
    if(svLT[i].getMaso() > svLT[j].getMaso()){
    SinhvienLienthong tmp = svLT[i];
    svLT[i] = svLT[j];
    svLT[j] = tmp;
    }
    }
    }
    cout<<"Danh sach sinh vien sau khi sap xep tang dan theo ma so:\n";
    XuatDS();
}

void TruongDH::Them_Sinhvien(){
    int k;
    cout<<"Nhap loai sinh vien muon them (1: chinh quy, 2: lien thong): ";
    cin>>k;
    if(k == 1){
    n++;
    SinhvienChinhquy *tmp = new SinhvienChinhquy[n];
    for(int i=0;i<n-1;i++){
    tmp[i] = svCQ[i];
    }
    cout<<"Nhap thong tin sinh vien chinh quy muon them:\n";
    tmp[n-1].Nhap();
    svCQ = tmp;
    }
    else if(k == 2){
    m++;
    SinhvienLienthong *tmp = new SinhvienLienthong[m];
    for(int i=0;i<m-1;i++){
    tmp[i] = svLT[i];
    }
    cout<<"Nhap thong tin sinh vien lien thong muon them:\n";
    tmp[m-1].Nhap();
    svLT = tmp;
    }
    else{
    cout<<"Loai sinh vien khong hop le\n";
}
}
void TruongDH::Xoa_Sinhvien(){
    string maSo;
    cin.ignore();
    cout<<"Nhap ma so sinh vien muon xoa: ";
    getline(cin,maSo);
    bool check = false;
    for(int i=0;i<n;i++){
        if(svCQ[i].getMaso() == maSo){
            check = true;
            for(int j=i;j<n-1;j++){
                svCQ[j] = svCQ[j+1];
            }
            n--;
            SinhvienChinhquy *tmp = new SinhvienChinhquy[n];
            for(int j=0;j<n;j++){
                tmp[j] = svCQ[j];
            }
            svCQ = tmp;
            break;
        }
    }
    if(!check){
        for(int i=0;i<m;i++){
            if(svLT[i].getMaso() == maSo){
                for(int j=i;j<m-1;j++){
                    svLT[j] = svLT[j+1];
                }
                m--;
                SinhvienLienthong *tmp = new SinhvienLienthong[m];
                for(int j=0;j<m;j++){
                    tmp[j] = svLT[j];
                }
                svLT = tmp;
                break;
            }
        }
    }
    if(!check){
        cout<<"Khong tim thay sinh vien!"<<endl;
    }else{
        cout<<"Da xoa sinh vien thanh cong!"<<endl;
    }
}
int main(){
    TruongDH TDH;
    int choice;
    do{
        cout<<"=============MENU==============\n";
        cout<<"1. Nhap danh sach sinh vien\n";
        cout<<"2. Xuat danh sach sinh vien\n";
        cout<<"3. Liet ke danh sach sinh vien chinh quy co diem ren luyen 100\n";
        cout<<"4. Dem so sinh vien lien thong khong co nghi buoi\n";
        cout<<"5. Tinh tong hoc bong sinh vien\n";
        cout<<"6. Tinh diem trung binh sinh vien chinh quy dat học bong\n";
        cout<<"7. Kiem tra sinh vien lien thong co diem trung binh tu 9 tro len va co so buoi vang bang 0\n";
        cout<<"8. Tim cac sinh vien chinh quy co diem trung binh cao nhat\n";
        cout<<"9. Sap xep danh sach sinh vien tang dan theo ma so\n";
        cout<<"10. Them sinh vien vao danh sach\n";
        cout<<"11. Xoa sinh vien ra khoi danh sach\n";
        cout<<"0. Thoat chuong trinh\n";
        cout<<"============================\n";
        cout<<"Moi ban chon: "; cin>>choice;
         switch (choice){
            case 1: 
                TDH.NhapDS();
                break;
            case 2: 
                TDH.XuatDS();
                break;
            case 3:
                TDH.Lietke_SVCQ_DRL100();
                break;
            case 4:
                cout<<"So luong sinh vien lien thong khong co buoi nghi la: "<<TDH.Dem_SVLT_khong_nghi_buoi()<<endl;
                break;
            case 5:
                cout<<"Tong hoc bong cua sinh vien la: "<<fixed<<setprecision(0)<<TDH.Tinh_Tong_Hocbong()<<endl;
                break;
            case 6:
                cout<<"Diem trung binh cua sinh vien chinh quy dat hoc bong la: "<<TDH.Tinh_DTB_SVCQ_co_Hocbong()<<endl;
                break;
            case 7:
                if (TDH.Kiemtra_SVLT_DTBtren9_khongnghibuoi()==1) cout<<"Co sinh vien lien thong co diem trung binh tu 9 tro len va co so buoi vang bang khong"<<endl;
                else cout<<"Khong co sinh vien lien thong co diem trung binh tu 9 tro len va co so buoi vang bang khong"<<endl;
                break;
            case 8:
                TDH.Tim_SVCQ_DTBcao_nhat();
                break;
            case 9:
                TDH.Sapxep_DanhSach_Tangdan();
                break;
            case 10:
                TDH.Them_Sinhvien();
                break;
            case 11:
                TDH.Xoa_Sinhvien();
                break;
            case 0:
                cout<<"Dang thoat chuong trinh!\n";
                break;
            default:
                cout<<"Nhap sai. Moi nhap lai";
                break;
         } 
    } while (choice!=0);
    return 0;
}

