//#include "stdafx.h"
//#define uint unsigned int
//#define matrix vector<vector<int>>

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

void printvector(vector<int> v){
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout<< endl;
}
vector<int> mergevec(vector<int> v1, vector<int> v2){
    vector<int> result = v1;
    result.insert(result.end(), v2.begin(), v2.end());
    return result;
}
void printset(set<int> v){
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout<< endl;
}
void printmap(map<string, int> v){
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << it->first << " " << it->second << " ";
    }
    cout<< endl;
}
void stash(){
    vector<int> v;
    v.push_back(5);
    v.push_back(11);
    v.push_back(7);
    printvector(v);
    vector<int> w;
    w.push_back(57);
    w.push_back(81);
    w.push_back(9);

    printvector(w);
    auto result = mergevec(v, w);
    printvector(result);
}
void mapstash(){
    map <string, int> m;
    m.insert(m.begin(), pair<string, int> ("Vasya", 178));
    m.insert(m.begin(), pair<string, int> ("Dasha", 156));
    m.insert(m.begin(), pair<string, int> ("Elena", 168));
    m.insert(m.begin(), pair<string, int> ("Dasha", 190));
    printmap(m);
}
void setstash(){
    set<int> s;
    s.insert(3);
    s.insert(3);
    printset(s);
    s.size();
}

int main()
{
    mapstash();

//    string * sp = new string("hello pointer");
//    string so = "hello object";

//    cout << so.length() << endl;    //
//    cout << (*sp).length() << endl; //
//    cout << sp->length() << endl;   //

//    cout << &sp << endl; //#5533
//    cout << sp  << endl;  //#7788
//    cout << *sp << endl; //hello pointer

//    cout << &so << endl; //#6547
//    cout << so  << endl;  //hello object


}
