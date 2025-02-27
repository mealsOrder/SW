#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
typedef long long ll;

using namespace std;
int N,flag;
ll leftMoney, bM, aM;
vector<ll>v;

// 최대 공약수
ll func(ll a, ll b){
    while(1){
        if(a%b == 0){
            return b;
        }
        ll r = a;
        a = b;
        b = r%a;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        // 입금
        if(a >= 0){
            if(leftMoney + a != b){
                flag = 1;
                break;
            }
            leftMoney = b;
        }
        // 출금
        else{
            // 
            if(leftMoney + a >=0){
                if(leftMoney + a != b){
                    flag = 1;
                    break;
                }
                leftMoney = b;
            }
            else{
                aM = b - a - leftMoney;
                if(bM == 0){
                    bM = aM;
                    v.push_back(b);
                }
                else{
                    bM = func(bM,aM);
                    v.push_back(b);
                }
            }
            leftMoney = b;
        }
                
    }

    for(int i=0;i<v.size();i++){
        if(v[i] - bM>=0){
            flag=1;
        }
    }
    if(bM == 0){
        bM=1;
    }

    if(flag == 1){
        cout << -1 << '\n';
    }
    else{
        cout << bM << '\n';
    }
    return 0;
}