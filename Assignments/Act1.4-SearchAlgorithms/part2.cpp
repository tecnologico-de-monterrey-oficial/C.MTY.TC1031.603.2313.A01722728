#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> linearSearchString(string str){
    int comparisons = 0;
    for(int i=0; i<str.size(); i+=2){
        comparisons ++;
        if(str[i]!=str[i+1]){
            return vector<int> {i, comparisons};
        }
    }
}

int main(){
    vector<string> samples {"AACCZZTTVXX", "AAB", "CCAAXWWTT", "XXYYZZAAC"};
    for(string str : samples){
        vector<int> result;
        result = linearSearchString(str);
        cout << str[result[0]] << " " << result[1] << endl; 
    }
    
    return 0;
}