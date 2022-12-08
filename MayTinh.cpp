#include <iostream>
#include <iomanip>
using namespace std;

class MatHang
{
    string mh, ten, nsx;
    int sl, dongia;

public:
    MatHang(string mh = "", string ten = "", string nsx = "", int sl = 0, int dongia = 0)
    {
        this->mh = mh;
        this->ten = ten;
        this->nsx = nsx;
        this->sl = sl;
        this->dongia = dongia;
    }
    string getMh()
    {
        return mh;
    }
    string getTen()
    {
        return ten;
    }
    string getNsx()
    {
        return nsx;
    }
    int getSl()
    {
        return sl;
    }
    int getDongia()
    {
        return dongia;
    }
    void nhap()
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        getline(cin, mh);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, ten);
        cout << "Nhap nha san xuat: ";
        fflush(stdin);
        getline(cin, nsx);
        cout << "Nhap so luong: ";
        cin >> sl;
        cout << "Nhap don gia: ";
        cin >> dongia;
    }
    void xuat()
    {
        cout << mh << setw(10) << ten << setw(10) << nsx << setw(10) << sl << setw(10) << dongia;
    }
};

class MayTinh : public MatHang
{
    string cpu, hdh;
    int trongluong;

public:
    void nhap()
    {
        MatHang :: nhap();
        cout << "Nhap loai CPU: ";
        fflush(stdin);
        getline(cin, cpu);
        cout << "Nhap he dieu hanh: ";
        fflush(stdin);
        getline(cin, hdh);
        cout << "Nhap trong luong: ";
        cin >> trongluong;
    }
    void xuat()
    {
        MatHang :: xuat();
        cout << setw(10) << cpu << setw(10) << hdh << setw(10) << trongluong << endl;
    }
};

void find(MayTinh *a, int n)
{
    string x;
    int ok = 0;
    cout << "Nhap ma hang hoac ten hang: ";
    fflush(stdin);
    getline(cin, x);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].getMh() == x || a[i].getTen() == x)
        {
            ok = 1;
            a[i].xuat();
            cout << endl;
        }
    }
    if (!ok)
        cout << "Khong tim thay thong tin may tinh!";
}

int maxGia(MayTinh *a, int n)
{
    int max = a[1].getDongia();
    for (int i = 1; i <= n; i++)
    {
        if (max < a[i].getDongia())
            max = a[i].getDongia();
    }
    return max;
}

int main()
{
    MayTinh a[100];
    int n;
    cout << "Nhap so may tinh: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].nhap();
    }
    cout << "\nDanh sach may tinh: \n";
    for (int i = 1; i <= n; i++)
    {
        a[i].xuat();
    }
    cout << "\nDanh sach may can tim: \n";
    find(a, n);
    cout << "\nDanh sach may dat nhat: ";
    int max = maxGia(a, n);
    cout << "\nDanh sach may dat nhat: ";
    for (int i = 1; i < n; i++)
    {
        if (max == a[i].getDongia())
            a[i].xuat();
    }
}