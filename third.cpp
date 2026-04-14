#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<bool> used;
int ans = INT_MIN;
int val=1;
void dfs(int node,int c,vector<vector<int>>& adj){
    if(c>ans){
        ans = c;
        val=node;
    }
    used[node] = true;
    int x=0;
    for (int child : adj[node]) {
        if(!used[child]){
            dfs(child,c+1,adj);
        }
    }
    return;
}
int maxi=0;
void f(int node,int c,vector<vector<int>>& adj){
     used[node] = true;
    for (int child : adj[node]) {
        if(!used[child]){
            maxi = max(maxi,c+1);
            f(child,c+1,adj);
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
                dfs(1,0,arr);
         used.assign(n + 1, false);
                f(val,0,arr);
        cout<<maxi<<endl;
       return 0;
}