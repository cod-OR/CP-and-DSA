
#include <bits/stdc++.h>
using namespace std;
#define ll long long


void display(int ar[], int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void insertion_sort(int ar[], int n){
    for(int id=0;id<n;id++){
        int temp= ar[id];
        int p=id;
        while(p>0 && ar[p-1]>temp){
            ar[p]=ar[p-1];
            p--;
        }
        ar[p]=temp;
    }
}

int main(){ 
    // freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int id=0;id<n;id++){
        cin>>ar[id];
    }

    display(ar, n);
    insertion_sort(ar,n);
    display(ar,n);

    return 0;
}
