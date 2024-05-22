#include<iostream>
#include<queue>
using namespace std;
const int MAX = 110;

int info[MAX][3];
int main() {
    
    int N;
    int ans = 0;
    cin >>N;

    for(int i=0;i<N;i++){
                  // ¼ýÀÚ >> strike >> ball
        cin >> info[i][0] >> info[i][1]>> info[i][2];
    }

    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){

                if(i!=j && j!=k && i!=k){
                    bool flag = false;
                    
                    for(int p=0;p<N;p++){
                        int first = info[p][0]/100;
                        int second = (info[p][0]/10)%10;
                        int third = info[p][0]%10;
                        int s=0, b=0;
                        if(first == i)s++;
                        if(second == j)s++;
                        if(third == k)s++;

                        if(i==second || i==third)b++;
                        if(j==first||j==third)b++;
                        if(k==first||k==second)b++;

                            
                        if(info[p][1]!=s || info[p][2]!=b)flag = true;
                    }

                    if(flag == false) ans++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}