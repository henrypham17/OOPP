#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int ktra (int x) {
	int count = 0;
	for (int i=2; i<=sqrt(x); i++)
		if(x%i==0) 
            count++;
	if (count==0) 
        return 1;
	else 
        return 0;
}
class Dayso {
    private:
        int n;
        int *p;
    public:
        Dayso() {
            n = 0;
            p = NULL;
        }
        friend istream &operator >> (istream &is, Dayso &d) {
            cout << "Nhap n: "; is >> d.n;
            d.p = new int[d.n + 1];
            for(int i=0; i<d.n; i++)
                is >> d.p[i];
            return is;
        }
        friend ostream &operator << (ostream &os, Dayso d) {
            for(int i=0; i<d.n; i++)
                os << d.p[i] << " ";
            os << endl;
            return os;
        }
        int Tong() {
            int s = 0;
            for(int i=0; i<n; i++)
                s += p[i];
            return s;
        }
        void Tbc() {
            int s = Tong();
            cout << fixed << setprecision(2) << (float)s / n << endl;
        }
        int Dem(){
			int count = 0;
			for (int i=0; i<n; i++)
				if(ktra(p[i])==1) count++; 
			return count;
		}
		void Insonguyento() {
			for (int i=0; i<n; i++)
				if (ktra(p[i])==1) cout << p[i] <<" "; 
		}
};
int main() {
    Dayso a;
    cin >> a; cout << a;
    cout << "Tong cua day so: " << a.Tong() << endl;
    cout << "Trung binh cong cua day so: ";
    a.Tbc();
    cout << "So luong so nguyen to: " << a.Dem() << endl;
    a.Insonguyento();
return 0;
}