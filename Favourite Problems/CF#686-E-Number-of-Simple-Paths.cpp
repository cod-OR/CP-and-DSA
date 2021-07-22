
// Problem  - https://codeforces.com/contest/1454/problem/E
// Find the number of simple undirected paths in given psuedotree ( a graph with n vertices and n edges)
// Idea is to start from leaves and run a bfs till you reach the cycle.
// Follow editorial to the problem for the explaination  


#include <bits/stdc++.h>
using namespace std;
#define sub             freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
#define ll              long long
#define ld              long double
#define ttime           cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
#define pb              push_back
#define unq(a)          sort(all(a));(a).resize(unique(all(a)) - (a).begin())
#define sz(x)           (int)((x).size())
#define input(arr,n)    for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x)          (x).begin(),(x).end()
#define rep(i,a,b)      for(ll i=a;i<b;i++)
#define pr(x)           cout << #x " = " << (x) << "\n"
#define mp              make_pair
#define ff              first
#define ss              second
#define YY              cout<<"Yes"<<endl
#define NN              cout<<"No"<<endl
#define ppc             __builtin_popcount
#define ppcll           __builtin_popcountll

const long long INF=1e18;
const long long A=200005;
const long long mod=1000000007;                    // 2971215073, 1000050131, 433494437

#define endl "\n"
#define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
bool comp(ll a,ll b){
    return a>b;
}

ll n,k,tt=1;

ll calculate(ll p){
    ll tot=(p*(p-1))/2;
    return tot+(p*(n-p));
}

void solve(){
    cin>>n; 
    vector<ll> adj[n+1];

    for(int i=0;i<n;i++){

        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<ll> leaves;
    vector<ll> visited(n+1);

    vector<ll> cntv(n+1, 1);
    for(int i=0;i<=n;i++){
        visited[i]=0;
        if(adj[i].size() == 1){
            leaves.push(i);
        }
    }

    while(!leaves.empty()){
        int node = leaves.front();
        leaves.pop();
        visited[node]=1;
        int cnt=0, child=-1, newchild=-1;
        for(auto it:adj[node]){
            if(visited[it]==0){
                child= it;
                break;
            }
        }

        if(child !=-1){
            cntv[child] += cntv[node];
            for(auto it:adj[child]){
                if(visited[it]==0){
                    newchild = it;
                    cnt++;
                }
            }
            if(cnt==1){
                leaves.push(child);
            }
        }
    }

    ll ans=0;
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){   
            ans+=(calculate(cntv[i]));
        }
    }

    cout<<ans<<endl;
    

}

signed main(){ 
    // sub;    
    fast;
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    // ttime;
    return 0;
}        

                                // Mischief Managed //   
                                         
