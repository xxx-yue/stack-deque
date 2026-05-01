#pragma once
#include<vector>
template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
namespace bit
{
	template<class T, class Container = std::vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child>0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;//这里要找孩子新的父母,所以要用(child-1)/2来找到他的父母
				}
				else break;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}
		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			Compare com;
			while (child<_con.size())//如果孩子>=size(),说明孩子已经不存在了不用继续向下调整了
			{
				if (child+1 < _con.size() && com(_con[child], _con[child + 1]))
					child++;
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
		return x < y;
};
template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
		return x > y;
};
template<class Compare>
void BubbleSort(int* a, int n, Compare com)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 1;
		for (int i = 1; i < n - j; i++)
		{
			if (com(a[i], a[i - 1]))
			{
				swap(a[i], a[i - 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
int main()
{
	Less<int> LessFunc;
	Greater<int>GreaterFunc;
	cout << LessFunc(1, 2) << endl;
}