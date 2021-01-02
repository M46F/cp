# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


void sol(int n, int k) {



    int curr_server = 0;
    int max_server = 0;
    int curr_load = 0;
    int curr_time = 0;

    queue <int>  q;


    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%i\n", &tmp);
        
        q.push(tmp);
        curr_load += 1;

        if (i > 0) {
            while (!q.empty()) {
                int first = q.front();
                if (first <= tmp - 1000) {
                    curr_load -= 1;
                    q.pop();
                } else {
                    break;
                }
            }
        }

        
        if (curr_load > (curr_server * k)) {
        curr_server += 1;
            if (curr_server > max_server) {
                max_server = curr_server;
            }
        }
        //cout << "iter " << i <<  " " << curr_server << " " << max_server << " " << curr_load << endl;
    }

    cout << max_server << endl;
}

int main() {
    int n, k;
    scanf("%i %i", &n, &k);
    sol(n, k);
    return 0;
}
