class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n=nums.size();

        //遞迴終止條件(Base Case)
        if(n <= 5)
        {
            sort(nums.begin(), nums.end());
            return nums[n-k];
        }
        //分組找中位數，並排序
        vector<int> medians;
        for(int i=0;i<nums.size();i+=5)
        {
            auto start=nums.begin()+i;
            auto end=nums.begin()+min(i+5,(int)nums.size());
            vector<int>numsi(start,end);
            sort(numsi.begin(),numsi.end());
            medians.push_back(numsi[numsi.size()/2]);
        }
        //找出中位數的中位數作為Pivot
        int p=findKthLargest(medians,(medians.size()+1)/2);

        //根據p進行分割
        vector<int> S1,S2,S3;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            if (x>p) S1.push_back(x);
            else if (x==p) S2.push_back(x);
            else  S3.push_back(x);
        }
        //判斷第k大的在哪個區塊內
        if (S1.size() >= k)
        {
            return findKthLargest(S1,k);
        }
        else if (S1.size() + S2.size() >= k)
        {
            return p;
        }
        else
        {
            return findKthLargest(S3,k - S1.size() - S2.size());
        }
    }
};