#include<iostream>
using namespace std;
int main(){
    //in cpp we need to go around the traditional modulus for handling negative numbers
    int x=-2;
    int k=5;
    int modulus = (x%k+k)%k;//take remainder with k , add k to it , then take remainder with the whole expression
    cout<<modulus<<endl;
    return 0;
}