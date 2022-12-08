#include<iostream>
using namespace std;

class PS {
    int ts, ms;
    public: 
    PS(){
        ts = 0;
        ms = 1;
    }
    PS(int a, int b){
        ts = a;
        ms = b;
    }
    void nhap(){
        cout << "Nhap tu so: "; cin >> ts;
        cout << "Nhap mau so: "; cin >> ms;
    }
    int ucln(int a, int b){
        if(b == 0){
            return a;
        }
        return ucln(b, a % b);
    }
    friend ostream &operator << (ostream &os, PS &p){
        cout << p.ts/p.ucln(p.ts, p.ms) << "/" << p.ms/p.ucln(p.ts, p.ms);
        return os;
    }
    PS operator + (PS a){
        PS b;
        b.ts = ts * a.ms + ms * a.ts;
        b.ms = ms * a.ms;
        return b;
    }
    PS operator * (PS a){
        PS b;
        b.ts = ts * a.ts;
        b.ms = ms * a.ms;
        return b;
    }
};


int main(){
    PS a, b;
    cout << "\nNhap phan so thu nhat: " << endl; a.nhap(); cout << a;
    cout << "\nNhap phan so thu hai: " << endl; b.nhap(); cout << b;
    PS c;
    c = a + b;
    PS d;
    d = a * b;
    cout << "\nTong 2 phan so: " << c;
    cout << "\nTich 2 phan so: " << d;
}