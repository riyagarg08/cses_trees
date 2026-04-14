#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<bool> used;
long long ans=0;
vector<long long> dp,subtree_size;
void dfs(int node,int c,vector<vector<int>>& adj){
   
    used[node] = true;
  
    for (int child : adj[node]) {
        if(!used[child]){
            dfs(child,c+1,adj);
            subtree_size[node] += subtree_size[child];
        }
    }
    ans += c;
    return;
}


void f1(int node,int c,vector<vector<int>>& adj){
   
     used[node] = true;
    for (int child : adj[node]) {
        if(!used[child]){
           dp[child] = dp[node] - subtree_size[child] + (dp.size() -1 - subtree_size[child]);
            f1(child,c+1,adj);
        }
    }
    return;
}
int main(){
    
        int n;
        cin>>n;
       vector<vector<int>> arr(n+1);
        for(int i=2;i<=n;i++){
            int x,y;
            cin>>x>>y;
            arr[y].push_back(x);
            arr[x].push_back(y);   
        }
       used.assign(n + 1, false);
        dp.assign(n+1,0);
        subtree_size.assign(n+1,1);
                dfs(1,0,arr);
                dp[1]=ans;
                
               
         used.assign(n + 1, false);
                f1(1,0,arr);
      for(int i=1;i<=n;i++){
            cout<<dp[i]<<" ";
        }
       return 0;
}