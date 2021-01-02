# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;

int merge(int arr[], int tmp[], int left, int mid, int right){
    //cout << "lmr" << left << " " << mid << " " << right << endl;
    int i = left;
    int j = mid;
    int k = left;
    int ct = 0;
    while((i <= mid - 1) && j <= right){
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
            k++;
        } else {
            tmp[k] = arr[j];
            j++;
            k++;
            ct += (mid - i);
        }
    }
    while (i <= mid - 1) {
        tmp[k] = arr[i];
        i++;
        k++;
    } 
     while (j <= right) {
         tmp[k] = arr[j];
         k++;
         j++;
    }
    for (i = left; i <= right; i++) {
        //cout << i << ", " << tmp[i] << endl;
        arr[i] = tmp[i]; 
    }       
    return ct;

}

int merge_sort(int arr[], int tmp[], int left, int right){
    int ct = 0;
    if (right > left){
        int mid = (right + left) / 2;
        ct += merge_sort(arr, tmp, left, mid);
        ct += merge_sort(arr, tmp, mid + 1, right);
        ct += merge(arr, tmp, left, mid + 1, right);
    }
    return ct;
}

int count_inversion(int arr[], int n){
    int tmp[n];
    return merge_sort(arr, tmp, 0, n-1);    
}

int main() {
    int N;
    scanf("%i/n", &N);
    int breads[N], expected[N];

    for(int i = 0; i < N; i++) {scanf("%i", &breads[i]);}
    for(int i = 0; i < N; i++) {scanf("%i", &expected[i]);}

    int inversion_bread, inversion_expected;
    
    int _size1 = sizeof(breads)/sizeof(int); 
    int _size2 = sizeof(expected)/sizeof(int); 
    //cout << "uwu: <<" << _size1 << "," << _size2 << endl;
    inversion_bread = count_inversion(breads, _size1);
    inversion_expected = count_inversion(expected, _size2);
    
    /*
    for(int i = 0; i < N; i++) {
        cout << breads[i] << ",";
    }
    cout << endl;
    

    for(int i = 0; i < N; i++) {
        cout << expected[i] << ",";
    }
    cout << endl;
    cout<< inversion_bread << " x " << inversion_expected << endl; 
    */
    if (abs(inversion_expected - inversion_bread) % 2 == 0) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
