#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) :m_nData(nParam) { }

	CMyData operator+(const CMyData &rhs)
	{
		return CMyData(m_nData + rhs.m_nData);
	}

	CMyData& operator=(const CMyData &rhs)
	{
		m_nData = rhs.m_nData;

		return *this;
	}

	operator int() { return m_nData; }

protected:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx(int nParam) : CMyData(nParam) { }

	CMyDataEx operator+(const CMyDataEx &rhs)
	{
	return CMyDataEx(static_cast<int>(CMyData::operator+(rhs)));
	}


	/*
	//인터페이스를 맞춰주기 위한 연산자 다중 정의
	using CMyData::operator+;
	using CMyData::operator=;
	*/

};

int main()
{
	CMyData a(3), b(4);
	cout << a + b << endl;

	CMyDataEx c(3), d(4), e(0);

	// CMyDataEx 클래스에 맞는 단순 대입 연산자가 없어서 컴파일 오류가 발생한다.
	e = c + d;
	cout << e << endl;

	return 0;
}