#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'commonPrefix' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY inputs as parameter.
 */
int commonPrefixLength(string s1, string s2){
    //cout<<s1<<"space"<<s2<<endl;
    int count =0 ;
    for(int i =0 , j =0 ; i < s1.size() &&  j < s2.size(); ++i,++j ){
        if(s1[i] == s2[j])
            count++;
        else {
        break;
        }    
    }
    return count;
}
void getZarr(string str,vector<int>&Z)
{
    int L, R, k;
 
    // [L, R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < str.size(); ++i) {
 
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R) {
            L = R = i;
 
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R < str.size() && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else {
 
            // k = i-L so k corresponds to number which
            // matches in [L, R] interval.
            k = i - L;
 
            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
 
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else {
                // else start from R and check manually
                L = i;
                while (R < str.size() && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}
vector<int> commonPrefix(vector<string> inputs) {
    vector<int> answer(inputs.size(), 0 ) ; 
    for(int i =0 ; i < inputs.size(); ++i){
        vector<int>Z(inputs[i].size(),0);
        cout<<Z.size()<<endl;
        getZarr(inputs[i], Z);
        int localAnswer = inputs[i].size();
        for (int i = 1; i < Z.size(); i++){
            cout<<"ra"<<Z[i]<<endl;
            localAnswer += Z[i];
            
        }
        
        // int localAnswer =0 ;
        // for(int j =0 ; j < inputs[i].size(); ++j){
        //     localAnswer += commonPrefixLength(inputs[i].substr(j,inputs[i].size()) , inputs[i]);
        //    // cout<<localAnswer<<endl;
        // }
        answer[i] = localAnswer;
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string inputs_count_temp;
    getline(cin, inputs_count_temp);

    int inputs_count = stoi(ltrim(rtrim(inputs_count_temp)));

    vector<string> inputs(inputs_count);

    for (int i = 0; i < inputs_count; i++) {
        string inputs_item;
        getline(cin, inputs_item);

        inputs[i] = inputs_item;
    }

    vector<int> result = commonPrefix(inputs);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
