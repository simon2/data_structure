//5.14ß
#define M 10

struct queuehead pockest[M];

void redix_sort(struct queuehead *input
                struct queuehead *output
                int n){
    int data, div, i;
    for(i=0, div=1; i<n; i++){
        div = div * M;
    }
    while((data=dequeue(input)) >= 0){
        i = (data/div)%M;
        enqueue(&pocket[i],data);
    }
    for(i=0;i<M;i++){
        while(data=dequeue(&pocket[i]) >= 0){
            enqueue(output, data)
        }
    }
}