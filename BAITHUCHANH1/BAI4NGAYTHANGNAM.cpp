#include <iostream>
using namespace std;
bool namnhuan(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{return true;}
	return false;
}
int Ngaytrongthang(int m, int y)
{	int maxday;
	switch (m)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: maxday = 31; break;
	case 4:case 6:case 9:case 11: maxday = 30;break;
	case 2:
		if (namnhuan(y))
		{
			maxday = 29;
		}
		else
		{
			maxday = 28;
		}
		break;
	}

	return maxday;
}
bool Ngayhople(int d, int m, int y)
{
	bool Kiemtra = true; 
	if (!(y > 0 && m))
	{
		Kiemtra = false; 
	}
	if (!(m >= 1 && m <= 12))
	{
		Kiemtra = false; 
	}
	if (!(d >= 1 && d <= Ngaytrongthang(m, y)))
	{
		Kiemtra = false; 
	}
	return Kiemtra;
}
void Ngaytieptheo(int& d, int& m, int& y)
{
	d++;
	if (d> Ngaytrongthang(m, y))
	{
		d = 1;
		m++;
		if (m > 12)
		{
			m = 1;
			y++;
		}
	}
}

int main()
{
	int d, m, y;
	cout << "Nhap ngay: ";
	cin >> d;

	cout << "Nhap thang: ";
	cin >> m;

	cout << "Nhap nam: ";
	cin >> y;

	if (Ngayhople(d, m, y))
	{
		int nd = d;
		int nm = m;
		int ny = y;
	Ngaytieptheo(nd, nm, ny);
		cout << "Ngay tiep theo: " << nd << " / " << nm << " / " << ny << endl;
	}
	else
	{
		cout << "Ngay khong hop le." << endl;
	}

	return 0;
}

