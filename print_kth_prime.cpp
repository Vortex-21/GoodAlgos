#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;
const int N = 1e8;
vector<bool> is_prime(N, 1);
vector<int> primes;
int main()
{
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(is_prime[i])primes.push_back(i);
    }
    // cout<<primes.size()<<endl;

    // for(auto i:primes)cout<<i<<" ";
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        cout<<primes[q-1]<<endl;
    }
    return 0;
}