#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#define n 8
#include<vector>
using namespace std;
struct Point{
    int x;
    int y;
};
class ConvexHull{
    Point p[n];
    vector<Point>v1;
    public:
        //For Data Input
    void getInputData(){
        ifstream fin("point.txt");
        for(int i=0;i<n;i++){
            fin>>p[i].x>>p[i].y;
        }
    }
    //For Show Input Data
    void showGetInputData(){
        for(int i=0;i<n;i++){
            cout<<p[i].x<<" "<<p[i].y<<endl;
        }
    }
    //It Return Line Distance
    int lineDist(Point p1, Point p2, Point p)
    {
        return abs ((p.y - p1.y) * (p2.x - p1.x) -
                   (p2.y - p1.y) * (p.x - p1.x));
    }

    int findSide(Point p1, Point p2, Point p)
    {
        int val = (p.y - p1.y) * (p2.x - p1.x) -
                  (p2.y - p1.y) * (p.x - p1.x);

        if (val > 0)
            return 1;
        if (val < 0)
            return -1;
        return 0;
    }
    void findHullPoint(Point p1,Point p2,int side){
        int ind = -1;
        int max_dist = 0;
        for (int i=0; i<n; i++)
        {
            int temp = lineDist(p1, p2, p[i]);
            if (findSide(p1, p2, p[i]) == side && temp > max_dist)
            {
                ind = i;
                max_dist = temp;
            }
        }
        if (ind == -1)
        {
            v1.push_back(p1);
            v1.push_back(p2);
            return;
        }
        findHullPoint(p[ind], p1, -findSide(p[ind], p1, p2));
        findHullPoint(p[ind], p2, -findSide(p[ind], p2, p1));
    }
    //here we create convex hull using recursion
    void createHull(){
        if(n<3){
            cout<<"Convex Hull can't be created"<<endl;
            return;
        }
        //Minimum And Maximum Point Found
        int min_x=0,max_x=0;
        for(int i=0;i<n;i++){
            if(p[i].x<p[min_x].x){
                min_x=i;
            }
            if(p[i].x>p[max_x].x){
                max_x=i;
            }
        }
        cout<<"Min x="<<min_x<<"Max x="<<max_x<<endl;
        findHullPoint(p[min_x],p[max_x],1);
        findHullPoint(p[min_x],p[max_x],-1);
    }
    //It Show Our Output
    void showOutput(){
        for(int i=0;i<v1.size()/2;i++){
            cout<<v1[i].x<<" "<<v1[i].y<<endl;
        }
    }
};
int main(){
    ConvexHull c;
    c.getInputData();
    c.showGetInputData();
    c.createHull();
    c.showOutput();
}
