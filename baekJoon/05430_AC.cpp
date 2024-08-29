#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;

    while(t--){
        deque<int> dq;
        string p, str, emptyString = "";
        cin >> p >> n >> str;

        bool reverse = false, error = false;

        for(int i = 0; i < str.length(); i++){
            if(isdigit(str[i])) emptyString += str[i];
            else{
                if(!emptyString.empty()){
                    dq.push_back(stoi(emptyString));
                    emptyString = "";
                }
            }
        }

        for(auto o : p){
            if(o == 'R'){
                if(reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else{
                if(dq.empty()){
                    cout << "error\n";
                    error = true;
                    break;
                }
                if(reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if(!error)
            cout << '[';

        if(reverse && !dq.empty()){
            for(auto o = dq.rbegin(); o != dq.rend(); o++){
                if(o == dq.rend() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }

        else if(!reverse && !dq.empty()){
            for(auto o = dq.begin(); o != dq.end(); o++){
                if(o == dq.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }

        if(!error)
            cout << "]\n";
    }

    return 0;
}