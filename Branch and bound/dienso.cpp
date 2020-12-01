#include<stdio.h>
int n;
int x[100];
int y[100];
int a[100][100]={0};
void input(){
    FILE *fptr= fopen("input.txt","r");
    fscanf(fptr,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(fptr,"%d", &x[i]);
    }
    for(int i=1;i<=n;i++){
        fscanf(fptr,"%d", &y[i]);
    }

}
void solution(){

}
void TRY(int k){
    if(){

    }
}
int main(){
    return 0;
}