#include <string>
#include <vector>

using namespace std;
//solve time :  15min
int solution(int n, vector<int> lost, vector<int> reserve) {
    int ans = 0;
    vector<int>a(n+1,0);

    for(int i=0;i<lost.size();i++){
        a[lost[i]]--;
    }

    for(int i=0;i<reserve.size();i++){
        a[reserve[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(a[i] == -1){
            if(a[i-1] == 1 ) {
                a[i] = 0;
                a[i-1] = 0;
            }
            else if(a[i+1] == 1){
                a[i] = 0;
                a[i+1] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i] >=0) ans++;
    }

    return ans;
}

int main(){

    return 0;
}