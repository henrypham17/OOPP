#include <iostream>
#include <iomanip>
using namespace std;

class Xe
{
    string bienso;
    int trongluong;

public:
    Xe(string bienso = "", int trongluong = 0)
    {
        this->bienso = bienso;
        this->trongluong = trongluong;
    }
    string getBienso()
    {
        return bienso;
    }
    int getTrongluong()
    {
        return trongluong;
    }
    void nhap()
    {
        cout << "Nhap bien so: ";
        fflush(stdin);
        getline(cin, bienso);
        cout << "Nhap trong luong: ";
        cin >> trongluong;
    }
    void xuat()
    {
        cout << bienso << setw(10) << trongluong;
    }
};

class Xe_Bus : public Xe
{
    int socho;

public:
    int getSocho()
    {
        return socho;
    }
    void nhap()
    {
        Xe ::nhap();
        cout << "Nhap so cho: ";
        cin >> socho;
    }
    void xuat()
    {
        Xe ::xuat();
        cout << setw(10) << socho << endl;
    }
};

class Xe_Tai : public Xe
{
    int taitrong;

public:
    int getTaitrong()
    {
        return taitrong;
    }
    void nhap()
    {
        Xe ::nhap();
        cout << "Nhap tai trong: ";
        cin >> taitrong;
    }
    void xuat()
    {
        Xe ::xuat();
        cout << setw(10) << taitrong << endl;
    }
};

int main()
{
    Xe_Bus *a;
    Xe_Tai *b;
    int n, m;
    cout << "Nhap so xe bus: ";
    cin >> n;
    cout << "Nhap sso xe tai: ";
    cin >> m;
    a = new Xe_Bus[n + 1];
    b = new Xe_Tai[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i].nhap();
    }
    cout << "Xe bus co nhieu hon 24 cho ngoi: \n";
    for (int i = 1; i <= n; i++)
    {
        if (a[i].getSocho() > 24)
            a[i].xuat();
    }
    for (int i = 1; i <= m; i++)
    {
        b[i].nhap();
    }
    cout << "Xe tai co tai trong khong qua 15 tan: \n";
    for (int i = 1; i <= m; i++)
    {
        if (b[i].getTaitrong() <= 15)
            b[i].xuat();
    }
    string x;
    int ok = 0;
    cout << "Nhap bien so chua thong tin can tim: \n";
    fflush(stdin);
    getline(cin, x);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].getBienso() == x)
        {
            ok = 1;
            a[i].xuat();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i].getBienso() == x)
        {
            ok = 1;
            b[i].xuat();
        }
    }
    if (!ok)
        cout << "Khong tim thay thong tin!";
}