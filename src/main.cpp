#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "test.hpp"

using namespace std;

int main (int argc, char* argv[]) {
  string libfile=argv[2];
  string line;
  ifstream f(libfile.c_str());
  getline(f,line);//Read number of cells
  int cell_num=atoi(line.c_str());
  
  LibCell* libCell= new LibCell[cell_num];
  for (int i=0;i<cell_num;i++){
    getline(f,line);//Read name of Cell
    libCell[i].set_name(line);
    getline(f,line);//Read delay,input,gates
    istringstream iss(line);
    int a,b,c;
    iss >> a >> b >> c;
    cout << a << b << c << endl;
    
    libCell[i].set_delay(a);
    ConcCell **cells;
    cells=new ConcCell*[c];
    string *conn=new string[c];
    for (int j=0;j<b;j++)
      cells[j]=new INPUTCell;
	
    for (int j=0;j<c;j++){
      getline(f,line);//Read gate info
      
      if (line.substr(0,line.find(" "))=="INV")//Add gate (without connection)
	cells[j+b]=new INVCell;
      else
	cells[j+b]=new NANDCell;

      conn[j] = line.substr(line.find(" ")+1);
      cout << conn[j] << endl;
    }
    libCell[i].add_cells(cells);
    for (int j=0;j<c;j++){
      if (cells[j+b]->get_type()==0){
	int x=atoi(conn[j].substr(1).c_str());
	
	if (conn[j].at(0)=='P'){
	  libCell[i].connect_cells(cells[x-1],cells[j+b]);
	}else{
	  libCell[i].connect_cells(cells[x-1+b],cells[j+b]);
	}
      }
    }
    getline(f,line);//Read blank line
  }
  return 0;
}

