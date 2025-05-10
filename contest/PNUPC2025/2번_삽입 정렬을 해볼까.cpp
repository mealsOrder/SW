#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<int>v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,t;

    cin >> n >>t;
    v.resize(n);

    for(int i=0;i<n;i++)cin >> v[i];
    /*
    for(int i=1;i<t;i++){
        int selc = v[i];
        int j=i-1;

        while(j>=0 && v[j] > selc){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = selc;
    }
    */
    stable_sort(v.begin(), v.begin()+t);
    for(int i=0;i<n;i++) cout << v[i] << ' ';
    cout << '\n';
    return 0;
}
