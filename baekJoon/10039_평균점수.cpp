#include <iostream>
#include <string>
using namespace std;

int arr[6];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int sum = 0;
	for(int i=0;i<5;i++){
		cin >> arr[i];
		if(arr[i]<=40) arr[i]=40;
		sum += arr[i];
	}

	cout << sum / 5;
	
}