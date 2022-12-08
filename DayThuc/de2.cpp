#include <iostream>
using namespace std;

class DayThuc
{
    int n;
    float *a;

public:
    void nhap()
    {
        cout << "Nhap so phan tu: ";
        cin >> n;
        a = new float[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    void xuat()
    {
        cout << "Day vua nhap: ";
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
    }
    friend int Dem(DayThuc b)
    {
        int cnt = 0;
        for (int i = 1; i <= b.n; i++)
        {
            if ((b.a[i] < -10) || (b.a[i] > 100))
                cnt++;
        }
        return cnt;
    }
    void LietKe()
    {
        int max = a[1] + a[2] + a[3];
        for (int i = 1; i <= n - 2; i++)
        {
            if (max < a[i] + a[i + 1] + a[i + 2])
                max = a[i] + a[i + 1] + a[i + 2];
        }
        cout << "\nCap 3 so lien tiep co tong lon nhat: ";
        for (int i = 1; i <= n - 2; i++)
        {
            if (max == a[i] + a[i + 1] + a[i + 2])
                cout << a[i] << " ," << a[i + 1] << " ," << a[i + 2];
        }
    }
};

int main()
{
    DayThuc a;
    a.nhap();
    a.xuat();
    cout << "\nSo phan tu nam ngoai doan [-10, 100]: " << Dem(a);
    a.LietKe();
}