//ѭ�����У��������
#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 100

struct Person
{
	string name;
	char sex;
};
Person newPerson(string name, char sex)
{
	Person P;
	P.name = name;
	P.sex = sex;
	return P;

}

class Queue
{
private:
	Person* base;//���г�ʼ��ַ
	int front;//������ͷָ��
	int rear;//������βָ��
public:
	void InitQueue();//��ʼ��˳�����
	int QueueLen();//���ض��г���
	void EnQueue(Person e);//���
	Person DeQueue();//����
	Person GetHead();//ȡͷԪ��
	void ShowQueue();//��ʾ����Ԫ��
};
void Queue::InitQueue()//��ʼ�����У���βָ����ͷָ���0��ע����ָ��Ǳ�ָ��
{
	base = new Person[MAXSIZE];
	front = rear = 0;
}
int Queue::QueueLen()//���ض��г���
{
	return((rear - front + MAXSIZE) % MAXSIZE);
}
void Queue::EnQueue(Person e)//��ӣ�βָ��ǰ��
{
	if ((rear + 1) % MAXSIZE == front)//�ж��Ƿ����
	{
		cout << "����������������ʧ��" << endl;
	}
	*(base + rear) = e;//���rear��ָ��ָ�򡱵Ŀռ�
	rear = (rear + 1) % MAXSIZE;//ǰ������
}
Person Queue::DeQueue()//���ӣ�ͷָ���һ
{
	if (rear == front)//�ж��Ƿ�ӿ�
	{
		cout << "�ӿգ�����ʧ�ܡ�����" << endl;
	}
	Person e;
	e = *(base + front);//�����ͷԪ��
	front = (front + 1) % MAXSIZE;//ͷָ��ǰ������
	return e;//���ر����Ԫ��ֵ
}
Person Queue::GetHead()//�����ض�ͷԪ��
{
	if (rear == front)
	{
		cout << "�ӿգ�����ʧ�ܡ�����" << endl;
	}
	return *(base + front);

}

//����2����
void EnPerson(Queue& Q)//������Ա
{
	string name;
	char sex;
	char f;
	while (true)//����ѭ��������һֱ����
	{
		cout << "�Ƿ����Ա����y/n��" << endl;
		cin >> f;
		if (f == 'n')
			break;
		cout << "����������+�ո�+�Ա�(m/f)��";//m�����ˣ�f��Ů��
		cin >> name;
		cin >> sex;
		Person P = newPerson(name, sex);
		Q.EnQueue(P);
	}
	cout << "������" << Q.QueueLen() << "����" << endl;
}

//����3����
void DePerson(Queue& Q, Queue& Qm, Queue& Qf)//�Ӷ����е�����Ա���������Ա𱣴浽��Ӧ����
{
	int n = Q.QueueLen();
	while (n)
	{
		n--;
		Person P;
		P = Q.DeQueue();
		if (P.sex == 'm')//�е�
			Qm.EnQueue(P);//���浽���Զ���
		else if (P.sex == 'f')//Ů��
			Qf.EnQueue(P);//���浽Ů�Զ���
		else
			cout << "�Ա�����ɾ�����ˡ���" << endl;
	}
	cout << "��ȫ�����ӣ��������ӵĳ�Ա�����Ա𱣴浽��Ӧ�Ķӡ�����" << endl;
}

//����4����
void PaPerson(Queue& Qm, Queue& Qf)
{
	int L;
	Qm.QueueLen() < Qf.QueueLen() ? L = Qm.QueueLen() : L = Qf.QueueLen();//ȡ��Ů��������С�Ķ��г���
	while (L)//���
	{
		Person Pm, Pf;//Pm�������м������Pf��Ů���м����
		Pm = Qm.DeQueue();
		Pf = Qf.DeQueue();
		cout << Pm.name << "��" << Pf.name << "��Գɹ�" << endl;
		L--;
	}
	if (Qm.QueueLen() < Qf.QueueLen())//���������������Ů����
	{
		Person P;
		P = Qf.GetHead();//���ض�ͷŮ��
		cout << P.name << "δ���" << endl;
	}
	else if (Qm.QueueLen() > Qf.QueueLen())//�������������Ů����
	{
		Person P;
		P = Qm.GetHead();//���ض�ͷ����
		cout << P.name << "δ���" << endl;
	}
	else
		cout << "ȫ����ԣ�" << endl;
}

//��ʾ�˵�����
void showMenu()
{
	cout << "****************************�����˵�*********************************" << endl;
	cout << "*****************����1����ʼ��ѭ������              *****************" << endl;
	cout << "*****************����2������ȫ����                  *****************" << endl;
	cout << "*****************����3�����Ӳ������Ա𱣴浽��Ӧ��  *****************" << endl;
	cout << "*****************����4����Ů��Է�������б���һ��δ���������*****" << endl;
	cout << "*****************����0���˳�����������              *****************" << endl;
	cout << "*************************��������������******************************" << endl;
	cout << "************************* 1901103��2�� ******************************" << endl;
	cout << "*************************��������������******************************" << endl;
}
int main()
{
	Queue Q,Qm,Qf;//����һ�����ж���
	int Choice = 0;
	Q.InitQueue();
	Qm.InitQueue();
	Qf.InitQueue();
	cout << "��ʼ��ѭ�����гɹ���������" << endl;
	while (true)
	{
		system("cls");//����
		showMenu();//��ʾ�˵�
		cout << "��ѡ���ܣ�";
		while (true)
		{
			cin >> Choice;
			if (Choice >= 0 && Choice <= 4)
				break;
			else
				cout << "�����������������" << endl;
		}
		switch (Choice)
		{
		case 1://����1����ʼ��ѭ������
			Q.InitQueue();
			cout << "��ʼ��˳��ջ�ɹ�����" << endl;
			system("pause");
			break;
		case 2://����2������ȫ����
			EnPerson(Q);
			system("pause");
			break;
		case 3://����3�����Ӳ������Ա𱣴浽��Ӧ��
			DePerson(Q, Qm, Qf);
			system("pause");
			break;
		case 4://����4����Ů��Է�������б���һ��δ���������
			PaPerson(Qm, Qf);
			system("pause");
			break;
		case 0://����5���˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}