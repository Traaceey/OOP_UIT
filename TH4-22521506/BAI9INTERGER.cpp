#include <iostream>
using namespace std;

class INTEGER {
    int n;
public:
    INTEGER() {        
        n = 0;
    }
    INTEGER(int n) {   
        this->n=n;
    }
    void set(int n) {  
        this->n=n;
    }
    int get() const {  
        return n;
    }
    friend istream& operator>>(istream& is, INTEGER& num) {  
        is >> num.n;
        return is;
    }
    friend ostream& operator<<(ostream& os, const INTEGER& num) { 
        os << num.n;
        return os;
    }
    INTEGER operator+(const INTEGER& num) const {    
        return INTEGER(n + num.n);
    }
    INTEGER operator-(const INTEGER& num) const {    
        return INTEGER(n - num.n);
    }
    INTEGER operator*(const INTEGER& num) const {    
        return INTEGER(n * num.n);
    }
    INTEGER operator/(const INTEGER& num) const {    
        return INTEGER(n / num.n);
    }
    bool operator==(const INTEGER& num) const {  
        return n == num.n;
    }
    bool operator!=(const INTEGER& num) const {  
        return n != num.n;
    }
    bool operator<(const INTEGER& num) const {   
        return n < num.n;
    }
    bool operator>(const INTEGER& num) const {   
        return n > num.n;
    }
    
};

int main() {
    INTEGER n1, n2, kq;
    cout << "Nhap vao so thu nhat: ";
    cin >> n1;
    cout << "Nhap vao so thu hai: ";
    cin >> n2;
    kq = n1 + n2;
    cout <<n1<<" + "<<n2<<" = " << kq << endl;
    kq = n1 - n2;
    cout <<n1<<" - "<<n2<<" = " << kq << endl;
    kq = n1 * n2;
    cout <<n1<<" * "<<n2<<" = " << kq << endl;
    if (n2 == 0) { 
    cout << "Lỗi. Không thể chia cho 0" << endl;
} else {
    kq = n1 / n2;
    cout <<n1<<" / "<<n2<<" = " << kq<<endl;
}
     if (n1 == n2) {
        cout << n1 << " = " << n2 << endl;
    } else if (n1 > n2) {
        cout << n1 << " > " << n2 << endl;
    } else {
        cout << n1 << " < " << n2 << endl;
    }

    return 0;
}
