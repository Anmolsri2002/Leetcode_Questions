class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i]);
            profit=max(profit,prices[i]-mini);
            
        }
       

        return profit;
    }
};