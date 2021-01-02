# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


void sol(int n) {
    int out = 0;

    vector<int> arrout;


    int current;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%i", &tmp);

        if (i == 0) {
            current = tmp;
            arrout.push_back(current);
            out += 1;
        }

        if (tmp > current) {
            current = tmp;
            arrout.push_back(tmp);
            out += 1;
        }
    }
    cout << out << endl;
    for (int i = 0; i < out; i++) {
        if (i == out - 1){
            cout << arrout[i] << endl;
        } else {
            cout << arrout[i] << " ";
        }
    }
}



int main() {
    int n;
    scanf("%i", &n);
    sol(n);
    return 0;
}
