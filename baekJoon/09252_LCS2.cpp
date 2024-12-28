#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

string s1, s2;
vector<char> v;
int n, m;
int arr[1005][1005];

int main(){    
    ios_base::sync_with_stdio(0);  
    cin.tie(0);cout.tie(0);  
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    s1 = "0" + s1;
    s2 = "0" + s2;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s2[i] == s1[j]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
        }
    }
    cout << arr[m][n] << '\n';
    
    int r = m, c = n;
    while (r > 0 && c > 0){
        if (s2[r] == s1[c]){
            v.push_back(s2[r]);
            r--;
            c--;
        }
        else if (arr[r][c - 1] > arr[r - 1][c]) c--;
        else r--;
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
}