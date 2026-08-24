#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

class nhanvien {
private:
    string hovaten;

public:
    nhanvien() {
        hovaten = "";
    }

    nhanvien(string ten) {
        hovaten = ten;
    }

    void inra(int stt) {
        cout << left << setw(10) << stt 
             << left << setw(30) << hovaten << "\n";
    }
};

typedef nhanvien nv;

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); 
    nv *dsnv2 = (nv*)operator new[](n * sizeof(nv)); 

   
    for (int i = 0; i < n; i++) {
        string ten;
        cout << "Nhap ho va ten nhan vien thu " << i + 1 << ": ";
        getline(cin, ten);

        
        new (&dsnv2[i]) nv(ten); 
    }

 
    cout << "\nDANH SACH NHAN VIEN\n";
    cout << left << setw(10) << "STT" 
         << left << setw(30) << "Ho va Ten" << "\n";

    for (int i = 0; i < n; i++) {
        dsnv2[i].inra(i + 1);
    }

    for (int i = 0; i < n; i++) {
        dsnv2[i].~nhanvien(); 
    }
    operator delete[](dsnv2);

    return 0;
}
