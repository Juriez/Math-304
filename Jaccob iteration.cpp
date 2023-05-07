#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,itr=7;
    cin>>n;
    double a[n][n],b[n];
    double x[n] = {0},X[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int k=0;k<100;k++){
    for(int i=0;i<n;i++){
            double sum = 0;
        for(int j=0;j<n;j++){

            if(i!=j){
                sum = sum + a[i][j]*x[j];
            }
        }
        x[i] = (b[i]-sum)/a[i][i];
        sum = 0;
            }

    }
    cout<<"So, the value of the variables of linear equations are :"<<endl;
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }cout<<endl;

}
