#include <iostream>
using namespace std;
#define maxSize 100
class SeqList 
{
private:
	char* p;
	int last;
public:
	
	void InitList();
	void DestroyList();
	void ListInsert(int i, char e);
	void ListDelete(int i);
	void printdata();
	void import_data(const char* t);
	void search_elem(char e);
};
void SeqList::InitList()
{
	p = new char[maxSize];
	last = 0;
}
void SeqList::DestroyList()
{
	last = 0;
	delete []p;
}
void SeqList::ListInsert(int i, char e)
{
	if (last>= maxSize)
	{
		cout << "����ռ�������" << endl;
		return ;
	}
	if (i > last + 1)
	{
		cout << "��˳������" << last << "��Ԫ�أ�����λ�ô���" << endl;
		return;
	}
	if (last == 0)
	{
		*p = e;
		last++;
		return;
	}
	if (i==last+1)
	{
		*(p + last) = e;
		last++;
		return;
	}
	for (int n = last - 1; n >= i - 1; n--)
	{
		*(p + n + 1) = *(p + n);
	}
	*(p + i - 1) = e;
	last++;
}
void SeqList::ListDelete(int i)
{
	if (last == 0)
	{
		cout << "��������������ɾ��" << endl;
		return;
	}
	if (i > last)
	{
		cout << "��˳������" << last << "��Ԫ�أ���������" << endl;
		return;
	}
	for (int n = i - 1; n <= last - 2; n++)
	{
		*(p + n) = *(p + n + 1);
	}
	last--;
}
void SeqList::printdata()
{
	cout << "��ʱ˳����е�Ԫ��Ϊ��" << endl;
	for (int i = 0; i < last ; i++)
		cout << *(p + i) << " ";
	cout << endl;
}
void SeqList::import_data(const char* t)
{
	if (strlen(t) +last> maxSize)
	{
		cout << "������ַ���������" << endl;
		return;
	}
	for (int i = last; i < strlen(t); i++)
	{
		ListInsert(i + 1, *(t + i));
	}
}
void SeqList::search_elem(char e)
{
	bool flag = false;
	for (int i = 0; i < last; i++)
	{
		if (*(p + i) == e)
		{
			cout << "��" << i + 1 << "��Ԫ�ص�ֵ����" << e << endl;
			flag = true;
		}
	}
	if (flag == false)
		cout << "˳������޵���" << e << "��Ԫ��" << endl;
}
int main()
{
	SeqList L;
	const char* t = "hello_data_structure";
	cout << "����˳���" << endl;
	L.InitList();
	cout << "����Ԫ��:" << endl;
	L.import_data(t);
	L.printdata();
	cout << "��λ��1�����ַ�1��" << endl;
	L.ListInsert(1, '1');
	L.printdata();
	cout << "��λ��3�����ַ�3��" << endl;
	L.ListInsert(3, '3');
	L.printdata();
	cout << "��λ��5�����ַ�5��" << endl;
	L.ListInsert(5, '5');
	L.printdata();
	cout << "��λ��8�����ַ�8��" << endl;
	L.ListInsert(8, '8');
	L.printdata();
	cout << "ɾ��λ��8Ԫ�أ�" << endl;
	L.ListDelete(8);
	L.printdata();
	cout << "ɾ��λ��5Ԫ�أ�" << endl;
	L.ListDelete(5);
	L.printdata();
	cout << "ɾ��λ��3Ԫ�أ�" << endl;
	L.ListDelete(3);
	L.printdata();
	cout << "ɾ��λ��1Ԫ�أ�" << endl;
	L.ListDelete(1);
	L.printdata();
	cout << "����Ԫ��:" << endl;
	L.search_elem('a');
	L.search_elem('b');
	cout << "�ɹ�ɾ��˳���" << endl;
	L.DestroyList();
	return 0;

}
