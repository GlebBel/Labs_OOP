#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> count(vector<string> vec){
    map<string, int> m;
    for(int i = 0; i<vec.size();i++){
        if ( m.find(vec[i]) == m.end() ) 
            m.insert(make_pair(vec[i],1));
        else 
            m[vec[i]]+=1;
    }
    return m;
}

void printCount(map<string, int> m){
    for(auto& item : m)
        cout << item.first << " : " << item.second << endl; 
}
void print(vector<string> myvector){
    for (vector<string>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';
}

vector<string> split(string s){
    vector<string> words;
    string word = "";
    for(int i = 0;i<s.length();i++){
        if(s[i]==' '){
            words.push_back(word);
             word = "";
        }
        else if(s[i]=='.')
            continue;
        else
            word+=s[i];
    }
    return words;
}

int main(){
    string s = "car potato potato potato potato desk tomate apple.";
    vector<string> seq =split(s);
    cout<<"Sequence: ";
    print(seq);
    sort(seq.begin(), seq.end());
    cout<<"Sorted sequence: ";
    print(seq);
    printCount(count(seq));
    return 0;
}