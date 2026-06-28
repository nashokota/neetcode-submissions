class Solution {
public:
    string minWindow(string s, string t) {
         if (s.length() < t.length()) {
            return "";
        }

        // Array to keep track of the count of each character needed
        vector<int> count(128, 0);
        for (char c : t) {
            count[c]++;
        }

        int required = t.length(); // Total characters we still need to match
        int min_len = INT_MAX;     // Length of the minimum window found
        int min_start = 0;         // Starting index of the minimum window
        int left = 0;              // Left pointer of the sliding window

        // Expand the window by moving the right pointer
        for (int right = 0; right < s.length(); right++) {
            // If the current character is needed, decrement the required count
            if (count[s[right]] > 0) {
                required--;
            }
            // Decrement the count of the current character in our map
            count[s[right]]--;

            // When all characters are matched, try to shrink the window from the left
            while (required == 0) {
                // Update the minimum window if the current one is smaller
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }
                
                // Remove the left character from the window
                count[s[left]]++;
                
                // If the removed character was required, the window is no longer valid
                if (count[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        // Return the minimum window substring, or an empty string if none was found
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
