#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <string>
#include <map>

void print(std::multimap<size_t, std::string>& M) { 

  auto it = M.begin();
  int key = it->first;
  auto it1 = M.lower_bound(key); 
  auto it2 = M.upper_bound(key); 
  size_t cont = 0;
  while (it1 != it2){ 
    if(cont == 5){
      break;
    }
    if (it1 -> first == key) 
      std::cout << "-" << it1->second << std::endl;         
    it1++;
    cont++; 
  }
  std::cout <<"\n";
}

#endif