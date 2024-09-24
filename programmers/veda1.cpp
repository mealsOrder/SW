#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<list>
using namespace std;

string input1 = "abcd";
string input2 = "";

string op1[6] = {"L", "P Z", "L", "D","R","l x"};
string op2[5] = {"P a", "P b", "L","l c","l d"};

void solved(string in, vector<string>op){
    list<char>L;
    for(auto t:in)L.push_back(t);
    auto c = L.end();
    int N = op.size();

    for(int i=0;i<N;i++){
        if(op[i][0] == 'P'){
            char p = op[i][2];
            L.insert(c,p);
        }
        else if(op[i][0] == 'L'){
            if(c != L.begin())c--;
        }
        else if(op[i][0] == 'R'){
            if(c != L.end())c++;
        }
        else if(op[i][0] == 'D'){
            if(c != L.begin()){
                c--;
                c = L.erase(c);   
            }
        }
        else if(op[i][0] == 'l'){
            char rep = op[i][2];
            if(c != L.end()){
                c = L.erase(c);
                L.insert(c,rep);
            }
            else{
                L.insert(c,rep);
            }

        }
        
    }

    for(auto i: L){
        cout << i;
    }
}

int main(){
    vector<string>s1;
    //string op1[6] = {"L", "P Z", "L", "D","R","l x"};
    s1.push_back("L");
    s1.push_back("P Z");
    s1.push_back("L");
    s1.push_back("D");
    s1.push_back("R");
    s1.push_back("l x");

    solved(input1,s1);
    cout << '\n';

    vector<string>s2;
    //string op2[5] = {"P a", "P b", "L","l c","l d"};
    s2.push_back("P a");
    s2.push_back("P b");
    s2.push_back("L");
    s2.push_back("l c");
    s2.push_back("l d");

    solved(input2,s2);
	return 0;
}