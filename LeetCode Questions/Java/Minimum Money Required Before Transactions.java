/*

https://leetcode.com/problems/minimum-money-required-before-transactions/

*/
class Solution {
    public long minimumMoney(int[][] ts) {
        
        long spend=0, cashback=0, cost=0;
        
        for(int[] t: ts)
        {
            if(t[0]>t[1])
            {
                spend+=t[0]-t[1];
                cashback=Math.max(cashback, (long)t[1]);
            }
            else
            {
                cost=Math.max(cost, (long)t[0]);
            }
        }
        return spend+Math.max(cashback, cost);
        
    }
}
