#include<iostream>
#include<stdexcept>
int main()
{
	double a, b;
	std::cout << "cin a,b"<<std::endl;
	while (std::cin >> a >> b) {
		try {
			if (b == 0) { throw std::runtime_error("b != 0"); }
			std::cout << a / b << std::endl;
			std::cout << "cin a,b" << std::endl;
		}
		catch (std::runtime_error err) {
			std::cout << err.what() << "\n try again? Enter y or n" << std::endl;   //无论输不输入y，程序总是在运行的。这也是后面没有处理y的原因
			char c;
			std::cin >> c;
			if (!std::cin || c == 'n') { break; }    //非cin有什么用？
		}
	}
	
}
