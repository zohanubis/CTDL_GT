#include<stdio.h>
#include<conio.h>
#include"BRTree.h"


void main()
{
	int luachon;
	do
	{
		do
		{
			printf("\n");
			printf("------------------------------MENU------------------------------\n");
			printf("1. Tao cay(doc tu file)\n");
			printf("2. Tim kiem mon hoc co ma X\n");
			printf("3. In cac mon hoc Thuc hanh\n");
			printf("0. Ket thuc chuong trinh\n");
			printf("Nhap lua chon cua ban: ");
			scanf_s("%d", &luachon);
		} while (luachon < 0);

		switch (luachon)
		{
		case 1:
		{
			BRTree brtree;
			initBRTree(brtree);
			createBSTreeStruct(brtree);
			break;
		}

		case 2:
		{
			BRTree brtree;
			char x[31];
			initBRTree(brtree);
			createBSTreeStruct(brtree);
			rewind(stdin);
			printf("\nNhap ma mon hoc can tim kiem: ");
			gets_s(x);
			BRTNode* temp = search(brtree.Root, x);
			if (temp == NULL)
				printf("Ma mon hoc %s khong co tren cay\n", x);
			else
				showBRTNodeSearch(temp);
			break;
		}

		case 3:
		{
			BRTree brtree;
			char x[31] = "Thuc hanh";
			initBRTree(brtree);
			createBSTreeStruct(brtree);
			traverseRNL_loaiHP(brtree.Root, x);
			break;
		}

		default:
			break;
		}
	} while (luachon > 0 && luachon <= 3);
}