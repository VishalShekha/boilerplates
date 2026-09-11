class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;

        int max = 0;

        while(i < j){
            int area = (j - i) * Math.min(height[j], height[i]);

            if(area > max) max = area;

            if(height[j] > height[i]) i++;
            else j--;
        }

        return max;
    }
}