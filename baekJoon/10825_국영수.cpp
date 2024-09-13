#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ff first.first
typedef long long ll;
vector< pair< pair<int,int>, pair<int,string> >>v; // 국 영 수 이름
bool cmp(pair< pair<int,int>, pair<int,string>>a,pair< pair<int,int>, pair<int,string> >b){
    if(a.first.first == b.first.first && a.first.second == b.first.second && a.second.first == b.second.first){
        return a.second.second < b.second.second;
    }
    else if(a.first.first == b.first.first && a.first.second == b.first.second ){
        return a.second.first > b.second.first;
    }
    else if(a.first.first == b.first.first){
        return a.first.second < b.first.second;
    }
    else{
        return a.first.first > b.first.first;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        string name;
        int k,e,m;
        cin >> name >> k >> e >> m  ;
        v.push_back({{k,e},{m,name}});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<N;i++){
        cout << v[i].second.second << '\n';
    }
    return 0;
}