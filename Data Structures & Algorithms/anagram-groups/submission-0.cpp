class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>grps;
        for(auto& str: strs){
            string ss = str;
            sort(ss.begin(),ss.end());
            grps[ss].push_back(str);
        }
        vector<vector<string>>res;
        for(auto& group: grps){
            res.push_back(group.second);
        }
        return res;
    }
};
