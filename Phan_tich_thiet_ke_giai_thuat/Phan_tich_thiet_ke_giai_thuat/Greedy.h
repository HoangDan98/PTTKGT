#pragma once
#include <iostream>
using namespace std;

struct egde
{
	int x, y;
};

void prim(int c[8][8], int n);
void prim_method();
void kruskal(int c[8][8], int n);
void kruskal_method();

void prim(int c[8][8], int n)
{
	float lowcost[8];				// m?ng tr?ng s? c?a ??nh ???c ch?n v?i các ??nh còn l?i
	int Closest[8];					// giá tr? ??nh k? g?n ??nh th
	int k, min;

	for (int i = 1; i < n; i++)			// Kh?i t?o ??nh ??u tiên trong cây bao trùm, l?y m?c ??nh là ??nh 1
	{
		lowcost[i] = c[0][i];
		Closest[i] = 0;
	}
	k = 1;

	for (int i = 1; i < n; i++)
	{
		min = lowcost[k];

		for (int j = 2; j < n; j++)
		{
			if ((lowcost[j] < min  && lowcost[j] != 0) || min == 0)
			{
				min = lowcost[j];
				k = j;
			}
		}
		cout << endl << Closest[k] + 1 << k + 1;
		lowcost[k] = 0;
		for (int j = 1; j < n; j++)
		{
			if ((c[k][j] < lowcost[j]) && (c[k][j] < 1000))
			{
				lowcost[j] = c[k][j];
				Closest[j] = k;
			}
		}
	}
}


void prim_method()
{

	int c[8][8] =
	{
		{0,2,3,1000,1000,1000,1000,1000},
		{2,0,1000,2,1000,1000,1000,1000},
		{3,1000,0,1,1000,1000,1000,1000},
		{1000,2,1,0,2,4,1000,1000},
		{1000,1000,1000,2,0,1,2,1000},
		{1000,1000,1000,4,1,0,2,1},
		{1000,1000,1000,1000,2,2,0,3},
		{1000,1000,1000,1000,1000,1,3,0}
	};



	prim(c, 8);
}


void kruskal(int c[8][8], int n)
{
	int *d = new int[n];
	egde* l = new egde[n - 1];
	int min, dem = 0, sum = 0, t = 0, temp;
	for (int i = 0; i < n; i++)
		d[i] = 0;
	do
	{
		min = 10000;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (c[i][j] > 0 && min > c[i][j] && !(d[i] != 0 && d[i] == d[j]))
				{
					min = c[i][j];
					l[dem].x = i;
					l[dem].y = j;
				}
		//T?o ra cây m?i
		if (d[l[dem].x] == 0 && d[l[dem].y] == 0) {
			t++;
			d[l[dem].x] = d[l[dem].y] = t;
		}
		//??a ??nh t??ng ?ng vào cây
		if (d[l[dem].x] == 0 && d[l[dem].y] != 0)
			d[l[dem].x] = d[l[dem].y];
		//??a ??nh t??ng ?ng vào cây
		if (d[l[dem].x] != 0 && d[l[dem].y] == 0)
			d[l[dem].y] = d[l[dem].x];
		//Ghép 2 cây thành 1 cây m?i
		if (d[l[dem].x] != d[l[dem].y] && d[l[dem].y] != 0)
		{
			temp = d[l[dem].x];
			for (int i = 0; i < n; i++)
				if (temp == d[i])
					d[i] = d[l[dem].y];
		}
		sum += min;
		dem++;

	} while (dem < n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cout << l[i].x + 1 << " " << l[i].y + 1 << endl;
	}
}

void kruskal_method()
{
	int c[8][8] =
	{
		{0,2,3,1000,1000,1000,1000,1000},
		{2,0,1000,2,1000,1000,1000,1000},
		{3,1000,0,1,1000,1000,1000,1000},
		{1000,2,1,0,2,4,1000,1000},
		{1000,1000,1000,2,0,1,2,1000},
		{1000,1000,1000,4,1,0,2,1},
		{1000,1000,1000,1000,2,2,0,3},
		{1000,1000,1000,1000,1000,1,3,0}
	};


	kruskal(c, 8);
}
