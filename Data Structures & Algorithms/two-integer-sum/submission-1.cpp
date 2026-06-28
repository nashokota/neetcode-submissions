class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ans =0;
        for(int i=0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    vector<int>ans;
                    ans.push_back(i);ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};
