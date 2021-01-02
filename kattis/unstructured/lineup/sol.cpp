# include<iostream>
# include<climits>
#include <stdio.h>
#include <math.h>
#include <string>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;


int main() {
	int n;
	scanf("%i\n", &n);
	string arr[n];
	string original[n];
	for (int i = 0; i < n; i++) {
		getline(cin, original[i]);
		arr[i] = original[i];
	}
	
	int N = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr + N);
	
	bool decreased = true;
	bool increased = true;
	for (int i = 0; i < n; i++) {
		increased = increased && (arr[i] == original[i]);
		decreased = decreased && (arr[n-(i+1)] == original[i]);
	}
	
	
	if (increased) {
		cout << "INCREASING" << endl;
	} else if (decreased) {
		cout << "DECREASING" << endl;
	} else {
		cout << "NEITHER" << endl;
	}
	
    return 0;
}

