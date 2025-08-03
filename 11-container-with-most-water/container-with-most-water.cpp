class Solution {
public:
    int maxArea(vector<int>& height) {
           int size = height.size()-1;
        int left=0,right=size;
        int maxarea = 0;
        while(left<right){
            int width = right - left;
            int current_height = min(height[left],height[right]);
            int area = current_height * width;
            maxarea = max(maxarea,area);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};