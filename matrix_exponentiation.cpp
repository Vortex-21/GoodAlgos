#include <bits/stdc++.h>
#define print(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define int long long int
#define ull unsigned long long int
#define begin(x) x.begin()
#define end(x) x.end()
#define all(x) begin(x),end(x)
#define watch(x) cout<<(#x)<<" = "<<(x)<<endl;
#define add_all(x) accumulate(all(x),0)
#define vi vector<int>
#define vp vector<pair<int,int>>
#define pb push_back
#define input(x) for(auto &i:x)cin>>i
using namespace std;
vector<vector<int>>identity(const vector<vector<int>>&mat){
    //returns the corresponding identity matrix of the matrix.
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>>I(col, vector<int>(col,0));
    for(int i=0;i<col;i++){
        I[i][i]=1;
    }
    return I;

}
vector<vector<int>>matmul(const vector<vector<int>>&A, const vector<vector<int>>&B){
    //returns C = AxB
    int rowA = A.size(),colA = A[0].size(),rowB = B.size(),colB = B[0].size();
    vector<vector<int>>C(rowA, vector<int>(colB,0));

    for(int i=0;i<rowA;i++){
        for(int j=0;j<colB;j++){
            int sum=0;
            for(int k=0;k<colA;k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}
vector<vector<int>>matrix_expo(vector<vector<int>>A, int exponent){
    auto res = identity(A);
    while(exponent){
        if(exponent&1){
            res = matmul(res, A);
            exponent-=1;
        }
        else{
            A = matmul(A,A);
            exponent/=2;
        }
    }
    return res;
}
void print_mat(vector<vector<int>>&C){
    for(auto i:C){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
}
void Solve()
{
    vector<vector<int>>A = {{1,1,2}, {2,1,3}, {1,2,1}}, B = {{1},{2},{3}};
    // auto C = matmul(A,B);
    
    auto C = matrix_expo(A, 2);
    print_mat(C);
}
int32_t main()
{
    int tc=1;
    // cin>>tc;
    for(int i=1;i<=tc;i++)
    {
      Solve();
    }
       
    return 0;
}
