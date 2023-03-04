#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
void SetColor(int text, int background) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
using namespace std;
const int n = 5, m = 5;
int tp(int v[], int n) {
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
	srand(time(NULL)); 
    int i, j;
    int mat1[n][m], mat2[n][m], mat3[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat1[i][j] = rand() % 50;
            mat2[i][j] = rand() % 50 - 0.3;
            mat3[i][j] = rand() % 50 - 0.2;
        }
    }
    int max1[n], max2[n], max3[n];
    for(i = 0; i < n; i++) {
        int p1[m], p2[m], p3[m];
        for (j = 0; j < m; j++) {
            p1[j] = mat1[i][j];
            p2[j] = mat2[i][j];
            p3[j] = mat3[i][j];
        }
        max1[i] = tp(p1, m);
        max2[i] = tp(p2, m);
        max3[i] = tp(p3, m);
    }
    SetColor(14, 0);
    cout << "Матриця 1:" << endl;
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }
    SetColor(10, 0);
    cout << "Максимальні елементи матриці 1:" << endl;
    for(i = 0; i < n; i++) {
        cout << max1[i] << " ";
    }
    cout << endl;
    SetColor(14, 0);
    cout << "Матриця 2:" << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }
    SetColor(10, 0); 
    cout << "Максимальні елементи матриці 2:" << endl;
    for(i = 0; i < n; i++) {
        cout << max2[i] << " ";
    }
    cout << endl;
    SetColor(14, 0);
     cout << "Матриця 3:" << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }
    SetColor(10, 0);
    cout << "Максимальні елементи матриці 3:" << endl;
    for(i = 0; i < n; i++) {
        cout << max3[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
