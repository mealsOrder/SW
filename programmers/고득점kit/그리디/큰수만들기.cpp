#include <string>
#include <vector>
using namespace std;
string solution(string n, int k) {
    string ans = "";
    int num = n.length()-k; // 구해야할 숫자의 길이
    int idx = 0;
    for(int i=0;i<num;i++){
        char mxChar = n[idx];
        int mxIdx = idx;
        for(int j=idx;j<=k+i;j++){
            if(mxChar<n[j]){
                mxChar = n[j];
                mxIdx=j;
            }
        }
        ans += mxChar;
        idx=mxIdx+1; 
    }
    return ans;
}
