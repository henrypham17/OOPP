#include<iostream>
#include<iomanip>
using namespace std;

class QLH {
    int mh, lh, sl;
    string ten, xuatxu;
    public:
    void nhap() {
        cout << "Nhap ma hang: "; cin >> mh;
        cout << "Nhap ten hang: "; fflush(stdin); getline(cin, ten);
        cout << "Xuat xu: "; getline(cin, xuatxu);
        cout << "Nhap loai hang: "; cin >> lh;
        cout << "Nhap so luong: "; cin >> sl;
    }
    void xuat(){
        cout << mh << setw(10) << ten << setw(10) << xuatxu << setw(10) << lh << setw(10) << sl << setw(10);
    }
    int getMh(){
        return mh;
    }
    int getLh(){
        return lh;
    }
    int getSl(){
        return sl;
    }
    string getTen(){
        return ten;
    }
    string getXuatxu(){
        return xuatxu;
    }
};

class DT : public QLH {
    int tgbh;
    public: 
    void nhap(){
        QLH :: nhap();
        cout << "Nhap thoi gian bao hanh theo thang: "; cin >> tgbh;
    }
    void xuat(){
        QLH :: xuat();
            cout << tgbh << endl;
    }
    int getTgbh(){
        return tgbh;
    }
};

int main(){
    int n;
    cout << "Nhap so mat hang dien tu: "; cin >> n;
    DT *a;
    a = new DT[n+1];
    for(int i = 0 ; i < n; i++){
        a[i].nhap();
    }

    int n1 = 0, n2 = 0, n3 = 0;
    for(int i = 0; i < n; i++){
        if(a[i].getLh() == 1){
            n1 += a[i].getSl();
        }
        if(a[i].getLh() == 2){
            n2 += a[i].getSl();
        }
        if(a[i].getLh() == 3){
            n3 += a[i].getSl();
        }
    }
    cout << "\nTong so hang loai 1: " << n1;
    cout << "\nTong so hang loai 2: " << n2;
    cout << "\nTong so hang loai 3: " << n3;
    if(n1 > n2 && n1 > n3){
        cout << "\nLoai 1 ton kho nhieu nhat";
    }
    if(n2 > n3 && n2 > n1){
        cout << "\nLoai 2 ton kho nhieu nhat";
    }
    if(n3 > n1 && n3 > n2){
        cout << "\nLoai 3 ton kho nhieu nhat";
    }

    string x;
    cout << "\nNhap ten hang can tim: ";
    fflush(stdin); getline(cin, x);
    for(int i = 0; i < n; i++){
        if(x == a[i].getTen()){
            a[i].xuat();
        }
    }
}