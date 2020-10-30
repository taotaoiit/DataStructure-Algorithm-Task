#include<iostream>
using namespace std;
#define MAXSIZE 100

//����stackʵ��˳���

class Stack
{
private:
	int* base;//ջ��ָ��
	int* top;//ջ��ָ��
	int stacksize;//�������
public:
	void initStack();//��ʼ��
	void push(int e);//��ջ
	int pop();//��ջ������ջ��Ԫ��
	int getTop();//����ջ��Ԫ��
	void show();//��ӡջ��Ԫ�ص��ᵼ��ȫ����ջ
};
void Stack::initStack()
{
	base = new int[MAXSIZE];
	top = base;
	stacksize = MAXSIZE;
}
void Stack::push(int e)
{
	if (top - base == stacksize)
	{
		cout << "ջ����������ʧ�ܡ���" << endl;
		return;
	}
	*top = e;
	top++;
}
int Stack::pop()
{
	if (top == base)
	{
		cout << "ջΪ�գ���ջʧ�ܡ���" << endl;
		return -10000;//�����0����
	}
	return *--top;
}
int Stack::getTop()
{
	if (top != base)
		return *(top - 1);
	else return 9999;
}
void Stack::show()
{
	while (top - base > 0)
		cout << pop() << ' ';
	cout << endl;
}

//�ݹ麯��������ת������
void digui(int n,int b,Stack &S)
{
	if (n == 0);
	else 
	{
		int t;
		t = n % b;
		S.push(t);//��n�����ֵt���β���ջ��
		digui(n / b, b, S);//�ݹ����
	}
}
//����ת������
void transBase()
{
	int n,b;
	Stack S;
	S.initStack();
	cout << "�������ת����10��������";
	cin >> n;
	cout << "������ת���Ľ��ƣ�";
	cin >> b;
	digui(n, b, S);
	S.show();
}
//��ʾ�˵�
void showMenu()
{
	cout << "****************************�����˵�*********************************" << endl;
	cout << "*****************����1����ʼ��˳��ջ                *****************" << endl;
	cout << "*****************����2����ջ                        *****************" << endl;
	cout << "*****************����3����ջ������ջ��Ԫ��          *****************" << endl;
	cout << "*****************����4������ջ��Ԫ��                *****************" << endl;
	cout << "*****************����5����ӡջ��Ԫ�ص��ᵼ��ȫ����ջ*****************" << endl;
	cout << "*****************����6������ת��                    *****************" << endl;
	cout << "*****************����0���˳�˳��ջ��������          *****************" << endl;
	cout << "*********************************************************************" << endl;
}
int main()
{
	Stack S;
	char f;
	int Choice = 0;
	cout << "�Ƿ��ʼ��˳��ջ��(y/n)" << endl;//��ʼ��˳��ջ
	cin >> f;
	if (f == 'n')
		return 0;//������ʼ��˳��ջ�����������
	S.initStack();
	cout << "��ʼ��ջ�ɹ�����" << endl;
	while (true)
	{
		system("cls");//����
		showMenu();//��ʾ�˵�
		cout << "��ѡ���ܣ�";
		while (true)
		{
			cin >> Choice;
			if (Choice >= 0 && Choice <= 6)
				break;
			else
				cout << "�����������������" << endl;
		}
		switch (Choice)
		{
		case 1://����1����ʼ��˳��ջ
			S.initStack();
			cout << "��ʼ��˳��ջ�ɹ�����" << endl;
			system("pause");
			break;
		case 2://����2����ջ
			int e2;
			cout << "�������ջԪ�أ�" << endl;
			cin >> e2;
			S.push(e2);
			system("pause");
			break;
		case 3://����3����ջ������ջ��Ԫ��
			int e3;
			e3 = S.pop();
			if (e3!=-10000)
				cout << "��ջ�ɹ�����ջ��Ԫ��Ϊ��" << e3 << endl;
			system("pause");
			break;
		case 4://����4������ջ��Ԫ��
			cout << "ջ��Ԫ��Ϊ��" << S.getTop() << endl;
			system("pause");
			break;
		case 5://����5��//��ӡջ��Ԫ�ص��ᵼ��ȫ����ջ
			S.show();
			system("pause");
			break;
		case 6://����6��//����ת��
			transBase();
			system("pause");
			break;
		case 0://����6���˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}