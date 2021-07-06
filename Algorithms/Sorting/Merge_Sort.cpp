
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void display(vector<int>& ar){
    for(auto it:ar){
        cout<<it<<" ";
    }
    cout<<endl;
}

void merge(vector<int> & ar, int st, int en){
    vector<int> v;
    int m= (st+en)/2;
    int left=st, right = m;
    while(left<m && right< en){
        if(ar[left]<=ar[right])v.push_back(ar[left++]);
        else    v.push_back(ar[right++]);

    }
    while(left<m){
        v.push_back(ar[left++]);
    }
    while(right<en){
        v.push_back(ar[right++]);
    }
    for(int i=st;i<en;i++){
        ar[i]=v[i-st];
    }
}

void merge_sort(vector<int> & ar, int st, int en){
    if(en-st<=1)return;
    int m=(st+en)/2;
    merge_sort(ar,st,m);
    merge_sort(ar,m,en);
    merge(ar, st,en);
}

void merge_sort(vector<int> & ar, int n){
    merge_sort(ar,0,n);
}

int main(){ 
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int id=0;id<n;id++){
        cin>>ar[id];
    }
    display(ar);
    merge_sort(ar,n);
    display(ar);

    return 0;
}
