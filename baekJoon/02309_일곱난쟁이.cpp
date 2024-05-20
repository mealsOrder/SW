#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
//vector<pair<int,int>>q;
int cnt;
int main() {
    int sum=0;
    for(int i=0;i<9;i++){
        int a;
        cin >> a;
        v.push_back(a);
        sum+=a;
    }
    sort(v.begin(),v.end());

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int hap = v[i]+v[j];
            if(i==j)continue;

            if(sum-hap == 100){
                for(int k=0;k<9;k++){
                    if(k != i && k!=j){
                        cout << v[k] << endl;

                    }
                }
                return 0;
            }

        }
    }
    

    return 0;
}