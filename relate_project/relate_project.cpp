#include <iostream>

#define MAXSIZE 500
using namespace std;

//联系人结构体
struct Person
{
	string m_Name;
	int gender;
	int age;
	string m_Phone;
	string m_Address;
};

//通讯录结构体
struct Addressbooks
{
	//通讯录上限
	Person personArray[MAXSIZE];
	//通讯录目前存储的人数
	int m_size;
};


//功能界面
void showMenu()
{
	cout << "******************************" << endl;
	cout << "*****    1.添加联系人    *****" << endl;
	cout << "*****    2.显示联系人    *****" << endl;
	cout << "*****    3.删除联系人    *****" << endl;
	cout << "*****    4.查找联系人    *****" << endl;
	cout << "*****    5.修改联系人    *****" << endl;
	cout << "*****    6.清空联系人    *****" << endl;
	cout << "*****    0.退出          *****" << endl;
	cout << "******************************" << endl;
}

//添加联系人功能函数
void addPerson(Addressbooks* abs)
{
	//判断通讯录人数是否满了
	if (abs->m_size == MAXSIZE)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		//添加姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		//添加性别
		cout << "请输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
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
				cout << "输入错误，请重新输入：" << endl;
			}
		}

		//输入年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		//输入电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		//输入地址
		cout << "请输入住址：" << endl;
		string adress;
		cin >> adress;
		abs->personArray[abs->m_size].m_Address = adress;

		abs->m_size++;

		cout << "添加成功" << endl;

		system("pause"); //按任意键继续
		system("cls"); //清屏操作
	}
}

//显示联系人函数
void showPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录中还没有人,请先添加联系人" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].gender == 1 ? "男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "手机号码：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人函数
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

//删除联系人函数
void dropPerson(Addressbooks* abs, int ret)
{
	for (int j = ret; j < abs->m_size; j++)
	{
		abs->personArray[j] = abs->personArray[j + 1];
	}
	abs->m_size--;
	cout << "删除成功" << endl;

	system("pause");
	system("cls");
}


//查找联系人函数
void findPerson(Addressbooks* abs, int ret)
{
	cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
	cout << "性别：" << (abs->personArray[ret].gender == 1 ? "男" : "女") << "\t";
	cout << "年龄：" << abs->personArray[ret].age << "\t";
	cout << "手机号码：" << abs->personArray[ret].m_Phone << "\t";
	cout << "地址：" << abs->personArray[ret].m_Address << endl;

	system("pause");
	system("cls");
}

void alterPerson(Addressbooks* abs, int ret)
{
	//修改姓名
	string name;
	cout << "输入新姓名：" << endl;
	cin >> name;
	abs->personArray[ret].m_Name = name;

	//修改性别
	int gender;
	cout << "输入新性别：" << endl;
	cout << "1--男" << "  " << "2--女" << endl;
	while (true)
	{
		cin >> gender;
		if (gender == 1 || gender == 2)
		{
			abs->personArray[ret].gender = gender;
			break;
		}
		cout << "输入无效，请重新输入" << endl;
	}

	//修改年龄
	int age;
	cout << "输入新年龄：" << endl;
	cin >> age;
	abs->personArray[ret].age = age;

	//修改手机号码
	string number;
	cout << "输入新手机号码：" << endl;
	cin >> number;
	abs->personArray[ret].m_Phone = number;

	string address;
	cout << "输入新地址：" << endl;
	cin >> address;
	abs->personArray[ret].m_Address = address;

	cout << "修改成功" << endl;

	system("pause");
	system("cls");
}

//清空通讯录
void cleanPerson(Addressbooks* abs)
{
	abs->m_size == 0;
	cout << "已清空" << endl;

	system("pause");
	system("cls");
}


int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	abs.m_size = 0;


	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		//添加联系人
		case 1:
			addPerson(&abs);
			break;
		//显示联系人
		case 2:
			showPerson(&abs);
			break;
		//删除联系人
		case 3:
		{
			string name;
			cout << "请输入你想要删除的联系人姓名：" << endl;
			cin >> name;
			int ret = existPerson(&abs, name);
			if (ret == -1)
			{
				cout << "没有此联系人" << endl;
			}
			else
			{
				dropPerson(&abs,ret);
			}
		}
			break;
		//查找联系人
		case 4:
		{
			string name;
			cout << "输入你想查找人的姓名" << endl;
			cin >> name;
			int ret = existPerson(&abs, name);
			if (ret == -1)
			{
				cout << "没有此联系人" << endl;
			}
			else
			{
				findPerson(&abs, ret);
			}
		}
			break;
		//修改联系人
		case 5:
		{
			string name;
			cout << "输入你想查找人的姓名" << endl;
			cin >> name;
			int ret = existPerson(&abs, name);
			if (ret == -1)
			{
				cout << "没有此联系人" << endl;
			}
			else
			{
				alterPerson(&abs, ret);
			}
		}
			break;
		//清空联系人
		case 6:
			cleanPerson(&abs);
			break;
		//退出程序
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入无效";
			break;
		}
	}


	system("pause");
	return 0;
}