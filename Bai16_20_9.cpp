#include<iostream>
#include<vector>
using namespace std;
int z;
class monhoc{
    protected :
    vector<float>mon;
    int chuyencan;
    float KT,DT;
    public:
    void nhap(monhoc*p);
    void xuat(monhoc*p);
    void diemtb(monhoc*p);
    float getkt() const{
        return KT;
    }
    int getdiemchuyencan() const{
        return chuyencan;
    }
};
class sinhvien:public monhoc {
    private:
    string  hoten,lop,masv;
    public:
    void nhap (sinhvien*p);
    void xuat(sinhvien*p);
    double diemhocphan(sinhvien*p);
    string  gethoten() const {
        return hoten;
    }

};
void monhoc::nhap(monhoc*p){
     mon.resize(z);
     for(int i=0;i<z;i++){
        cout<<"nhap vao diem mon "<<i<<":";
        cin>>mon[i];
     }
    cout<<"nhap vap diem chuyen can:";
    cin>>p->chuyencan;
    cout<<"nhap vao diem kiem tra:";
    cin>>p->KT;
    cout<<"nhap vao diem diem thi:";
    cin>>p->DT;
    cin.ignore();
}
void sinhvien::nhap(sinhvien*p){
   
    cout<<"nhap vao ho va ten:";
    getline(cin,p->hoten);
    cout<<"nhap vao lop:";
    getline(cin,p->lop);
    cout<<"nhap vao masv:";
    getline(cin,p->masv);
     monhoc::nhap(p);
}
void monhoc::xuat(monhoc*p){
    for(int i =0;i<z;i++){
        cout<<"diem mon hoc "<<i+1<<":"<<mon[i];
    }
    cout<<"Diem chuyen can:"<<chuyencan<<endl;
    cout<<"Diem kiem tra:"<<KT<<endl;
    cout<<"DIEM THI:"<<DT<<endl;
}

double sinhvien::diemhocphan(sinhvien*p){
    double kq;
    kq = (0.2*p->chuyencan)+(0.3*p->KT)+(0.5*p->DT);
    return kq;
}
void sinhvien::xuat(sinhvien* p) {
    cout << "Ho ten: " << p->hoten << endl;
    cout << "Lop: " << p->lop << endl;
    cout << "Ma SV: " << p->masv << endl;
    monhoc::xuat(p);
}
    


int main() {
    int n;
    cout << "Nhap vao so sinh vien: ";
    cin >> n;
    cin.ignore();
    cout << "Nhap vao so mon hoc: ";
    cin >> z;
    cin.ignore();

    vector<sinhvien> sv(n);

    for (int i = 0; i < n; i++){ sv[i].nhap(&sv[i]);}
    for (int i = 0; i < n; i++){ sv[i].xuat(&sv[i]);}

    for (int i = 0; i < n; i++) {
        cout << "Sinh vien: " << sv[i].gethoten()
             << " co diem hoc phan: " << sv[i].diemhocphan(&sv[i]) << endl;
    
        if (sv[i].getkt() == 0 || sv[i].getdiemchuyencan() < 5) {
            cout << " Sinh vien " << sv[i].gethoten() << " bi cam thi"<<endl;
        } else {
            cout << " Sinh vien " << sv[i].gethoten() << " duoc di thi\n";
        }
    }
}
