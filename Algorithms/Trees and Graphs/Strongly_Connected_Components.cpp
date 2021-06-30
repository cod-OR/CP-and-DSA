
                        //    I solemnly swear that I am upto no good //

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
// #define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
bool comp(ll a,ll b){
    return a>b;
}

ll n,k,tt=1;
vector<vector<int> > scc;       // stores Strongly Connected Components
vector<int> adj[A], adjr[A];

void dfs(int x, vector<int> &visited,stack<int> &st){
    for(auto it:adj[x]){
        if(!visited[it]){
            visited[it]=1;
            dfs(it,visited,st);
        }
    }
    st.push(x);
}

void dfsr(int x, vector<int> &visited){
    for(auto it:adjr[x]){
        if(!visited[it]){
            visited[it]=1;
            scc.back().pb(it);
            dfsr(it, visited);
        }
    }
}
void kosaraju(){
    vector<int> visited(n+1);
    stack<int> st;
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){    
            visited[i]=1;
            dfs(i, visited, st);
        }
    }
    for(int i=0;i<=n;i++){
        visited[i]=0;
    }

    while(!st.empty()){
        if(!visited[st.top()]){
            visited[st.top()]=1;
            scc.pb({st.top()});
            dfsr(st.top(), visited);        // dfs for reversed list
        }
        st.pop();
    }
}

void solve(){
    //string s,t;
    ll m;
    cin>>n>>m; 

    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);           // adj. list
        adjr[b].pb(a);          // reverse adj. list
    }

    kosaraju();
    
    cout<<"Strongly connected componentes: \n";
    int cnt=0;
    for(auto v:scc){
        cout<<cnt++<<": ";
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

signed main(){ 
    sub;    
    fast;
    // pre();
    // clock_t clk = clock();
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    // ttime;
    return 0;
}        

                                // Mischief Managed //   
                                         
