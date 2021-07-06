// Bubble sort

#include<bits/stdc++.h> 
using namespace std;

void bubble_sort(vector<int> &arr, int n){
    for(int itr=1;itr<=n;itr++){
        bool flag=0;
        for(int id=0;id<n-1;id++){
            if(arr[id]>arr[id+1]){
                swap(arr[id], arr[id+1]);
                flag=1;
            }
        }
        if(!flag)
            break;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int id=0;id<n;id++){
        cin>>arr[id];
        cout<<arr[id]<<" ";
    }
    cout<<endl;

    bubble_sort(arr,n);

    for(int id=0;id<n;id++){
        cout<<arr[id]<<" ";
    }
    cout<<endl;
    
    return 0;
}
