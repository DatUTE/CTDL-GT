#include<iostream>
#include<string>
#include"DSLK.h"
#include<regex>
#define cls system("cls")
using namespace std;

LList List;
NODE* node = new NODE;
void MenuThemNode(LList& lst);
void MenuXoaNode(LList& lst);
int check(int n)
{
	regex re_num("^[0-9]+$");
	string input;
	int numberReturn = -1;
	while (1)
	{
		cout << "Nhap lua chon: ";
		getline(cin, input);
		if (regex_match(input, re_num) && stoi(input) < n && stoi(input) >= 0)
		{
			numberReturn = stoi(input);
			break;
		}
		else
		{
			cout << "Lua chon khong hop le!" << endl;
		}
	}
	return numberReturn;
}
void Menu(LList& lst)
{
	int choice;
	//InitNode(List);
	bool exam = true;
	while (exam)
	{
		cls;
		cout << "===========Menu===========" << endl;
		cout << "1.Them 1 node vao DS" << endl;
		cout << "2.Xuat DS lien ket don" << endl;
		cout << "3.Them node " << endl;
		cout << "4.Xoa node" << endl;
		cout << "0.Thoat!" << endl;

		choice = check(7);
		cin.ignore(0);
		switch (choice)
		{
		case 1:
		{
			cls;
			int data;
			cout << "Nhap du lieu cho node: ";
			cin >> data;
			cin.ignore(1);
			node = CreateNode(data);
			addTail(lst, node);
			break;
		}
		case 2:
		{
			cls;
			cout << "\nDANH SACH LIEN KET DON" << endl;
			printNode(lst);
			system("pause");
			break;
		}
		case 3:
		{
			MenuThemNode(List);
			break;
		}

		case 4:
		{
			MenuXoaNode(List);
			break;
		}
		case 0:
		{
			cout << "GOODBYE!" << endl;
			exam = false;
			break;
		}
		default:
			break;
		}
	}
}
void MenuThemNode(LList &lst)
{
	while (true)
	{
		cls;
		int selection;
		cout << "1.Them node p vao sau node q" << endl;
		cout << "2.Them node p vao truoc node q" << endl;
		cout << "3.Them node vao vi tri bat ki" << endl;
		cout << "4.Quay lai Menu" << endl;
		selection = check(5);
		switch (selection)
		{
		case 1:
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau:";
			cin >> x;
			NODE* p = CreateNode(x);
			addNode_p_VaosauNode_q(lst, p);//them node p vao sau node q
			break;
		}
		case 2:
		{
			cls;
			int x;
			cout << "\nNhap gia tri node p can them vao truoc:";
			cin >> x;
			NODE* p = CreateNode(x);
			addNode_p_VaotruocNode_q(lst, p);//them node p vao sau node q
			break;
		}
		//cach 1: su dung bien cuc bo
		//cach 2: su dung bien toan cuc
		//moi lan them node o case 1 thi n++, bien n de luu so luong node trong danh sach(khong khuyen khich)
		case 3:
		{
			cls;
			int x, vt;
			int n = 0;
			for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
			{
				n++;
			}
			cout << "\nNhap gia tri node p can them : ";
			cin >> x;
			NODE* p = CreateNode(x);
			do
			{
				cout << "\nNhap vi tri can them: ";
				cin >> vt;
				cin.ignore(1);
				if (vt <1 || vt > n + 1)
				{
					cout << "Vi tri can them phai nam trong doan[1;" << n + 1 << "]" << endl;
				}
			} while (vt <1 || vt >n + 1);
			addNode_p_VaoVtBatki(lst, p, vt, n);//them node p vao sau node q
			break;
		}
		case 4:
		{
			cls;
			Menu(List);
			break;
		}
		default:
			break;
		}
	}
}
void MenuXoaNode(LList& lst)
{
	while (true)
	{
		cls;
		int selection;
		cout << "1.Xoa node dau" << endl;
		cout << "2.Xoa node cuoi" << endl;
		cout << "3.Xoa node sau node q" << endl;
		cout << "4.Xoa node bat ki" << endl;
		cout << "0.Quay lai Menu" << endl;
		selection = check(6);
		switch (selection)
		{
		case 1:
		{
			cls;
			delHead(List);
			break;
		}
		case 2:
		{
			cls;
			delTail(List);
			break;
		}
		case 3:
		{
			cls;
			int x;
			cout << "Nhap gia tri node q: ";
			cin >> x;
			cin.ignore(0);
			NODE* q = CreateNode(x);
			del_sauNode_q(List, q);
			break;
		}
		case 4:
		{
			cls; 
			int x;
			cout << "Nhap gia tri can xoa:";
			cin >> x;
			cin.ignore(0);
			delNode(List, x);
			break;
		}
		case 0:
		{
			cls;
			Menu(List);
			break;
		}
		default:
			break;
		}
	}
}
int main(){
	cls;
	//khoi tao node
	InitNode(List);
	Menu(List);
	delMemmory(List);
	system("pause");
	return 0;
}