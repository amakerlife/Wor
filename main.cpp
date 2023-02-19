#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<fstream>
#include"wor.h"
#define ll long long
#define ull unsigned long long
#define INF 0x7fffffff
#define mod 1000000007
#define bug(x) cout<<"Bug "<<(x)<<endl
#define el cout<<endl
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
inline ll lread()
{
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
char changeb(char s)
{
	return (s-'a'+'A');
}
void init()
{
	system("update.exe");
}
const int N=1e3+10;
int n,n_lastwords;
string word[N],cx[N],zw[N];
int jieguo[N];
int cwgs=0;
int t[N];
int main()
{
	system("title Wor v1.3.5   By Makerlife");
	cout<<"正在检查更新......"<<endl;
	init();
	memset(jieguo,1,sizeof(jieguo));
	system("cls");
	cout<<"欢迎使用 Wor\n版本 v1.3.5"<<endl;
	cout<<"本程序由 Makerlife 开发"<<endl;
	int cnt_lastwords;
	ifstream fin("data/last.txt");//读入之前错误的单词
	if(fin.is_open())
	{
		fin>>n_lastwords;
		string strtmp;getline(fin,strtmp);
		cnt_lastwords=3*n_lastwords+2;
		for(int i=2;i<=3*n_lastwords+1;i++)
		{
			if(i%3==2) getline(fin,word[(i+1)/3]);
			if(i%3==0)
			{
				string tmpcx;
				getline(fin,tmpcx);
				if(!((tmpcx[0]>='a' && tmpcx[0]<='z') || (tmpcx[0]>='A' && tmpcx[0]<='Z')))
				{
					cx[i/3]=' ';
					zw[i/3]=tmpcx;
					i++;
					continue;
				}
				else
				{
					cx[i/3]=tmpcx;
				}
			}
			if(i%3==1) getline(fin,zw[(i-1)/3]);
		}
	}
	cout<<"请读入单词（读入格式请见 README.pdf）："<<endl;
	srand((int)time(0));
	n=read();
	int tn=n;
	if(n<4)
	{
		cout<<"错误: 单词数量不能小于 4\n错误码: 1"<<endl;
		cout<<"请按回车退出......"<<endl;
		char ch=getchar();
		return 0;
	}
	for(int i=cnt_lastwords;i<=3*n-1+cnt_lastwords;i++)//输入单词表
	{
		if(i%3==2) getline(cin,word[(i+1)/3]);
		if(i%3==0)
		{
			string tmpcx;
			getline(cin,tmpcx);
			if(!((tmpcx[0]>='a' && tmpcx[0]<='z') || (tmpcx[0]>='A' && tmpcx[0]<='Z')))
			{
				cx[i/3]=' ';
				zw[i/3]=tmpcx;
				i++;
				continue;
			}
			else
			{
				cx[i/3]=tmpcx;
			}
		}
		if(i%3==1) getline(cin,zw[(i-1)/3]);
	}
	n+=n_lastwords;

	// cout<<n_lastwords<<endl;
	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<word[i]<<" "<<cx[i]<<" "<<zw[i]<<endl;
	// }
	// system("pause");

	el;
	cout<<"读入成功"<<endl;
	usleep(500000);
	system("cls");
	cout<<"请输入要背诵的单词数量: ";
	int m;
	m=read();
	if(m>n)
	{
		cout<<"错误: 题目数量不能大于单词数量\n错误码: 2"<<endl;
		cout<<"请按回车退出......"<<endl;
		char ch=getchar();
		return 0;
	}
	system("cls");
	int memsetn=rand()%tn+1;
	for(int i=0;i<=n+1;i++)
	{
		t[i]=memsetn;
	}
	for(int i=0;i<m;)//出题
	{
		cout<<"已答对 "<<i<<"/"<<m<<" 个单词"<<endl;
        cout<<"请选择单词 ";
		while(1)//确保与之前的题目不重复
		{
			int f=0;
			for(int j=0;j<i;j++)
			{
				if(t[i]==t[j])
				{
					f=1;
					break;
				}
			}
			if(f==0) break;
			t[i]=rand()%n+1;
		}
		cout<<word[t[i]];
		int t1,t2,t3,t4;
		int sj=rand()%4+1;
		t1=rand()%n+1;//生成ABCD选项
		t2=rand()%n+1;
		t3=rand()%n+1;
		t4=rand()%n+1;
		if(sj==1)//确保选项不重复
		{
			t1=t[i];
			while(t1==t2 || t1==t3 || t1==t4 || t2==t3 || t2==t4 || t3==t4)
			{
				t2=rand()%n+1;
				t3=rand()%n+1;
				t4=rand()%n+1;
			}
		}
		if(sj==2)
		{
			t2=t[i];
			while(t1==t2 || t1==t3 || t1==t4 || t2==t3 || t2==t4 || t3==t4)
			{
				t1=rand()%n+1;
				t3=rand()%n+1;
				t4=rand()%n+1;
			}
		}
		if(sj==3)
		{
			t3=t[i];
			while(t1==t2 || t1==t3 || t1==t4 || t2==t3 || t2==t4 || t3==t4)
			{
				t1=rand()%n+1;
				t2=rand()%n+1;
				t4=rand()%n+1;
			}
		}
		if(sj==4)
		{
			t4=t[i];
			while(t1==t2 || t1==t3 || t1==t4 || t2==t3 || t2==t4 || t3==t4)
			{
				t2=rand()%n+1;
				t3=rand()%n+1;
				t1=rand()%n+1;
			}
		}
		cout<<" 的释义："<<endl;
		el;
		if(cx[t1]==" ") cout<<"A "<<zw[t1]<<endl;
		else cout<<"A "<<cx[t1]<<" "<<zw[t1]<<endl;
		if(cx[t2]==" ") cout<<"B "<<zw[t2]<<endl;
		else cout<<"B "<<cx[t2]<<" "<<zw[t2]<<endl;
		if(cx[t3]==" ") cout<<"C "<<zw[t3]<<endl;
		else cout<<"C "<<cx[t3]<<" "<<zw[t3]<<endl;
		if(cx[t4]==" ") cout<<"D "<<zw[t4]<<endl;
		else cout<<"D "<<cx[t4]<<" "<<zw[t4]<<endl;
		char input;
		cin>>input;//输入选项
		if('a'<=input && input<='z')
		{
			input=changeb(input);
		}
		if(!('A'<=input && input<='D'))
		{
			cout<<"错误: 输入不合法\n错误码: 3"<<endl;
			jieguo[i]=0;
			system("pause");
			system("cls");
			continue;
		}
		if(input==char(sj+'A'-1))
		{
			cout<<"回答正确！"<<endl;
			i++;
			if(jieguo[i]!=0) jieguo[i]=1;
			system("TIMEOUT /T 1");
		}
		else
		{
			cout<<"回答错误！"<<endl;
			cout<<word[t[i]]<<" "<<cx[t[i]]<<" "<<zw[t[i]]<<endl;
			jieguo[i]=0;
			system("pause");
		}
		system("cls");
	}
	for(int i=0;i<m;i++)
	{
		if(jieguo[i]==0)
		{
			cwgs++;
		}
	}
	if(cwgs!=0)
	{
		cout<<"以下 "<<cwgs<<" 个单词还需要加强记忆：\n\n";
		ofstream fout("data/last.txt");
		if(!fout.is_open())
		{
			cerr<<"failed to open last.txt"<<endl;
		}
		fout<<cwgs<<endl;
		for(int i=0;i<m;i++)
		{
			if(jieguo[i]==0)
			{
				cout<<word[t[i]]<<" "<<cx[t[i]]<<" "<<zw[t[i]]<<endl;
				// file_process(2,word[t[i]],cx[t[i]],zw[t[i]]);
				fout<<word[t[i]]<<endl;
				fout<<cx[t[i]]<<endl;
				fout<<zw[t[i]]<<endl;
			}
		}
		fout.close();
		cout<<"\n\n";
	}
	if(cwgs!=m)
	{
		cout<<"以下 "<<m-cwgs<<" 个单词掌握的不错：\n\n";
		for(int i=0;i<m;i++)
		{
			if(jieguo[i]!=0)
			{
				cout<<word[t[i]]<<" "<<cx[t[i]]<<" "<<zw[t[i]]<<endl;
			}
		}
		cout<<"\n\n";
		if(cwgs==0)
		{
			ofstream fout("data/last.txt");
			if(!fout.is_open())
			{
				cerr<<"failed to open last.txt"<<endl;
			}
			fout<<cwgs<<endl;
		}
	}
	cout<<"请按回车退出......"<<endl;
	char ch=getchar();
	ch=getchar();
	return 0;
}

