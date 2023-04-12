// helang++ prototype (2022.08.19)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#define u8 short
#define dstring std::string
#define dvar std::vector<u8>
#define darray std::vector<dvar>
#define dmap std::unordered_map<std::string, u8>
darray var;
dmap varname;

void createvar(dstring name) {
   dvar variable;
   var.push_back(variable);
   varname[name] = var.size() - 1;
}

void initvar(dstring name,u8 size) {
    dvar& varef = var[varname[name]];
    varef.resize(size);
    for (u8 i = 0;i< size; i++)
    varef[i] = 0;
}

void initvar(dstring name) {
    dvar& varef = var[varname[name]];
    varef.resize(1);
    varef[0] = 0;
}
void assignvar(dstring name, dvar value) {

    dvar& varef = var[varname[name]];
    varef.resize(value.size());
    varef = value;
    
}

void printvar(dstring name) {
    std::cout << name <<": ";
    for (u8 i : var[varname[name]])
       std::cout << std::to_string(i) << "|";
       
    std::cout << std::endl;
}


void addvar(dstring name,dvar data){
   for (u8 i = 0; i < data.size(); i++){
       if (var[varname[name]].size() <= i)
           var[varname[name]].push_back(data[i]);
        else
      var[varname[name]][i] += data[i];
   }
    
}
void minusvar(dstring name,dvar data){
   for (u8 i = 0; i < data.size(); i++){
       if (var[varname[name]].size() <= i)
           var[varname[name]].push_back(data[i]);
        else
      var[varname[name]][i] -= data[i];
   }
    
}

void multiplyvar(dstring name, dvar data) {
   for (u8 i = 0; i < data.size(); i++){
     
      var[varname[name]][i] *= data[i];
   }
    
}
void dividevar(dstring name,dvar data){
   for (u8 i = 0; i < data.size(); i++){
       if (data[i] != 0)
       
       
      var[varname[name]][i] /= data[i];
   }
    
}
void ppvar (dstring name) {
   for (u8& i : var[varname[name]]) i++;
}
void mmvar (dstring name) {
   for (u8& i : var[varname[name]]) i--;
}
void indexvar(dstring name, dvar index, u8 data) {
    
    if (index.empty())
      return;
    if (index[0] == 0)
       for (u8& i:var[varname[name]])
       i = data;
    for (u8 i : index){
        if (i == 0)
          return;
       var[varname[name]][i-1] = data;
    }
}

void printsvar(dstring name) {
  std::cout << name <<": ";
    for (u8 i : var[varname[name]])
       std::cout << (char)i;
       
    std::cout << std::endl;
}
dvar getvar(dstring name) {
    return var[varname[name]];
}

int main() {
    using namespace std;
    // Write C++ code here
   // std::cout << "Hello world!";
    string input;
   // cin >> input;
    
    //todo: parse
    return 0;
}
