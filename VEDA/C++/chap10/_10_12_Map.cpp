#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){
    map<string,string>m;

    m.insert({"love","사랑"});
    m.insert({"apple","사과"});
    m["cherry"] = "체리";

    cout << "cnt : " << m.size() << '\n';

    string eng;
    while(true){
        cout << "찾고싶은 단어>>";
        cin >> eng;
        if(eng == "exit")break;

        if(m.find(eng) == m.end()) cout << "없음\n";
        else cout << m[eng] << '\n';
    }
    cout << "종료합니다...\n";
    return 0;
}