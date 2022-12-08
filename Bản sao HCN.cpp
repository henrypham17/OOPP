#include<iostream>
using namespace std;

class HCN {
    int cd, cr;
    public: 
    friend istream &operator >> (istream &is, HCN &hcn){
        cout << "Nhap chieu dai: "; cin >> hcn.cd;
        cout << "Nhap chieu rong: "; cin >> hcn.cr;
        return is;
    }
    friend ostream &operator << (ostream &os, HCN &hcn){
        cout << "Kich thuoc HCN: " << hcn.cd << ", " << hcn.cr << endl;
        return os;
    }
    int DienTich(){
        return cd * cr;
    }
};

int main(){
    int n;
    cout << "Nhap so hinh chu nhat: "; cin >> n;
    HCN *a;
    a = new HCN[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    float s = 0;
    for(int i = 0 ; i < n; i++){
        s += a[i].DienTich();
    }
    cout << "\nDien tich trung binh cua cac hinh chu nhat: " << s/n;

    float min = a[0].DienTich();
    for(int i = 0; i < n; i++){
        if(min > a[i].DienTich()) min = a[i].DienTich();
    }
    cout << "\nNhung hinh chu nhat co dien tich nho nhat: \n";
    for(int i = 0; i < n; i++){
        if(min == a[i].DienTich()){
            cout << a[i] << " " << " o vi tri: " << i << " ";
        }
    }
}