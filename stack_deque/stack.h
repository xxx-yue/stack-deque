#pragma once
#include<deque>
namespace bit
{
	template<class T,class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& top()
		{
			return _con.back();
		}
		size_t size()const
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
//Queue 是队列,先进先出
//Stack 是栈,后进先出