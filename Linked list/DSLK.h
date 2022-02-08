#pragma once
#include<iostream>

using namespace std;
//khai bao cau truc linked list don
struct NODE
{
	int data;
	NODE* pNext;
};
struct LList
{
	NODE* pHead;
	NODE* pTail;
};
//khoi tao 1 node
NODE* CreateNode(int data);
//khoi tao danh sach
void InitNode(LList& lst);
//ktra list rong
bool isEmpty(LList lst);
//them node
void addHead(LList& lst, NODE *pNode);
void addTail(LList& lst, NODE* pNode);
void addNode_p_VaosauNode_q(LList& lst, NODE* p);
void addNode_p_VaotruocNode_q(LList& lst, NODE* p);
void addNode_p_VaoVtBatki(LList& lst, NODE* p, int vt,int n);
//xoa node
void delHead(LList& lst);
void delTail(LList& lst);
void del_sauNode_q(LList& lst, NODE* q);
void delNode(LList& lst, int x);
void delMemmory(LList& lst);
//xuat ra node
void printNode(LList lst);
int maxNode(LList lst);
