#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<bool> used;
int ans = INT_MIN,res=INT_MIN;
int val=1,val2=1;
vector<int> dist1,dist2;
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

void f(int node,int c,vector<vector<int>>& adj){
     if(c>res){
        res = c;
        val2=node;
    }
     used[node] = true;
    for (int child : adj[node]) {
        if(!used[child]){
           
            f(child,c+1,adj);
        }
    }
    dist1[node] = c;
    return;
}
void f1(int node,int c,vector<vector<int>>& adj){
   
     used[node] = true;
    for (int child : adj[node]) {
        if(!used[child]){
           
            f1(child,c+1,adj);
        }
    }
    dist2[node] = c;
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
                dist1.assign(n+1,0);
         used.assign(n + 1, false);
                f(val,0,arr);

                dist2.assign(n+1,0);
         used.assign(n + 1, false);
                f1(val2,0,arr);
        for(int i=1;i<=n;i++){
            cout<<max(dist1[i],dist2[i])<<endl;
        }
       return 0;
}