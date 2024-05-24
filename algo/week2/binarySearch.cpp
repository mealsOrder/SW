#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>v;

int search(vector<int>&s,int target,int left, int right  ){

    while(left<=right){
        int mid = (left+right)/2;
        if(v[mid] == target){
            
            return 1;
        }else if(v[mid]>target){
            right = mid-1;
        }else if(v[mid]<target){
            left = mid+1;
        }
    }
    return 0;
}

int main(){
    int N,M;

    cin >> N >> M;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<M;i++){
        int b;
        cin >> b;
        if(search(v,b,0,N-1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    return 0;
}