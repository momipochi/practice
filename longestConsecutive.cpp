
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    size_t n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    set<int> s;
    for (size_t i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }

    auto iter = s.begin();
    signed int count = *iter;
    unsigned int max = 0;
    unsigned int curr = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (*iter == count)
        {
            curr++;
        }
        else if(curr > max)
        {
            max = curr;
            curr = 1;
            count = *iter;
            
        }else{
            curr = 1;
            count = *iter;
        }
        iter++;
        count++;
    }
    return curr > max ? curr : max;
}

int main()
{
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << longestConsecutive(nums);
}
