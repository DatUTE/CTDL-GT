#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int linearSearch(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return i;
		}

	}
	return -1;
}
int main()
{
	const int size = 20;
	int arrs[size];
	srand((unsigned)time(0));
	for (int i = 0; i < size; i++)
	{
		arrs[i] = (rand() % 100) +1;
		cout << "arr[" << i << "]: " << arrs[i] << endl;
	}
	int key;
	cout << "enter number need search: ";
	cin >> key;
	int retVal = linearSearch(arrs, size, key);
	if (retVal >= 0 )
	{
		cout << "key founded in possition " << retVal << endl;
	}
	else
	{
		cout << "not found key" << endl;
	}
	return 0;
}