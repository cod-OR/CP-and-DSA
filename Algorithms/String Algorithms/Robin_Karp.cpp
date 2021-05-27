        	//    I solemnly swear that I am upto no good //

#include <bits/stdc++.h>
#define sub   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ff first
#define ss second
#define NN cout<<"NO"<<endl;
#define YY cout<<"YES"<<endl;
#define ub upper_bound
#define lb lower_bound
#define A 1000001
#define make(a,b,c) make_pair(a,make_pair(b,c)) 
bool comp(ll a,ll b){
	return a>b;
}

int p=31;
int calculateHash(string &s, int n){
	int h=0;
	for(int i=0;i<n;i++){
		h+=(s[i]*pow(p,i));
	}
	return h;
}
 void gocheck(string &text,string &patt,int j){
 	for(int i=0;i<patt.size();i++){
 		if(patt[i]!=text[i+j]){
 			return;
 		}
 	}
 	cout<<"found at "<<j<<endl;
 }

void solve(){
	ll m,n,k;
	string text,patt;
	cin>>text;
	cin>>patt;
	n=text.size();
	m=patt.size();
	int h1=calculateHash(text,n);
	int h2=calculateHash(patt,n);
	
	if(h1==h2)gocheck(text,patt,0);

	for(int i=1;i<=m-n;i++){
		h2-=patt[i];
		h2/=p;
		h2+=(patt[i+n-1]*pow(p,n-1));
		if(h1==h2)gocheck(text,patt,i);
	}

}


int main(){	
    sub;    
    fast;
   	int t=1;
    // cin>>t;
    while(t--){
    	solve();
	}
    return 0;
}        

        		        // Mischief Managed //    
