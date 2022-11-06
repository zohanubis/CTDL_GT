#include "stdio.h"
#include "stdbool.h"

#define MAX 100

#define V 6

int P[V][V] = {
	// {0, 9, 75, 0, 0},
	// {9, 0, 95, 19, 42},
	// {75, 95, 0, 51, 66},
	// {0, 19, 51, 0, 31},
	// {0, 42, 66, 31, 0}

	// {0,4,2,5,0,1},
	// {4,0,3,8,7,0},
	// {2,3,0,9,0,8},
	// {5,8,9,0,10,0},
	// {0,7,0,10,0},
	// {1,0,8,0,0,0}

	{0,1,0,0,6},
	{1,0,8,4,1},
	{0,8,0,6,0},
	{0,4,6,0,3},
	{6,4,0,3,0}
};

int main()
{
	int no_edge;	// số cạnh
	// Mảng theo dõi đỉnh đã chọn sẽ trở true hay là false
	int selected[V]; // Tập w(s)
	// Đặt memset ban đầu dã chọn
	// memset(selected,false,sizeof(selected));
	// Đặt số cạnh bằng 0
	no_edge = 0;
	// Số lượng đỉnh trong cây khung nhỏ nhất sẽ
	// luôn nhỏ hơn (V - 1) => V là số đỉnh trong đồ thị

	selected[0] = true;
	int x;	// số dòng
	int y;	// số cột

	// In cạnh và độ dài
	printf("Canh : Do dai\n");
	while (no_edge < V - 1)
	// Với mọi đỉnh trong tập S, tìm tất cả các đỉnh kế nhau
	// tính khoảng cách từ đỉnh đã chọn ở bước 1
	// nếu đỉnh nằm trong tập S thì loại bỏ nếu không
	// thì chọn đỉnh khác gần đỉnh đã chọn ở bước 1
	{
		int min = MAX;
		x = 0;
		y = 0;
		for (int i = 0; i < V; i++)
		{
			if(selected[i]){
				for (int j = 0; j < V; j++){
					if (!selected[j] && P[i][j]){
						if(min > P[i][j]){
							min = P[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		printf("%d -> %d : %d\n", x , y , P[x][y]);
		selected[y]= true;
		no_edge++;
	}
	return 0;
}