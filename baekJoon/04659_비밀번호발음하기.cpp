#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
bool isMoum(char a){ 
    return a == 'a' || a == 'i' || a == 'e' || a == 'o' || a == 'u'; 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true){
    string s;
		cin >> s;
		if (s == "end") break;
		bool flag1 = false;
		bool flag2 = true;
		for (char a : s){
			if (isMoum(a)){ 
                flag1 = true; 
                break; 
            }
		}
		stack<char> col;
		for (char a : s){
			if (col.size() != 0){
				
                if (col.top() == a){
					if (a != 'e' && a != 'o'){ 
                        flag2 = false; 
                        break; 
                    }
				}

				if (col.size() > 1){
					if (isMoum(col.top()) == isMoum(a)){
						char n = col.top();
						col.pop();
						if (isMoum(col.top()) == isMoum(a)){ 
                            flag2 = false; 
                            break; 
                        }
						else{ 
                            col.push(n); 
                        }
					}
				}
			}
			col.push(a);
		}
		if (!flag1 || !flag2){ 
            cout << "<" << s << ">" << " is not acceptable.\n"; 
        }
		else{ 
            cout << "<" << s << ">" << " is acceptable.\n"; 
        }
	}
}