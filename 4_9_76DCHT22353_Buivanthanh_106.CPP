#include<iostream>
#include<vector>
#include<string>
using namespace std;
class  sinhvien{
    private:
    string hoten;
    string namsinh;
    float diem[5];
    public:
    void nhap();
    void xuat();
    float dtb();
    void diemthilai();
    string gethoten() const { 
        return hoten;
     }
    string getnamsinh() const{
        return namsinh;
    } 

};
typedef sinhvien sv;
void sinhvien::nhap(){
    cout<<"nhap ten sinh vien:";
    getline(cin,hoten);
    cout<<"nhap nam sinh:";
    getline(cin,namsinh);
    for(int i=0;i<5;i++){
        cout<<"nhap diem thu "<<i+1<<"la :";
        cin>>diem[i];
    }
    cin.ignore();
}
void sinhvien::xuat(){
    cout<<"ho va ten :"<<hoten<<"\n";
    cout<<"nam sinh :"<<namsinh<<"\n";
    for(int i =0;i<5;i++){
        cout<<"diem thu:"<<i+1<<"la :"<<diem[i]<<"\n";
    }

} 
float sinhvien::dtb(){
    ;
    int tong=0;
    for(int i =1;i<=4;i++){
        tong+=diem[i];
     
    }
    float kq = tong/5;
 cout<<"diem tb la :"<<kq<<"\n";
  return kq;
}
   void sinhvien::diemthilai() {
    bool thilai = false;
    for (int i = 0; i < 5; i++) {
        if (diem[i] < 5) {
            cout << hoten << " thi lai mon " << i+1
                 << " diem la: " << diem[i] << "\n";
            thilai = true;
        }
    }
    if (thilai=false) {
        cout << hoten<< " qua tat ca cac mon"<<"\n";
    }
}


int main(){
    sinhvien sv;
    int n;
    cout<<"nhap n:";
    cin>>n;
    cin.ignore();
    vector<sinhvien> dssv(n);
    for(int i=0 ;i<n;i++){
        dssv[i].nhap();
    }
    for(int i=0 ;i<n;i++){
        dssv[i].xuat();
    }
    for(int i=0;i<n;i++){
        dssv[i].dtb();
    }
    for (int i = 0; i < n; i++) {
    dssv[i].diemthilai();
}

        return 0 ;
    }

