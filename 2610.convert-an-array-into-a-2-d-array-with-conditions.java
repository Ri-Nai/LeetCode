/*
 * @lc app=leetcode.cn id=2610 lang=java
 * @lcpr version=30204
 *
 * [2610] 转换二维数组
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        // sort nums
        Arrays.sort(nums);
        // create a list of lists
        List<List<Integer>> result = new ArrayList<>();
        // iterate through nums
        for (int i = 0, j = 0; i < nums.length; i++) {
            // add nums[i] to result
            while (j < nums.length && nums[j] == nums[i]) {
                if (result.size() < j - i + 1) {
                    result.add(new ArrayList<>());
                }
                result.get(j - i).add(nums[j]);
                j++;
            }
            i = j - 1;  
        }
        return result;
    }
}
//   @lc code=end



/*
// @lcpr case=start
// [1,3,4,1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

