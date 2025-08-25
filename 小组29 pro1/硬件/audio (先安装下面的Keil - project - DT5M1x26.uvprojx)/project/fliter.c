#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DT5M1x26.h"

#define PI 3.1415926

/* 生成带通滤波器 */
void bandPassFilter(double f1, double f2, double fs, int N, vu32 *b, vu32 *a) {
    int i, j;
    double w1 = 2 * PI * f1 / fs;
    double w2 = 2 * PI * f2 / fs;
    double bw = w2 - w1;
    int M = N / 2;
    double H[M];
    double w[M];

    /* 计算带通滤波器的理想幅频特性 */
    for (i = 0; i < M; i++) {
        if (i == M / 2) {
            H[i] = bw / PI;
        } else {
            H[i] = sin(bw * (i - M / 2.0)) / (PI * (i - M / 2.0));
        }
        w[i] = 0.54 - 0.46 * cos(2 * PI * i / N);  /* 汉宁窗函数 */
        H[i] *= w[i];
    }

    /* 求出带通滤波器的差分方程系数 */
    for (i = 0; i < N; i++) {
        b[i] = 0;
        a[i] = 0;
    }
    b[0] = H[0];
    a[0] = 1;
    for (i = 1; i < M; i++) {
        b[i] = H[i];
        a[i] = 2 * cos(w1 * i);
    }
    for (i = N - 1, j = 1; i >= M; i--, j++) {
        b[i] = H[j];
        a[i] = 2 * cos(w2 * j);
    }
}

/* 带通滤波函数 */
void filter(double *x, double *y, int N, vu16 *b, vu16 *a) {
    int i, j;
    double sum1, sum2;

    for (i = 0; i < N; i++) {
        sum1 = sum2 = 0;
        for (j = 0; j <= i; j++) {
            sum1 += b[j] * x[i - j];
        }
        for (j = 1; j <= i; j++) {
            sum2 += a[j] * y[i - j];
        }
        y[i] = sum1 - sum2;
    }
}