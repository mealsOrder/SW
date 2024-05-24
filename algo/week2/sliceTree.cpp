#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX = 1000001;
long long tree[MAX];

int main() {
    long long N,M,mx=0;

    cin >> N>>M;
    for(int i=0;i<N;i++){
        cin >> tree[i];
    }
    sort(tree,tree+N);
    long long left = 0;
    long long right = tree[N-1];
    while(left<=right){
        long long sum = 0;
        long long cut = (left+right)/2;

        for(int i=0;i<N;i++){
            if(tree[i] -cut > 0){
                sum += tree[i]-cut;
            }
        }
        if(sum >= M){
            left = cut + 1; 
            mx = cut;
            if(cut > mx){
                mx = cut;
            }
        }else{
            right = cut - 1;
        }
    }
    cout << mx << "\n";
    return 0;
}