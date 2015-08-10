//堆实现优先队列
#include<iostream>
#include<vector>
#include"work.h"

using namespace std;
class Heap  
{  
public:
	void print();
    void push(work a); //插入结点 
    void pop();   //删除根结点
	work top();
	void jian(int b);
private:  
    vector<work> queue;
	int num;
};  
void Heap::print()
{
	for(int i=0;i<queue.size();i++)
	{
		cout<<"任务名："<<queue[i].name<<endl;
		cout<<"  "<<"优先数："<<queue[i].ti<<endl;
		cout<<"   "<<"进入时间："<<queue[i].si<<endl;
	}
}
void Heap::push(work a)//进入堆
{  
	work c;
	num = queue.size();
	if (num == 0)  
    {  
		queue.push_back(a);  
    } 
	else
	{
		queue.push_back(a);  
		int b = num;  
		while (queue[b].ti< queue[(b - 1)/2].ti)//上浮，直到满足最小堆  
		{  
			c = queue[b];
			queue[b]=queue[(b - 1)/2];
			queue[(b - 1)/2] = c;
			b = (b - 1) /2;  
		}  
	}
}
void Heap::jian(int  b)//剩下的优先级改变
{
	for(int i = 0;i<b;i++)
	{
	  queue[i].ti =queue[i].ti-queue[0].time;
	}
}
void Heap::pop()//出堆  
{  
	num = queue.size();
		if(num==0)
	{
		cout<<"已空"<<endl;
	}
	else
	{
		  work temp=queue[0];
		  queue[0]=queue[num-1];
		  queue[num-1]=temp;
          queue.pop_back();
		  num--;
		  if(num>1)
		  {
			  int i=0;
			  int j=2*i+1;
			  work temp2=queue[i];
			  while(j<num)
			  {
				  if((j<num-1)&&queue[j].ti>queue[j+1].ti)
					 {
						j++;
					 }
				if(temp2.ti>queue[j].ti)
					{
						queue[i]=queue[j];
						i=j;
						j=2*j+1;
					}
				else
					break;
				}
			queue[i]=temp2;
			}
	} 
}
work Heap::top()  
{  
	num = queue.size();
	if(num == 0)
	{ cout<<"队列是空的"<<endl;}
	else
	 return queue[0];
}