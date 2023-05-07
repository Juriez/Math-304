#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,itr =200;
    cin>>n;
    double a[n][n],b[n],x[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }

    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int k=0;k<itr;k++){
        for(int i=0;i<n;i++){
            double sum1 = 0,sum2=0;
            for(int j=0;j<i;j++){
                    if(i!=j){
                sum1 = sum1 + a[i][j]*x[j];}
            }
            for(int j=i+1; j<n;j++){
                    if(i!=j){
                sum2 = sum2+a[i][j]*x[j];}
            }
            x[i] =(b[i] -sum1 -sum2)/a[i][i];
            sum1=sum2=0;

        }
    }
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }cout<<endl;
}
