/* 模板类的继承中，子类不能直接调用父类的成员（对象与函数）， 解决的方法是调用的时候 使用this-> 或者 Base<T>:: 来指定，这样指定确实都会指定到父类的成员
*/

#include <iostream>

template <typename T>
class Distance{
public:
    T p1x,p1y,p2x,p2y;
    virtual T dis() = 0;
    Distance(T x1, T y1, T x2, T y2) : p1x(x1),p1y(y1),p2x(x2), p2y(y2){};
    T abs(T x){ return x>0? x: -x;}
};


class Manhattan_Distance:public Distance<int>{
public:
    Manhattan_Distance(int x1, int y1, int x2, int y2): Distance<int>::Distance(x1, y1, x2, y2){};
    int dis(){ return this->abs(this->p1x - this->p2x)+ this->abs(this->p1y - this->p2y);}
};

template <typename T>
class Euclidean_Distance:public Distance<T>{
public:
    Euclidean_Distance(T x1, T y1, T x2, T y2): Distance<T>::Distance(x1, y1, x2, y2){};
    T dis(){return (this->p1x - this->p2x)*(this-> p1x - this->p2x) + (this->p1y - this->p2y)*(this->p1y - this->p2y);}
};



int main(){
    int x1 = 701, y1 = 12736, x2 =  1856, y2 =  7128;
    std::cin>>x1>>y1>>x2>>y2;
    Manhattan_Distance md(x1, y1, x2, y2);
    Euclidean_Distance<int> ed(x1, y1, x2, y2);
    std::cout<<md.dis()<<" "<<(double)ed.dis();
}
