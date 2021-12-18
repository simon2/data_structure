#define N 10

int hash(int num){
    return num / 10;
}


void insert(int bucket[], int size, int num){
    int i;
    for(i=size-1;i>=0;i--){
        if(bucket[i]>num)
            bucket[i+1] = bucket[i];
        else
            break;
    }
    bucket[i+1] = num;
}

void bucket_sort(int nums[], int n){
    int buckets[N][N];
    int sizes[N];
    int i;
    for(i=0;i<N;i++)
        sizes[i] = 0;
    
    for(i=0;i<n;i++){
        int num = nums[i];
        int hash_code = hash(num);
        insert(buckets[hash_code], sizes[hash_code]++, num);
    }

    int j, k = 0;
    for(i=0;i<N;i++){
        for(j=0;j<sizes[i];j++){
            nums[k++] = buckets[i][j];
        }
    }
}