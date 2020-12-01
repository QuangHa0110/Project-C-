#include <stdio.h>
#include <stdlib.h>
int price[100][100];
int n;
int x[100];      // danh sách các đỉnh
bool check[100]; // mảng đánh dấu các đỉnh
int f;
int min_f; // giá trị tốt nhất hiện tại
int cmin;  // chi phí nhỏ nhất của 1 cạnh trong tất cả các cạnh
void input()
{
    cmin = 1000000000;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fscanf(fptr, "%d", &price[i][j]);
            if (i != j && price[i][j] < cmin)
                cmin = price[i][j];
        }
        check[i] = false; // đánh dấu những điểm chưa đi qua là false
    }

    for (int i = 1; i < n;  i++)
    {
        min_f = min_f + price[i][i + 1]; // tìm phương án tốt bằng thuật toán tham lam, đi tuần tự các điểm
    }
    x[1] = 1;        // lúc đầu đi qua đỉnh 1
    check[1] = true; // đỉnh 1 đã đi qua nên đánh dấu là true
    f = 0;
    min_f = min_f + price[n][1]; // phương án tốt ban đầu dựa vào thuật toán tham lam đi tuần tự các điểm
    fclose(fptr);
}
void solution()
{
    if (f + price[x[n]][x[1]] < min_f) // nếu chi phí đã có + chi phí tiếp theo nhỏ hơn phương án tốt nhất hiện tại thì update lại phương án tốt  nhất
    {
        min_f = f + price[x[n]][x[1]];
        printf("update best = %d\n", min_f);
    }
}
void TRY(int k)
{

    for (int v = 1; v <= n; v++)
    {
        if (!check[v])
        {
            x[k] = v;
            check[v] = true;      // đánh dấu đỉnh đã đi qua là true
            f = f + price[x[k - 1]][x[k]];
            if (k == n) // đã đi hết n thành phố
            {
                solution();
            }
            else
            {
                int gk = f + (n - k + 1) * cmin; // hàm cận dưới
                if (gk < min_f)                  // nếu bestConfig hiện tại vẫn lớn hơn thì tiếp tục thử
                    TRY(k + 1);
            }
            check[v] = false;
            f = f - price[x[k - 1]][x[k]];
        }
    }
}

int main()
{
    input();
    TRY(2);

    return 0;
}