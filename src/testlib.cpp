#include "test.hpp"
#include <string>

//ConcCell method

ConcCell* ConcCell::get_in0(){
  return in0;
}

ConcCell* ConcCell::get_in1(){
  return in1;
}

ConcCell* ConcCell::get_out(){
  return out;
}

//INVCell method
int INVCell::set_in0(ConcCell *in){
  in0 = in;
  return 0;
}

int INVCell::set_in1(ConcCell *in){
  return -1
}

int INVCell::set_out(ConcCell *in){
  out = in;
  return 0;
}

int INVCell::get_type(ConcCell *in){
  return 0;
}

//NANDCell method
int NANDCell::set_in0(ConcCell *in)
{
  in0 = in;
  return 0;
}

int NANDCell::set_in1(ConcCell *in){
  in1 = in;
  return 0;
}

int NANDCell::set_out(ConcCell *in){
  out = in;
  return 0;
}

int NANDCell::get_type(){
  return 1;
}
