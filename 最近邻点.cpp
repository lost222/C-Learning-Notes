/*  平面最近邻点算法 
          核心是一个对于[a,b] 区间内所有点一一比较，获取最小距离的line_min函数
          一个对于[a,b]区间内递归获取最小距离的group函数，
          递归拆成三段， 一段左一段右， 可以严格证明对于中间区间比较不需要超过8个点 
          所以第三段只需比较8个点。
          */
          
          
#include<iostream>
#include<cmath>
#include<vector>
//#include<iomanip>
#include<algorithm>
#include<stdio.h>
using namespace std;
class point{                   //数据结构 重载方便排序
public:
    double t_x, t_y;
    point(double x, double y):t_x(x),t_y(y){}
    bool operator<(const point &);
};

bool point::operator<(const point &b){
    return this->t_x < b.t_x;
}

double tri_min(double x1, double x2, double x3){
    double miner = x1 < x2 ? x1 : x2;
    return  miner < x3 ? miner : x3;
}

double distanse(point t1, point t2){
    return    sqrt(pow(t1.t_x - t2.t_x,2) + pow(t1.t_y - t2.t_y, 2) );
}

double line_min(int a, int b, const vector<point>& lines){ //扫描获得[a,b]内最小距离 O(n^2)
    vector<point>::const_iterator start = lines.begin() + a;
    vector<point>::const_iterator ssend = lines.begin() + b;
    double min = distanse(*start, *(ssend-1) );
    for(auto i = start; i!= ssend; i++){
        for (auto j = i+1; j!=ssend; j++){
            if(distanse(*i, *j) < min){
                min = distanse(*i, *j);
            }
        }
    }
    return min;
}

double group_min(int a, int b, const vector<point> & lines){  //递归，  O( nlog(n) )
    vector<point>::const_iterator start = lines.begin() + a;
    vector<point>::const_iterator ssend = lines.begin() + b;
    int mid = (a+b) / 2;
    int mid_l = mid > 4 ? mid - 4 : 0;
    int mid_r = mid + 4 < b ? mid + 4 : b;
    if(b - a < 4){
        //递归基，这个4是瞎写的。会有冗余计算
        //return tri_min( line_min(a,mid, lines) , line_min(mid, b, lines), line_min(mid_l, mid_r, lines)) ;
        return line_min(a,b,lines);
    }
    //递归  
    return tri_min( group_min(a,mid, lines) , group_min(mid, b, lines), line_min(mid_l, mid_r, lines)) ;
}

int main(){
    int times;
    while(cin>>times){
            if(times == 0){break;}
            vector<point> lines;
        for(int i=0; i<times; i++){
                double x, y;
                //cin>>x>>y;
                scanf("%lf%lf",&x,&y);
                point *p = new point(x,y);
                lines.push_back(*p);
        }
        sort(lines.begin(), lines.end());     // 基础 排序
        int s = lines.end() - lines.begin();
        double mind = group_min(0,s,lines);
        printf( "%.2f\n",mind/2);
        //cout<<setiosflags(ios::fixed)<<setprecision(2)<<mind/2<<endl;
    }
    return 0;
}
