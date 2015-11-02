#include "test.hpp"
#include <string>

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
    a->set_out(b);
  }else{
    b->set_in1(a);
    a->set_out(b);
  }
}
