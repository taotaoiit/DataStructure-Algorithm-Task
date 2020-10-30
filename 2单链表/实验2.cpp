#include<iostream>
using namespace std;
#include<string>
struct List
{
	List* next;
	string name;
};
//���еĲ����������£�
/*
void createList_front(Lis*& L,int n)//��ǰ�巨������ͷ�ڵ����������ʼ��n��Ԫ��
void createList_back(List*& L, int n)//�ú�巨������ͷ�ڵ����������ʼ��n��Ԫ��
void createList(List*& L)//��ǰ�巨���巨�ϲ�����������
string getElem(List*& L, int n)//�õ���n��λ���ϵ�Ԫ��ֵ
void locateElem(List*& L,string e)//���ҳ�����������Ԫ��ֵΪe��Ԫ��λ��
void insertElem(List*& L, int i, string e)//������ĵ�i��λ�ò�����Ԫ�أ�ֵΪe
void showList(List*& L)//��ʾ��ǰ����
void deleteElem(List*& L,int n)//ɾ����n��λ���ϵ�Ԫ��
void showMenu()//�˵�
*/
void createList_front(List*& L,int n)//��ǰ�巨������ͷ�ڵ������
{
	L = new List;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		cin >> p->name;
		p->next = L->next;
		L->next = p;
	}
	cout << "��ʼ���ɹ�������" << endl;
}
void createList_back(List*& L, int n)//�ú�巨������ͷ�ڵ������
{
	L = new List;
	List* R = new List;
	L->next = NULL;
	R= L;
	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		cin >> p->name;
		R->next = p;
		p->next = NULL;
		R = p;
	}
	cout << "��ʼ���ɹ�������" << endl;
}
void createList(List*& L)//��ǰ�巨���巨�ϲ�����������
{
	char j,k;
	cout << "�Ƿ񴴽�����y/n" << endl;
	cin >> j;
	if (j == 'y')
	{
		int n;
		cout << "��ѡ�񴴽�����ķ�������ǰ�巨����f����巨����b��" << endl;
		cin >> k;
		if (k == 'f')
		{
			cout << "�����봴������ʱ����Ҫ��ʼ����Ԫ�ظ�����" << endl;
			cin >> n;
			cout << "������Ԫ�أ�" << endl;
			createList_front(L, n);
		}
		else if (k == 'b')
		{
			cout << "�����봴������ʱ����Ҫ��ʼ����Ԫ�ظ�����" << endl;
			cin >> n;
			cout << "������Ԫ�أ�" << endl;
			createList_back(L, n);
		}
	}
	else
	{
		cout << "�����˳���" << endl;
	}
}
string getElem(List*& L, int n)
{
	List* p = new List;
	int i;
	p = L;
	for (i = 0; i < n; i++)
	{
		p = p->next;
	}
	if (!p || i > n)
	{
		cout << "���д���" << endl;
		return "error_opreate";
	}
	cout << "��" << n << "��λ�õ�Ԫ��Ϊ��" << p->name << endl;
	return p->name;
}
void locateElem(List*& L,string e)
{
	List* p = new List;
	p = L->next;
	int num=1;
	while (p)
	{
		if (p->name == e)
		{
			cout << "��" << num << "��λ���ϵ�Ԫ��ֵ����" << e << "����ֵַΪ��" << p << endl;;
		}
		num++;
		p = p->next;
	}
}
void insertElem(List*& L, int i, string e)
{
	List* p = L;
	int j = 0;
	while (p && (j < i - 1))
	{
		p = p->next; 
		j++;
	}
	if (!p || j > i - 1)
	{
		cout << "����" << endl;
		return;
	}
	List* s = new List;
	s->name = e;
	s->next = p->next;
	p->next = s;
}
void showList(List*& L)//��ʾ��ǰ����
{
	List* p = new List;
	p = L->next;
	cout << "��ǰ������Ԫ��Ϊ��";
	while (p)
	{
		cout << p->name << "  ";
		p = p->next;
	}
	cout << endl;
}
void deleteElem(List*& L,int n)
{
	List* p = new List;
	p = L;
	for (int i = 0; i < n-1; i++)
	{
		p = p->next;
		if (!p) 
		{
			cout << "error_operate"<<endl;
			return;
		}
	}
	if (!p->next)
	{
		cout << "error_operate"<<endl;
		return;
	}
	List* q = new List;
	q = p->next;
	p->next = q->next;
	cout << "successfully deleted" << endl;
	delete q;
}
void showMenu()
{
	cout << "**********************�����˵�***************************" << endl;
	cout << "*****************����1������������ʼ��*****************" << endl;
	cout << "*****************����2����ȡĳλ��Ԫ��ֵ*****************" << endl;
	cout << "*****************����3������ĳԪ��ֵλ��*****************" << endl;
	cout << "*****************����4������Ԫ�ص�ĳλ��*****************" << endl;
	cout << "*****************����5��ɾ��ĳ��λ��Ԫ��*****************" << endl;
	cout << "*****************����0���˳������������*****************" << endl;
	cout << "*********************************************************" << endl;
}
int main()
{
	List* L;
	int a, b, c;
	string e,g;
	///////////////////////////////
	int Choice = 0;
	bool flag=false;
	while (true)
	{
		system("cls");
		showMenu();
		if(flag==true)
			showList(L);
		cout << "��ѡ���ܣ�" << endl;
		while (true)
		{
			cin >> Choice;
			if (Choice >= 0 && Choice <= 5)
			{
				break;
			}
			else
			{
				cout << "������󣬳����˳�" << endl;
				Choice = 0;
				return 0;
			}
		}
		switch (Choice)
		{
		case 1://����1������������ʼ��
			createList(L);
			showList(L);
			flag = true;
			system("pause");
			break;
		case 2://����2���õ�ĳλ���ϵ�Ԫ��ֵ
			cout << "����λ�ã�" << endl;
			cin >> a;
			getElem(L, a);
			system("pause");
			break;
		case 3://����3������ĳԪ��ֵ��������λ��
			cout << "���������Ԫ��ֵ��" << endl;
			cin >> e;
			locateElem(L, e);
			system("pause");
			break;
		case 4://����4��������ĳλ�ò���Ԫ��
			cout << "���������Ԫ�ص�λ�ã�" << endl;
			cin >> b;
			cout << "���������Ԫ�ص�ֵ��" << endl;
			cin >> g;
			insertElem(L, b, g);
			showList(L);
			system("pause");
			break;
		case 5://����5��ɾ��������ĳλ��Ԫ��
			cout << "������ɾ����λ�ã�" << endl;
			cin >> c;
			deleteElem(L, c);
			showList(L);
			system("pause");
			break;
		case 0://����6���˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;


}