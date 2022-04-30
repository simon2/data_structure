//3.1
#include <stdio.h>

int search(int n,int[] b,int k){
    int i,j,p;
    i = 0;
    j = n-1;
    while(i <= j){
        p = (i+j)/2;    //binary search
        if(b[p]<=k){
            i = p + 1;
        }else{
            j = p - 1;
        }
    }
    if(j >= 0 && b[j] == k){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int a[] = {3,6,7,10,13,15,19};
    if(search(7,a,14)){
        printf("......");
    }else{
        printf("......");
    }
    retrn 0;
}

//3.2(1ß)
int bin_search(int a[],int n,int key){
    int l,m,u;
    l = 0; u = n - 1;
    while(l <= u){
        m = (l + u) / 2;
        if(a[m] < key)
            l = m + 1;
        else if(a[m] > key)
            u = m - 1;
        else
            return m;
    }
    return -1;
}
//3.2(3)
int bin_search_first(int a[], int n, int key){
    int l, m, u;
    int p;
    l = -1; u = n;
    while(l + 1 != u){
        m = (l + u) / 2;
        if(a[m] < key){
            l = m;
        }else{
            u = m;
        }
    }
    p = u;
    if(p == n/*l == n-1*/|| a[p] != key){
        return -1;
    }else{
        return p;
    }
}