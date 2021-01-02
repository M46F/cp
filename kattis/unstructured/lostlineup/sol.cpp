# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;


int main() {
	int n;
	scanf("%i", &n);	
	vector<tuple<int, int>> v;
	for (int i = 1; i < n; i++) {
		int tmp;
		scanf("%i", &tmp);
		
		v.push_back(make_tuple(tmp, i));
	}
	
	sort(v.begin(), v.end());
	
	cout << 1;
	for (int i = 0; i < (int)v.size(); i++) {
		cout << " " << get<1>(v[i]) + 1;
	}
	cout << "\n";
	
    return 0;
}

