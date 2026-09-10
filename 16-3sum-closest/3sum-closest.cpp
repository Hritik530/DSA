class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int current_sum = nums[i] + nums[j] + nums[k];
                    
                    if (abs(target - current_sum) < abs(target - closest_sum)) {
                        closest_sum = current_sum;
                    }
                }
            }
        }
        return closest_sum;

    }
};