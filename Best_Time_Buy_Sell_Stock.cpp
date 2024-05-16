//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include <bits/stdc++.h>
#include <vector>
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=i+1;j<n;j++)
#define cc cout<<
using namespace std;


int bestProfit(vector<int>& prices)
{
    int n = prices.size(), profit = 0,buy = 0, sell = 0, max = 0;

    fi(n)
    {
        buy = prices[i];
        fj(n)
        {
            sell = prices[j];
            if(sell<=buy) break;
            profit = sell - buy;

            if(max<=profit) max = profit;
        }
    }
    return max;
}


int main()
{
    vector<int> prices = {7,6,4,3,1};
    cc bestProfit(prices);
    return 0;
}
