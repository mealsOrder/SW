#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int main(){
	
	for(int t=1;t<=10;t++){
		
		int len;
		string s;
		
		cin >> len >> s;
		
		for(int i=0;i<s.size();i++){
			for(int j=0;j<s.size()-1;j++){
				
				if(s[j] == s[j+1]){
					s.erase(j,2);
				}
			}
		}

		cout << "#" << t << " " << s << endl;
		
	}
	

	return 0;
}