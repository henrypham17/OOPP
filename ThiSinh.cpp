#include <iostream>
using namespace std;

class ThiSinh
{
private:
    string hoten;
    float diem;

public:
    void nhap()
    {
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap diem: ";
        cin >> diem;
    }
    void xuat()
    {
        cout << hoten << " " << diem;
    }
    string getHoTen()
    {
        return hoten;
    }
    float getDiem()
    {
        return diem;
    }
};

class Olympic : public ThiSinh
{
private:
    char truong;

public:
    void nhap()
    {
        ThiSinh ::nhap();
        cout << "Nhap ten truong: "; cin >> truong;
    }
    void xuat()
    {
        ThiSinh ::xuat();
        cout << " " << truong;
    }
    char getTruong()
    {
        return truong;
    }
};

int main()
{
    int n;
    float d1 = 0, d2 = 0, d3 = 0;
    cout << "Nhap n: ";
    cin >> n;
    Olympic *a;
    a = new Olympic[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i].nhap();
    }
    for (int i = 0; i <= n; i++)
    {
        a[i].xuat();
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i].getTruong() == 'A')
            d1 += a[i].getDiem();
        if (a[i].getTruong() == 'B')
            d2 += a[i].getDiem();
        if (a[i].getTruong() == 'C')
            d3 += a[i].getDiem();
    }
    cout << "\nTong diem truong A: " << d1;
    cout << "\nTong diem truong B: " << d2;
    cout << "\nTong diem truong C: " << d3;

    if(d1 > d2 && d1 > d3) cout << "Truong co tong diem cao nhat: A";
    if(d2 > d1 && d2 > d3) cout << "Truong co tong diem cao nhat: B";
    if(d3 > d2 && d3 > d1) cout << "Truong co tong diem cao nhat: C";
    
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; i++){
        if(a[i].getTruong == 'A') cnt1++;
        if(a[i].getTruong == 'B') cnt2++;
        if(a[i].getTruong == 'C') cnt3++;
    }
    cout << "So luong sinh vien truong A: " << cnt1;
    cout << "So luong sinh vien truong B: " << cnt2;
    cout << "So luong sinh vien truong C: " << cnt3;
}