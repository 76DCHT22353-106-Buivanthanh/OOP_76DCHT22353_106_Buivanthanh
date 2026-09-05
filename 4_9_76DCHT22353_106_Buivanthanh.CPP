#include<iostream>
using namespace std;
#include<vector>
class sinhvien {
    private:
    string hoten;
    string namsinh;
    float monhoc[4];
    public:
    void nhap(sinhvien* p);
    void xuat(sinhvien* p);
    float tb(sinhvien* p);
    
    string  gethoten() const{
        return hoten;
    };
    string getnamsinh() const{
        return namsinh;
    };
     double phaithitot(sinhvien* p);
};
typedef sinhvien sv;
void sinhvien::nhap(sinhvien* p){
   cout<<"nhap vao ho va ten:";
   getline(cin,p->hoten);
   cout<<"nhap vao nam sinh :";
   getline(cin,p->namsinh);
   for(int i=0;i<4;i++){
    cout<<"nhap vao diem mon  "<<i+1<<":";
    cin>>p->monhoc[i];
   }
   cin.ignore();
}
void sinhvien::xuat(sinhvien* p){
    cout<<" ho va ten hoc sinh :"<<p->hoten<<"\n";
    cout<<"nam sinh cua hoc sinh:"<<p->namsinh<<endl;
    for(int i=0;i<4;i++){
           cout << "Diem mon " << i+1 << ": " << p->monhoc[i] << endl;
    }
}
float sinhvien::tb(sinhvien *p){
    int tong=0;
    float kq=0;
    for (int i=0;i<4;i++){
        tong+=p->monhoc[i];
    }
    kq=tong/4;
    cout<<"diem tb la :"<<kq<<"\n";
    return kq;
}
double sinhvien::phaithitot(sinhvien *p){
    int tong=0;
    float kq=0;
    for (int i=0;i<4;i++){
        tong+=p->monhoc[i];
    }
    kq=tong/4;
    bool duoi5=false;
    for(int i=0;i<4;i++){
        if(p->monhoc[i]<5){
          duoi5=true;
          break;
        }
        else{
            duoi5=false;
        }
    }
    
    if(kq>7&&duoi5==false){
        cout<<"hoc sinh:"<<p->gethoten()<<"  phai thi tôt nghiep"<<"\n";
    }
    else{
         cout << "Hoc sinh " <<p->gethoten() << " khong duoc thi tot nghiep.\n";
    }
        return kq;
    }

int main(){
    int n;
    cout<<"nhap vao so sinh vien:";
    cin>>n;
    cin.ignore();
    sinhvien sv;
    vector<sinhvien> dssv(n);
    for(int i=0;i<n;i++){
       sv.nhap(&dssv[i]);
    }
    for(int i=0;i<n;i++){
        sv.xuat(&dssv[i]);
    }
    for(int i=0;i<n;i++){
        sv.tb(&dssv[i]);
    }
    for(int i=0;i<n;i++){
        sv.phaithitot(&dssv[i]);
    }
}
