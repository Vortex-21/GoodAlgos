#include<bits/stdc++.h>
using namespace std;

double power(double mid,int n){
    if(n == 1)return mid;
    // cout<<"exe"<<endl;
    double a = power(mid,n/2);
    double ans = a*a;
    if(n%2)ans*=a;
    return ans;
}


double n_root(int n,int m){
    //calculating for precision of 5 decimal places  
    double st = 1, en = m;
    double range = 1e-6;
    while((en-st) > range){
        cout<<"st = "<<st<<" en = "<<en<<endl;
        double mid = (en+st)/2.0;
        if(power(mid,n) < m)st = mid;
        else en=mid;
    }   
    cout<<st<<" "<<en<<endl;
    return st;
}
int main()
{   
    cout<<"Exe"<<endl;
    double ans = n_root(3,28);
    // auto ans = power(2,2);
    cout<<"ans = "<<ans<<endl;
    return 0;
}