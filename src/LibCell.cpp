#include "test.hpp"
#include <string>
#include <iostream>

void LibCell::set_name(std::string in){
  name = in;
}

void LibCell::set_delay(int in){
  delay = in;
}

void LibCell::add_cells(ConcCell** in){
  cells = in;
}

void LibCell::connect_cells(ConcCell *a, ConcCell *b){
  if (b->get_in0()==NULL){
    b->set_in0(a);
  }else{
    if (b->get_type()==0)
      std::cout << "Already Connected";
    else if (b->get_in1()!=NULL)
      std::cout << "Already Connected";
    else
      b->set_in1(a);
  }
}
