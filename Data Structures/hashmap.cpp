#include <bits/stdc++.h>
using namespace std;

int main(){
    //creation
    unordered_map<string,int> m; //Insertion, Deletion and Update in O(1) time complexity

    map<string,int> m1;//based on BST. Insertion, Deletion and Update in O(logn) time complexity. Keeps keys in order.

    //insertion

    //1
    pair<string,int> p = make_pair("vaibhav",3);
    m.insert(p);
    m1.insert(p);

    //2
    pair<string,int> q = make_pair("mohite",1);
    m.insert(q);
    m1.insert(q);

    //3
    m["dashrath"] = 2;
    m["is"] = 0;
    m1["dashrath"] = 1;

    for(auto i:m) cout << i.first << ": " << i.second << endl;
    for(auto i:m1) cout << i.first << " ";
    cout << endl;
    cout << m.at("vaibhav") << endl;
    //if any key is not present then at method through out of range error

    cout << m["unknown"] << endl;
    //m["key"] will give the value corresponding to the key if present else it will make a pair with that key and assign 0 to it
    cout << m.at("unknown") << endl;

    //size
    cout << m.size() << endl;

    //Update
    m["vaibhav"] = 32;
    cout << m.at("vaibhav") << endl;

    //counting occurence of a key
    cout << m.count("occur") << endl;
    cout << m.count("unknown") << endl;

    //Erase
    cout << m.count("is") << endl;
    m.erase("is");
    cout << m.count("is") << endl;

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout << it->first << ": " << it->second << endl;
        it++;
    }

    return 0;
}