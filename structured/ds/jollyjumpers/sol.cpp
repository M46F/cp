# include<iostream>
# include<climits>
#include <stdio.h>
#include <math.h>
#include <string>
#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;


void sol(int n) {
        if (n < 2) {
            if (n == 1) {
                cout << "Jolly" << endl;
            } else {
                cout << "Not jolly" << endl;
            }
            int tmp;
            for (int i = 0; i < n; i++) { scanf("%i", &tmp);}
        } else {
            int arr[n];
            int arr2[n-1];

            for (int i = 0; i < n; i++) { scanf("%i", &arr[i]);}
            for (int i = 0; i < n - 1; i++) {
                arr2[i] = abs(arr[i] - arr[i+1]);
            }

            int _len = sizeof(arr2) / sizeof(arr2[0]);
            sort(arr2,  arr2 + _len);

            bool jolly = true;
            for (int i = 0; i <  n - 1; i++) {
                if (arr2[i] != i + 1) {
                    jolly = false;
                    break;
                }
            }
            if (jolly) {
                cout << "Jolly" << endl;
            } else {
                cout << "Not jolly" << endl;
            }
        }
}

int main() {
    int n;
    while(scanf("%i", &n) == 1){
        sol(n);
    }
    return 0;
}
