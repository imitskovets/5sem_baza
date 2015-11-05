//
// Created by van_mit on 05.11.15.
//
#include <iostream>
#include <math.h>
#include <stdio.h>

double myFunc(double x, double y, double h, double a, double b){
    return  ((1 + a * h) * y + b * h * x);
}
double func(double x, double h, double a, double b){
    return ((1 + b / pow(a, 2)) * exp(a * x) - (b * x) / a - b / a * a);
}

void plot()
{
    FILE *gp = popen("gnuplot -persist","w"); // gp - дескриптор канала

    if (gp == NULL)
    {
        printf("Error opening pipe to GNU plot.\n");
        exit(0);
    }

    fprintf(gp, "plot 'Y.txt' u 1:2 w linesp, 'myY.txt' u 1:2 w linesp\n");
    pclose(gp);
}

int main(){
    double N = 1000;
    double a = 1;
    double b = 1;
    double x_start = 0;
    double x_end = 2;
    double h;
    double norma = 1;
    //std::cout << "N = " ;
   //std::cin >> N;
    N++;
    h = (x_end - x_start) / (N - 1);
    /*long double X[(long int)(N+1)];
    long double myY[(long int)(N+1)];
    long double Y[(long int)(N+1)];*/
    double X;
    double Y;
    double myY;
    double errorY;
    double tmp = 0;
    myY = 1;
    Y = 1;
    X = x_start;
    FILE* fd1 = fopen("myY.txt","w");
    FILE* fd2 = fopen("Y.txt","w");
    fprintf(fd1,"%f\t%f\n", X, myY);
    fprintf(fd2,"%f\t%f\n", X, Y);
    for (long int i = 0; i < N; i++ ){
        X += h;
        tmp = myY;
        myY = myFunc(X,tmp,h,a,b);
        Y = func(X,h,a,b);
        fprintf(fd1,"%f\t%f\n", X, myY);
        fprintf(fd2,"%f\t%f\n", X, Y);
        errorY += h * pow((Y - myY), 2);
    }
    plot();
    norma = sqrt(errorY);
    std::cout << norma << std::endl;

}
