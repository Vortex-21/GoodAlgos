#include<bits/stdc++.h>
using namespace std;
int LCSof3 (string s1, string s2, string s3)
    {
            int n1 = s1.size();
            int n2 = s2.size();
            int n3 = s3.size();
            // your code here
            int dp[n1+1][n2+1][n3+1];
            memset(dp,0,sizeof(dp));
            for(int i=n1-1;i>=0;i--){
                for(int j=n2-1;j>=0;j--){
                    for(int k=n3-1;k>=0;k--){
                        if(s1[i]==s2[j] and s2[j]==s3[k]){
                            dp[i][j][k] = 1 + dp[i+1][j+1][k+1];
                        }
                        else{
                            dp[i][j][k] = max(dp[i+1][j][k],max(dp[i][j+1][k],dp[i][j][k+1]));
                        }
                    }
                }
            }
            return dp[0][0][0];
    }

int main(){
    cout<<LCSof3("anshu","minakshi","sh")<<endl;
    return 0;
}