#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

string si[] = {"D","C","B","A","E"} ;

int main(){
    
    for(int i=0;i<3;i++){
        int a,b,c,d;
        cin >> a>>b>>c>>d;

        cout << si[a+b+c+d] << endl;

    }

	return 0;
}