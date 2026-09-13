class Solution {

    public int characterReplacement(String s, int k) {
        int[] cnt = new int[26];

        int i = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int j = 0; j < s.length(); j++) {

            cnt[s.charAt(j) - 'A']++;

            maxFreq = Math.max(maxFreq, cnt[s.charAt(j) - 'A']);

            int windowLength = j - i + 1;

            if (windowLength - maxFreq > k) {
                cnt[s.charAt(i) - 'A']--;
                i++;
            }

            ans = Math.max(ans, j - i + 1);
        }

        return ans;
    }
}
