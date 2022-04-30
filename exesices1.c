//1.1(1)
#include <math.h>

double fp(double x){
    if(x==0) return 1.0;
    else return sin(x)/x;
}

//1.1(2)
#include <stdio.h>

double integral(double a, double b, int m){
    double fp(double);
    double h = (b-a)/2/m;
    double c3=0; int k;
    for(k=1;k<=m;k++){
        c3 += fp(a+(2*k-1)*h);
    }
    c3 *= 4;
    double c4 = 0;
    for(k=1;k<=m-1;k++){
        c4 += fp(a+2*k*h);
    }
    c4 *= 2;
    return h/3*(fp(a)+fp(b)+c3+c4);
}

//1.2(1)
#include <stdio.h>
main(){
    int a[20][20],i,j,n;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

//1.2(2)
int comb(int n, int r){
    if(r==0 || n==r) return 1;
    return comb(n-1,r)+comb(n-1,r-1);
}

//1.3(1)
double rect(double a, double b, int n){
    double f(double);
    double h,S = 0.0;
    int i;
    h = (b - a) / n;
    w = 0.0;
    for(i=0;i<n;i++){
        w += f(a + i * h);
    }
    S = w * h;
    return S;
}

//1.3(2)
double integral(double a, double b, double eps){
    double rect(double a, double b, int n);
    double S, Sp;
    int n = 2;
    S = rect(a,b,n);
    do{
        Sp = S;
        n = n * 2;
        S = rect(a,b,n);
    }while(fabs((S-Sp)/S) > eps)
    return S;
}
