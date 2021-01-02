# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


void sol(int n) {
    int arr[n];
    for (int i = 0; i < n; i++) { scanf("%i", &arr[i]);}
    
    map<int, int>  htable;

    int out = 0;
    for (int i = 0; i < n; i++) {
        
/*        cout << "iter " << i << " out " << out << endl;
        for (auto itr = htable.begin(); itr != htable.end(); ++itr) { 
            cout << itr->first << '\t' << itr->second << '\n'; 
        } 
*/        // arr[i] not in hashtable
        if (htable.find(arr[i]) == htable.end()) {

            out += 1;

            // arr[i] - 1 not in hashtable create new, if exist add new
            if (htable.find(arr[i] - 1) == htable.end()) {
                htable[arr[i] - 1] = 1;
            } else {
                htable[arr[i] - 1] += 1;
            }
        } else {
            // exist but zero out += 1
            if (htable[arr[i]] < 1) {
                out += 1;
            } else {
                htable[arr[i]] -=1;
            }


            // arr[i] - 1 not in hashtable create new, if exist add new
            if (htable.find(arr[i] - 1) == htable.end()) {
                htable[arr[i] - 1] = 1;
            } else {
                htable[arr[i] - 1] += 1;
            }
        }
    }
    cout << out << endl;
}

int main() {
    int n;
    scanf("%i", &n);
    sol(n);
    return 0;
}
