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

void binarySearchString(string str){
    int comparisons = 0;
    int left = 0;
    int right = str.size() - 1;
    while(left <= right){
        comparisons ++;
        int mid = left + (right-left)/2;
        if(str[mid]!=str[mid+1] && str[mid]!=str[mid-1]){
            cout << str[mid] << " " << comparisons << endl;
            break;
        }
        else if(str[mid]!=str[mid+1]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

}

int main(){
    vector<string> samples {"AACCZZTTVXX", "AAB", "CCAAXWWTT", "XXYYZZAAC"};
    for(string str : samples){
        vector<int> result;
        result = linearSearchString(str);
        cout << str[result[0]] << " " << result[1] << " ";
        binarySearchString(str); 
    }
    
    return 0;
}