#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
struct DoVat
{
    char tenDV[10];
    float TL,GT,DG;
    int soDVDuocChon;
};

DoVat *docFile(float *W, int *n)
{
    FILE *f = fopen("Balo.txt","r");
    fscanf(f,"%f",W);   // Xác định trọng lượng balo
    DoVat *dsdv;    // ds là mảng động
    dsdv =(DoVat*)malloc(sizeof(DoVat));    // Cấp phát 1 đồ vật
    int i=0;
    while (!feof(f))
    {
        fscanf(f,"%f%f[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
        dsdv[i].DG = dsdv[i].GT/dsdv[i].TL; // Đơn giá
        dsdv[i].soDVDuocChon=0;
        i++;
        dsdv =(DoVat *) realloc (dsdv,sizeof(DoVat)*(i+1));  // Tăng kích thước đồ vật (Cấp phát)
    }
    *n=i;   // Số lượng đồ vật
    fclose(f);
    return dsdv; // Mảng đồ vật trả về
}
void swap(DoVat *x, DoVat *y)
{
    DoVat temp ;
    temp = *x; 
    *x = *y;
    *y = temp;
}
void BubbleSort(DoVat *dsdv, int n)
{
    int i, j;
    for  (i = 0; i <= n-2; i++)
    {
        for ( j = n-1; j>= i+1; j++)
        {
            if (dsdv[j].DG > dsdv[j-1].DG)
            {
                swap(&dsdv[j],&dsdv[j-1]);
            }
        }
    }
}
void outputDSDV (DoVat *dsdv, int n, float W)
{
    int i;
    float tongTL=0.0, tongGT = 0.0;
    printf("\n\tPhuong an thu duoc tu Greedy : \n");
    printf("|---|----------------|---------|---------|---------|-----------------|\n");
    printf("|STT|   Ten Do Vat   | T.Luong | Gia Tri | Don Gia | So DV duoc chon |\n");
    printf("|---|----------------|---------|---------|---------|-----------------|\n");
    for (int i = 0; i < n; i++)
    {
        printf("|%-3d|%-20s|%9.2f|%9.2f|%9.2f|%8d       |\n",i+1,dsdv[i].tenDV,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].soDVDuocChon);
        tongTL=tongTL+dsdv[i].soDVDuocChon * dsdv[i].TL;
        tongGT=tongGT+dsdv[i].soDVDuocChon * dsdv[i].GT;
        printf("|---|----------------|---------|---------|---------|-----------------|\n");
        printf("\n\tTrong luong cua balo = %9.2f\n",W);
        printf("\n\tTong trong luong cac vat duoc chon = %9.2f\n\nTong gia tri = %9.2f\n",tongTL,tongGT);
    }
}
void greedy(DoVat *dsdv, int n, float W)
{
    int i;
    for(i = 0; i < n;i++)
    {
        dsdv[i].soDVDuocChon = (W /dsdv[i].TL);
        W = W - dsdv[i].soDVDuocChon * dsdv[i].TL;    
    }
}
int main() {
    int n;
    float W;
    DoVat *dsdv;
    dsdv=docFile(&W,&n);
    BubbleSort(dsdv,n);
    greedy(dsdv,n,W);
    outputDSDV(dsdv,n,W);
    free(dsdv); // giải phóng
    return 0;
}
// Đề Bài : Cho một cái ba lô có thể đựng một trọng lượng W và n loại đồ vật, mỗi đồ vật i có một trọng lượng gi và một giá trị vi. Tất cả các loại đồ vật đều có số lượng không hạn chế. Tìm một cách lựa chọn các đồ vật đựng vào ba lô, chọn các loại đồ vật nào, mỗi loại lấy bao nhiêu sao cho tổng trọng lượng không vượt quá W và tổng giá trị là lớn nhất.