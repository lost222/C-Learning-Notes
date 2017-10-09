#include<iostream>
using namespace std;
class  ComplexNum
{
	double a, b;
public:
	ComplexNum(double a, double b) { this->a = a; this->b = b; }
	ComplexNum(ComplexNum &s) { a = s.a; b = s.b; }
	double realPart()const { return a; }
	double virtPart()const { return b; }
	ComplexNum& operator+(const ComplexNum &s) {                            //实现在类内部的重载，缺点是只能由类发起。就本题来说就是不能写1+s；
		this->a += s.a;
		this->b +=s.b;
		return    *this;
	}
	friend int get();
	friend ComplexNum& add(ComplexNum a, double b);
	friend ComplexNum operator+(const ComplexNum&ss, double b);   //函数的返回值不能是引用？
	void printCom() { cout << a << "+" << b << "i" << endl; }
};

ComplexNum operator+(const ComplexNum&ss, double b){       //实现在类外的重载，第一个参数还是只能是类的引用。？？
	ComplexNum c(ss.a + b, ss.b);
	return c;
}
int main()
{
	ComplexNum  a(1, 2),b(3,4),c(1,1);
	c.printCom();
	(a + b).printCom();
	(c + 1).printCom();
	return 0;
}
