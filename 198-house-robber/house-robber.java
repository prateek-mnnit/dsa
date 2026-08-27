class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        Integer dp[] = new Integer[n];
        return min(nums , 0 , dp);
    }
    int min(int[] nums , int i , Integer dp[]){
        if(i>=nums.length) return 0;
        if(dp[i] !=null) return dp[i];
        int nt = min(nums  , i+1 , dp);

        int take = nums[i] + min(nums , i+2,dp);
        return dp[i] = Math.max(nt,take);
    }

}