#pragma once
#include <iostream>
using namespace std;



void searchBin(int a[], int value,int n)
{
	int m,l = 0, r = n;
	m = n / 2;
	while (l<r)
	{
		if (value < a[m])
		{
			r = m;
			m = (l + m) / 2;
		}
		else if (value > a[m])
		{
			l = m;
			m = (m + r) / 2;
		}
		else
		{
			cout << m + 1 << endl;
			int temp = m+1;
			m--;
			while (a[m] == value)
			{
				cout << m + 1 << endl;
				m--;
			}
			while (a[temp] == value)
			{
				cout << temp + 1 << endl;
				temp++;
			}
			break;
		}
	}
}

void search()
{
	int a[] = { 1,2,3,4,5,5,5,5,5,5,5,6,7,8,9 };
	searchBin(a, 5, 15);
}

void mergeSort(int a[],int l, int r)
{

}


void sort()
{

}

int tinh_GiaiThua(int n)
{
	if (n == 0) return 1;
	return n * (tinh_GiaiThua(n - 1));
}

void GiaiThua()
{
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << tinh_GiaiThua(n);
}

int tim_UCLN(int a, int b)
{
	if (b == 0) return a;
	else
		return tim_UCLN (b, a%b);
}

void UCLN()
{
	int a = 10, b = 8;
	tim_UCLN(a, b);
	cout << tim_UCLN(a, b);
}

int tinh_LuyThua(int x, int n)
{
	if (n == 0) return 1;
	else return (x * tinh_LuyThua(x, n - 1));
}

void LuyThua()
{
	int x, n;
	cout << "Nhap x,n: "; cin >> x >> n;
	cout << tinh_LuyThua(x, n);
}

int tinh_Tong(int a[], int n)
{
	if (n == 1) return a[0];
	else
	{
		a[n - 2] += a[n - 1];
		tinh_Tong(a, n - 1);
	}
}

void Tong()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << tinh_Tong(a, 10);

}

int tinh_Tich(int a[], int n)
{
	if (n == 1) return a[0];
	else
	{
		a[n - 2] *= a[n - 1];
		tinh_Tich(a, n - 1);
	}
}

void Tich()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << tinh_Tich(a, 10);
}

void tim_Min_Max(int a[], int n, int min, int max)
{
	if (n == 1) 
		cout << min << endl << max;
	else
	{
		if (min > a[n - 1]) min = a[n - 1];
		if (max < a[n - 1]) max = a[n - 1];
		tim_Min_Max(a, n - 1, min, max);
	}
}

int bin_Min(int a[], int l, int r)
{
	if (l == r) return a[l];
	else
	{
		int min_l = bin_Min(a, l, (l + r) / 2);
		int min_r = bin_Min(a, (l + r) / 2 + 1, r);
		if (min_l > min_r) return min_r;
		else return min_l;
	}
}

void Min_Max()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	tim_Min_Max(a, 10, a[0], a[0]);
}

