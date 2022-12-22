#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pr(n) cout << n << endl
#define tv(v) for(auto &i : v) cin >> i
#define fo(i,in,fn) for(int i=in;i<fn;i++)
#define fol(i,in,fn) for(ll i=in;i<fn;i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
#define vl vector<ll>
#define vi vector<int>
#define mi map<int,int>
#define ml map<ll,ll>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define si set<int>
#define sl set<ll>
#define ff first
#define ss second
#define setbits(x) __builtin_popcountll(x)
#define setDp(dp,i) memset(dp,i,sizeof(dp));
#define fset(x) fixed << setprecision(x)
#define mod 1000000007
 
void dfs_helper(vector<vi> &adj, vector<bool> &visited, int &count, int u, int p, bool &cycle){
    visited[u] = true;
    count++;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs_helper(adj,visited,count,v,u,cycle);
        }
        else if(visited[v] && v != p){
            cycle = true;
        }
    }
}
 
bool checkOddCycle(vector<vi> &adj, int n)
{
    vector<bool> visited(n,false);
 
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int count = 0;
            bool cycle = false;
            dfs_helper(adj,visited,count,i,-1,cycle);
            if(cycle && count%2){
                return true;
            }
        }
    }
 
    return false;
}
 
void solve(){
 
    int n;
    cin >> n;
 
    vector<vi> adj(n);
    set<pi> s;
    int flag=0;
 
    map<int,int> mp;
 
    for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        mp[u]++;
        mp[v]++;
        if(u==v || mp[u] > 2 || mp[v] > 2){
            flag=1;
        }
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
 
    if(flag){
        cout << "NO\n";
        return;
    }
 
    if(checkOddCycle(adj,n)){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }
 
}
 
int main(){
 
    fast
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    cin >> t;
 
    while(t--){
        solve();
    }
 
}