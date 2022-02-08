#include<iostream>
#include<ctime>

using namespace std;
void print_Array(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void bubble_Sort(int a[], int n	)
{
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(a[j], a[j + 1]);
			}
		}
	}
}
void seclection_sort(int a[], int n) {
	bool check = false;
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[min]) {
				min = j;
				check = true;
			}
		}
		if (check)
		{
			Swap(a[min], a[i]);
		}
	}
}
int main()
{
	int arr[1000];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;
	}
	print_Array(arr, 10);
	//bubble_Sort(arr, 10);
	seclection_sort(arr, 10);
	print_Array(arr, 10);
	return 0;
}