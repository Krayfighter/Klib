#include <iostream>
#include <vector>
#include "./types/dict.hpp"

using namespace std;


int main() {
    Dictionary<int> dict;
    dict.push("first", 1);
    dict.push("second", 2);
    cout << dict["first"] << endl;
    cout << dict["second"] << endl;
}