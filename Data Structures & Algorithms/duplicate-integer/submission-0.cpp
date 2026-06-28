class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // use unordered_set instead of vector 'check' because there's may negative number in vector 'nums'
        // .sixe() to get the length
        //
        unordered_set<int> check;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(check.find(x) == check.end()){
                check.insert(x);
                continue;
            }
            else {
                return true;
            }
        }
        return false;
    }
};