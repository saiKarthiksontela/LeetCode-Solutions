int stoneGameVIII(int* stones, int stonesSize) {

    int n = stonesSize;

    long long prefix[n];

    prefix[0] = stones[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + stones[i];
    }

    long long best = prefix[n - 1];

    for(int i = n - 2; i >= 1; i--) {

        long long take = prefix[i] - best;

        if(take > best) {
            best = take;
        }
    }

    return (int)best;
}