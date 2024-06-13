#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    // 정밀도 때문에 long long을 사용함
    vector<pair<long long ,long long>>v;
    for(int i=0;i<N;i++){
        long long a,b;
        cin >> a>>b;
        v.push_back({a,b});
    }
    v.push_back({v[0].first,v[0].second});
    long long r1=0,r2=0;
    for(int i=0;i<N;i++){
        r1 += v[i].first*v[i+1].second;
        r2 += v[i+1].first*v[i].second;
    }
    double res = (double)abs(r1-r2) / (double)2;
    printf("%.1lf",res);
    return  0;
}