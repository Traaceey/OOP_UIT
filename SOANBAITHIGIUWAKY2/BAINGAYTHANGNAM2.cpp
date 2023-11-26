#include <iostream>
using namespace std;
class CDate{
    private:
        int ngay, thang, nam;
    public:
        CDate(int = 0, int = 0, int = 0);
        ~CDate();
        bool Kiemtra(int &, int &, int &);
        CDate operator++();
        CDate operator++(int );
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
        CDate CDate::operator++(int ){
       CDate day=*this;
       ++(*this);
       return day;
    }
    CDate CDate::operator++(){
    ++ngay; // Tăng ngày của đối tượng hiện tại lên 1
    switch(thang){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(ngay>31){ // Nếu ngày vượt quá 31 thì tăng tháng
                ngay=1;
                thang++;
                if(thang>12){ // Nếu tháng vượt quá 12 thì tăng năm
                    thang=1;
                    nam++;
                }
            }
            break;
        case 4: case 6: case 9: case 11:
            if(ngay>30){
                ngay=1;
                thang++;
            }
            break;
        case 2:
            if(((nam%4==0)&&(nam%100!=0))||(nam%400==0)){
                if(ngay>29){
                    ngay=1;
                    thang++;
                }
            }
            else{
                if(ngay>28){
                    ngay=1;
                    thang++;
                }
            }
            break;
    }
    return *this; // Trả về một đối tượng CDate
}

    int main(){
         CDate currentDate;
    std::cout << "Nhap vao thoi gian: " << std::endl;
    std::cin >> currentDate;
    std::cout << "Thoi gian vua gap la: " << currentDate << std::endl;
    std::cout << "Thoi gian 1 ngay sau la ";
    ++currentDate;
    std::cout << currentDate << std::endl;
    std::cout << "Thoi gian 1 ngay truoc la: ";
    CDate previousDate = currentDate++;
    std::cout << currentDate << std::endl;
    std::cout << "Thoi gian goc la: " << previousDate << std::endl;
    
    }