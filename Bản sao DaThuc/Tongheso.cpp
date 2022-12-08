#include <iostream>
#include<math.h>
using namespace std;

class DT
{
    int n;
    float *a;

public:
    DT(){
        n = 0;
        a = NULL;
    }
    ~DT(){

    }
    friend istream &operator>>(istream &is, DT &d){
        cout << "\nNhap bac cua da thuc: ";
        cin >> d.n;
        d.a = new float[d.n + 1];
        for (int i = 0; i <= d.n; i++)
        {
            cin >> d.a[i];
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, DT &d){
        cout << d.a[0];
        for (int i = 1; i <= d.n; i++)
        {
            cout << " + " << d.a[i] << "x^" << i;
        }
        return os;
    }
    DT operator+(DT d){
        DT b;
        int k, i;
        if (n > d.n){
            k = n;
        }
        else if (n == d.n){
            k = n;    // k = d.n
        }
        else{
            k = d.n;
        }
        b.a = new float[k + 1];
        for (int i = 0; i <= k; i++){
            if (i <= n && i <= d.n)
            {
                b.a[i] = a[i] + d.a[i];
            } else if(i <= n) {
                b.a[i] = a[i];
            } else {
                b.a[i] = d.a[i];
            }
        }
        i = k;
        while(i > 0 && b.a[i] == 0.0) i--;
        b.n = i;
        return b;
    }
    friend float Tinh(float x, DT a){
        float s = 0;
        for(int i = 0; i <= a.n; i++){
            s += a.a[i] * pow(x, i);
        }
        return s;
    }
    // friend float DaoHam(float x, DT a){
    //     float s = 0;
    //     for(int i = 0; i <= a.n; i++){
    //         s += a.a[i] * i * pow(x, i - 1);
    //     }
    //     return s;
    // }
    float DaoHam(float x){
        float s = 0;
        for(int i = 0; i <= n; i++){
            s += a[i] * i * pow(x, i - 1);
        }
        return s;
    }
};

int main(){
    DT P, Q, R;
    cin >> P; cout << "Da thuc P: " << P;
    cin >> Q; cout << "Da thuc Q: " << Q;
    R = P + Q;
    cout << "\nDa thuc R: " << R;
    float x;
    cout << "\nNhap gia tri x: "; cin >> x;
    cout << "\nGia tri P tai x: " << Tinh(x, P);
    cout << "\nDao ham cua P tai x: " << P.DaoHam(x);
    float s = Tinh(x, P) + Tinh(x, Q);
    s = sqrt(s);
    cout << "\nGia tri bieu thuc P + Q tai x: " << s;
}