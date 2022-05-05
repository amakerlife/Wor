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
const int N=1e3+10;
int n;
string word[N],cx[N],zw[N];
int jieguo[N];
int cwgs=0;
int t[N];
int main()
{
//	freopen("words.txt","r",stdin);
//	freopen(".out","w",stdout);
//	fstream file;
//	file.open("words.txt");
	memset(jieguo,1,sizeof(jieguo));
	system("title M Words Book 单词本 v1.2.0 - Lab   By Makerlife");
	cout<<"欢迎使用 M Words Book 单词本实验室版本\n版本 v1.2.0 - Lab\n实验室功能可能会不稳定"<<endl;
	cout<<"本程序由 Makerlife 开发"<<endl;
	cout<<"您可以访问下方网址进行更新"<<endl;
	cout<<"https://amakerlife.github.io/MWB"<<endl;
	cout<<"请读入单词（读入格式请见 Read Me.md）："<<endl;
	srand((int)time(0));
//	file>>n;
	n=read();
	int tn=n;
	if(n<4)
	{
		cout<<"错误: 单词数量不能小于4\n如有其他疑惑请询问开发人员"<<endl;
		cout<<"请按回车退出......"<<endl;
		char ch=getchar();
		return 0;
	}
//	fstream file;
//	file.open("words.txt");
	for(int i=2;i<=3*n+1;i++)
	{
		if(i%3==2) getline(cin,word[(i+1)/3]);/*file>>word[(i+1)/3];cin>>word[(i+1)/3];*/
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
//			getline(cin,cx[i/3]);/*file>>word[i/3];cin>>cx[i/3];*/
		}
		if(i%3==1) getline(cin,zw[(i-1)/3]);/*file>>word[(i-1)/3];cin>>zw[(i-1)/3];*/
	}
//	fclose;
	el;
	cout<<"读入成功"<<endl;//输入单词表
	usleep(500000);
	system("cls");
	cout<<"请输入要背诵的单词数量: ";
	int m;
	m=read();
	if(m>n)
	{
		cout<<"错误: 题目数量不能大于单词数量\n如有其他疑惑请询问开发人员"<<endl;
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
//	cout<<t[1]<<endl;
//	t[0]=rand()%n+1;

	cout<<"输入1为选中文词义，输入其他为选择英语单词";
	int tmppp=read();
	system("cls");
	if(tmppp==1)
	{
		for(int i=0;i<m;)//出题
		{
			cout<<"已答对 "<<i<<"/"<<m<<" 个单词"<<endl;
	        cout<<"请选择单词 ";
	//		t[i]=rand()%n+1;
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
	//
	//				bug(t1);
	//				bug(t2);
	//				bug(t3);
	//				bug(t4);
	//				el;
	//
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
	//
	//				bug(t1);
	//				bug(t2);
	//				bug(t3);
	//				bug(t4);
	//				el;

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
	//
	//				bug(t1);
	//				bug(t2);
	//				bug(t3);
	//				bug(t4);
	//				el;

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
	//
	//				bug(t1);
	//				bug(t2);
	//				bug(t3);
	//				bug(t4);
	//				el;

				}
			}
			cout<<" 的释义（请输入大写字母）："<<endl;
			el;
			if(cx[t1]==" ") cout<<"A "<<zw[t1]<<endl;
			else cout<<"A "<<cx[t1]<<" "<<zw[t1]<<endl;
			if(cx[t2]==" ") cout<<"B "<<zw[t2]<<endl;
			else cout<<"B "<<cx[t2]<<" "<<zw[t2]<<endl;
			if(cx[t3]==" ") cout<<"C "<<zw[t3]<<endl;
			else cout<<"C "<<cx[t3]<<" "<<zw[t3]<<endl;
			if(cx[t4]==" ") cout<<"D "<<zw[t4]<<endl;
			else cout<<"D "<<cx[t4]<<" "<<zw[t4]<<endl;
	//		cout<<"C "<<cx[t3]<<" "<<zw[t3]<<endl;
	//		cout<<"D "<<cx[t4]<<" "<<zw[t4]<<endl;

	//		cout<<char(sj+'A'-1)<<endl;

			char input;
			cin>>input;//输入选项
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
			for(int i=0;i<m;i++)
			{
				if(jieguo[i]==0)
				{
					cout<<word[t[i]]<<" "<<cx[t[i]]<<" "<<zw[t[i]]<<endl;
				}
			}
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
		}
		cout<<"请按回车退出......"<<endl;
		char ch=getchar();
		ch=getchar();
		return 0;
	}
	else
	{
		for(int i=0;i<m;)//出题
		{
			cout<<"已答对 "<<i<<"/"<<m<<" 个单词"<<endl;
	        cout<<"请选择中文为 ";
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
			cout<<zw[t[i]];
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
	//
	//				bug(t1);
	//				bug(t2);
	//				bug(t3);
	//				bug(t4);
	//				el;
	//
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
			cout<<" 的单词（请输入大写字母）："<<endl;
			el;
			if(cx[t1]==" ") cout<<"A "<<word[t1]<<endl;
			else cout<<"A "<<cx[t1]<<" "<<word[t1]<<endl;
			if(cx[t2]==" ") cout<<"B "<<word[t2]<<endl;
			else cout<<"B "<<cx[t2]<<" "<<word[t2]<<endl;
			if(cx[t3]==" ") cout<<"C "<<word[t3]<<endl;
			else cout<<"C "<<cx[t3]<<" "<<word[t3]<<endl;
			if(cx[t4]==" ") cout<<"D "<<word[t4]<<endl;
			else cout<<"D "<<cx[t4]<<" "<<word[t4]<<endl;
	//		cout<<"C "<<cx[t3]<<" "<<zw[t3]<<endl;
	//		cout<<"D "<<cx[t4]<<" "<<zw[t4]<<endl;

	//		cout<<char(sj+'A'-1)<<endl;

			char input;
			cin>>input;//输入选项
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
			for(int i=0;i<m;i++)
			{
				if(jieguo[i]==0)
				{
					cout<<word[t[i]]<<" "<<cx[t[i]]<<" "<<zw[t[i]]<<endl;
				}
			}
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
		}
		cout<<"请按回车退出......"<<endl;
		char ch=getchar();
		ch=getchar();
		return 0;
	}
}

