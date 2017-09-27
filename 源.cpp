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
			std::cout << err.what() << "\n try again? Enter y or n" << std::endl;   //�����䲻����y���������������еġ���Ҳ�Ǻ���û�д���y��ԭ��
			char c;
			std::cin >> c;
			if (!std::cin || c == 'n') { break; }    //��cin��ʲô�ã�
		}
	}
	
}