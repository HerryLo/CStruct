#include <stdio.h>
#include <ctime>
#include <iostream>
#include <math.h>

using namespace std;

clock_t start, stop;

#define MAXN 10
double duration;

double fn1(int n, double a[], double x);
double fn2(int n, double a[], double x);

int main() {
    int arr[MAXN];
    for(int i=0;i<MAXN;i++){
        arr[i] = 6 - rand()%10;
        char str = i+1==MAXN?'\n':',';
        cout<<arr[i]<<str;
    }
    
    int max = 0, ThisNum = 0;
    for(int i = 0;i<MAXN;i++){
        ThisNum += arr[i];
        if(ThisNum > max){
            max = ThisNum;
        }else if(ThisNum < 0){
            ThisNum = 0;
        }
    }
    cout<<max<<endl;
    return 0;
};

double fn1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for(i=1;i<=n;i++)
        p+= (a[i] * pow(x, i));
    return p;
};

double fn2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for(i=n;i>0;i--)
        p = a[i-1]+ x*p;
    return p;
};
