#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<list>
using namespace std;


// n <=10
// cap <=16
// files size 12
bool vis[16];
bool chk[18];
int arr[13];
int ans;
int tmp[13][13];
int pre;
int ansSum;
void back(int x,int k,vector<int> files,int c){
    sort(files.begin(),files.end());
    if(x == k){
        int sum = 0;
        for(int i=0;i<x;i++){
            //cout << arr[i] << " ";
            sum += arr[i];
        }
        if(sum <= c ) ans = max(ans,x);
        //cout << '\n';
        return;
    }
    else{
        int last = 0;
        for(int i=0;i<files.size();i++){
            if(!vis[i] && files[i] != last){
                last = arr[x] = files[i];
                vis[i] = true;
                back(x+1,k,files,c);
                vis[i] = false;
            }
        }
    }
}

/*
if(n == 0){

        return;
    }
    else{
        for(int i=0;i<files.size();i++){

            if(!vis[i]){
                tmp[n][i] = files[i];
                if((arr[n] + tmp[n][i]) < capacity){
                    vis[i] = true;

                    vis[i] = false;
                }
            }
            else{

            }
            if(!vis[i] && (arr[n] + files[i]) < capacity){
                arr[n] += files[i];
                vis[i] = true;
                ans++;
                solved(n,capacity,files);
                vis[i] = false;
                arr[n] -= files[i];
                ans--;
            }
            else if(!vis[i] && (arr[n] +files[i]) == capacity){
                arr[n] += files[i];
                vis[i] = true;
                ans++;
                solved(n-1,capacity,files);
            }
            else if(!vis[i] && (arr[n] +files[i]) > capacity ){
                solved(n-1,capacity,files);
            }
        }
    }

*/

void solved(int n, int capacity, vector<int> files){
    ansSum = 0;
    //for(int j=0;j<n;j++){
        
        for(int i=0;i<=capacity;i++){
            back(0,i,files,capacity);
            //ansSum+=ans;
        }
        //ansSum+=ans;
        cout << ans << '\n';
    //}
    //cout << ansSum << '\n';
    cout << '\n';
}

int main(){
    vector<int>s1;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    s1.push_back(4);
    s1.push_back(5);


    solved(2,5,s1);
    

    ans =0;
    fill(vis,vis+1,0);
    vector<int>s2;
    s2.push_back(1);
    s2.push_back(4);
    s2.push_back(5);

    solved(1,5,s2);

    ans =0;
    fill(vis,vis+1,0);
    vector<int>s3;
    s3.push_back(2);
    s3.push_back(2);
    s3.push_back(2);
    s3.push_back(2);
    s3.push_back(2);

    solved(2,3,s3);

    ans =0;
    fill(vis,vis+1,0);
    vector<int>s4;
    s4.push_back(1);
    s4.push_back(3);
    s4.push_back(4);
    s4.push_back(5);
    s4.push_back(6);
    s4.push_back(7);

    solved(3,6,s4);

    ans =0;
    fill(vis,vis+1,0);
    vector<int>s5;
    s5.push_back(1);
    s5.push_back(1);
    s5.push_back(7);
    s5.push_back(5);
    s5.push_back(6);
    s5.push_back(3);

    solved(3,6,s5);
	return 0;
}