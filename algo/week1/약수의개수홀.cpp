#include <iostream>
#include <vector>
using namespace std;
 
 vector<int>v;
int main() {

    int N;

    cin >>N;
    
    for(int i=1;i<=N;i++){
        int cnt = 0;
        for(int j=2;j<N;j++){
            if(i%j==0){
                cnt++;
            }
        }
        if(cnt%2 ==1){
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    return 0;
}