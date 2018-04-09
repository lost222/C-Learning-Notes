//g++不做越界检查，但是不知道为什么cin一个比声明更长的字符串的时候也不会有烫烫烫bug
//表现是每次都能正常的cout cin的内容
//包括用指针指向一个单独int，之后指针+1都是可行的

#include <iostream>
using namespace std;

int arr[5] = {0,1,2,3};
int a = 10;


int main() {
    int *p = arr;
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    int *p1 = &a;
    cout<<endl;
    for(int i=0;i<6;i++){
        cout<<*(p1+i)<<" ";
    }

    char chr[4];
    cin>>chr;
    cout<<chr<<endl;
    return 0;
}
