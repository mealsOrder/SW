#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// 10
// 2 4 7 8 9 10 11 15 16 19
// 16

int biSearch(int arr[],int s,int e,int target){
	if(s>e) return -1;
	else if(s == e){
		if(arr[s] == target) return s;
		else return -1;
	}
	else{
		int mid = (s+e)/2;
		if(arr[mid] == target) return mid;
		else if(arr[mid]>target){
			return biSearch(arr,s,mid-1,target);
		}
		else{
			return biSearch(arr,mid+1,e,target);
		}
	} 
	
}
int main(){
	
	int N,M;
	int arr[100];
	
	cin >>N;
	
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	cin >> M;
	
	sort(arr,arr+N);
	
	int idx = biSearch(arr,0,N-1,M);
	
	if(idx == -1){
		cout << "X\n";
	}
	else{
		cout << idx << endl;
	}
	return 0;
}