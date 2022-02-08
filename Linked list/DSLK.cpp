#include"DSLK.h"

//Create Node function
NODE *CreateNode(int data) {
	NODE* node = new NODE;
	if (node == NULL) {
		return NULL;
		cout << "Not enough memory" << endl;
	}
	node->data = data;
	node->pNext = NULL;
	return node;
}
//initialization Node function
void InitNode(LList& lst) {
	lst.pHead = lst.pTail = NULL;
}
bool isEmpty(LList lst) {
	if (lst.pHead == NULL)
	{
		return true;
	}
	return false;
}
//add node in head linked list
void addHead(LList& lst, NODE* pNode) {
	if (isEmpty(lst)) {
		lst.pHead = lst.pTail = pNode;
	}
	else
	{
		pNode->pNext = lst.pHead;//cho con tro cua node can them la node lst lk den node dau pHead
		lst.pHead = pNode; //cap nhat lai pHead chinh la node p
	}
}
//add node in Tail linked list
void addTail(LList& lst, NODE* pNode) {
	if (isEmpty(lst)) {
		lst.pHead = lst.pTail = pNode;
	}
	else
	{
		lst.pTail->pNext= pNode;//cho con tro cua pTail lk voi node lst
		lst.pTail = pNode; //cap nhat lai pTail chinh la node pNode
	}
}
void addNode_p_VaosauNode_q(LList& lst, NODE* p)
{
	int x;
	cout << "\nNhap gia tri node q:";
	cin >> x;
	NODE* q = CreateNode(x);
	//neu q la node dau tien va duy nhat
	if (q->data == lst.pHead->data && lst.pHead->pNext == NULL)
	{
		addTail(lst, p);
	}
	else {
		for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
		{
			if (q->data == k->data)
			{
				NODE* n = CreateNode(p->data);//Khoi tao node h moi de them vao sau node q;
				NODE* g = k->pNext;// cho node g tro den node nam sau node q
				n->pNext = g;//B1: Tao moi lien ket tu node p den node g <=> tao moi lien ket tu node p toi node nam sau q
				k->pNext = n;//B2: Tao moi lien ket tu node q toi node p
			}
		}
	}
}
void addNode_p_VaotruocNode_q(LList& lst, NODE* p)
{
	int x;
	cout << "Nhap gia tri node q: ";
	cin >> x;
	NODE* q = CreateNode(x);
	if (q->data == lst.pHead->data && lst.pHead->pNext == NULL)
	{
		addHead(lst, p);
	}
	else
	{
		NODE* g = new NODE;//Node giu lien ket voi node nam truoc node q
		for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
		{
			if (q->data == k->data) 
			{
				NODE* m = CreateNode(p->data);
				m->pNext = k;
				g->pNext = m;
			}
			g = k;//giu lien ket voi node nam truoc node q trong sanh sach
		}
	}
}
// them node p vao vi tri vt trong danh sach lst
void addNode_p_VaoVtBatki(LList& lst, NODE* p, int vt, int n)
{	
	//danh sach dang rong
	if (lst.pHead == NULL || vt == 1)
	{
		addHead(lst, p);// them vao dau
	}
	else if (vt == n + 1)
	{
		addTail(lst, p);//them vao cuoi
	}
	else
	{
		int dem = 0;
		NODE* g = new NODE;//Node giu lien ket voi node nam truoc node q
		for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
		{
			dem++;
			if (dem == vt)
			{
				NODE* m = CreateNode(p->data);
				m->pNext = k;
				g->pNext = m;
				break;
			}
			g = k;//giu lien ket voi node nam truoc node q trong sanh sach
		}
	}
}
//xoa node dau
void delHead(LList& lst)
{
	if (lst.pHead == NULL)
	{
		return;
	}
	else
	{
		NODE* p = lst.pHead;
		lst.pHead = lst.pHead->pNext;
		delete p;
	}
}
//xoa node cuoi
void delTail(LList& lst)
{
	if (lst.pHead == NULL)
	{
		return;
	}
	// truong hop danh sach co 1 phan tu
	if (lst.pHead->pNext == NULL)
	{
		delHead(lst);
	}
	else
	{
		for (NODE* k = lst.pHead; k != NULL; k = k + 1)
		{
			if (k->pNext = lst.pTail)
			{
				delete lst.pTail;
				k->pNext = NULL;//cho con tro node ke cuoi tro toi null
				lst.pTail = k;//cap nhat lai pTail
				return;
			}
		}
	}
}
//xoa node sau node q ton tai trong danh sach
void del_sauNode_q(LList& lst, NODE *q)
{
	if (lst.pHead == NULL)
	{
		return;
	}
	else
	{
		for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
		{
			if (k->data == q->data)
			{
				NODE* g = k->pNext;//node g la node nam sau node k <=> node ma ta se xoa
				k->pNext = g->pNext;
				delete g;
			}
		}
	}
}
//xoa 1 node bat ki
void delNode(LList& lst, int x)
{
	NODE* g = new NODE;
	if (lst.pHead ->data == x)
	{
		delHead(lst);
		return;
	}
	else if (lst.pTail->data == x)
	{
		delTail(lst);
		return;
	}
	else
	{
		for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
		{
			if (k->data == x)
			{
				g->pNext = k->pNext;
				delete k;
			}
			g = k;
		}
	}
}
// giai phong vung nho cho danh sach
void delMemmory(LList& lst)
{
	NODE* k =NULL;
	while (lst.pHead != NULL)
	{
		k = lst.pHead;
		lst.pHead = lst.pHead->pNext;
		delete k;
	}
}
void printNode(LList lst) {
	for (NODE* k = lst.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
	cout << endl;
}
int maxNode(LList lst) {
	int max = lst.pHead->data;//gan gia tri max cho data cua node dau
	//duyet tu node thu 2
	for (NODE* k = lst.pHead->pNext; k != NULL; k = k->pNext)
	{
		if (max < k->data) {
			max = k->data;
		}
	}
	return max;
}