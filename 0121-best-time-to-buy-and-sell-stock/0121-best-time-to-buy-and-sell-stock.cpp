class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minpr=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            int price=prices[i];
            minpr=min(minpr,price);
            maxprofit=max(maxprofit,price-minpr);
        }
        return maxprofit;
    }
};