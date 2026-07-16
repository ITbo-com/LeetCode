class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tot = nums.size();
        vector<int> v1(tot, 1);
        int Max=1;
        for(int i=1; i<tot; i++){
            for(int j=0; j<i;j++){
                if(nums[i] > nums[j]){
                    v1[i] = max(v1[i], v1[j]+1);
                    Max = max(Max, v1[i]);
                }
            }
        }
        return Max;
    }
};