#include<iostream>
#include<ctime>

using namespace std;

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
int main()
{
    //int arr[10] = { 2,3,4,1,6,9,8,7,0,10 };
    int arr[10];
	srand((int)time(NULL));
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
	}
	printArray(arr, 10);
	mergeSort(arr, 0, 10 - 1);
	printArray(arr, 10);
	return 0;
}