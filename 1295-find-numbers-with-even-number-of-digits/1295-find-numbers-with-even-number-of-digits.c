int findNumbers(int* nums, int numsSize) {
int e_count = 0;
    for(int i=0;i<numsSize;i++){
        int count = 0;
        int temp = nums[i];
        while(temp>0){
            count ++;
            temp /= 10;
        }
        if(count % 2 ==0){
            e_count ++;
        }
    }

    return e_count;
}