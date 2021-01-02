# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


void append_parsed(string token, string& parsed_class){
    if (token[0] == 'u') {
        parsed_class += 'a';
    } else if (token[0] == 'm') {
        parsed_class += 'b';
    } else {
        parsed_class += 'c';
    }
}

void parse_class(string name, string& parsed_class) {
    string delimiter = "-";
    size_t pos = 0;
    string token;
    while((pos = name.find(delimiter)) != string::npos) {
        token = name.substr(0, pos);
        append_parsed(token, parsed_class);
        name.erase(0, pos + delimiter.length());
    }
    append_parsed(name, parsed_class);

    int _len = parsed_class.length();
    for(int i = 0; i < _len / 2; i++) {
        swap(parsed_class[i], parsed_class[_len-i-1]);
    }
}

void append_mid_class(int maxlen, string& parsed_class) {
    int _len = parsed_class.length();
    while (_len < maxlen){
        parsed_class += 'b';
        _len += 1;
    }
}


bool sortbysec(const tuple<string, string>& a,  const tuple<string, string>& b) { 
    if (get<1>(a) != get<1>(b)) {
        return (get<1>(a) < get<1>(b));
    } else {
        return (get<0>(a) < get<0>(b));
    }
}

int main() {
    int T;
    scanf("%i\n", &T);
    
    for(int tc = 0; tc < T; tc++){
        int N;
        scanf("%i\n", &N);
        int maxlen = 0;

        vector<std::tuple<string, string>> name_pairs;


        for(int n = 0; n < N; n++){
            
            string _input;
            getline(cin, _input);

            string _delimiter = ": ";
            int pos = _input.find(_delimiter);
            string name = _input.substr(0, pos);
            _input.erase(0, pos + _delimiter.length());

            string classes = _input.substr(0, _input.find(" class"));
            string parsed_class = "";
            parse_class(classes, parsed_class);

            int _len =parsed_class.length();
            maxlen = max(_len, maxlen);

            name_pairs.push_back(make_tuple(name, parsed_class));
        }

        for(int n = 0; n < N; n++){
            append_mid_class(maxlen, get<1>(name_pairs[n]));
        }

        sort(name_pairs.begin(), name_pairs.end(), sortbysec);
        for(int n = 0; n < N; n++){
            cout << get<0>(name_pairs[n]) << endl;
            //" " << get<1>(name_pairs[n]) <<endl;
        }
        name_pairs.clear();
        cout << "==============================" << endl;
    }

    return 0;
}
