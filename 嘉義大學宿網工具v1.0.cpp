/*
嘉義大學宿舍工具
Version:1.0
版權所有 :廖子慶 
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
		cout<<"嘉義大學宿舍工具 [Version 1.0]"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"1.檢查網路"<<endl<<endl;
		cout<<"2.設定網路IP"<<endl<<endl;
		cout<<"3.快速檢修"<<endl<<endl;
		cout<<"4.進階維修"<<endl<<endl; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"請選擇：";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cin>>n;
		system("cls");
		switch (n)
		{
			case 1:
				msg("快速檢修");
				break;
			case 2:
				set("254");
				msg("快速檢修");
				break;
			case 3:
				fast();
				msg("進階維修");
				break;
			case 4:
				cout<<"正在嘗試變更預設閘道...241"<<endl;
				set("241");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"網路已正常連接，預設閘道...241。"<<endl<<endl;
					system("pause");				
					break;
				}
				cout<<"正在嘗試變更預設閘道...242"<<endl;
				set("242");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"網路已正常連接，預設閘道...242。"<<endl<<endl;
					system("pause");					
					break;
				}
				cout<<"正在嘗試變更預設閘道...243"<<endl;
				set("243");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"網路已正常連接，預設閘道...243。"<<endl<<endl;	
					system("pause");				
					break;
				}
				cout<<"正在嘗試變更預設閘道...254"<<endl;
				set("254");
				wait(9);
				system("cls");				
				if(ck())
				{
					cout<<"網路已正常連接，預設閘道...254。"<<endl<<endl;	
					system("pause");				
					break;
				}
				cout<<"全部嘗試修復完畢，如有問題請告知宿網工讀生。"<<endl;				
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
		cout<<"第"<<t+1<<"次檢查中...請稍候"<<endl;
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
		pat="乙太網路";
		while(fin>>str)
			if(str=="區域連線:")
			{
				pat="區域連線";
				break;
			}
		cout<<"輸入你的IP: 10.10.";
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
	if(str!="直接存取")
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"Proxy錯誤"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"控制台>>網際網路選項>>連線>>區域網路設定   取消所有的勾選"<<endl; 
		system("pause");
		exit(0); 
		}
	system("cls");
	cout<<"快速修復完畢！"<<endl<<endl;
}
void wait(int t)
{
	cout<<"等待網路生效...";
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
		cout<<"網路已正常連接，如有問題請嘗試快速檢修。"<<endl<<endl;
	else
	{
		cout<<"網路連接異常，請先檢查是否";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"爆流";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"，如非爆流請嘗試"<<next<<"。"<<endl;				
	}
	system("pause");
}
