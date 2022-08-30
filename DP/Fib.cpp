#include<iostream>
#include<vector>

using namespace std;

int fib(int n,vector<int>& dp){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int ans=fib(n-1,dp)+ fib(n-2,dp);
    dp[n]=ans;
    return ans;
}

int fibTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main(){
    
    int n=10;
    vector<int> dp(n+1,-1);
    cout<<fib(n,dp)<<endl;
    cout<<fibTab(n)<<endl;
    return 0;
}
