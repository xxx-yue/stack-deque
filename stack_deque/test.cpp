#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#include"stack.h"
#include"Queue.h"
#include"PriorityQueue.h"
void test_op1()
{
	srand(time(0));
	const int N = 100000;
	deque<int> dq;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		auto e = rand() + 1;
		v.push_back(e);
		dq.push_back(e);
	}
	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock( );

	int begin2 = clock();
	sort(dq.begin(), dq.end());
	int end2 = clock();
	cout << "v:" << end1 - begin1 << endl;
	cout << "dq:" << end2 - begin2 << endl;
}
void test_op2()
{
	srand(time(0));
	const int N = 100000;
	deque<int> dq1;
	deque<int> dq2;
	for (int i = 0; i < N; i++)
	{
		auto e = rand() + i;
		dq1.push_back(e);
		dq2.push_back(e);
	}
	int begin1 = clock();
	sort(dq1.begin(), dq1.end());
	int end1 = clock();
	int begin2 = clock();
	vector<int>dqq2(dq2.begin(),dq2.end());
	sort(dqq2.begin(), dqq2.end());
	int end2 = clock();
	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
}
//int main()
//{
//	//test_op1();
//	test_op2();
//	return 0;
////}
//int main()
//{
//	int begin1 = clock();
//	priority_queue<int,deque<int>>q1;
//	q1.push(4);
//	q1.push(9);
//	q1.push(7);
//	q1.push(3);
//	while (!q1.empty())
//	{
//		q1.pop();
//	}
//	int end1 = clock();
//	cout << end1 - begin1 << endl;
//	int begin2 = clock();
//	priority_queue<int>q2;
//	q2.push(4);
//	q2.push(9);
//	q2.push(7);
//	q2.push(3);
//	while (!q2.empty())
//	{
//		q2.pop();
//	}
//	int end2 = clock();
//	cout << end2 - begin2 << endl;
//	cout << endl;
//	return 0;
//}