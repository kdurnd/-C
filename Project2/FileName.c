#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Max(int* x, int sz)
{
	int a = *x;
	int i;
	for (i = 1; i < sz; i++)
	{
		if (a < *(x + 1))
			a = *(x + 1);
	}
	return a;
}
int mian()
{
	int n, k;
	int total;
	int com = 0;
	int arr[4000];//����combo
	int x = 0;//arr������±�
	char lev[10];
	int i;
	int acc = 0;
	scanf("%d%d", &n, &k);
	int a = round((double)(900000) / n);//����perfect�÷�
	int b = round((double)(585000) / n);//����good�÷�

	for (i = 0; i < k; i++)
	{
		scanf("%s", lev);
		if (0 == strcmp("prefect", lev))
		{
			acc += a;
			com++;
		}
		else if (0 == strcmp("good", lev))
		{
			acc += b;
			com++;
		}
		else
		{
			arr[x] = com;
			com = 0;
			x++;
		}
	}
	acc += (n - k) * a;
	arr[x] = arr[x] + com + (n - k);
	total = Max(arr, x);
	acc += 100000 * total / n;
	printf("%d", acc);
	return 0;
}
