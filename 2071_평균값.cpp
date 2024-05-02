#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main(){
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		int sum=0,ans=0;
		float p=0;
		for(int i=0;i<10;i++){
			int a;
			cin >>a;
			sum+=a;
		}
		p=(float)sum / 10;
		ans = round(p);
		
		cout << "#" << t << " " << ans << endl;
	}
    


}