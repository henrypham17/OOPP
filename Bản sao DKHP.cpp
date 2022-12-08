#include <iostream>
#include<iomanip>
using namespace std;

class MonHoc
{
private:
    string mamon, tenmon;
    int sotinchi;

public:
    MonHoc()
    {
        mamon = tenmon = "";
        sotinchi = 0;
    }

    void Nhap()
    {
        cout << "Nhap ma mon hoc: ";
        cin.ignore();
        getline(cin, mamon);
        cout << "Nhap ten mon: ";
        getline(cin, tenmon);
        cout << "Nhap so tin chi: ";
        cin >> sotinchi;
    }

    void Xuat()
    {
        cout << setw(15) << left << mamon << setw(20) << left << tenmon << setw(10) << left << sotinchi << endl;
    }

    string get_mamon()
    {
        return mamon;
    }
    string get_tenmon()
    {
        return tenmon;
    }
    int get_sotinchi()
    {
        return sotinchi;
    }
};

class DKHP
{
private:
    int MSV;
    string tensv;
    int *luachon;

public:
    DKHP()
    {
        MSV = 0;
        tensv = "";
        luachon = NULL;
    }
    ~DKHP()
    {
        delete[] luachon;
    }

    void Nhap(int m, MonHoc *p)
    {
        cout << "Nhap ma sinh vien: ";
        cin >> MSV;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, tensv);

        cout << "Nhap lua chon cac mon hoc (1/0): " << endl;
        luachon = new int[m + 1];
        for (int i = 0; i < m; i++)
        {
            cout << p[i].get_tenmon() << ": ";
            cin >> luachon[i];
        }
    }

    void Xuat()
    {
        cout << setw(15) << left << MSV << setw(20) << left << tensv;
    }

    int get_MSV()
    {
        return MSV;
    }
    string get_tensv()
    {
        return tensv;
    }

    int TongTinChi(int m, MonHoc *p)
    {
        int s = 0;
        for (int i = 0; i < m; i++)
        {
            if (luachon[i] == 1)
            {
                s += p[i].get_sotinchi();
            }
        }
        return s;
    }

    int check(int k)
    {
        if (luachon[k] == 1)
        {
            return 1;
        }

        return 0;
    }
};

int main()
{
    MonHoc *a;
    DKHP *b;

    // Nhap danh sach m mon hoc va ban DKHP cua n sinh vien

    int m, n;
    cout << "Nhap so luong mon hoc: ";
    cin >> m;

    a = new MonHoc[m + 1];

    cout << "Nhap Cac Mon Hoc: " << endl;
    for (int i = 0; i < m; i++)
    {
        a[i].Nhap();
    }

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    b = new DKHP[n + 1];

    cout << "Nhap Cac Sinh Vien: " << endl;
    for (int i = 0; i < n; i++)
    {
        b[i].Nhap(m, a);
    }

    // In tong so tin chi ma tung sinh vien da dky

    cout << "\nDanh Sach Dang Ky Hoc Phan: " << endl;
    cout << setw(15) << left << "MSV" << setw(20) << left << "Ho ten" << setw(10) << left << "So tin chi" << endl;

    for (int i = 0; i < n; i++)
    {
        b[i].Xuat();
        cout << setw(10) << left << b[i].TongTinChi(m, a) << endl;
    }

    // Nhap vao 1 ma mon hoc, thong ke so sinh vien da dang ky mon hoc do
    string x;
    cout << "\nNhap ma mon hoc can thong ke: ";
    cin.ignore();
    getline(cin, x);

    int cnt = 0;
    int ok = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i].get_mamon() == x)
        {
            ok = 1;
            for (int j = 0; j < n; j++)
            {
                if (b[j].check(i) == 1)
                {
                    cnt++;
                }
            }
        }
    }
    if (ok)
    {
        cout << "\nSo sinh vien dang ky mon co ma " << x << " la: " << cnt;
    }
    else
    {
        cout << "\nKhong co ma mon hoc nay, vui long kiem tra lai !" << endl;
    }

    return 0;
}
