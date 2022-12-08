#include <iostream>
#include<math.h>
using namespace std;

class Diem {
    float hd, td;

public:
    Diem(){
        hd = td = 0;
    }
    Diem(float a, float b){
        hd = a;
        td = b;
    }
    friend istream &operator >> (istream &is, Diem &d){
        cout << "Nhap hoanh do: "; cin >> d.hd;
        cout << "Nhap tung do: "; cin >> d.td;
        return is;
    }
    friend ostream &operator << (ostream &os, Diem &d){
        cout << "(" << d.hd << ", " << d.td << ")" << endl;
        return os;
    }
    float Kc(Diem a){
        return sqrt(pow(hd - a.hd, 2) + pow(td - a.td, 2));
    }
    friend float KC(Diem a){
        return sqrt(pow(a.hd, 2) + pow(a.td, 2));
    }
    float getHd(){
        return hd;
    }
    float getTd(){
        return td;
    }
};

int main(){
    int n;
    cout << "Nhap n: "; cin >> n;
    Diem *a;
    a = new Diem[n + 1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    float s = 0;
    for(int i = 0; i < n; i++){
        s += a[i].Kc(a[i+1]);
    }
    cout << "\nDo dai duong gap khuc: " << s;

    float max = 0;
    int temp;
    for(int i = 0; i < n; i++){
        if(max < KC(a[i])){
            max = KC(a[i]);
            temp = i;
        }
    }
    cout << "\nDiem cach xa goc toa do nhat: " << a[temp];

    float t = 0;
    for(int i = 0; i < n; i++){
        t += a[i].getTd();
    }
    cout << "\nTong khoang cach den tung do: " << t;

    float r;
    cout << "\nNhap ban kinh: "; cin >> r;
    cout << "\nSo diem nam trong duong tron ban kinh R: \n";
    for(int i = 0; i < n; i++){
        if(KC(a[i]) <= r){
            cout << a[i];
        }
    }
}