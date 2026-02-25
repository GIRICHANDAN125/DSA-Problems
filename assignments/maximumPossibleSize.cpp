class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int num : nums)
            mp[num]++;
        
        int count = 0;
        
        for(auto it : mp) {
            if(it.second % 2 != 0)
                count++;
        }
        
        return count;
    }
};