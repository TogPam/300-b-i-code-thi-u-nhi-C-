//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order./
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]./

#include <bits/stdc++.h>
#include <vector>
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=i+1;j<n;j++)
using namespace std;

vector<int> Two_Sum(vector<int>& nums, int target)
{
    int n = nums.size();

    fi(n)
    {
        fj(n)
        {
            if(nums[i]+nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> a = {2,7,11,15};
    int target = 9;

    vector<int> solve = Two_Sum(a,target);

    cout<<"[";
    fi(solve.size())
    {
        cout<<" "<<solve[i]<<" ";
    }
    cout<<"]\n";
    return 0;
}
