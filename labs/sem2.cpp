//
// Created by van_mit on 05.11.15.
//
#include <iostream>
#include <math.h>



double fgrob(double x){
    double result = 0;
    if ((x <= 3) && (x >= -3)){
        result = 1;
    }
    return result;
}

double fkolokol(double x){
    double result = 0;
    if ((x <= 3) && (x >= -3)){
        result = ((double)exp(- x * x * 0.5)-exp(- 4.5));
    }
    return result;
}

int main(){
    int n = 100;
    double start = -20;
    double end = 20;
    int ksi = 2;
    double tkrit = 16.0 / abs(ksi);
    double x[(2 * n) ];
    double h = (end - start) / (2 * n);
    double tau = tkrit / (2 * n);
    double f[2 * n ][2 * n + 1];
    double beta = ksi * tau / h;
    double alfa = 1 - beta;
    for (int j = 0; j < 2 * n + 1 ; j++){
        x[j] = 20 * ((double)j/n - 1);
        f[j][0] = 0;
        f[0][j] = fkolokol(x[j]);
    }
    for (int j = 0; j < 2 * n - 1 ; j++){
        for (int i = 1; i < 2 * n + 1 ; i++){
            f[j + 1][i] = alfa * f[j][i] + beta * f[j][i - 1];
            std::cout << f[j][i] << std::endl;
        }
    }
    FILE* fd = fopen("second.txt","w");
    for (int i = 0; i < 2 * n + 1; i++ ){
        fprintf(fd,"%f\t%f\n", x[i], f[n][i]);

    }
}

