
// When the time constraints are really really tight, these may help
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx2")


// templates to print pairs and vectors directly
template<typename T> ostream& operator <<(ostream &out,vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}

