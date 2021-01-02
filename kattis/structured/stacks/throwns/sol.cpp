# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


int main() {
    int T, N;
    scanf("%i %i\n", &T, &N);
    cout << -3 % 8 << endl;

    string cmd_str;
    getline(cin, cmd_str);


    std::string delimiter = " ";

    size_t pos = 0;
    string cmd;

    stack<string> cmds;

    bool isundo = false;
    while ((pos = cmd_str.find(delimiter)) != string::npos) {
        cmd = cmd_str.substr(0, pos);
        cmd_str.erase(0, pos + delimiter.length());
        
        if (cmd != "undo") {
            if(isundo){
                for(int i = 0; i < stoi(cmd); i++){
                    cmds.pop();
                }
            } else {
                cmds.push(cmd);
            }

            isundo  = false;
        } else {
            isundo = true;
        }
    }
    cmd = cmd_str;

    if(isundo){
        for(int i = 0; i < stoi(cmd); i++){
                cmds.pop();
        }
    } else {
        cmds.push(cmd);
    }

    int curr = 0;
    while (!cmds.empty()) {
        curr += stoi(cmds.top());
        curr %= T;
        while(curr < 0) {
            curr += T;
        }
        cmds.pop();
    }

    cout << curr << endl;
    return 0;
}
