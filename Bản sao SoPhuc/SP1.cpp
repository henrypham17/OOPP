#include<iostream>
#include<math.h>
using namespace std;

class SP{
    int pt, pa;
    public: 
    // friend istream &operator >> (istream &is, SP &sp){
    //     cout << "Nhap phan thuc: "; cin >> sp.pt;
    //     cout << "Nhap phan ao: "; cin >> sp.pa;
    //     return is;
    // }
    SP(){
        pt = pa = 0;
    }
    SP(int c, int d){
        this->pt = c;
        this->pa = d;
    }
    void nhap(){
        cout << "Nhap phan thuc: "; cin >> pt;
        cout << "Nhap phan ao: "; cin >> pa;
    }
    friend ostream &operator << (ostream &os, SP &sp){
        if(sp.pa > 0){
            cout << sp.pt << " + " << sp.pa << "i" << endl;
        } else {
            cout << sp.pt << sp.pa << "i" << endl;
        }
        return os;
    }
    // float operator !(){
    //     return pow(pt, 2) + pow(pa, 2);
    // }
    friend float operator! (SP a){
        return pow(a.pt, 2) + pow(a.pa, 2);
    }
};

int main(){
    SP a, b;
    cout << "Nhap so phuc 1: \n"; a.nhap(); cout << a;
    cout << "Nhap so phuc 2: \n"; b.nhap(); cout << b;
    // cout << "\nTong s = " << !a + !b;
    float s;
    s = !a + !b;
    cout << "\nTong s = " << s;
}