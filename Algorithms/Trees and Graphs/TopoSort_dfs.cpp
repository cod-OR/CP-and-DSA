                        //    I solemnly swear that I am upto no good //

#include <bits/stdc++.h>
using namespace std;
#define sub             freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
#define ll              long long
#define pb              push_back
#define sz(x)           (int)((x).size())
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x)          (x).begin(),(x).end()

#define endl "\n"
#define int ll


ll n,k,tt=1;

void dfs(int x, vector<int> &order, vector<vector<int> > &adj, vector<int> &visited){
    visited[x]=1;
    for(auto it:adj[x]){
        if(!visited[it])
            dfs(it,order,adj,visited);
    }
    order.pb(x);
}

void solve(){
    
    ll n,m;
    cin>>n>>m;  // number of vertices and edges
    vector<int> ar(n);
    vector<vector<ll> > adj(n+1);

    // input

    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }

    // dfs_topo algorithm

    vector<int> order,visited(n+1);

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,order,adj,visited);
        }
    }
    
    reverse(all(order));

    for(int x:order){
        cout<<x<<" ";
    }
    cout<<endl;
    

}
           
signed main(){
    fast;
    ll t=1;
    #ifndef ONLINE_JUDGE
        sub;    
    #endif

    // cin>>t;
    while(t--)
        solve();

    return 0;
}        

                                // Mischief Managed //
