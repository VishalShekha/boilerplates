class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i = 0;
        int ans = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        for(int j = 0; j < s.length(); j++){
            map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0) + 1);
            while(map.get(s.charAt(j)) > 1){
                map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 1) - 1);
                i++;
            }
            ans = Math.max(ans, j - i + 1);
        }

        return ans;
    }
}