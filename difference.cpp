#include<bits/stdc++.h>
using namespace std;
int main()
{
    float x[10],fx1[10];
    float fx[10];
    for(int i=0;i<11;i++)
    {
        cin>>x[i];
        cin>>fx[i];
    }
    fx1[0]=(fx[1]-fx[0])/(x[1]-x[0])b;
    fx1[10]=(fx[10]-fx[10-1])/(x[10]-x[10-1]);
    for(int i=1;i<10;i++)
    {
        fx1[i]=(fx[i+1]-fx[i-1])/(x[i+1]-x[i-1]);
    }
    for(int i=0;i<11;i++)
    {
        //cin>>x[i];
        //cin>>fx[i];
        cout<<fx1[i]<<"   ";

    }

}
