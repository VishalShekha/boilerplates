class Solution {
    public String longestPalindrome(String s) {
        
        int right = 0, left = 0;

        for(int i = 0; i < s.length(); i++){
            int len1 = checkpali(s, i, i);
            int len2 = checkpali(s, i, i+1);
            int len = Math.max(len1, len2);

            if(len > right - left){
                left = i - (len-1) /2 ;
                right = i + len/ 2;
            }
        }

        return s.substring(left, right+1);

    }

    public int checkpali(String s, int left, int right){
        
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            left--; right++;
        }
        return right - left - 1;
    }
}