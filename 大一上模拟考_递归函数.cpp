#include<iostream>

//题目描述：
//用递归函数实现求多项式A(x) = anxn+ an-1xn-1+...+ a1x + a0在x处的值。
//输入：
//一个整数m，接下来输入m个整数，分别代表a0、a1、... 、an的值，再输入一个整数x。
//输出：
//计算多项式在x处的值。
//样例输入：
//3
//1 2 3
//2
//样例输出：
//17
//提示：上述样例输入， 即a0=1， a1=2， a2=3，需要计算当x=2时，a2x2+a1x+a0的值。
//多项式规则是A(x)=(...((anx+ an-1)x+...+ a1)x+ a0)，按照该规则设计递归函数。


int f(int x, int n, int* arr){
	//if (n == 2) {
	//	return (arr[0]*x + arr[1])*x + arr[2];
	//}

	if (n == 1) {
		return arr[0]* x + arr[1];
	}

	if(n == 0){
		return arr[0];
	}

	return f(x, n - 1, arr) * x + arr[n];
	
}








int main(){
	int x; 
	int n;
	std::cin>>n;
	int *p = new int[n];
	for(int i=n - 1;i >=0; i--){
		std::cin>>p[i];
	}
	std::cin>>x;
	int result = f(x,n - 1,p);
	std::cout<<result<<std::endl;
}
