#include <iostream>
#include <cmath>
using namespace std;

class SP1 {
protected:
    double thuc, ao;
public:
    SP1(double r = 0, double i = 0) : thuc(r), ao(i) {}
    void nhap() {
        cin >> thuc >> ao;
    }
    void in() {
        cout << thuc << " + " << ao << "i";
    }
    double module() const {
        return sqrt(thuc * thuc + ao * ao);
    }
};

class SP2 : public SP1 {
public:
    SP2(double r = 0, double i = 0) : SP1(r, i) {}
    SP2& operator=(const SP2& sp) {
        thuc = sp.thuc;
        ao = sp.ao;
        return *this;
    }
    bool operator>(const SP2& sp) const {
        return this->module() > sp.module();
    }
};

int main() {
    SP2 ds[10];
    
    int n;
    cout<<"nhap vao n:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        ds[i].nhap();
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!(ds[i] > ds[j])) {
                SP2 temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ds[i].in();
        cout << " ";
    }
    return 0;
}
