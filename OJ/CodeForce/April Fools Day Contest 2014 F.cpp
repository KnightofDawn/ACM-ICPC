#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{

    int A;
    int B[]={0,1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 
             1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 
             2, 2, 5, 4, 1, 4, 1, 51, 1, 2, 1, 14, 
             1, 2, 2, 14, 1, 6, 1, 4, 2, 2, 1, 52, 
             2, 5, 1, 5, 1, 15, 2, 13, 2, 2, 1, 13, 
             1, 2, 4, 267, 1, 4, 1, 5, 1, 4, 1, 50, 
             1, 2, 3, 4, 1, 6, 1, 52, 15, 2, 1, 15, 
             1, 2, 1, 12, 1, 10, 1, 4, 2 };
    cin>>A;

     cout<<B[A]<<endl;

    //cout<<res<<endl;

    return 0;

}
