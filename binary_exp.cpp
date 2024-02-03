#include<bits/stdc++.h>
using namespace std;
long long power(int n){
            
            if(n==0){
                return 1;
            }
            
            long long ans = power(n/2);
            if(n%2){
                return ans*ans*2;
            }
            else return ans*ans;
        }
int main(){
  cout<<power(100)<<endl;
  return 0;
}