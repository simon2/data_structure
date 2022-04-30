//recursion
int binary_search(int nums[], int n, int x){
    return _binary_search(nums, 0, n-1, x);
}

int _binary_search(int nums[], int l, int r, int x){
    if(r >= l){
        int mid = (l + r) / 2;

        if(nums[mid] == x){
            return mid;
        }else if(nums[mid] > x){
            return _binary_search(nums,l,mid-1,x);
        }else{
            return _binary_search(nums,mid+1,r,x);
        }
    }
    return -1;
}

//loop
int binary_search(int nums[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;

        if(nums[mid] == x){
            return mid;
        }else if(nums[mid] > x){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return -1;
}