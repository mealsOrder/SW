#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >>T;
    while(T--){
        string ops,_list;
        cin >> ops;
        int num;
        cin >> num;
        cin>>_list;

        for(char op:ops){
            if(op == 'R'){
                _list.reserve();
            }
            else{
                if(_list.empty()){
                    cout << "error\n";
                    break;
                }
                else{
                    _list.erase(0);
                }
            }
        }
        cout << _list << '\n';
    }


    return 0;
}