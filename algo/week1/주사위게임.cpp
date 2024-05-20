#include <iostream>
#include <algorithm>

using namespace std;
int ans[1001];
int main() {
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        
        int a,b,c;
        int same=0;
        cin >> a>>b>>c;
        if(a == b && b == c){
            ans[i] = 10000+a*1000;
        }
        else if(a==b||a==c||b==c){
            
            if(a==b) same = a;
            if(a==c) same = a;
            if(b==c) same = b;
            ans[i] = 1000+same*100;
        }
        else{
            same = max({a,b,c});
            ans[i] = same*100;
        }

    }

    sort(ans,ans+N);

    cout << ans[N-1] << endl;
    
    return 0; 
}