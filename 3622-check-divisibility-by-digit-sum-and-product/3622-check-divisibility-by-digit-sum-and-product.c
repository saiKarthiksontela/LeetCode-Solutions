bool checkDivisibility(int n) {
    int temp = n;
    int sum = 0;
    int product = 1;
    while(temp>0){

        int last = temp%10;
        sum += last;
        product *= last;

        temp /= 10;
    }
    return n % (sum + product) == 0;  
}