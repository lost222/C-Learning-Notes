#include<iostream>
using namespace std;

long long int Fib[90] = { 1,1 };
long long int F(int n)
{
	if (Fib[n - 1] != 0)
	{ 
		cout << "Fib[" << n <<"]被调用"<< endl;
		return Fib[n - 1];
	}
	Fib[n-1]=F(n - 2) + F(n - 1);
	cout << "Fib[" << n << "]被保存了" << endl;
	return Fib[n - 1];
}

int n;

int main()
{
	cout << "input n" << endl;
	cin >> n;
	if (n < 1 || n>90) { cout << "wrong" << endl; return 0; }
	cout << F(n) << endl;
	return 0;
	
}

