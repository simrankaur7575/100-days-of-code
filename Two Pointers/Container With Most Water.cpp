 /*
 QUES - Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */

 int maxArea(vector<int> &height) {
            int end = height.size() - 1, start = 0;
            int maxVol = 0;

            while(start < end)
            {
                maxVol = max(maxVol, (end - start) * min(height[start], height[end]));

                if (height[start] < height[end]) {
                    start++;
                } else {
                    end--;
                }
            }
            return maxVol;
        }
