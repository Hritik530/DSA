class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low=0, high=0;
        int minlen = n+1;
        int temp = 0;
        while(high<n){
            temp += nums[high];
            while(temp >= target){
                if(high - low + 1 < minlen){
                    minlen = high - low +1;
                }
                temp -= nums[low];
                low++;
            }
            high++;
        }
        if(minlen == n+1){
            return 0;
        }
        return minlen;
    }
};