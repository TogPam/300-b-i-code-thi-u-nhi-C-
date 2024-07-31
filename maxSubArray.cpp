// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int maxSubArray(vector<int> nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];

    int curSum = 0;
    int maxSum = nums[0];
    for (int num : nums)
    {
        curSum = max(curSum, 0);
        curSum += num;
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main()
{
    vector<int> a = {5, 4, -1, 7, 8};
    cout << maxSubArray(a);
    return 0;
}
