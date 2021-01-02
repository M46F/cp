# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;


int main() {
	int arr[3];
	scanf("%i %i %i", &arr[0], &arr[1], &arr[2]);
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n);
	
	int diff1 = arr[1] - arr[0];	
	int diff2 = arr[2] - arr[1];
	
	int out;
	if (diff1 == diff2) {
		out = arr[2] + diff1;
	}
	else {
		if (diff2 > diff1) {
			out = arr[2] - diff1;
		} else {
			out = arr[1] - diff2;	
		}
	}
	cout << out << endl;
    return 0;
}

