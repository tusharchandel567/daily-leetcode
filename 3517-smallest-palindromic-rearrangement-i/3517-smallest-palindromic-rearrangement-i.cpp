class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count characters
        for (char c : s) {
            freq[c - 'a']++;
        }

        string half = "";
        char middle = '\0';

        // Build smallest first half
        for (int i = 0; i < 26; i++) {

            half += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2 == 1) {
                middle = 'a' + i;
            }
        }

        string secondHalf = half;
        reverse(secondHalf.begin(), secondHalf.end());

        if (middle != '\0') {
            return half + middle + secondHalf;
        }

        return half + secondHalf;
    }
};