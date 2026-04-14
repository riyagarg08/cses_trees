#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> used;
int ans = 0;
int dfs(int node,vector<vector<int>>& adj){
    used[node] = true;
    int res =0;
    int x=0;
    for (int child : adj[node]) {
        if(!used[child]){
            res += dfs(child,adj);
        }
    }
    return res
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
                dfs(1,arr);
        cout<<ans<<endl;
       return 0;
}