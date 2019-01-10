#ifndef MYINT_H
#define MYINT_H

#include <iostream>

class MyInt
{
private:
	int m_num;
public:
	// constructor
	MyInt(int num): m_num(num){}

	// copy constructor
	MyInt(const MyInt &num)
	{
		m_num = num.m_num;
	}

	// copy assignment operator
	MyInt& operator=(const MyInt &num)
	{
		m_num = num.m_num;
		return *this;
	}
	
	// overload the operators we need
	MyInt operator+(const MyInt &r)
	{
		int temp = 0;
		temp = m_num + r.m_num;
		MyInt result(temp);
		return result;
	}

	MyInt operator-(const MyInt &r)
	{
		int temp = 0;
		temp = m_num - r.m_num;
		MyInt result(temp);
		return result;
	}
	
	MyInt operator/(const MyInt &r)
	{
		if (r.m_num == 0)
		{
			// we can not devide by zero
			// you may want to throw an exception here
			return MyInt(0);
		}
		int temp = 0;
		temp = m_num / r.m_num;
		MyInt result(temp);
		return result;
	}

	MyInt operator*(const MyInt &r)
	{
		int temp = 0;
		temp = m_num * r.m_num;
		MyInt result(temp);
		return result;
	}

	friend std::ostream& operator<<(std::ostream &os,const MyInt &num);
};
// overload the global operator << so that we can print
// our object the same way we print an int
std::ostream& operator<<(std::ostream &os,const MyInt &num)
{
	os << num.m_num;
	return os;
}

#endif // MYINT_H
