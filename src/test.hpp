#include <string>

//Conceptual Cell
class ConcCell{
protected:
  ConcCell *in0;
  ConcCell *in1;
  ConcCell *out;
public:
  ConcCell();
  virtual void set_in0(ConcCell *){}; 
  virtual void set_in1(ConcCell *){}; 
  virtual void set_out(ConcCell *){}; 
  virtual int get_type(){return -1;};          //Return 0 for INV, 1 for NAND2, -1 for INPUT
  ConcCell* get_in0();                         //Return NULL if invalid
  ConcCell* get_in1();                         //Return NULL if invalid
  ConcCell* get_out();                         //Return NULL if invalid
};

class INVCell: public ConcCell{
public:
  void set_in0(ConcCell *);
  void set_in1(ConcCell *);
  void set_out(ConcCell *);
  int get_type();
};

class NANDCell: public ConcCell{
public:
  void set_in0(ConcCell *);
  void set_in1(ConcCell *);
  void set_out(ConcCell *);
  int get_type();
};

class INPUTCell: public ConcCell{
public:
  int get_type();
};

//Library Cell
class LibCell{
  std::string name;
  int delay;
  ConcCell** cells;
  ConcCell*  outputcells;
public:
  void set_name(std::string);
  void set_delay(int);
  void add_cells(ConcCell**);
  void connect_cells(ConcCell *, ConcCell *);
};
