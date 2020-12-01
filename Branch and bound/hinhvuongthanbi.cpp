#include <iostream>
using namespace std;
int n=4;
int a[17]={0};  // kho so, a=1 su dung i; a=0 <=> chua su dung i
int m[4][4];
int nghiem=0;
// void init(){
//   for(int i=1;i<=n*n;i++)
//      a=0; //chua so nao dc su dung
// }

int kiemtra(){
  int h,c,x=(1+n*n)*n/2; // hang , cot
  for(h=0;h<n;++h){
     int th=0;  
     for(c=0;c<n;++c)
        th+=m[h][c]; // tong hang
     if(th!=x)return 0;
  }

  for(c=0;c<n;++c){
     int tc=0; // tong cot
     for(h=0;h<n;++h)
        tc+=m[h][c]; // tong cot
     if(tc!=x)return 0;
  }
  int t1=0,t2=0;
  for(h=0;h<n;++h){
     t1+=m[h][h];
     t2+=m[h][n-h-1];
  }
  if(t1!=x)return 0;
  if(t2!=x)return 0;
  return 1;
}
void in_kq(){
  if(kiemtra()){
     nghiem++;
     cout<<"nghiem: "<<nghiem<<endl;
     for(int h=0;h<n;++h){
        for(int c=0;c<n;++c)
          cout<<m[h][c]<<" ";
        cout<<endl;
     }
  }
}
void fill(int k){
  int h=k/n, c=k%n;
  for(int i=1; i<=n*n; ++i)
     if(a[i]==0){        //i chua dung
        a[i]=1;           //dung i
        m[h][c]=i;    //dung vao vi tri m[h][c]
        if(k==n*n-1)    //fill full?
          {in_kq(); exit;}        //chek->ok->show
        else            //not full
          fill(k+1);    //fill next
        a[i]=0;        //HUY?: i khong dung nua
     }
}

int main(){
 // init();
  fill(0);
  return 0;
}  