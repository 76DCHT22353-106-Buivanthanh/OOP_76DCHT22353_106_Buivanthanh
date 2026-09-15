#include <iostream>
#include <string>
using namespace std;
#include<vector>

class nguoi {
private:
    string hoten;
    int nsinh;
public:
    void nhap() {
        
        cout << "Nhap vao ho va ten: ";
        getline(cin, hoten);
        cout << "Nhap vao nam sinh: ";
        cin >> nsinh;
        cin.ignore();
    }
    void xuat() {
        cout << "Ho ten: " << hoten << ", Nam sinh: " << nsinh << endl;
    }

nguoi() : hoten(""), nsinh(0) {};
 nguoi(string hoten,int nsinh){
    this->hoten=hoten;
    this->nsinh=nsinh;
}
string gethoten() const{
   return hoten;
}

};

class sinhvien : public nguoi {
private:
    int masv;
    float diemtb;
public:
sinhvien() : nguoi("", 0), masv(0), diemtb(0) {};
sinhvien( string hoten,int nsinh,int masv,float diemtb):nguoi( hoten, nsinh){
    this->masv=masv;
    this->diemtb=diemtb;
}
    void nhap() {
        cin.ignore();
        nguoi::nhap(); 
        cout << "Nhap vao ma sinh vien: ";
        cin >> masv;
        cout << "Nhap vao diem trung binh: ";
        cin >> diemtb;
        
    }
    void xuat() {
        nguoi::xuat();
        cout << "Ma SV: " << masv << ", Diem TB: " << diemtb << endl;
    }
    float getdiemtb() const{
        return diemtb;
    }
    
};

int main() {
    int n;
    cout<<"nhap so sinh vien trong danh sach:";
    cin>>n;
    cin.ignore();
    vector<sinhvien>ds(n);
    for(int i=0;i<n;i++){
      ds[i].nhap();
    }
    for(int i=0;i<n;i++){
      ds[i].xuat();
    }
  
  for (int i = 0; i < n - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (ds[j].getdiemtb() > ds[maxIndex].getdiemtb()) {
            maxIndex = j;
        }
    }
   
    if (maxIndex != i) {
        swap(ds[i], ds[maxIndex]);
    }
}


for (int i = 0; i < n; i++) {
    cout << "Ho ten thi sinh: " << ds[i].gethoten()
         << " | Diem TB: " << ds[i].getdiemtb() << endl;
}

}
