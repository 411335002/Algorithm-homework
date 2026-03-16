class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int p, int r)
    {
        if (p >= r)
            return;
        int q = (p+r)/2;
        mergeSort(nums, p, q);
        mergeSort(nums, q+1, r);
        merge(nums, p, q, r);
    }
    void merge(vector<int>& nums, int p, int q, int r)
    {
        int nl = q-p+1;
        int nr = r-q;
        int* L = new int[nl];
        int* R = new int[nr];
        for (int i=0;i<nl;i++)
            L[i]=nums[p+i];
        for (int j=0;j<nr;j++)
            R[j]=nums[q+j+1];
        int i=0;
        int j=0; 
        int k=p;
        while (i<nl && j<nr)
        {
            if (L[i] <= R[j])
            {
                nums[k] = L[i];
                i = i + 1;
            }
            else
            {
                nums[k] = R[j];
                j = j + 1;
            }
            k = k + 1;
        }
        while (i<nl)
        {
            nums[k] = L[i];
            i = i + 1;
            k = k + 1;
        }
        while (j<nr)
        {
            nums[k] = R[j];
            j = j + 1;
            k = k + 1;
        } 
        delete[] L;
        delete[] R;
    }
};