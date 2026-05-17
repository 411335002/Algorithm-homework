class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);

        int a=robrange(nums,0,n-2); // 偷 0 ~ n-2
        int b=robrange(nums,1,n-1); // 偷 1 ~ n-1
        return max(a,b);
    }
private:
    int robrange(vector<int>& nums, int start, int end)
    {
        int rangesize = end-start+1;
        vector<int> dp(rangesize, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start],nums[start+1]);

        for (int i=2;i<rangesize;i++)
        {
            int current=start+i;
            dp[i]=max(dp[i-1],dp[i-2]+nums[current]);
        }
        return dp[rangesize-1];
    } 
};