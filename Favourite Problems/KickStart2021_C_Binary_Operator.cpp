
// Link - https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ec290

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
#define PR(x)           cout << #x " = " << (x) << "\n"
#define mp              make_pair
#define ff              first
#define ss              second
#define YY              cout<<"Yes"<<endl
#define NN              cout<<"No"<<endl
#define ppc             __builtin_popcount
#define ppcll           __builtin_popcountll

const long long INF=1e18;
const long long A=200005;
const long long mod=514229;

#define endl "\n"
#define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
bool comp(ll a,ll b){
    return a>b;
}

ll n,k,tt=1;
string s;
map<pairll, ll> pp;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int hasz(int a, int b) {
    if(pp.find({a,b})!= pp.end())return pp[{a,b}];
    else return pp[{a,b}]=((rng()+1)%mod);
}

ll gimme_bal(char c){
    if(c=='(')return 1;
    else if(c==')')return -1;
    return 0;
}

int merge(int a, int b, char ope) {
    if(ope == '+') {
        return (a + b) % mod;
    }
    if(ope == '*') {
        return (long long) a * b % mod;
    }
    return hasz(a,b) % mod;
}    

ll rec(int st, int en){
    // if(st>en)return 0;
    ll a,b;
    if(s[st]=='('){
        int i=st+1;
        ll bal=1;
        while(bal>0){
            bal+=(gimme_bal(s[i++]));
        }
        a= rec(st+1, i-2);
        if(i>en)return a;


        b= rec(i+1, en);
        return merge(a,b, s[i]);
    }
    else{
        a=0;
        while(st<=en && isdigit(s[st])){
            a= (10ll*a + (s[st++])-'0') % mod;
        }
        if(st>en)return a;

        return merge(a, rec(st+1,en), s[st]);

    }
}

void solve(){
    cin>>n; 
    mapll mapping;
    ll next=1;
    for(int i=0;i<n;i++){
        cin>>s;
        // cout<<s<<endl;
        ll val=rec(0, sz(s)-1);
        if(mapping.find(val)==mapping.end()){
            mapping[val]=next++;
        }
        cout<<mapping[val]<<" ";
    }
    cout<<endl;
}

signed main(){ 
    // sub;    
    fast;
    // pre();
    // clock_t clk = clock();
    ll t=1;
    cin>>t;
    while(t--){
        cout << "Case #" << tt++ << ": ";
        solve();
    }
    // ttime;
    return 0;
}        
                                         
