// helang++ prototype (2022.08.19)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <sstream>
#include <cstring>
#include <regex>
#include <unordered_map>
#define u8 short
#define dstring std::string
#define dvar std::vector<u8>
#define darray std::vector<dvar>
#define dmap std::unordered_map<std::string, u8>
#define dtoken std::vector<std::string>

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

std::vector<std::string> tokenize(std::istringstream& ss) {
    std::vector<std::string> tokens;
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

template <typename T>
void vector_pop_front(std::vector<T>& vec){
    std::reverse(vec.begin(),vec.end()); // first becomes last, reverses the vector
    vec.pop_back(); // pop last
    std::reverse(vec.begin(),vec.end()); // reverses it again, so the elements are in the same order as before

}

inline u8 midnum(std::string& s) {
    std::regex regex(R"(\d+)");   // matches a sequence of digits
    u8 out;
    std::smatch match;
    while (std::regex_search(s, match, regex)) {
        out = std::stoi(match.str());
        s = match.suffix();
    }
    return out;
}


int main() {
    using namespace std;
    // Write C++ code here
   // std::cout << "Hello world!";

    dstring line;
    while (std::getline(std::cin, line)) {
        istringstream ss(line);
        dtoken a = tokenize(ss);
        
        if (!a.empty()) {
            if (a[0] == "u8" && a.size() > 1) {
                createvar(a[1]);
                vector_pop_front(a);
            }
            
            if (a[0] == "print" && a.size() > 1) 
                printvar(a[1]);
            if (a.size() > 2) {
                if (a[0][a[0].length() - 1] == '[' ) {
                    a[0].resize(a[0].size() - 1);
                  u8 i = 1, v = 0;
                  dvar content;
                  while(true) {
                      if (a[i][0] == '='){
v = i;
                          break;
                      }
                        for (char v : a[i]) {
                            if (isdigit(v)) {
                          content.push_back(std::stoi(a[i]));
}
}
                      i++;
                  }
                
                    indexvar(a[0], content, std::stoi(a[v + 1] ));
                
                }
                if (a[1] == "=") {
                    if (a[2].c_str()[0] == '[') {
                        u8 cxk = midnum(a[2]);
                        initvar(a[0], cxk);
                    } else {
                
                    dvar content;
                    for (u8 i = 1; i < a.size(); i++) {
                        for (char v : a[i]) {
                            if (isdigit(v)) {
                                content.push_back(std::stoi(a[i]));
                                break;
                            }
                        }
                    }
                    assignvar(a[0], content);
                    }
                }
                

            }
        }
    }

    //todo: parse
    return 0;
}
