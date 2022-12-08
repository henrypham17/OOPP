#include <iostream>
using namespace std;

class DayNguyen
{
    int n;
    int *a;

public:
    void nhap()
    {
        cout << "Nhap so phan tu: ";
        cin >> n;
        a = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
    void xuat()
    {
        cout << "Day so vua nhap: ";
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << "\t";
        }
    }
    friend float TBC(DayNguyen a)
    {
        float s = 0;
        int cnt = 0;
        for (int i = 1; i <= a.n; i++)
        {
            if (a.a[i] % 2 == 0)
            {
                s += a.a[i];
                cnt++;
            }
        }
        return s / cnt;
    }
    int Max()
    {
        int max = a[1];
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 1 && max < a[i])
            {
                max = a[i];
            }
        }
        return max;
    }
};

int main()
{
    DayNguyen a;
    a.nhap();
    a.xuat();
    cout << "\nTBC cac so chan: " << TBC(a);
    cout << "\nMax cac phan tu le: " << a.Max();
}