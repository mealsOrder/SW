#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pair<string,string>>v;
    int N,M;
    cin >>N>>M;
    for(int i=0;i<N;i++){
        string a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    for(int i=0;i<M;i++){
        string target;
        cin >> target;
        int lef = 0;
        int rig = N-1;
        while(lef<=rig){
            int mid = (lef+rig)/2;
            if(v[mid].first == target){
                cout << v[mid].second << '\n';
                break;                
            }
            else if(v[mid].first < target){
                lef = mid+1;
            }
            else{
                rig = mid-1;
            }
        }

    }

    return 0;
}