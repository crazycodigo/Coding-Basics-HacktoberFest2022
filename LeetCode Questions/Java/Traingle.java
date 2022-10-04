class Traingle {
    public int[][] dp = new int[201][201];
    public int minimumTotal(List<List<Integer>> triangle) {
        for(int i=0;i<dp.length;i++){
            Arrays.fill(dp[i],10001);
        }
        return minimumTotali(triangle , triangle.get(0).get(0), 0 , 0);
    }
    public int minimumTotali(List<List<Integer>> triangle , int element ,int ind , int eleInd) {
        if(ind == triangle.size()-1){
            return element;
        }
        if(dp[ind][eleInd] != 10001){
            return dp[ind][eleInd];
        }
        int left = Integer.MAX_VALUE;
        int right = Integer.MAX_VALUE;
        if(ind+1 < triangle.size()) {
            left = element + minimumTotali(triangle, triangle.get(ind + 1).get(eleInd), ind + 1, eleInd);
            if(eleInd < triangle.get(ind+1).size()) {
                right = element + minimumTotali(triangle,triangle.get(ind + 1).get(eleInd + 1),ind+1,eleInd+1);
            }
        }
        dp[ind][eleInd] = Math.min(left,right);
        return dp[ind][eleInd];
    }
}