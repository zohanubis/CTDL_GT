#include "stdio.h"
#define MAX 50
void readFile (float a[][MAX],  int &n , int &m, float &w);
void printTable(float a[][MAX], int n, int m, float w);
void tinhDonGia(float a[][50], int &n, int &m, float w );
void sortTable(float a[][MAX], int n, int m, float w);
void select(float a[][MAX], int n, int m, float w);

int main()
{
    float a[MAX][MAX],w;
    int n,m;
    readFile(a,n,m,w);
    tinhDonGia(a,n,m,w);
    printTable(a,n,m,w);
    sortTable(a,n,m,w);
    printf("\n\t\t\tTable after sort : \n");
    printTable(a,n,m,w);
    printf("\n\t\t\tSelect : \n");
    select(a,n,m,w);
    return 0;
}

void readFile(float a[][50], int &n , int &m, float &w)
{
    FILE *f= fopen("Knapsack.txt","rt");
    if (f == NULL)
    {
        printf("\nLoi doc file !");
        return ;
    }
    fscanf(f,"%f\n",&w);
    fscanf(f,"%d%d\n",&n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(f,"%f",&a[i][j]);
        }
    }
}

void printTable(float a[][MAX], int n, int m, float w)
{
    printf("Trong luong balo : %f",w);
    printf("\nLoai do vat\tTrong Luong\tGia Tri\tSo Luong\tDon Gia\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2f\t\t",a[i][j]);
        }
        printf("\n");
    }
}
void tinhDonGia(float a[][MAX], int &n, int &m, float w)
{
    m++;
    int temp = m;
    for (int i = 0; i < n; i++)
    {
        a[i][temp-1]= a[i][temp-3]/a[i][temp -4];
    }
}
void swapRow(float a[][MAX], int n, int m ,int x, int y)
{
    for (int i = 0; i < m; i++)
    {
        float temp = a[x][i];
        a[x][i] = a[y][i];
        a[y][i] = temp;
    }
}
void sortTable(float a[][MAX], int n, int m, float w)
{
    for (int i = 0; i < n-1; i++)
    {
        for(int j = i +1 ; j< n;j++)
        {
            if (a[i][m-1]< a[j][m-1])
            {
                swapRow(a,n,m,i,j);
            }
        }
    }
}

void select(float a[][50], int n, int m ,float w)
{
    m += 2;
    float temp, tongGT = 0 , tongTL = 0 ;
    float b[MAX][MAX];
    int count = 0;
    printf("\nLoai do vat\tTrong Luong\tGia Tri\tSo Luong CL\tDon Gia\tSo Luong Lay\tW con lai :\n");
    for (int i = 0; i < n; i++) 
    {
        temp = a[i][3]; // giữ số lượng ban đầu để phía sau trừ cái lượng lấy đi
        while (w < (a[i][1] * a[i][3]))
        {
            a[i][3]--;
        }
        if (w >= (a[i][1] * a[i][3]))
        {
            tongGT += a[i][2] * a[i][3];
            tongTL += a[i][2] * a[i][3];
            b[count][0] = a[i][0];
            b[count][1] = a[i][3];
            count++;
            w = w - a[i][1] * a[i][3];
            a[i][6] = w ;
            a[i][5] = a[i][3];
            a[i][3] = temp - a[i][3];
        }
        if (w == 0)     // Phần dừng
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2f\t\t", a[i][j]);
        }
        printf("\n");
    }
    int flag = 0;
    printf("\nDo Vat Lay \tSo Luong \tTong TL \tTong GT\n");
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 2; j++)     // 2 chưa tối ưu, cần biến đếm
        {
            printf("%.2f\t\t",b[i][j]);
        }
        if (flag == 0)
        {
            printf("%.2\t\t%.2f", tongTL, tongGT);
            flag++;
        }
        printf("\n");
    }
}