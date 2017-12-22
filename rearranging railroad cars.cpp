#include<conio.h>
#include <iostream>
#include <stack>
 
using namespace std;
 
template <class T>
void PrintfNum(T a[], const int & n);
 
// move cars from holding track to output track
void OutPut(stack<int> t[],int n, int totalStack,int& min){
             //move car from holding track
             for(int x = 0;x < totalStack; ++x){
                 if(!t[x].empty() && t[x].top() == min){
                     cout << "Move car " << t[x].top() << " from holding track " << x << " to output" << endl;
                     t[x].pop();
                     ++min;
                     x = -1; // find next car from the first holding track 0
                 }
             }
}
 
// move cars from input track to holding track
bool Hold(stack<int> t[],int n , int totalStack){
    for(int i = 0;i < totalStack; ++i){
                if(t[i].empty() || (!t[i].empty() && t[i].top() > n)){
                    cout << "holding track " << i << " hold car " << n  << endl;
                    t[i].push(n);
                    return true; // we already find a holding track, so break the loop. 
                }
    }
    return false;
}
 
int main(int argc, char* argv[])
{
    const int NUM = 9;
    const int STACKNUM = 3;
    stack<int> t[STACKNUM];
    int min = 1;
    int a[NUM] = {5,8,1,7,4,2,9,6,3};
    PrintfNum(a,NUM);
    for(int i = NUM - 1; i >= 0; --i)
    {
        if(a[i] == min)
        {// try to move cars from input track or holding track
            cout << "Move car " << a[i] << " from input to output" << endl;
             ++min;
            OutPut(t,a[i],STACKNUM,min);             
        }
        else
        {// move cars from input track to holding track
 
            if(!Hold(t,a[i],STACKNUM))
            {
                cout << "Not enough holding track" << endl;
                break;
            }       
       }
    }
    system("pause");
    return 0;
}

template <class T>
void PrintfNum(T a[], const int & n){
    for(int i = 0; i < n; ++i){
        cout << a[i] << ",";
    }
    cout << endl;
}
