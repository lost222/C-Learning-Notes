//形参是const 实参不是，----完全可行，
//形参不是const 实参是， ----万一函数写的时候改变了呢？ 会报错

#include <iostream>

void testconst(int *p){
    std::cout<<*p<<std::endl;
    int a = 10;
    p = &a;
    std::cout<<*p<<std::endl;
}


int main() {
    int a = 5;
    int b = 15;
    const int *  p = &a;
    testconst(p);
    return 0;
}
