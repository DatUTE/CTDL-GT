#include<iostream>

using namespace std;

int main()
{
	int n;
	cout << "nhap so n: ";
	cin >> n;
	/*
	*
	**
	***
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "---------------------------" << endl;
	/*
	***
	**
	*
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i; j >= 1; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
	/*
	***
	 **
	  *
	*/
	for (int i = 0; i < n; i++)
	{
		for (int x = 0; x < i; x++)
		{
			cout << " ";
		}
		for (int j = n - i; j >= 1; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "---------------------------" << endl;
	/*
	  *
	 **
	***
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1- i; j >= 1; j--)
		{
			cout << " ";
		}
		for (int x = 0; x <= i; x++)
		{
			cout << "*";
		}
		cout << endl;
	}
	//tam giac
	cout << "=================" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << " ";
		}
		for (int x = 1; x <= (2 * i - 1); x++)		
		{
			cout << "*";
		}
		cout << endl;
	}
	//tam giac nguoc
	cout << "=================" << endl;
	for (int i = 1; i <= n; i++)
	{
		
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}
		for (int x = (n*2-i); x >=i; x--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}