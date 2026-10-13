class Solution {
public:
    bool checkInclusion(std::string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false;
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        // Count frequencies for the first window of size n1
        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        if (count1 == count2) return true;
        
        // Slide the window over s2
        for (int i = n1; i < n2; i++) {
            // Add the new character entering the window on the right
            count2[s2[i] - 'a']++;
            // Remove the old character leaving the window on the left
            count2[s2[i - n1] - 'a']--;
            
            if (count1 == count2) return true;
        }
        
        return false;
    }
};