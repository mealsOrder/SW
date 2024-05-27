#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

int main(){
	list<int>L = {1,2};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    cout << *t << '\n';

    L.push_back(5);
    L.insert(t,6);
    t++;
    t=L.erase(t);
    cout << *t << '\n';

    for(auto i :L) cout << i << " ";
	

	return 0;
}