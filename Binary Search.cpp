#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(vector<int> vec, int key)
{
	int first = 0;
	int last = vec.size() - 1;
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (key > vec[mid])
		{
			first = mid + 1;
		}
		else if(key < vec[mid])
		{
			last = mid - 1;
		}
		else
		{
			return mid;
		}
		
	}
	return -(first + 1);
}
int main()
{
	vector<int> numbers;
	srand(unsigned(time(0)));
	for (int i = 0; i < 50; i++)
	{
		numbers.push_back((rand() % 100) + 1);
	}
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " " ;
	}
	cout << endl;
	int key;
	cout << "enter number need find: ";
	cin >> key;
	int retVal = binarySearch(numbers, key);
	if (retVal > -1)
	{
		cout << "key founded in possition " << retVal << endl;
	}
	else
	{
		cout << "key not found! " << endl;
	}
	return 0;
}
