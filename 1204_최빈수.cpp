#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;



int arr[1001];
int chk[101];


void init(){
	for(int i=0;i<101;i++){
		chk[i] = 0;
	}
}

int main(){

    int T;
    int N; // 번호 , 1000명

    cin >> T;
    for(int t=0;t<T;t++){
    	
    	// init
    	init();
    	int n;
    	cin >> n;
        for(int i =0;i<1000;i++){
            cin >> n;
            chk[n]++;
            
        }
		
		int max = 0;
		int ans = 0;
		for(int j=0;j<=100;j++){
			if(max <= chk[j]){
				max = chk[j];
				ans = j;
			}
		}
        cout << "#" << t+1 << " " << ans << endl;

        
    }


}