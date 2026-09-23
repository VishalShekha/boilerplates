class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int low = i;
            int high = i;

            while (low >= 0 && high < n &&
                   s.charAt(low) == s.charAt(high)) {
                result++;
                low--;
                high++;
            }

            low = i;
            high = i + 1;

            while (low >= 0 && high < n &&
                   s.charAt(low) == s.charAt(high)) {
                result++;
                low--;
                high++;
            }
        }

        return result;
    }
}