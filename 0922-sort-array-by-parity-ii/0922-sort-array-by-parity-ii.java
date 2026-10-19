class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int n = nums.length;

        int E = 0, O = 1;
        while(E<n && O<n){

            if(nums[E] % 2 == 0)
                E += 2;
            else if(nums[O] % 2 == 1)
                O += 2;
            else{

                int temp = nums[E];
                nums[E] = nums[O];
                nums[O] = temp;
                E += 2;
                O += 2;
            }
        }
        return nums;
    }
}