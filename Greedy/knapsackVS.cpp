#include "stdio.h"
#include "string.h"
#include "math.h"

void knapsack(int n, float trongLuong[], float giaTri[], float dungTich) {
    float x[20], tp = 0;
    int i, j, v;
    v = dungTich;

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    for (i = 0; i < n; i++)
    {
        if (trongLuong[i] > v)
            break;
        else 
        {
            x[i] = 1.0;
            tp = tp + giaTri[i];
            v = v - trongLuong[i];
        }
    }

    if (i < n)
        x[i] = v / trongLuong[i];
    tp = tp + (x[i] * giaTri[i]);

    printf("\nKet qua cua moi vector: ");
    for (i = 0; i < n; i++)
    {
        printf("%f\t", x[i]);
    }
    printf("\nGiat tri lon nhat cua vat pham:- %f", tp);

}

int main() {
    float trongLuong[20], giaTri[20], dungTich;
    int n, i, j;
    float donGia[20], temp;

    printf("\nNhap so luong vat pham : ");
    scanf("%d", &n);

    printf("\nNhap trong luong va gia tri cua moi vat pham : \n");
    for (i = 0; i < n; i++) 
    {
        printf("\nNhap trong luong %d: ", i + 1); scanf("%f", &trongLuong[i]);
        printf("Nhap gia tri %d: ", i + 1); scanf("%f", &giaTri[i]);
    }

    printf("\nNhap dung tich cua balo : ");
    scanf("%f", &dungTich);

    for (i = 0; i < n; i++) {
        donGia[i] = giaTri[i] / trongLuong[i];   // Ðon giá
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (donGia[i] < donGia[j])
            {
                temp = donGia[j];
                donGia[j] = donGia[i];
                donGia[i] = temp;

                temp = trongLuong[j];
                trongLuong[j] = trongLuong[i];
                trongLuong[i] = temp;

                temp = giaTri[j];
                giaTri[j] = giaTri[i];
                giaTri[i] = temp;
            }
        }
    }

    knapsack(n, trongLuong, giaTri, dungTich);
    return(0);
}
