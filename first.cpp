#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(int node,vector<vector<int>>& arr,vector<int>& vis,vector<int>& ans){
    vis[node]=1;
    int res=0;
    for(auto it:arr[node]){
        if(!vis[it]){
           res += dfs(it,arr,vis,ans);
        }
        
    }
    ans[node] = res;
    return res+1;
}
int main(){
    
        int n;
        cin>>n;
       vector<vector<int>> arr(n+1);
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            arr[i].push_back(x);
            arr[x].push_back(i);
        }
        vector<int> vis(n+1,0);
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,arr,vis,ans);
            }
        }
         for(int i=1;i<=n;i++){
           cout<<ans[i]<<" ";
        }
       return 0;
}