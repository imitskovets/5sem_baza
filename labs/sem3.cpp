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
    int n = 80;
    double start = -20;
    double end = 20;
    int ksi = 5;
    double tkrit = 16.0 / abs(ksi);
    double x[(2 * n) ];
    double h = (end - start) / (2 * n);
    double tau = tkrit / (2 * n);
    double f[2 * n ][2 * n + 1];
    double omega = h + ksi * tau;
    double gamma = ksi * tau / h;
    double gam = 4 / gamma;
    double a[(2 * n)];
    double b[(2 * n)];
    double lambda2 = ksi * tau / omega;
    double yold = 0;
    a[0] = 0;
    b[0] = 0;
    //check last points
    for (int i = 0; i < 2 * n; i++){
        x[i] = 20 * ((double)i/n - 1);
        f[0][i] = fkolokol(x[i]);
    }

    for (int j = 0; j < 2 * n; j++){
        f[j][0] = 0;
        f[j][2 * n - 1] = 0;
    }

    for (int j = 0; j < 2 * n - 1; j++){
        double *y = nullptr;
        y = new double [(2 * n)];
        //double y[(2 * n)];
        double nu2 = h * yold / omega;
        //double D[(2 * n)];
        double *D = nullptr;
        D = new double [(2 * n)];
        for (int i = 1; i < 2 * n - 1; i++){
            a[i + 1] = 1 / (a[i] - gam);
            D[i] = f[j][i] - (f[j][i + 1] - f[j][i - 1]) / gam;
            b[i + 1] = (b[i] + D[i] * gam) / (a[i] - gam);
        }
        for (int i = 2 * n - 2; i >= 0; i--){
            y[(2 * n - 1)] = (nu2 + lambda2 * b[(2 * n - 1)]) / (1 - lambda2 * a[(2 * n - 1)]);
            f[j + 1][i] = y[i];
            y[i] = a[i+1] * y[i + 1] + b[i + 1];
        }
        yold = y[(2 * n - 1)];
        delete [] y;
        delete [] D;

    }

    FILE* fd = fopen("thirdSem.txt","w");
    for (int i = 0; i < 2 * n; i++ ){
        fprintf(fd,"%f\t%f\n", x[i], f[50][i]);

    }

    FILE* fd1 = fopen("thirdSem2.txt","w");
    for (int j = 0; j < 2 * n; j++){
        fprintf(fd1, "%i\t%i\n", j , (2 * n + 1));
        for (int i = 0; i < 2 * n + 1; i++) {
            fprintf(fd1, "%i\t%f\t%f\n", i, x[i], f[j][i]);
        }
        fprintf(fd1, "\n\n");
    }



}
