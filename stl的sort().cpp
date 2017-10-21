#include<iostream>
#include<algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
class Young
{
public:
    bool operator<(const Young&);
    void output();
    Young(){};
    void set_(int x,const T& a);
private:
    T el;
    int rank_;
};

template<typename T>
void Young<T>::set_(int x,const T& a)
{
    el = a;
    rank_= x;
}

template<typename T>
bool Young<T>::operator<(const Young&b)
{
    return this->rank_<b.rank_;
}

template<typename T>
void Young<T>::output()
{
    cout<<"rank is"<<rank_<<"  "<<"el is"<<el<<endl;
}

int main()
{
    Young<int> *p = new Young<int>[12];
    for(int i=0;i<12;i++)
    {
        (p+i)->set_(15-i,6);
    }
    sort(p,p+12);
    for(int i=0;i<12;i++)
    {
        (p+i)->output();
    }
}
