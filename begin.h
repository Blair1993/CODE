#include<iostream>
#include<vector>
#include<windows.h>
#include"minheap.h"
using namespace std;
class zhixing
{	
public:
	void input();//��ͨ����
};
void input() 
{ 
	int jishu;
	int n;
	cout<<"������Ҫִ����ҵ��������"<<endl;
	cin>>n;   
	vector<work> ss(100);
	Heap qq;
	for(int i=0;i<n;i++)
	{   
		int runtime;//���е�ʱ��
		ss[i].name = i+65;
		cout<<"�������"<<i+1<<"����ҵ���ȣ�"<<endl; 
		cin>>runtime;
		ss[i].time = runtime;
		ss[i].ti = runtime;
		ss[i].si = 0;
	} 
	for(int j = 0;j<n;j++)
	{
			qq.push(ss[j]);
	}
	Heap qq1 = qq;
		cout<<"�������������������������������������������������������������ֶѵĴ�ӡ��"<<endl;
		for(int j = 0;j<n;j++)
		{
			
			cout<<"����"<<qq1.top().name;
			cout<<"   "<<"����ҵ�����ʱ�䣺"<<qq1.top().si;
			cout<<"   "<<"����ҵ�ĳ��ȣ�"<<qq1.top().time;
			cout<<"   "<<"���ȼ���"<<qq1.top().ti<<endl;
			qq1.pop();
		}
	Heap yy = qq;
	Heap yy1 = yy;
	Heap tt = qq;
	Heap tt1 = tt;
	int waittime = 0;
	for(int k = 0;k<n;k++)
	{
		cout<<"����"<<qq.top().name<<"����"<<endl;
		cout<<"   "<<"���ȼ���"<<qq.top().ti<<endl;
		cout<<"   "<<"ִ���С���"<<endl;
		Sleep(1000);
        qq.jian(n-k);
		waittime = waittime+qq.top().ti;
		qq.pop();
    }//��ͨ����
	cout<<"�������������������������������������������������������������������"<<endl;
	waittime = 0;
	//for(int j = 0;j<n;j++)
	//{
			//cout<<"����"<<yy1.top().name<<endl;
			//cout<<"   "<<"����ҵ�����ʱ�䣺"<<yy1.top().si<<endl;
			//cout<<"   "<<"���ȼ���"<<yy1.top().ti<<endl;
			//yy1.pop();
	//}
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		yy1 = yy;
		cout<<"�������������������������������������������������������������ֶѵĴ�ӡ��"<<endl;
		for(int j = 0;j<n+2*i;j++)
		{
			
			cout<<"����"<<yy1.top().name;
			cout<<"   "<<"����ҵ�ĳ��ȣ�"<<yy1.top().time;
			cout<<"   "<<"���ȼ���"<<yy1.top().ti<<endl;
			yy1.pop();
		}
		cout<<"����������������������������������������������������������������ִ�У�"<<endl;
		cout<<"����"<<yy.top().name<<"����"<<endl;
		cout<<"   "<<"���ȼ���"<<yy.top().ti<<endl;
		cout<<"   "<<"��ҵ���ȣ�"<<yy.top().time<<endl;
		cout<<"   "<<"ִ���С���"<<endl;
		Sleep(1000);
		yy.jian(n+2*i);
		yy.pop();
		cout<<"�������������������������������������������������������������ֶѵĴ�ӡ��"<<endl;
		yy1 = yy;
		for(int j = 0;j<n+2*i-1;j++)
		{
			
			cout<<"����"<<yy1.top().name;
			cout<<"   "<<"����ҵ�ĳ��ȣ�"<<yy1.top().time;
			cout<<"   "<<"���ȼ���"<<yy1.top().ti<<endl;
			yy1.pop();
		}
		//cout<<"����"<<yy.top().name<<"����"<<endl;
		//cout<<"   "<<"���ȼ���"<<yy.top().ti<<endl;
		//cout<<"   "<<"ִ���С���"<<endl;
		//Sleep(1000);
		//yy.jian(i,n);
		//yy.pop();
		cout<<"���������3�������ȼ�:"<<endl;
		for(int j = 0;j<3;j++)
		{
			work l;
			cin>>l.ti;
			l.si = waittime+yy.top().si;
			l.time = l.ti;
			l.name= 3*i+n+1+65+j;
			yy.push(l);
		}
		//cin>>l.ti>>l1.ti>>l2.ti;
		//l.time = l.ti;
		//l.si = waittime +yy.top().si;
		//l1.time = l.ti;
		//l1.si = waittime +yy.top().si;
		//l2.time = l.ti;
		//l2.si = waittime +yy.top().si;
		//yy.push(l);
		//yy.push(l1);
		//yy.push(l2);
		//yy1 = yy;

	}
	cout<<"�������������������������������������������������������������������ȼ����ԣ�"<<endl;
	cout<<"���"<<"  " <<"����"<<"  "<<"���ȼ�"<<endl;
	for(int i =0 ;i<n;i++)
	{
		cout<<i+1<<"     "<<ss[i].name<< "     "<<ss[i].ti<<endl;
	}
	cout<<"������Ҫ���ĵ���ҵ������"<<endl;
	int nn;
	cin>>nn;
	if(nn>n)
	{
		cout<<"������Χ"<<endl;
		cout<<"������С��"<<n<<"����"<<endl;
		int r;
		cin>>r;
		nn = r;
	}
	cout<<"��������ĺ�����ȼ���"<<endl;
	int mm;
	cin>>mm;
	ss[nn-1].ti = mm;
	ss[nn-1].time  = mm;
	Heap hh;
	for(int j = 0;j<n;j++)
	{
			hh.push(ss[j]);
	}
	waittime = 0;
	for(int k = 0;k<n;k++)
	{
		cout<<"����"<<hh.top().name<<endl;
		cout<<"   "<<"����ҵ�ѵȴ���ʱ�䣺"<<waittime<<endl;
		cout<<"   "<<"���ȼ���"<<hh.top().ti<<endl;
		cout<<"   "<<"ִ���С���"<<endl;
		Sleep(1000);
        hh.jian(n-k);
		waittime = waittime+hh.top().ti;
		hh.pop();
    }
	system("pause");
}
