#include<iostream>
#include<iomanip>
using namespace std;
class Mathang {
	private:
		string mh;
		int dg;
	public:
		void Nhap() {
			cout << "Ma hang: ";
			fflush(stdin); getline(cin, mh);
			cout << "Don gia: ";
			cin >> dg;
		}
		void Xuat() {
			cout << mh << setw(20) << dg << endl;
		}
		string getMh() {
			return mh;
		}
		int getDg() {
			return dg;
		}
};
class Hoadon {
	private:
	    string mh, ngb;
	    int sl;
	public:
		void Nhap() {
			cout << "Ma hang: ";
			fflush(stdin); getline(cin, mh);
			cout << "So luong: ";
			cin >> sl;
			cout << "Ngay ban: ";
			fflush(stdin); getline(cin, ngb);
		}
		void Xuat() {
			cout << mh << setw(20) << sl << setw(15) << ngb << endl;
		}
		string getMh() {
			return mh;
		}
		int getSl() {
			return sl;
		}
		string getNgb() {
			return ngb;
		}
};
int main() {
    int m, n;
    cout << "Nhap so MH: "; cin >> m;
    cout << "Nhap so HD: "; cin >> n;
    Mathang *a;
    Hoadon *b;
    a = new Mathang[m + 1];
    b = new Hoadon[n + 1];
    for(int i=0; i<m; i++)
	    a[i].Nhap();
	cout << "Danh sach Mat hang: \n";
	for(int i=0; i<m; i++)
	    a[i].Xuat();
	for(int i=0; i<n; i++)
	    b[i].Nhap();
	cout << "Danh sach Hoa don: \n";
	for(int i=0; i<n; i++)
	    b[i].Xuat();
	int count = 0;
	for(int i=0; i<n; i++)
	    if(b[i].getSl()>10)
	        count++;
	cout << "\nSo hoa don co sl > 10: " << count;
	string x;
	int s = 0;
	cout << "\nNhap so ngay ban: ";
	fflush(stdin); getline(cin, x);
	for(int i=0; i<n; i++)
	    if(x==b[i].getNgb())
	        for(int j=0; j<m; j++)
	            if(a[j].getMh()==b[i].getMh())
	                s += a[j].getDg() * b[i].getSl();
	cout << "\nSo tien ban trong ngay " << x << " la: " << s;
return 0;
}