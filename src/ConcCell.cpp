#include "test.hpp"

//ConcCell method

ConcCell::ConcCell(){
  in0 = NULL;
  in1 = NULL;
  out = NULL;  
}

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
void INVCell::set_in0(ConcCell *in){
  in0 = in;
}

void INVCell::set_in1(ConcCell *in){
}

void INVCell::set_out(ConcCell *in){
  out = in;
}

int INVCell::get_type(){
  return 0;
}

//NANDCell method
void NANDCell::set_in0(ConcCell *in)
{
  in0 = in;
}

void NANDCell::set_in1(ConcCell *in){
  in1 = in;
}

void NANDCell::set_out(ConcCell *in){
  out = in;
}

int NANDCell::get_type(){
  return 1;
}

//INPUT Cell method

int INPUTCell::get_type(){
  return -1;
}
