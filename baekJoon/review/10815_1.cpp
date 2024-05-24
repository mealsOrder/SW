#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>A;
vector<int>B;
vector<int>ans;
int binarySearch(vector<int>&v,int target,int left,int right){
    while(left<=right){
        int mid = (left+right)/2;
        if(v[mid] == target) return 1;
        else if(v[mid] < target){
            left = mid +1;
        }
        else{
            right = mid-1;
        }
    }
    return 0;
}

int main(){
    int N,M;
    cin >>N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    cin >>M;
    for(int i=0;i<M;i++){
        int b;
        cin >>b;
        B.push_back(b);
    }
    
    sort(A.begin(),A.end());

    for(int tar:B){
        int left = 0;
        int right = N-1;
        ans.push_back(binarySearch(A,tar,left,right));
    }

    for(int num:ans){
        cout << num << " ";
    }

    return 0;
}