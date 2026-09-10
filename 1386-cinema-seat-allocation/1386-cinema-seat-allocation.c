#define TABLE_SIZE 20011

typedef struct {
    long long row;
    int mask;
    int used;
} HashEntry;

int findIndex(HashEntry table[], long long row) {

    int index = row % TABLE_SIZE;

    while(table[index].used && table[index].row != row) {
        index = (index + 1) % TABLE_SIZE;
    }

    return index;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {

    HashEntry table[TABLE_SIZE] = {0};

    long long answer = 2LL * n;

    int blockA = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4);
    int blockB = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
    int blockC = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);

    for(int i = 0; i < reservedSeatsSize; i++) {

        long long row = reservedSeats[i][0];
        int seat = reservedSeats[i][1];

        int index = findIndex(table, row);

        if(table[index].used == 0) {
            table[index].used = 1;
            table[index].row = row;
            table[index].mask = 0;
        }

        table[index].mask |= (1 << (seat - 1));
    }

    for(int i = 0; i < TABLE_SIZE; i++) {

        if(table[i].used == 0)
            continue;

        int mask = table[i].mask;

        int groups;

        if((mask & blockA) == 0 && (mask & blockC) == 0) {
            groups = 2;
        }
        else if((mask & blockA) == 0 ||
                (mask & blockB) == 0 ||
                (mask & blockC) == 0) {
            groups = 1;
        }
        else {
            groups = 0;
        }

        answer += groups - 2;
    }

    return (int)answer;
}