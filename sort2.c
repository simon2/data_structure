void bubbleSort(int nums[], int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++)
            if(nums[j]<nums[j-1])
                swap(&nums[j],&nums[j-1]);
    }
}

void selectSort(int nums[], int n){
    int i;
    for(i=0;i<n;i++){
        int min_idx = i;
        int j;
        for(j=i;j<n;j++){
            if(nums[j]<nums[min_idx])
                min_idx = j;
        }
        swap(&nums[min_idx],&nums[i]);
    }
}

void insertionSort(int sum[], int n){
    int i;
    for(i=0;i<n;i++){
        int key = nums[i];

        int j = i - 1;
        while(j >= 0 && nums[j] > key){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}

void mergesort(int nums[], int n){
    _merge_sort(nums, 0, n-1);
}

void _merge_sort(int nums[], int l, int r){
    int m = (l + r) / 2;
    _merge_sort(nums, l, m);
    _merge_sort(nums, m+1, r);
    merge(nums, l, m, r);
}

void merge(int nums[], int l, int m, int r){
    int i, j;
    
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(i = 0; i<n1; i++){
        L[i] = nums[l+i];
    }
    for(i = 0; i<n1; i++){
        R[i] = nums[m + 1 + i];
    }

    i = j = 0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            nums[l+i+j] = L[i];
            i++;
        }else{
            nums[l+i+j] = R[j];
            j++;
        }
    }
    while(i<n1){
        nums[l+i+j] = L[i];
        i++;
    }
    while(j<n2){
        nums[l+i+j] = R[i];
        j++;
    }
    free(L); free(R);
}

void quickSort(int nums[], int n){
    _quick_sort(nums, 0, n-1);
}

void _quick_sort(int nums[], int l, int r){
    if(l < r){
        int pi = partition(nums, l, r);
        _quick_sort(nums, l, pi-1);
        _quick_sort(nums, pi+1, r);
    }
}

int partition(int nums[], int l, int r){
    int pivot = nums[r];
    int i = l;

    int j;
    for(j=l;j<=r-1;j++){
        if(nums[j]<=pivot){
            swap(&nums[i],nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[r]);
    return i;
}

int partition2(int nums[], int l, int r){
    int pivot = nums[r];
    int i = l;

    int j = r - 1;
    while(j > l){
        while(nums[i] < pivot){
            i++;
        }
        while(nums[j] > pivot){
            j--;
        }
        swap(&nums[i], &nums[j]);
    }
    swap(&nums[i], &nums[r]);
    return i;
}

void heapsort(int nums[], int n){
    heapify(nums, n);
    for(i = n-1; i>=0; i--){
        swap(&nums[0],&nums[i]);
        sink(nums, i, 0);
        // heapify(nums, i);
    }
}

void counting_sort(int nums[], int n){
    int high = max(nums, n);
    int low = min(nums, n);
    int size = high - low + 1;

    int *output = (int *)malloc(sizeof(int)*n);
    int *count = (int *)malloc(sizeof(int)*size);

    int i;
    for(i = 0;i<size;i++){
        count[i] = 0;
    }
    for(i=0;i<n;i++){
        count[nums[i]-low]++;
    }
    for(i=1;i<size;i++){
        count[i] += count[i-1];
    }
    for(i=0;i<n;i++){
        int num = nums[i];
        int pos = count[num-low] - 1;
        output[pos] = nums[i];
        count[nums-low]--;
    }
}

void radix_sort(int nums[], int n){
    int radix = 10;
    int mx = max(nums[],n);

    int exp;
    for(exp=1;mx/exp>0;exp*=radix){
        radix_counting_sort(nums, n, exp, radix);
    }
}

void radix_counting_sort(int nums[], int n, int exp, int radix){

    int *output = (int *)malloc(sizeof(int)*n);
    int *count = (int *)malloc(sizeof(int)*radix);

    int i;
    for(i = 0;i<radix;i++){
        count[i] = 0;
    }
    for(i=0;i<n;i++){
        count[nums[i]/exp%radix]++;
    }
    for(i=1;i<radix;i++){
        count[i] += count[i-1];
    }
    for(i=n-1;i>=0;i--){
        int num = nums[i];
        int pos = count[num/exp%radix] - 1;
        output[pos] = nums[i];
        count[nums/exp%radix]--;
    }
    for(i=0;i<n;i++){
        nums[i] = output[i];
    }
}


int hash(int num){
    return num / 10;
}

void bucket_sort(int nums[], int n){
    int buckets[N][N];
    int sizes[N];

    int i;
    for(i=0;i<N;i++){
        sizes[i] = 0;
    }

    for(i = 0; i<N; i++){
        int num = nums[i];
        int hash_code = hash(num);
        insert(buckets[hash_code],sizes[hash_code]++, num);
    }

    for(i=0;i<N;i++){
        radix_counting_sort(buckets[i], sizes[i],1,10);
    }

    int j,k = 0;
    for(i=0;i<N;i++){
        for(j=0;j<sizes[i];j++){
            nums[k++] = buckets[i][j];
        }
    }
}

void insert(int bucket[], int size, int num){
    int i;
    // for(i = size-1;i>=0;i--){
    //     if(bucket[i]>num){
    //         bucket[i+1] = bucket[i];
    //     }else{
    //         break;
    //     }
    //     bucket[i+1] = num;
    // }
    bucket[size] = num;
}