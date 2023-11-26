#include <iostream>
#include <ctime>
using namespace std;
class CDate{
    private:
        int day, month,year;
    public:
    ~CDate();
    CDate();
    CDate(int);
    CDate(int, int);
    CDate(int, int,int);
    int getday() const ;
    int getmonth() const ;
    int getyear() const ;
    void setday(int);
    void setmonth(int);
    void setyear(int);
    bool Kiemtrahople(int &, int &, int &);
    CDate operator--(int);
    CDate operator++(int);
    friend istream &operator>>(istream& is, CDate &time);
    friend ostream &operator<<(ostream& os, CDate &time);

};
CDate::~CDate(){

}
CDate::CDate(){
     time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
}
CDate::CDate(int day){ 
     time_t now = time(0);
   tm *ltm = localtime(&now);
    this->day=day;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
    if(Kiemtrahople(day, month, year)){
         this->day=day;
    month=5;
    year=2023;}
    else {
        day=1;
        month=1;
        year=2023;
    }
}
CDate::CDate(int day, int month){
    time_t now = time(0);
   tm *ltm = localtime(&now);
    this->day=day;
    this->month=month;
    year = 1900 + ltm->tm_year;
    year=2023;
    if (Kiemtrahople(day, month, year)){
         this->day=day;
    this->month=month;
    year=2023;}
    else {
        day=1; month=1; year=2023;
    }
}
CDate::CDate(int day, int month, int year){
    this->day=day;
    this->month=month;
    this->year=year;
    if (Kiemtrahople(day, month, year)){
         this->day=day;
    this->month=month;
    this->year=year;}
    else {
        day=1; month=1; year=2023;
    }
}
void CDate::setday(int day){
    this->day=day;
}
void CDate::setmonth(int month){
    this->month=month;
}
void CDate::setyear(int year){
    this->year=year;
}
int CDate::getday() const {
    return day;
}
int CDate::getmonth() const {
    return month;
}
int CDate::getyear() const {
    return year;   
}
bool CDate::Kiemtrahople(int &day, int &month, int &year){
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
            is>>time.day;
            cout<<"Nhap thang: ";
            is>>time.month;
            cout<<"Nhap nam: ";
            is>>time.year;
            Check=time.Kiemtrahople(time.day, time.month, time.year);
            if (Check==false) {cout<<"Du lieu nhap vao khong hop le. Vui long nhap lai: "<<endl;}
        }
        while(Check==false);
        return is;
        }
        ostream &operator<<(ostream &os, CDate &time){
            os<<"Ngay "<<time.day<<" thang "<<time.month<<" nam "<<time.year;
            return os;
        }
        CDate CDate::operator++(int time){
         CDate date;
        date.day= this->day;
        date.month=this->month;
        date.year=this->year;
        date.day++;
        switch(date.month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:{
                if (date.day >31){
                    date.day = 1;
                    date.month ++;
                    if (date.month> 12){
                        date.year ++;
                        date.month=1;
                    }
                }
            break;
            }
            case 4: case 6: case 9: case 11:{
                if (date.day >30){
                    date.day =1;
                    date.month++;
                }
            break;
            }
            case 2:{
                if ((date.year % 4 ==0 && date.year % 100 !=0)|| (date.year % 400 ==0)){
                    if (date.day >29){
                        date.day =1;
                        date.month++;
                    }
                }
                else {
                    if (date.day >28){
                        date.day=1;
                        date.month++;
                    }
                }
                break;
            }

        } return date;
    }
    CDate CDate::operator--(int time){
        CDate date;
        date.day= this->day;
        date.month=this->month;
        date.year=this->year;
        date.day--;
        if (day ==0 ||day==1){
            date.month--;
            switch (date.month){
                case 1: case 3: case 5 : case 7: case 8: case 10:{
                    date.day=31;
                    break;
                }
                case 0:{
                    date.day = 31;
                    date.month=12;
                    date.year--;
                    break;
                }
                case 4: case 6: case 9: case 11:{
                    date.day=30;
                    break;
                }
                case 2:{
                    if ((date.year % 4 ==0 && date.year % 100!=0)|| (date.year% 400 ==0))
                        date.day=29;
                    else 
                        date.day=28;
                }
            }
        } return date;
    }
    int main(){
        CDate A;
        cout<<"Ngay hom nay la: "<<A<<endl;
        CDate congthemA=A++;
        cout<<"Du lieu tang them 1 ngay la: "<<congthemA<<endl;
        CDate trudiA = A--;
        cout<<"Du lieu tru di 1 ngay la: "<<trudiA<<endl<<endl;

        CDate B(1);
        cout<<B<<endl;
        CDate congthemB=B++;
        cout<<"Du lieu tang them 1 ngay la: "<<congthemB<<endl;
        CDate trudiB = B--;
        cout<<"Du lieu tru di 1 ngay la: "<<trudiB<<endl<<endl;

        CDate C(1,4);
        cout<<C<<endl;
        CDate congthemC=C++;
        cout<<"Du lieu tang them 1 ngay la: "<<congthemC<<endl;
        CDate trudiC = C--;
        cout<<"Du lieu tru di 1 ngay la: "<<trudiC<<endl<<endl;

        CDate D(30,2,2004);
        cout<<D<<endl;
        CDate congthemD=D++;
        cout<<"Du lieu tang them 1 ngay la: "<<congthemD<<endl;
        CDate trudiD = D--;
        cout<<"Du lieu tru di 1 ngay la: "<<trudiD<<endl<<endl;

        CDate time;
        cout<<"Nhap vao ngay, thang, nam:"<<endl;
        cin>>time;
        cout<<"Du lieu sau khi nhap vao la: "<<time<<endl;
        CDate Congthemngay = time++;
        cout<<"Du lieu tang them 1 ngay la: "<<Congthemngay<<endl;
        CDate Trudingay = time--;
        cout<<"Du lieu tru di 1 ngay la: "<<Trudingay<<endl;
        return 0;
     }