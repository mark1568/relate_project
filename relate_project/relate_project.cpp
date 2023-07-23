#include <iostream>

#define MAXSIZE 500
using namespace std;

//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int gender;
	int age;
	string m_Phone;
	string m_Address;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼����
	Person personArray[MAXSIZE];
	//ͨѶ¼Ŀǰ�洢������
	int m_size;
};


//���ܽ���
void showMenu()
{
	cout << "******************************" << endl;
	cout << "*****    1.�����ϵ��    *****" << endl;
	cout << "*****    2.��ʾ��ϵ��    *****" << endl;
	cout << "*****    3.ɾ����ϵ��    *****" << endl;
	cout << "*****    4.������ϵ��    *****" << endl;
	cout << "*****    5.�޸���ϵ��    *****" << endl;
	cout << "*****    6.�����ϵ��    *****" << endl;
	cout << "*****    0.�˳�          *****" << endl;
	cout << "******************************" << endl;
}

//�����ϵ�˹��ܺ���
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�����Ƿ�����
	if (abs->m_size == MAXSIZE)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		//�������
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		//����Ա�
		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int gender = 0;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[abs->m_size].gender = gender;
				break;
			}
			else
			{
				cout << "����������������룺" << endl;
			}
		}

		//��������
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		//����绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		//�����ַ
		cout << "������סַ��" << endl;
		string adress;
		cin >> adress;
		abs->personArray[abs->m_size].m_Address = adress;

		abs->m_size++;

		cout << "��ӳɹ�" << endl;

		system("pause"); //�����������
		system("cls"); //��������
	}
}

//��ʾ��ϵ�˺���
void showPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼�л�û����,���������ϵ��" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].gender == 1 ? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "�ֻ����룺" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ�˺���
int existPerson(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ�˺���
void dropPerson(Addressbooks* abs, int ret)
{
	for (int j = ret; j < abs->m_size; j++)
	{
		abs->personArray[j] = abs->personArray[j + 1];
	}
	abs->m_size--;
	cout << "ɾ���ɹ�" << endl;

	system("pause");
	system("cls");
}


//������ϵ�˺���
void findPerson(Addressbooks* abs, int ret)
{
	cout << "������" << abs->personArray[ret].m_Name << "\t";
	cout << "�Ա�" << (abs->personArray[ret].gender == 1 ? "��" : "Ů") << "\t";
	cout << "���䣺" << abs->personArray[ret].age << "\t";
	cout << "�ֻ����룺" << abs->personArray[ret].m_Phone << "\t";
	cout << "��ַ��" << abs->personArray[ret].m_Address << endl;

	system("pause");
	system("cls");
}

void alterPerson(Addressbooks* abs, int ret)
{
	//�޸�����
	string name;
	cout << "������������" << endl;
	cin >> name;
	abs->personArray[ret].m_Name = name;

	//�޸��Ա�
	int gender;
	cout << "�������Ա�" << endl;
	cout << "1--��" << "  " << "2--Ů" << endl;
	while (true)
	{
		cin >> gender;
		if (gender == 1 || gender == 2)
		{
			abs->personArray[ret].gender = gender;
			break;
		}
		cout << "������Ч������������" << endl;
	}

	//�޸�����
	int age;
	cout << "���������䣺" << endl;
	cin >> age;
	abs->personArray[ret].age = age;

	//�޸��ֻ�����
	string number;
	cout << "�������ֻ����룺" << endl;
	cin >> number;
	abs->personArray[ret].m_Phone = number;

	string address;
	cout << "�����µ�ַ��" << endl;
	cin >> address;
	abs->personArray[ret].m_Address = address;

	cout << "�޸ĳɹ�" << endl;

	system("pause");
	system("cls");
}

//���ͨѶ¼
void cleanPerson(Addressbooks* abs)
{
	abs->m_size == 0;
	cout << "�����" << endl;

	system("pause");
	system("cls");
}


int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	abs.m_size = 0;


	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		//�����ϵ��
		case 1:
			addPerson(&abs);
			break;
		//��ʾ��ϵ��
		case 2:
			showPerson(&abs);
			break;
		//ɾ����ϵ��
		case 3:
		{
			string name;
			cout << "����������Ҫɾ������ϵ��������" << endl;
			cin >> name;
			int ret = existPerson(&abs, name);
			if (ret == -1)
			{
				cout << "û�д���ϵ��" << endl;
			}
			else
			{
				dropPerson(&abs,ret);
			}
		}
			break;
		//������ϵ��
		case 4:
		{
			string name;
			cout << "������������˵�����" << endl;
			cin >> name;
			int ret = existPerson(&abs, name);
			if (ret == -1)
			{
				cout << "û�д���ϵ��" << endl;
			}
			else
			{
				findPerson(&abs, ret);
			}
		}
			break;
		//�޸���ϵ��
		case 5:
		{
			string name;
			cout << "������������˵�����" << endl;
			cin >> name;
			int ret = existPerson(&abs, name);
			if (ret == -1)
			{
				cout << "û�д���ϵ��" << endl;
			}
			else
			{
				alterPerson(&abs, ret);
			}
		}
			break;
		//�����ϵ��
		case 6:
			cleanPerson(&abs);
			break;
		//�˳�����
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������Ч";
			break;
		}
	}


	system("pause");
	return 0;
}