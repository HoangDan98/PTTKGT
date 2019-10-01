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

void merge(int a[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l, temp[100];
	while (i <= m && j <= r)
	{
		if (a[i] > a[j])
		{
			temp[k] = a[j];
			j++;
		}
		else
		{
			temp[k] = a[i];
			i++;
		}
		k++;

	}

	if (i > m)
	{
		for (int t = j; t <= r; t++)
			temp[t] = a[t];
	}
	else if (j > r)
	{
		for (int t = i; t < m + 1; t++)
			temp[r - m + t] = a[t];
	}

	for (int t = l; t <= r; t++)
		a[t] = temp[t];
}


void merge_sort(int a[], int l, int r)
{
	int m = (l + r) / 2;
	if (l < r)
	{
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void quick_sort(int a[],int l, int r)
{
	if (l < r)
	{
		int i = l+1, j = r;
		while (i < j)
		{
			while (a[l] > a[i] && i < j) i++;
			while (a[l] <= a[j] && j >= i) j--;
			if (i < j)	swap(a[i], a[j]);
		}
		swap(a[l], a[j]);

		quick_sort(a, l, j-1);
		quick_sort(a, j+1, r);
	}
}

void sort()
{
	int a[] = { 1,4,6,4,3,54,5,6,4,4,5,3,5,3,5,7,8,9,6,4 };
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	quick_sort(a, 0, 19);
	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << " ";
	}
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


int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int max_left_vector(int a[], int i, int j)
{
	int max_sum = -10000, sum = 0;
	for (int k = j; k > i; k--)
	{
		sum += a[k];
		max_sum = max(sum, max_sum);
	}
	return max_sum;
}

int max_right_vector(int a[], int i, int j)
{
	int max_sum = -10000, sum = 0;
	for (int k = i; k <= j; k++)
	{
		sum += a[k];
		max_sum = max(sum, max_sum);
	}
	return max_sum;
}

int max_sub_vector(int a[], int i, int j)
{
	if (i == j) return a[i];
	else
	{
		int m = (i + j) / 2;
		int wl = max_sub_vector(a, i, m);
		int wr = max_sub_vector(a, m+1, j);
		int wm = max_left_vector(a, i, m) + max_right_vector(a, m + 1, j);
		return max(wl, max( wr, wm));
	}
}

void max_sub()
{
	int a[] = { -98,54,67,65,-879,78,65,21,-6,67};
	for (int i = 0; i < 9; i++)
		cout << a[i] << " ";
	cout << endl;

	cout << "---------\n" << max_sub_vector(a, 0, 9);
}
