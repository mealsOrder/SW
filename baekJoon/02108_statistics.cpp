#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >>N;
    vector<int>arr(N);
    int sum = 0;
    double avg = 0;
    int mid = 0;
    int quency = 0;
    int range = 0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(),arr.end());
    avg = round((double)sum / N);
    cout << avg << '\n';
    mid = arr[N/2];
    cout << mid << '\n';

    map<int,int>freq;
    for(int i=0;i<N;i++){
        freq[arr[i]]++;
    }

    int maxFreq = 0;
    vector<int>modes;
    for(auto item : freq){
        if(item.second > maxFreq){
            modes.clear();
            modes.push_back(item.first);
            maxFreq = item.second;
        }else if(item.second == maxFreq){
            modes.push_back(item.first);
        }
    }
    if(modes.size()>1){
        sort(modes.begin(),modes.end());
        cout << modes[1] << '\n';
    }else{
        cout << modes[0] << '\n';
    }

    range = arr[N-1] - arr[0];
    cout << range << '\n';
    return 0;
}