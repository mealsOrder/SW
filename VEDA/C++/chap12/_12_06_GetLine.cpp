#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void fileRead(vector<string>&v, ifstream &fin){
    string line;
    while(getline(fin,line)){
        v.push_back(line);
    }
}

void search(vector<string>&v,string word){
    for(int i=0;i<v.size();i++){
        int idx = v[i].find(word);
        if(idx != -1){
            cout << v[i] << '\n';
        }
    }
}
int main(){
    vector<string>wordVector;
    ifstream fin("words.txt");
    if(!fin){
        cout <<"cant open\n";
        return 0;
    }
    fileRead(wordVector,fin);
    fin.close();

    cout<<"word.txt 를 읽었습니다.\n";
    while(true){
        cout << "검색할 단어를 입력하세여 >>"
    }
    return 0;   

}