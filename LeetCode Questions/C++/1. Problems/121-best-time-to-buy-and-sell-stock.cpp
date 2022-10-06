class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        // Setting initial values of minimum and maximum values
        int min = INT_MAX;
        int maximum = 0;
        
        // Iterating through the vector
        for(int i = 0; i < prices.size(); i++){
            // Assigning new min if the current element is smaller than the current min value
            if(prices[i] < min){
                min = prices[i];
            }
            
            // The maximum is the greater of 2 values: 
            // 1. Itself 
            // 2. The difference between todays price and the smallest price ever (!)
            maximum = max(maximum, prices[i] - min);
        }
        // Returning solution 
        return maximum;
    }
};