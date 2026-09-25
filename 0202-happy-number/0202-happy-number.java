class Solution {
    public boolean isHappy(int n) {
	    int temp = n;
	    int sum = 1;
	    if(temp==4|temp==0)
	    sum = 0;
	   while(temp!=1&temp!=4&temp!=0){
	       sum = 0;
	    while(temp>0){
	        int last = temp%10;
	        int sq = last * last;
	        sum += sq;
	        temp/=10;
	    }
	    temp=sum;
	   }
	   return sum == 1;
    }
}