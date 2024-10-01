#include<iostream>
#include<algorithm>

using namespace std;

int CK[201][201]= {0,};	//이미 찾은 경로인지 확인
int ans[201]= {0,};		//답 체크
int A,B,C;				//물통 부피

void init();
void DFS(int a,int b,int c);

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> A >> B >> C;
	
	DFS(0,0,C);
	
	for(int i=0;i<201;i++){
		if(ans[i])cout << i << " ";
	}
}

void DFS(int a,int b, int c){
	//방문 확인
	if(CK[b][c]!=1){
		CK[b][c]=1;
		if(a==0){
			ans[c]=1;
		}
		if(c!=0){
			//A 물통 채우기
			if(c+a<A){
				DFS(a+c,b,0);
			}
			else{
				DFS(A,b,c+a-A);
			}
			//B 물통 채우기
			if(c+b<B){
				DFS(a,b+c,0);
			}
			else{
				DFS(a,B,c+b-B);
			}
		}
		if(b!=0){
			//A 물통 채우기
			if(b+a<A){
				DFS(a+b,0,c);
			}
			else{
				DFS(A,a+b-A,c);
			}
			//C 물통 채우기
			if(b+c<C){
				DFS(a,0,b+c);
			}
			else{
				DFS(a,b+c-C,C);
			}
		}
		if(a!=0){
			//B 물통 채우기
			if(a+b<B){
				DFS(0,a+b,c);
			}
			else{
				DFS(a+b-B,B,c);
			}
			//C 물통 채우기
			if(a+c<C){
				DFS(0,b,a+c);
			}
			else{
				DFS(a+c-C,b,C);
			}
		}
	}
	
}