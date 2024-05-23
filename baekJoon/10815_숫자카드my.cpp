#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 500001;
vector<int>A;
vector<int>B;
vector<pair<int,int>>D;
int C[MAX];
int main() {
    int N,M;

    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    cin >> M;
    for(int i=0;i<M;i++){
        int b;
        cin >> b;
        B.push_back(b);
        D.push_back({b,i});
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(D.begin(),D.end());
    
    for(int num:A){
        int left = 0;
        int right = M-1;
        while(left<=right){
            int mid = (left+right)/2;

            if(num == D[mid].first){
                C[ D[mid].second ]++;
                break;
            }
            else if(num>D[mid].first){
                left = mid+1;
            }
            else if(num<D[mid].first){
                right = mid-1;
            }

        }

    }
    for(int i=0;i<M;i++){
        cout << C[i] << " ";
    }

    return 0;
}