#include <iostream>
#include "cstring"

using namespace std;

class CString {
private:
    char * data;
    int length;

public:
    // Constructors
    CString() {
        length = 0;
        data = new char[1];
        data[0] = '\0'; // Empty string
    }

    CString(const CString& str) {
        length = str.getLength();
        data = new char[length+1];
        strcpy(data, str.getData());
    }
    
    CString(const char * str) {
        length = strlen(str);
        data = new char[length+1];
        strcpy(data, str);
    }

    // Destructor
    ~CString() {
        delete [] data;
    }

    // Getter and Setter methods
    const char * getData() const {
        return data;
    }

    const int getLength() const {
        return length;
    }

    // String concatenation
    CString operator+(const CString& str) const {
        CString newStr;
        newStr.length = length + str.getLength();
        newStr.data = new char[newStr.getLength()+1];
        strcpy(newStr.data, data);
        strcat(newStr.data, str.getData());
        return newStr;
    }

    // String assignment operator
    CString& operator=(const CString& str) {
        if (&str == this) {
            return *this;
        }
        delete [] data;
        length = str.getLength();
        data = new char[length+1];
        strcpy(data, str.getData());
        return *this;
    }

    // String comparison operators
    bool operator==(const CString& str) const {
        return strcmp(data, str.getData()) == 0;
    }

    bool operator!=(const CString& str) const {
        return !(*this == str);
    }

    bool operator<(const CString& str) const {
        return strcmp(data, str.getData()) < 0;
    }

    bool operator>(const CString& str) const {
        return strcmp(data, str.getData()) > 0;
    }
};

int main() {
    char str1[100];
    char str2[100];

    cout << "Nhap chuoi thu nhat: ";
    cin.getline(str1, 100);

    cout << "Nhap chuoi thu hai: ";
    cin.getline(str2, 100);

    CString cstr1(str1);
    CString cstr2(str2);

    CString sum = cstr1 + cstr2;
    cout << "Tong 2 chuoi: " << sum.getData() << endl;

    if (cstr1 == cstr2) {
        cout << "Hai chuoi bang nhau" << endl;
    }
    else if (cstr1 > cstr2) {
        cout << "Chuoi 1 lon hon chuoi 2" << endl;
    }
    else if (cstr1 < cstr2) {
        cout << "Chuoi 1 nho hon chuoi 2" << endl;
    }

    return 0;
}
