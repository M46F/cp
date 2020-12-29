# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


void sol(int *arr, int n) {
    int arrmin[n];
    int arrmax[n];

    for ( int i = 0; i < n; i++) {
//        cout << i << endl;
        if (i == 0) {
            arrmin[i] = arr[i];
            arrmax[n-1-i] = arr[n-1-i];
    //        cout << "asu: " << arr[n-1-i]<<endl;
        } else {
            arrmin[i] = max(arrmin[i-1], arr[i]);
            arrmax[n-1-i] = min(arrmax[n-i], arr[n-i-1]);
       //     cout << "asu: " << arrmax[n-1-i]<< " " << arr[n-i-1] << endl;
        }
    }


    /*for ( int i = 0; i < n; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
    for ( int i = 0; i < n; i++) {
        cout << arrmin[i] << ",";
    }

    cout << endl;
    for ( int i = 0; i < n; i++) {
        cout << arrmax[i] << ",";
    }
    */
    int out = 0;
    for ( int i = 0; i < n; i++) {
        
        //cout << i << ":" << arr[i] << endl;
        if (i == 0) {
            if (arr[i] <= arrmax[i+1]) {
                out++;
            } 
        } else if ( i == n - 1){
            if (arr[i] > arrmin[i-1]) {
                out++;
            } 
        } else if (arr[i] > arrmin[i-1] && arr[i] <= arrmax[i+1]) {
            out++;
        }
    }
    cout << out << endl;
}


int main() {
    int n;
    scanf("%i\n", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {scanf("%i", &arr[i]);}
    sol(arr, n);
    return 0;
}
