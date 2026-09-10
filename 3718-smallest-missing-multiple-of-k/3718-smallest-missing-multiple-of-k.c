int missingMultiple(int* nums, int numsSize, int k) {
    
    int multiple = k;
    int found;

    while(1){

        found = 0;

        for(int i=0;i<numsSize;i++){

            if(nums[i] == multiple){
                found = 1;
                break;
            }
        }

        if(found == 0){
            
            return multiple;    
        }

        multiple += k;
    }


}