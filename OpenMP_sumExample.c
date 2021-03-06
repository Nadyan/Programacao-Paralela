#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int i, n;
    float a[100], b[100], sum;
    
    n = 100;
    
    #pragma omp parallel for num_threads(8)
    for(i = 0; i < n; i++){
        a[i] = b[i] = i * 1.0;
    }

    sum = 0.0;
    
    #pragma omp parallel for reduction(+: sum) num_threads(8) 
    for(i = 0; i < n; i++){
        sum = sum + (a[i] * b[i]);
    }
    
    printf("Sum = %f\n", sum);

    return 0;
}
