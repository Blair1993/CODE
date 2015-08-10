#include<iostream>
#include<vector>
#include<windows.h>
#include"minheap.h"
using namespace std;
class zhixing
{	
public:
	void input();//普通输入
};
void input() 
{ 
	int jishu;
	int n;
	cout<<"请输入要执行作业的数量："<<endl;
	cin>>n;   
	vector<work> ss(100);
	Heap qq;
	for(int i=0;i<n;i++)
	{   
		int runtime;//运行的时间
		ss[i].name = i+65;
		cout<<"请输入第"<<i+1<<"个作业长度："<<endl; 
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
		cout<<"………………………………………………………………………………现堆的打印："<<endl;
		for(int j = 0;j<n;j++)
		{
			
			cout<<"任务："<<qq1.top().name;
			cout<<"   "<<"该作业进入的时间："<<qq1.top().si;
			cout<<"   "<<"该作业的长度："<<qq1.top().time;
			cout<<"   "<<"优先级："<<qq1.top().ti<<endl;
			qq1.pop();
		}
	Heap yy = qq;
	Heap yy1 = yy;
	Heap tt = qq;
	Heap tt1 = tt;
	int waittime = 0;
	for(int k = 0;k<n;k++)
	{
		cout<<"任务："<<qq.top().name<<"进入"<<endl;
		cout<<"   "<<"优先级："<<qq.top().ti<<endl;
		cout<<"   "<<"执行中……"<<endl;
		Sleep(1000);
        qq.jian(n-k);
		waittime = waittime+qq.top().ti;
		qq.pop();
    }//普通测试
	cout<<"………………………………………………………………………………插入测试"<<endl;
	waittime = 0;
	//for(int j = 0;j<n;j++)
	//{
			//cout<<"任务："<<yy1.top().name<<endl;
			//cout<<"   "<<"该作业进入的时间："<<yy1.top().si<<endl;
			//cout<<"   "<<"优先级："<<yy1.top().ti<<endl;
			//yy1.pop();
	//}
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		yy1 = yy;
		cout<<"………………………………………………………………………………现堆的打印："<<endl;
		for(int j = 0;j<n+2*i;j++)
		{
			
			cout<<"任务："<<yy1.top().name;
			cout<<"   "<<"该作业的长度："<<yy1.top().time;
			cout<<"   "<<"优先级："<<yy1.top().ti<<endl;
			yy1.pop();
		}
		cout<<"………………………………………………………………………………继续执行："<<endl;
		cout<<"任务："<<yy.top().name<<"进入"<<endl;
		cout<<"   "<<"优先级："<<yy.top().ti<<endl;
		cout<<"   "<<"作业长度："<<yy.top().time<<endl;
		cout<<"   "<<"执行中……"<<endl;
		Sleep(1000);
		yy.jian(n+2*i);
		yy.pop();
		cout<<"………………………………………………………………………………现堆的打印："<<endl;
		yy1 = yy;
		for(int j = 0;j<n+2*i-1;j++)
		{
			
			cout<<"任务："<<yy1.top().name;
			cout<<"   "<<"该作业的长度："<<yy1.top().time;
			cout<<"   "<<"优先级："<<yy1.top().ti<<endl;
			yy1.pop();
		}
		//cout<<"任务："<<yy.top().name<<"进入"<<endl;
		//cout<<"   "<<"优先级："<<yy.top().ti<<endl;
		//cout<<"   "<<"执行中……"<<endl;
		//Sleep(1000);
		//yy.jian(i,n);
		//yy.pop();
		cout<<"请输入插入3个的优先级:"<<endl;
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
	cout<<"………………………………………………………………………………更改优先级测试："<<endl;
	cout<<"序号"<<"  " <<"名字"<<"  "<<"优先级"<<endl;
	for(int i =0 ;i<n;i++)
	{
		cout<<i+1<<"     "<<ss[i].name<< "     "<<ss[i].ti<<endl;
	}
	cout<<"请输入要更改的作业序数："<<endl;
	int nn;
	cin>>nn;
	if(nn>n)
	{
		cout<<"超出范围"<<endl;
		cout<<"请输入小于"<<n<<"的数"<<endl;
		int r;
		cin>>r;
		nn = r;
	}
	cout<<"请输入更改后的优先级："<<endl;
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
		cout<<"任务："<<hh.top().name<<endl;
		cout<<"   "<<"该作业已等待的时间："<<waittime<<endl;
		cout<<"   "<<"优先级："<<hh.top().ti<<endl;
		cout<<"   "<<"执行中……"<<endl;
		Sleep(1000);
        hh.jian(n-k);
		waittime = waittime+hh.top().ti;
		hh.pop();
    }
	system("pause");
}
