#include<bits/stdc++.h>
using namespace std;

vector<int>makeprefixarray(string s){
    int n = s.size();
    int prevLPS=0;
    vector<int>prefix(n,0);
    int curr=1;
    while(curr<n){
        if(s[curr] == s[prevLPS]){
            prefix[curr] = prevLPS+1;
            prevLPS+=1; 
            curr+=1;

        }
        else{
            if(prevLPS == 0){
                prefix[curr]=0;
                curr+=1;
            }
            else{
                prevLPS = prefix[prevLPS-1];     
            }
        }
    }
    return prefix;
}

int main(){
    string t="aabaaabaaac";
    string p="aabaaac";
    vector<int>prefix=makeprefixarray(p);
   
    int i(0),j(0);
    int pos=-1;
    while(i<t.size()){
        if(t[i] == p[j]){
            i+=1;
            j+=1;
        }
        else{
            if(j==0){
                i+=1;
            }
            else{
                j=prefix[j-1];
            }
        }

        if(j == p.size()){
            pos = i-p.size();
        }
    }

    cout<<"pos = "<<pos<<endl;
   
    return 0;
}