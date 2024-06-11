#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> nums, modes;
int cnt[8001]; // 최빈값
int N, modeCnt;
double sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    nums = vector<int>(N);
    modes.reserve(N);
    for (int &num : nums)
    {
        cin >> num;
        sum += num;
        ++cnt[num + 4000];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < 8001; ++i)
    {
        if (cnt[i] > modeCnt) // 다르면 초기화
        {
            modes.clear();
            modeCnt = cnt[i];
            modes.push_back(i - 4000);
        }
        else if (cnt[i] == modeCnt) // 같으면 추가
        {
            modes.push_back(i - 4000);
        }
    }

    cout << round(sum / N) + 0.0 << "\n"; //-0 방지
    cout << nums[N / 2] << "\n";
    cout << (modes.size() == 1 ? modes.front() : modes[1]) << "\n"; // 크기가 1이면 맨 앞, 아니면 2번째
    cout << nums.back() - nums.front();
    return 0;
}