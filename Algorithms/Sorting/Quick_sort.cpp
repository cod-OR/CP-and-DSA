// Quick sort
std::vector<ll> ar(1000001);

int pertition(int st,int j){
	int pivot = ar[st];
	int i=st+1;
	int j=st+1;
	for(j=st+1;j<=en;j++){
		if(ar[j]<pivot){
			swap(ar[i],ar[j]);
			i++;
		}
	}
	swap(ar[start],ar[i-1]);
	return i-1;
}


void quicksort(int st,int en){
	if(st<en){
		int pivot=partition(st,en);
		quicksort(st,pivot-1);
		quicksort(pivot+1,en);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	quicksort(0,n);

}
