class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
       int n=2*k+1; //視窗大小
       vector<int> ans(nums.size(), -1);
       if (nums.size() < n)
            return ans;
       long long sum = 0;
       for (int i=0;i < n;i++)
       {
            sum += nums[i];
       }
       for (int i=k;i < nums.size()-k;i++)
       {
            ans[i]=sum/n;
            if (i+k+1 < nums.size())
            {
                sum = sum-nums[i-k]+nums[i+k+1];
            }
       }
       return ans;
    }
};