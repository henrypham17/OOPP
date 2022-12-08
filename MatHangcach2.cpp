#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class MatHang
{
private:
	string mahang;
	ll dongia;

public:
	void Nhap()
	{
		cout << "Nhap ma hang: ";
		getline(cin, mahang);
		cout << "Nhap don gia: ";
		cin >> dongia;
	}
	void Xuat()
	{
		cout << "|" << mahang << "|" << dongia << "|" << endl;
	}
	ll getDongia()
	{
		return dongia;
	}
	string getMahang()
	{
		return mahang;
	}
};

class HoaDon
{
private:
	string mahang, ngay;
	int soluong;

public:
	void Nhap()
	{
		cout << "Nhap ma hang: ";
		getline(cin, mahang);
		cout << "Nhap so luong: ";
		cin >> soluong;
		cout << "Nhap ngay ban: ";
		cin.ignore();
		getline(cin, ngay);
	}
	void Xuat()
	{
		cout << "|" << mahang << "|" << soluong << "|" << ngay << "|" << endl;
	}
	int getSoluong()
	{
		return soluong;
	}
	string getMahang()
	{
		return mahang;
	}
	string getNgayban()
	{
		return ngay;
	}
};

int main()
{
	int m;
	cout << "Nhap so luong mat hang: ";
	cin >> m;
	cout << "\nNhap thong tin " << m << " mat hang: ";
	MatHang *mh = new MatHang[m];
	for (int i = 0; i < m; i++)
	{
		cout << "\nMat hang " << i + 1 << ": \n";
		cin.ignore();
		mh[i].Nhap();
		//		mh[i].Xuat();
	}

	int n, cnt = 0;
	cout << "\nNhap so luong hoa don: ";
	cin >> n;
	cout << "\nNhap thong tin " << n << " hoa don: ";
	HoaDon *hd = new HoaDon[n];
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "\nHoa don " << i + 1 << ": \n";
		hd[i].Nhap();
		//		hd[i].Xuat();
		if (hd[i].getSoluong() > 10)
			cnt++;
	}

	if (cnt)
		cout << "\nCo " << cnt << " hoa don co so luong > 10";
	else
		cout << "\nKhong co hoa don co so luong > 10";
	cout << "\nNhap so ngay can tinh tien: ";
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		if (hd[i].getNgayban() == s)
		{
			for (int j = 0; j < n; j++)
			{
				if (hd[i].getMahang() == mh[j].getMahang())
				{
					cout << "\nSo tien ban duoc trong ngay " << s << " la: " << mh[j].getDongia() * hd[i].getSoluong() << endl;
					return 0;
				}
			}
		}
	}
	cout << "\nKhong tim thay hoa don ngay " << s;
}