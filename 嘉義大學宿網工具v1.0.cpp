/*
�Ÿq�j�ǱJ�٤u��
Version:1.0
���v�Ҧ� :���l�y 
https://github.com/DuckLL/NCYUDormitoryNetwokTool.git
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
string ip="";
bool ck();
void set(string link);
void fast();
void wait(int t);
void msg(string next);
int main()
{
	int n;
	while(1)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout<<"�Ÿq�j�ǱJ�٤u�� [Version 1.0]"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"1.�ˬd����"<<endl<<endl;
		cout<<"2.�]�w����IP"<<endl<<endl;
		cout<<"3.�ֳt�˭�"<<endl<<endl;
		cout<<"4.�i������"<<endl<<endl; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"�п�ܡG";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin>>n;
		system("cls");
		switch (n)
		{
			case 1:
				msg("�ֳt�˭�");
				break;
			case 2:
				set("254");
				msg("�ֳt�˭�");
				break;
			case 3:
				fast();
				msg("�i������");
				break;
			case 4:
				cout<<"���b�����ܧ�w�]�h�D...241"<<endl;
				set("241");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"�����w���`�s���A�w�]�h�D...241�C"<<endl<<endl;
					system("pause");				
					break;
				}
				cout<<"���b�����ܧ�w�]�h�D...242"<<endl;
				set("242");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"�����w���`�s���A�w�]�h�D...242�C"<<endl<<endl;
					system("pause");					
					break;
				}
				cout<<"���b�����ܧ�w�]�h�D...243"<<endl;
				set("243");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"�����w���`�s���A�w�]�h�D...243�C"<<endl<<endl;	
					system("pause");				
					break;
				}
				cout<<"���b�����ܧ�w�]�h�D...254"<<endl;
				set("254");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"�����w���`�s���A�w�]�h�D...254�C"<<endl<<endl;	
					system("pause");				
					break;
				}
				cout<<"�������խ״_�����A�p�����D�Чi���J���uŪ�͡C"<<endl;				
		}		
	}
	return 0;
}
bool ck()
{
	int i,t;
	ifstream fin;
	string str;
	t=0;
	while(t<3)
	{
		cout<<"��"<<t+1<<"���ˬd��...�еy��"<<endl;
		system("ping 8.8.8.8 > system.log");
		fin.open("system.log");
		while(str!="=")
			fin>>str;
		for(i=0;i<6;i++)
			fin>>str;
		system("cls");
		fin.close();
		if(str!="0")
			t++;
		else
			return true;	
	}
	return false;
}
void set(string link)
{
	ifstream fin;
	string pat,str;
	if(ip=="")
	{
		system("ipconfig > system.log");
		fin.open("system.log");
		pat="�A�Ӻ���";
		while(fin>>str)
			if(str=="�ϰ�s�u:")
			{
				pat="�ϰ�s�u";
				break;
			}
		cout<<"��J�A��IP: 10.10.";
		cin>>ip;				
	}
	if(ip[2]=='.')
		system(("netsh interface ip set address   \""+pat+"\" static 10.10."+ip+" 255.255.255.0 10.10."+ip[0]+ip[1]+"."+link+" 1").c_str());
	else
		system(("netsh interface ip set address   \""+pat+"\" static 10.10."+ip+" 255.255.255.0 10.10."+ip[0]+ip[1]+ip[2]+"."+link+" 1").c_str());
	system(("netsh interface ip set dns \""+pat+"\" static 140.130.41.11 primary").c_str());
	system(("netsh interface ip add dns \""+pat+"\" 140.130.81.11 ").c_str());
}
void fast()
{
	ifstream fin;
	int i;
	string str;
	system("ipconfig /flushdns");
	system("ipconfig /renew");
	system("netsh winhttp import proxy source=ie");
	system("netsh winhttp show proxy > system.log");
	system("netsh winhttp>reset proxy");
	fin.open("system.log");
	for(i=0;i<5;i++)
		fin>>str;
	if(str!="�����s��")
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"Proxy���~"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"����x>>���ں����ﶵ>>�s�u>>�ϰ�����]�w   �����Ҧ����Ŀ�"<<endl; 
		system("pause");
		exit(0); 
		}
	system("cls");
	cout<<"�ֳt�״_�����I"<<endl<<endl;
}
void wait(int t)
{
	cout<<"���ݺ����ͮ�...";
	clock_t now = clock();
    while( clock() < now + t* CLOCKS_PER_SEC)
	{
		cout<<(clock()-now)/1000+1;
		cout<<"\b";
		for(int i=0;i<10000000;i++);
    }    
	cout<<endl;
}
void msg(string next)
{
	if(ck())
		cout<<"�����w���`�s���A�p�����D�й��էֳt�˭סC"<<endl<<endl;
	else
	{
		cout<<"�����s�����`�A�Х��ˬd�O�_";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"�z�y";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"�A�p�D�z�y�й���"<<next<<"�C"<<endl;				
	}
	system("pause");
}
