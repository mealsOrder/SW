#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int arr[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int ans = 0;
    int n = name.size();
    int minMove = n-1;
    for(int i=0;i<n;i++){
        ans += arr[name[i] - 'A'];
        int j = i+1; // i번째 오른쪽에 있으며 A가 아닌 문자 j
        while( j<n && name[j]=='A')j++;
        minMove = min(minMove,min(i + i + (n-j), n-j+n-j+i));
    }

    return ans;
}

int solution2(string name) 
{
    int answer = 0;
    int L2 = 0;
    int move = name.size() - 1;
    int length = name.size();

    for(int i=0; i<name.size();i++) 
    {   
        answer += min(name[i] - 'A','Z' - name[i] +1);        
        
        int L2_idx = i+1;
        while(L2_idx < length)
        {
            if(name[L2_idx] == 'A') L2_idx++;
            else break;
        }
        L2 = length - 1 - L2_idx + 1;
        move = min(move, i + L2 + min(i, L2));         
    }
    return answer + move;
}