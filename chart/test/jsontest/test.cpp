#include <iostream>
#include "json.hpp"
#include <vector>
#include <map>

using json = nlohmann::json;
using namespace std;
void test() {
    json js;
    js["name"] = "zhanghao";
    js["age"] = "19";
    js["city"] = {{"shiyan", "zhangwan"}, {"shanghai", "songjiang"}};
    cout << js << endl;
    js["lunch"] = {"dr", "da", "td"};
    cout << js << "\n";
    auto serial_buf = js.dump();
    auto json_buf = json::parse(serial_buf);
    cout << "name is " << json_buf["name"] << "\n";
    cout << "age is " << json_buf["age"] << "\n";
    cout << "city " << json_buf["city"] << "\n";
    cout << "lunch " << json_buf["lunch"] << "\n";
}

void test1() {
    json js;
    vector<int> a{1,2,3};
    map<string, int> maps;   
    maps.insert({"zhang", 212});
    maps.insert({"da", 32});
    js["vector"] = a;
    js["map"] = maps;
    cout << js << "\n"; 
    auto dum = js.dump();
    cout << "dum " << dum << "\n";

    cout << "----------" << "\n";
    auto jsbuf = json::parse(dum);
    vector<int> vec = jsbuf["vector"];
    map<string, int> map = jsbuf["map"];
    for(auto& i: vec) {
        cout << i << " ";
    }
    cout << "\n";
    for(auto& item: map) {
        cout << item.first << item.second << "\n";
    }
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
