class Solution {

    static int l_b(int a[], int key){
        int n = a.length;
        int l=0,h=n-1;
        int ans = -1;

        while(l<=h){
            int mid = (l+h)/2;

            if(a[mid] == key){
                ans = mid;
                h = mid-1;
            }
            else if(key < a[mid])
                h = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }

        static int u_b(int a[], int key){
        int n = a.length;
        int l=0,h=n-1;
        int ans = -1;

        while(l<=h){
            int mid = (l+h)/2;

            if(a[mid] == key){
                ans = mid;
                l = mid+1;
            }
            else if(key < a[mid])
                h = mid-1;
            else
                l = mid+1;
        }
        return ans;
    }


    public int[] searchRange(int[] nums, int target) {
        int lbound = l_b(nums,target);
        int ubound = u_b(nums,target);
        int[] result = {lbound, ubound};
        return result;
    }
}