#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>rank,parent,size;
    DSU(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;    
        }
    }
    int findPar(int node)
    {
        if(node == parent[node])return node;

        return parent[node] = findPar(parent[node]);
    }
    void UnionByRank(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);   
        if(ulp_u == ulp_v)return;

        int Ru=rank[ulp_u];
        int Rv=rank[ulp_v];

        if(Ru < Rv)
        {
            parent[ulp_u]=ulp_v;
        }
        else if(Rv < Ru)
        {
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]+=1;
        }
    }
    void UnionBySize(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);   
        if(ulp_u == ulp_v)return;

        int Su=size[ulp_u];
        int Sv=size[ulp_v];

        if(Su < Sv)
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else if(Sv < Su)
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            
        }
    }
};



int main()
{
    
    DSU ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);
    //check if 1 and 5 belong to the same component or not
    if(ds.findPar(1) == ds.findPar(3))cout<<"Same component"<<endl;
    else cout<<"NOt same component";
    ds.UnionBySize(3,7);
    if(ds.findPar(1) == ds.findPar(6))cout<<"Same component"<<endl;
    // ds.UnionByRank(1,2);

    return 0;

}