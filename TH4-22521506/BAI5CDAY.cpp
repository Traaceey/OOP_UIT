#include <iostream>
using namespace std;
class CDate{
    private:
        int ngay, thang, nam;
    public:
        CDate(int = 0, int = 0, int = 0);
        ~CDate();
        bool Kiemtra(int &, int &, int &);
        CDate operator+(int &);
        CDate operator-(int &);
        long operator-(CDate&);
        CDate operator++(int );
        CDate operator--(int );
        friend istream &operator>>(istream& is, CDate &time);
        friend ostream &operator<<(ostream& os, CDate &time);
};
CDate::~CDate(){

}
CDate::CDate(int day, int month, int year){
    ngay=day;
    thang=month;
    nam=year;
}
bool CDate::Kiemtra(int &day, int &month, int&year){
    switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                {
                    if(day<=0|| day>31) return false;
                
                break;
                }
        
            case 4: case 6: case 9: case 11:
                {
                    if (day<=0|| day>30) return false;
                    break;
                }
            case 2:
                {
                    if ((year % 4==0 && year % 100!=0) || year %400==0){
                        if (day<=0|| day>29) return false;}
                    else if (day<=0 || day>28) return false;
                    break;
                }
                
            default:
            {
                return false;
                break;
            }
            return true;
                }
     }
    istream &operator>>(istream &is, CDate &time){
        bool Check;
        do {
            Check = false;
            cout<<"Nhap ngay: ";
            is>>time.ngay;
            cout<<"Nhap thang: ";
            is>>time.thang;
            cout<<"Nhap nam: ";
            is>>time.nam;
            Check=time.Kiemtra(time.ngay, time.thang, time.nam);
            if (Check==false) {cout<<"Du lieu nhap vao khong hop le. Vui long nhap lai: "<<endl;}
        }
        while(Check==false);
        return is;
        }
        ostream &operator<<(ostream &os, CDate &time){
            os<<"Ngay "<<time.ngay<<" thang "<<time.thang<<" nam "<<time.nam;
            return os;
        }
        CDate CDate::operator+(int &time){
            CDate date;
            date.ngay = this->ngay;
            date.thang = this->thang;
            date.nam = this->nam;
            int t= date.ngay + time;
            do {
                switch(date.thang){
                    case 1: case 3: case 5 :case 7: case 8: case 10: case 12:
                    {    if (t>31){
                            date.thang++;
                            if (date.thang==13){
                                date.thang=1;
                                date.nam++;
                            }
                            t-=31;
                        }
                        else {
                            date.ngay=t;
                            t=0;
                        }
                        break;
                }
                    case 4: case 6: case 9: case 11:
                    {
                        if (t>30){
                            date.thang++;
                            t-=30;
                        }
                        else {
                            date.ngay=t;
                            t=0;
                        }
                        break;
                    }
                    case 2:{
                        if((date.nam %4 ==0 && date.nam %100!=0)||(date.nam %400==0)){
                            if (t>29){
                                date.thang++;
                                t-=29;
                            }
                            else {
                                date.ngay = t;
                                t=0;
                            }
                        }
                        break;
                    }
            }
        } while (t>0);
        return date;
        }
    CDate CDate::operator-(int &time){
        CDate date;
        date.ngay= this->ngay;
        date.thang=this->thang;
        date.nam=this->nam;
        int t = time;
        do {
            if (date.ngay>t){
                date.ngay-=t;
                t=0;
            }
            else {
                t-=date.ngay;
                date.thang--;
                switch(date.thang){
                    case 1: case 3: case 5: case 7: case 8: case 10:{
                        date.ngay = 31;
                        break;
                    }
                    case 4: case 6: case 9: case 11:{
                        date.ngay=30;
                        break;
                    }
                    case 2: {
                        if ((date.nam % 4 ==0 && date.nam % 100 !=0) || (date.nam % 400 ==0))
                            date.ngay=29;
                        else 
                            date.ngay = 28;
                        break;
                    }
                    case 0:{
                        date.thang=12;
                        date.nam--;
                        date.ngay=31;
                        break;
                    }
                }
            }
        } while (t>0);
        return date;
    }
    
    long CDate::operator-(CDate &time){
        CDate date;
        date.ngay= this->ngay;
        date.thang=this->thang;
        date.nam=this->nam;
        long t1=date.ngay;
        do{
            switch (date.thang){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
                    t1+=31;
                    date.thang--;
                    if (date.thang==0){
                        date.nam--;
                        date.thang=12;
                    }
                    break;
                }
                case 4: case 6: case 9: case 11:{
                    t1+=30;
                    date.thang--;
                    break;
                }
                case 2:{
                    if ((date.nam % 4 ==0 && date.nam % 100 !=0)||(date.nam % 400 ==0)){
                        t1+=29;
                        date.thang--;
                    }
                    else {t1 +=28;
                    date.thang--;
                }
                break;
            }
        }
    } while (date.nam >0);
    date.ngay = time.ngay;
    date.thang = time.thang;
    date.nam= time.nam;
    long t2 = date.ngay;
    do {
        switch(date.thang){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
                t2+=31;
                date.thang--;
                if (date.thang ==0){
                    date.nam--;
                    date.thang=12;
                }
                break;
            }
            case 4: case 6 : case 9: case 11:{
                t2+=30;
                date.thang--;
                break;
            }
            case 2:{
                if ((date.nam % 4 ==0 && date.nam % 100 !=0)||(date.nam % 400==0)){
                    t2+=29;
                    date.thang--;
                }
                else {
                    t2+=28;
                    date.thang--;
                }
                break;

            }
        }
    } while (date.nam >0);
    return abs(t1-t2);
    }
    CDate CDate::operator++(int time){
         CDate date;
        date.ngay= this->ngay;
        date.thang=this->thang;
        date.nam=this->nam;
        date.ngay++;
        switch(date.thang){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
                if (date.ngay >31){
                    date.ngay = 1;
                    date.thang ++;
                    if (date.thang> 12){
                        date.nam ++;
                        date.thang=1;
                    }
                }
            break;
            }
            case 4: case 6: case 9: case 11:{
                if (date.ngay >30){
                    date.ngay =1;
                    date.thang++;
                }
            break;
            }
            case 2:{
                if ((date.nam % 4 ==0 && date.nam % 100 !=0)|| (date.nam % 400 ==0)){
                    if (date.ngay >29){
                        date.ngay =1;
                        date.thang++;
                    }
                }
                else {
                    if (date.ngay >28){
                        date.ngay=1;
                        date.thang++;
                    }
                }
                break;
            }

        } return date;
    }
    CDate CDate::operator--(int time){
        CDate date;
        date.ngay= this->ngay;
        date.thang=this->thang;
        date.nam=this->nam;
        date.ngay--;
        if (ngay ==0){
            date.thang--;
            switch (date.thang){
                case 1: case 3: case 5 : case 7: case 8: case 10:{
                    date.ngay=31;
                    break;
                }
                case 0:{
                    date.ngay = 31;
                    date.thang=12;
                    date.nam--;
                    break;
                }
                case 4: case 6: case 9: case 11:{
                    date.ngay=30;
                    break;
                }
                case 2:{
                    if ((date.nam % 4 ==0 && date.nam % 100!=0)|| (date.nam% 400 ==0))
                        date.ngay=29;
                    else 
                        date.ngay=28;
                }
            }
        } return date;
    }
     int main(){
        CDate time;
        cout<<"Nhap vao ngay, thang, nam:"<<endl;
        cin>>time;
        cout<<"Du lieu sau khi nhap vao la: "<<time<<endl;
        cout<<"Nhap vao so ngay cong them: ";
        int ngaycong;
        cin>>ngaycong;
        CDate Cong = time + ngaycong;
        cout<<"Du lieu sao khi cong them la: "<<Cong<<endl;
        cout<<"Nhap so ngay tru di: ";
        int ngaytru;
        cin>>ngaytru;
        CDate Tru= time - ngaytru;
        cout<<"Du lieu sau khi tru di la: "<<Tru<<endl;
        cout<<"Nhap vao du lieu ngay thang nam muon tru: "<<endl;
        CDate dulieutru;
        cin>>dulieutru;
        cout<<"Du lieu vua nhap la: "<<dulieutru<<endl;
        long CTimespan = time - dulieutru;
        cout<<"Khoang cach giua 2 du lieu la: "<<CTimespan<<" ngay"<<endl;
        CDate Congthemngay = time++;
        cout<<"Du lieu tang them 1 ngay la: "<<Congthemngay<<endl;
        CDate Trudingay = time--;
        cout<<"Du lieu tru di 1 ngay la: "<<Trudingay<<endl;
        return 0;
     }