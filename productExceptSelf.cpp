
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/description/
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n);
    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        output[i] = output[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}

int main()
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    const auto &res = productExceptSelf(nums);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
