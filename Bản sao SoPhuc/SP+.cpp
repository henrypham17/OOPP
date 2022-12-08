#include<iostream>
using namespace std;

class SP{
    int pt ,pa;
    public:
    SP(){
        pt = pa = 0;
    }
    SP(int a, int b){
        pt = a;
        pa = b;
    }
    friend istream &operator >> (istream &is, SP &sp){
        cout << "Nhap phan thuc: "; cin >> sp.pt;
        cout << "Nhap phan ao: "; cin >> sp.pa;
        return is;
    }
    friend ostream &operator << (ostream &os, SP &sp){
        if(sp.pa > 0){
            cout << sp.pt << " + " << sp.pa << "i" << endl;
        } else {
            cout << sp.pt << sp.pa << "i" << endl;
        }
        return os;
    }
    SP operator+ (SP a){
        SP c;
        c.pt = pt + a.pt;
        c.pa = pa + a.pa;
        return c;
    }
};

int main(){
    SP a, b, c;
    cout << "Nhap so phuc 1: " << endl; cin >> a; cout << a;
    cout << "Nhap so phuc 2: " << endl; cin >> b; cout << b;
    cout << "Nhap so phuc 3: " << endl; cin >> c; cout << c;
    SP s = a + b +c;
    cout << "Tong 3 so phuc: " << s;
}