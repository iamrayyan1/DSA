#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSW(vector<int> &nums, int k)
{
    vector<int> ans;
    priority_queue<int> p;

    for (int i = 0; i < k; i++)
    {
        p.push(nums[i]);
    }

    ans.push_back(p.top());

    for (int i = k; i < nums.size(); i++)
    {
        p.push(nums[i]);

        while (p.top() == nums[i - k])
        {
            p.pop(); // removing the element that is no longer needed
        }

        ans.push_back(p.top());
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7, 12, 22, -5, 8};
    int k = 3;

    vector<int> max = maxSW(nums, k);

    for (int i; i < max.size(); i++)
    {
        cout << max[i] << " ";
    }
}
