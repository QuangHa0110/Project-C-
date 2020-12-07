#include <stdio.h>

void insertionSort(int a[], int n)
{ // thuật toán sắp xếp chèn
    for (int i = 0; i < n; i++)  // duyệt từ đầu đến cuối danh sách
    {
        int last = a[i];    // phần tử cần thêm vào dãy đã sắp xếp
        int j = i;            
        while (j > 0 && a[j-1] > last)   // nếu phần tử trước lớn hơn phần tử cần thêm vào thì đổi chỗ 2 phần tử này
        {
           a[j]=a[j-1];
           j--;
        }
        a[j]=last;            // chèn phần tử cần thêm vào vị trí phù hợp
    }
}
void printResult(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
}
int main()
{   int a[10]={1,3,4,2,5,6,7,8,23,4};
    insertionSort(a,10);
    printResult(a,10);

    return 0;
}