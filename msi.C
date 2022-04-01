/******************************
  Program "msi.m" compiled by "Murphi Release 3.1"

  Murphi Last Modefied Date: "Jan 29 1999"
  Murphi Last Compiled date: "Mar 18 2022"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Murphi Release 3.1"
#define MURPHI_DATE "Jan 29 1999"
#define PROTOCOL_NAME "msi"
#define BITS_IN_WORLD 2376
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
        return ( s << mu_1_Proc::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Proc (char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_Proc (void): mu__byte(1, 3, 2) {};
  mu_1_Proc (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Proc::values[] =
  { "Proc_1","Proc_2","Proc_3",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Value& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Value& val)
    {
      if (val.defined())
        return ( s << mu_1_Value::values[ int(val) - 4 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Value (char *name, int os): mu__byte(4, 5, 2, name, os) {};
  mu_1_Value (void): mu__byte(4, 5, 2) {};
  mu_1_Value (int val): mu__byte(4, 5, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -4]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 4] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Value& a, mu_1_Value& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Value::values[] =
  { "Value_1","Value_2",NULL };

/*** end scalarset declaration ***/
mu_1_Value mu_1_Value_undefined_var;

class mu_1_Dir: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Dir& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Dir& val)
  {
    if (val.defined())
      return ( s << mu_1_Dir::values[ int(val) - 6] );
    else return ( s << "Undefined" );
  };

  mu_1_Dir (char *name, int os): mu__byte(6, 6, 1, name, os) {};
  mu_1_Dir (void): mu__byte(6, 6, 1) {};
  mu_1_Dir (int val): mu__byte(6, 6, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -6]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -6] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_Dir::values[] = {"Directory",NULL };

/*** end of enum declaration ***/
mu_1_Dir mu_1_Dir_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
        return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_Node (void): mu__byte(0, 3, 3) {};
  mu_1_Node (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 6) && (value() <= 6)) return (value() - 6);
    if ((value() >= 1) && (value() <= 3)) return (value() - 0);
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 0) return value(val+6);
    if (val >= 1 && val <= 3) return value(val+0);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_Node::values[] = {"Directory","Proc_1","Proc_2","Proc_3",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_VCType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_VCType& val) { return mu__byte::operator=((int) val); };
  mu_1_VCType (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_VCType (void): mu__byte(0, 2, 2) {};
  mu_1_VCType (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_VCType mu_1_VCType_undefined_var;

class mu_1_AckCount: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_AckCount& val) { return mu__long::operator=((int) val); };
  mu_1_AckCount (char *name, int os): mu__long(-2, 2, 3, name, os) {};
  mu_1_AckCount (void): mu__long(-2, 2, 3) {};
  mu_1_AckCount (int val): mu__long(-2, 2, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_AckCount mu_1_AckCount_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 7] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (char *name, int os): mu__byte(7, 19, 4, name, os) {};
  mu_1_MessageType (void): mu__byte(7, 19, 4) {};
  mu_1_MessageType (int val): mu__byte(7, 19, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -7]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -7] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_MessageType::values[] = {"GetS","GetM","PutS","PutM","Data","InvAck","InvAllAck","PutAck","FwdGetSAck","FwdGetMAck","Inv","FwdGetS","FwdGetM",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_MessageType mu_mtype;
  mu_1_Node mu_src;
  mu_1_VCType mu_vc;
  mu_1_Value mu_value;
  mu_1_Node mu_fwd_to;
  mu_1_AckCount mu_ack_cnt;
  mu_1_Message ( char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = CompareWeight(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_fwd_to, b.mu_fwd_to);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ack_cnt, b.mu_ack_cnt);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = Compare(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = Compare(a.mu_fwd_to, b.mu_fwd_to);
    if (w!=0) return w;
    w = Compare(a.mu_ack_cnt, b.mu_ack_cnt);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_vc.MultisetSort();
    mu_value.MultisetSort();
    mu_fwd_to.MultisetSort();
    mu_ack_cnt.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_vc.print_statistic();
    mu_value.print_statistic();
    mu_fwd_to.print_statistic();
    mu_ack_cnt.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_src.clear();
    mu_vc.clear();
    mu_value.clear();
    mu_fwd_to.clear();
    mu_ack_cnt.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_src.undefine();
    mu_vc.undefine();
    mu_value.undefine();
    mu_fwd_to.undefine();
    mu_ack_cnt.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_src.reset();
    mu_vc.reset();
    mu_value.reset();
    mu_fwd_to.reset();
    mu_ack_cnt.reset();
 };
  void print() {
    mu_mtype.print();
    mu_src.print();
    mu_vc.print();
    mu_value.print();
    mu_fwd_to.print();
    mu_ack_cnt.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_vc.print_diff(prevstate);
    mu_value.print_diff(prevstate);
    mu_fwd_to.print_diff(prevstate);
    mu_ack_cnt.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_vc.to_state(thestate);
    mu_value.to_state(thestate);
    mu_fwd_to.to_state(thestate);
    mu_ack_cnt.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_vc.value(from.mu_vc.value());
    mu_value.value(from.mu_value.value());
    mu_fwd_to.value(from.mu_fwd_to.value());
    mu_ack_cnt.value(from.mu_ack_cnt.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(char *n, int os)
{
  name = n;
  mu_mtype.set_self_2(name, ".mtype", os + 0 );
  mu_src.set_self_2(name, ".src", os + 8 );
  mu_vc.set_self_2(name, ".vc", os + 16 );
  mu_value.set_self_2(name, ".value", os + 24 );
  mu_fwd_to.set_self_2(name, ".fwd_to", os + 32 );
  mu_ack_cnt.set_self_2(name, ".ack_cnt", os + 40 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 20] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(20, 25, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(20, 25, 3) {};
  mu_1__type_0 (int val): mu__byte(20, 25, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -20]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -20] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_0::values[] = {"Dir_M","Dir_S","Dir_I","Dir_MX_D","Dir_SM_A","Dir_MM_A",NULL };

/*** end of enum declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_1_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_1_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_1_id () : mu__byte(0,2,0) {};
  mu_1__type_1_id (int val) : mu__byte(0,2,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_1
{
 public:
  mu_1_Node array[ 3 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 3 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_1 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_1 ();
  mu_1_Node& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 2) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 3; i++)
    {
        array[i].value(from.array[i].value());
        valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_1_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 3; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 3; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Node &element)
  {
    update_size();
    if (current_size >= 3) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 3; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_1_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Node temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 3; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 3; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 3; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_1::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 3; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 8 + os);
  k = os + i * 8;
  for(i = 0; i < 3; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_1::~mu_1__type_1()
{
}
/*** end multiset declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1_DirState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_state;
  mu_1_Node mu_owner;
  mu_1_Value mu_value;
  mu_1__type_1 mu_sharers;
  mu_1_DirState ( char *n, int os ) { set_self(n,os); };
  mu_1_DirState ( void ) {};

  virtual ~mu_1_DirState(); 
friend int CompareWeight(mu_1_DirState& a, mu_1_DirState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = CompareWeight(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_DirState& a, mu_1_DirState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_owner, b.mu_owner);
    if (w!=0) return w;
    w = Compare(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = Compare(a.mu_sharers, b.mu_sharers);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_owner.MultisetSort();
    mu_value.MultisetSort();
    mu_sharers.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_owner.print_statistic();
    mu_value.print_statistic();
    mu_sharers.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_owner.clear();
    mu_value.clear();
    mu_sharers.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_owner.undefine();
    mu_value.undefine();
    mu_sharers.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_owner.reset();
    mu_value.reset();
    mu_sharers.reset();
 };
  void print() {
    mu_state.print();
    mu_owner.print();
    mu_value.print();
    mu_sharers.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_owner.print_diff(prevstate);
    mu_value.print_diff(prevstate);
    mu_sharers.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_owner.to_state(thestate);
    mu_value.to_state(thestate);
    mu_sharers.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_DirState& operator= (const mu_1_DirState& from) {
    mu_state.value(from.mu_state.value());
    mu_owner.value(from.mu_owner.value());
    mu_value.value(from.mu_value.value());
    mu_sharers = from.mu_sharers;
    return *this;
  };
};

  void mu_1_DirState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_DirState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_DirState::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_owner.set_self_2(name, ".owner", os + 8 );
  mu_value.set_self_2(name, ".value", os + 16 );
  mu_sharers.set_self_2(name, ".sharers", os + 24 );
}

mu_1_DirState::~mu_1_DirState()
{
}

/*** end record declaration ***/
mu_1_DirState mu_1_DirState_undefined_var;

class mu_1__type_2: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_2& val)
  {
    if (val.defined())
      return ( s << mu_1__type_2::values[ int(val) - 26] );
    else return ( s << "Undefined" );
  };

  mu_1__type_2 (char *name, int os): mu__byte(26, 37, 4, name, os) {};
  mu_1__type_2 (void): mu__byte(26, 37, 4) {};
  mu_1__type_2 (int val): mu__byte(26, 37, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -26]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -26] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_2::values[] = {"Proc_M","Proc_S","Proc_I","Proc_IS_D","Proc_IM_A","Proc_IM_AD","Proc_II_A","Proc_SM_A","Proc_SM_AD","Proc_SI_A","Proc_MI_A","Proc_IS_DP",NULL };

/*** end of enum declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_ProcState
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_2 mu_state;
  mu_1_Value mu_value;
  mu_1_AckCount mu_ack_cnt;
  mu_1_ProcState ( char *n, int os ) { set_self(n,os); };
  mu_1_ProcState ( void ) {};

  virtual ~mu_1_ProcState(); 
friend int CompareWeight(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ack_cnt, b.mu_ack_cnt);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ProcState& a, mu_1_ProcState& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_value, b.mu_value);
    if (w!=0) return w;
    w = Compare(a.mu_ack_cnt, b.mu_ack_cnt);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_value.MultisetSort();
    mu_ack_cnt.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_value.print_statistic();
    mu_ack_cnt.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_value.clear();
    mu_ack_cnt.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_value.undefine();
    mu_ack_cnt.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_value.reset();
    mu_ack_cnt.reset();
 };
  void print() {
    mu_state.print();
    mu_value.print();
    mu_ack_cnt.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_value.print_diff(prevstate);
    mu_ack_cnt.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_value.to_state(thestate);
    mu_ack_cnt.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ProcState& operator= (const mu_1_ProcState& from) {
    mu_state.value(from.mu_state.value());
    mu_value.value(from.mu_value.value());
    mu_ack_cnt.value(from.mu_ack_cnt.value());
    return *this;
  };
};

  void mu_1_ProcState::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ProcState::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ProcState::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_value.set_self_2(name, ".value", os + 8 );
  mu_ack_cnt.set_self_2(name, ".ack_cnt", os + 16 );
}

mu_1_ProcState::~mu_1_ProcState()
{
}

/*** end record declaration ***/
mu_1_ProcState mu_1_ProcState_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_ProcState array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_ProcState& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Proc is internally represented from 3 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Proc_1", i * 48 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 48 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 48 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_4_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_4_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_4_id () : mu__byte(0,3,0) {};
  mu_1__type_4_id (int val) : mu__byte(0,3,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_4
{
 public:
  mu_1_Message array[ 4 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 4 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_4 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_4 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_4 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 3) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 4; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 4; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 4; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_4_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 4; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 4; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 4) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 4; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_4_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 4; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 4; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 4; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_4::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 4; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 72 + os);
  k = os + i * 72;
  for(i = 0; i < 4; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end multiset declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1__type_4 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1__type_4& operator[] (int index) /* const */
  {
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - (6) ];
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Directory", i * 320 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 320 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 320 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 320 + os);i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1__type_6
{
 public:
  mu_1_Message array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_6 (char *n, int os) { set_self(n, os); };
  mu_1__type_6 ( void ) {};
  virtual ~mu_1__type_6 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_6& operator= (const mu_1__type_6& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_6& a, mu_1__type_6& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_6::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_6::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_6::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 72 + os);
    delete[] s;
  }
};
mu_1__type_6::~mu_1__type_6()
{
}
/*** end array declaration ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1__type_7
{
 public:
  mu_1__type_6 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_7 (char *n, int os) { set_self(n, os); };
  mu_1__type_7 ( void ) {};
  virtual ~mu_1__type_7 ();
  mu_1__type_6& operator[] (int index) /* const */
  {
    if ( ( index >= 6 ) && ( index <= 6 ) )
      return array[ index - (6) ];
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_7::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Directory", i * 216 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 216 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 216 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 216 + os);i++;
}
mu_1__type_7::~mu_1__type_7()
{
}
/*** end array declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1__type_8: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_8& val) { return mu__byte::operator=((int) val); };
  mu_1__type_8 (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_8 (void): mu__byte(0, 3, 3) {};
  mu_1__type_8 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_8 mu_1__type_8_undefined_var;

const int mu_ProcCount = 3;
const int mu_ValueCount = 2;
const int mu_NumVCs = 3;
const int mu_RequestChannel = 0;
const int mu_ForwardChannel = 1;
const int mu_ResponseChannel = 2;
const int mu_NetMax = 4;
const int mu_Proc_1 = 1;
const int mu_Proc_2 = 2;
const int mu_Proc_3 = 3;
const int mu_Value_1 = 4;
const int mu_Value_2 = 5;
const int mu_Directory = 6;
const int mu_GetS = 7;
const int mu_GetM = 8;
const int mu_PutS = 9;
const int mu_PutM = 10;
const int mu_Data = 11;
const int mu_InvAck = 12;
const int mu_InvAllAck = 13;
const int mu_PutAck = 14;
const int mu_FwdGetSAck = 15;
const int mu_FwdGetMAck = 16;
const int mu_Inv = 17;
const int mu_FwdGetS = 18;
const int mu_FwdGetM = 19;
const int mu_Dir_M = 20;
const int mu_Dir_S = 21;
const int mu_Dir_I = 22;
const int mu_Dir_MX_D = 23;
const int mu_Dir_SM_A = 24;
const int mu_Dir_MM_A = 25;
const int mu_Proc_M = 26;
const int mu_Proc_S = 27;
const int mu_Proc_I = 28;
const int mu_Proc_IS_D = 29;
const int mu_Proc_IM_A = 30;
const int mu_Proc_IM_AD = 31;
const int mu_Proc_II_A = 32;
const int mu_Proc_SM_A = 33;
const int mu_Proc_SM_AD = 34;
const int mu_Proc_SI_A = 35;
const int mu_Proc_MI_A = 36;
const int mu_Proc_IS_DP = 37;
/*** Variable declaration ***/
mu_1_DirState mu_DirNode("DirNode",0);

/*** Variable declaration ***/
mu_1__type_3 mu_Procs("Procs",72);

/*** Variable declaration ***/
mu_1__type_5 mu_Net("Net",216);

/*** Variable declaration ***/
mu_1__type_7 mu_InBox("InBox",1496);

/*** Variable declaration ***/
mu_0_boolean mu_msg_processed("msg_processed",2360);

/*** Variable declaration ***/
mu_1_Value mu_LastWrite("LastWrite",2368);

void mu_Send(const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dst, const mu_1_Node& mu_src, const mu_1_VCType& mu_vc, const mu_1_Value& mu_value, const mu_1_Node& mu_fwd_to, const mu_1_AckCount& mu_ack_cnt)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

/*** begin multisetcount 0 declaration ***/
  int mu__intexpr9 = 0;
  {
  mu_1__type_4_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net[mu_dst].valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr9++;
        }
      if (mu_i == 4-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr9) < (mu_NetMax)) ) Error.Error("Assertion failed: Too many messages");
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_vc.isundefined())
  mu_msg.mu_vc.undefine();
else
  mu_msg.mu_vc = mu_vc;
if (mu_value.isundefined())
  mu_msg.mu_value.undefine();
else
  mu_msg.mu_value = mu_value;
if (mu_fwd_to.isundefined())
  mu_msg.mu_fwd_to.undefine();
else
  mu_msg.mu_fwd_to = mu_fwd_to;
if (mu_ack_cnt.isundefined())
  mu_msg.mu_ack_cnt.undefine();
else
  mu_msg.mu_ack_cnt = mu_ack_cnt;
mu_Net[mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Node& mu_n)
{
cout << "\n====================Error Msg====================\n";
cout << "mtype: ";
cout << ( mu_msg.mu_mtype );
cout << "\n";
cout << "src: ";
cout << ( mu_msg.mu_src );
cout << "\n";
cout << "src_state: ";
if ( (mu_msg.mu_src>=1 && mu_msg.mu_src<=3) )
{
mu_Procs[mu_msg.mu_src].mu_state.print();
}
else
{
mu_DirNode.mu_state.print();
}
cout << "dst_state: ";
if ( (mu_n>=1 && mu_n<=3) )
{
mu_Procs[mu_n].mu_state.print();
}
else
{
mu_DirNode.mu_state.print();
}
cout << "\n";
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

void mu_AddToSharersList(const mu_1_Node& mu_n)
{
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr10 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_DirNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr10++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( (mu__intexpr10) == (0) )
{
mu_DirNode.mu_sharers.multisetadd(mu_n);
}
};
/*** end procedure declaration ***/

mu_0_boolean mu_IsSharer(const mu_1_Node& mu_n)
{
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr11 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_DirNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr11++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
return (mu__intexpr11) > (0);
  Error.Error("The end of function IsSharer reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_IsSharerListEmpty()
{
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr12 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr12++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
return (mu__intexpr12) == (0);
  Error.Error("The end of function IsSharerListEmpty reached without returning values.");
};
/*** end function declaration ***/

void mu_RemoveFromSharersList(const mu_1_Node& mu_n)
{
/*** end multisetremove 0 declaration ***/
  mu_1__type_1_id mu__idexpr13;
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_DirNode.mu_sharers[mu_i]) == (mu_n) ) { mu__idexpr13 = mu_i; mu_DirNode.mu_sharers.multisetremove(mu__idexpr13); };
        }
      if (mu_i == 3-1) break;
    }
/*** end multisetremove 0 declaration ***/
};
/*** end procedure declaration ***/

void mu_SendInvReqToSharers(const mu_1_Node& mu_rqst)
{
{
for(int mu_p = 1; mu_p <= 3; mu_p++) {
bool mu__boolexpr14;
  if (!(mu_IsSharer( (int)mu_p ))) mu__boolexpr14 = FALSE ;
  else {
  mu__boolexpr14 = ((mu_p) != (mu_rqst)) ; 
}
if ( mu__boolexpr14 )
{
mu_Send ( mu_Inv, (int)mu_p, (int)mu_Directory, mu_ForwardChannel, mu_1_Value_undefined_var, mu_rqst, 0 );
}
};
};
};
/*** end procedure declaration ***/

void mu_DirReceive(mu_1_Message& mu_msg)
{
/*** Variable declaration ***/
mu_1__type_8 mu_cnt("cnt",0);

/*** begin multisetcount 4 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr15++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
mu_cnt = mu__intexpr15;
mu_msg_processed = mu_true;
switch ((int) mu_DirNode.mu_state) {
case mu_Dir_I:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_DirNode.mu_state = mu_Dir_S;
mu_AddToSharersList ( mu_msg.mu_src );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_DirNode.mu_value, mu_1_Node_undefined_var, 0 );
break;
case mu_GetM:
mu_DirNode.mu_state = mu_Dir_M;
mu_DirNode.mu_owner = mu_msg.mu_src;
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_DirNode.mu_value, mu_1_Node_undefined_var, (int)mu_cnt );
break;
case mu_PutS:
mu_Send ( mu_PutAck, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
case mu_PutM:
if ( !((mu_msg.mu_src) != (mu_DirNode.mu_owner)) ) Error.Error("Assertion failed: error at Dir_I: PutM from owner");
mu_Send ( mu_PutAck, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_Directory );
break;
}
break;
case mu_Dir_S:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_AddToSharersList ( mu_msg.mu_src );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_DirNode.mu_value, mu_1_Node_undefined_var, 0 );
break;
case mu_GetM:
if ( mu_IsSharer( mu_msg.mu_src ) )
{
if ( (mu_cnt) == (1) )
{
mu_DirNode.mu_state = mu_Dir_M;
}
else
{
mu_DirNode.mu_state = mu_Dir_SM_A;
mu_SendInvReqToSharers ( mu_msg.mu_src );
}
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_DirNode.mu_value, mu_1_Node_undefined_var, (mu_cnt) - (1) );
}
else
{
mu_DirNode.mu_state = mu_Dir_SM_A;
mu_SendInvReqToSharers ( mu_msg.mu_src );
mu_Send ( mu_Data, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_DirNode.mu_value, mu_1_Node_undefined_var, (int)mu_cnt );
}
mu_DirNode.mu_sharers.undefine();
mu_DirNode.mu_owner = mu_msg.mu_src;
break;
case mu_PutS:
mu_Send ( mu_PutAck, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
if ( mu_IsSharer( mu_msg.mu_src ) )
{
if ( (mu_cnt) == (1) )
{
mu_DirNode.mu_state = mu_Dir_I;
}
mu_RemoveFromSharersList ( mu_msg.mu_src );
}
break;
case mu_PutM:
if ( !((mu_msg.mu_src) != (mu_DirNode.mu_owner)) ) Error.Error("Assertion failed: error at Dir_S: PutM from owner");
mu_Send ( mu_PutAck, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_RemoveFromSharersList ( mu_msg.mu_src );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_Directory );
break;
}
break;
case mu_Dir_M:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_DirNode.mu_state = mu_Dir_MX_D;
mu_Send ( mu_FwdGetS, mu_DirNode.mu_owner, (int)mu_Directory, mu_ForwardChannel, mu_1_Value_undefined_var, mu_msg.mu_src, 0 );
mu_AddToSharersList ( mu_msg.mu_src );
mu_AddToSharersList ( mu_DirNode.mu_owner );
mu_DirNode.mu_owner = mu_Directory;
break;
case mu_GetM:
mu_DirNode.mu_state = mu_Dir_MM_A;
mu_Send ( mu_FwdGetM, mu_DirNode.mu_owner, (int)mu_Directory, mu_ForwardChannel, mu_1_Value_undefined_var, mu_msg.mu_src, 0 );
mu_DirNode.mu_value = mu_msg.mu_value;
mu_DirNode.mu_owner = mu_msg.mu_src;
break;
case mu_PutS:
mu_Send ( mu_PutAck, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
case mu_PutM:
if ( (mu_DirNode.mu_owner) == (mu_msg.mu_src) )
{
mu_DirNode.mu_value = mu_msg.mu_value;
mu_LastWrite = mu_DirNode.mu_value;
mu_DirNode.mu_owner = mu_Directory;
mu_DirNode.mu_state = mu_Dir_I;
}
mu_Send ( mu_PutAck, mu_msg.mu_src, (int)mu_Directory, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_Directory );
break;
}
break;
case mu_Dir_MX_D:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_PutS:
mu_msg_processed = mu_false;
break;
case mu_PutM:
mu_msg_processed = mu_false;
break;
case mu_FwdGetSAck:
if ( (mu_cnt) == (0) )
{
mu_DirNode.mu_state = mu_Dir_I;
}
else
{
mu_DirNode.mu_state = mu_Dir_S;
}
mu_DirNode.mu_value = mu_msg.mu_value;
mu_LastWrite = mu_DirNode.mu_value;
break;
case mu_Data:
if ( (mu_cnt) == (0) )
{
mu_DirNode.mu_state = mu_Dir_I;
}
else
{
mu_DirNode.mu_state = mu_Dir_S;
}
mu_DirNode.mu_value = mu_msg.mu_value;
mu_LastWrite = mu_DirNode.mu_value;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_Directory );
break;
}
break;
case mu_Dir_MM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_PutS:
mu_msg_processed = mu_false;
break;
case mu_PutM:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
case mu_FwdGetMAck:
mu_DirNode.mu_state = mu_Dir_M;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_Directory );
break;
}
break;
case mu_Dir_SM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_GetS:
mu_msg_processed = mu_false;
break;
case mu_GetM:
mu_msg_processed = mu_false;
break;
case mu_PutS:
mu_msg_processed = mu_false;
break;
case mu_PutM:
mu_msg_processed = mu_false;
break;
case mu_Data:
mu_msg_processed = mu_false;
break;
case mu_InvAllAck:
mu_DirNode.mu_state = mu_Dir_M;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_Directory );
break;
}
break;
}
};
/*** end procedure declaration ***/

void mu_ProcReceive(mu_1_Message& mu_msg, const mu_1_Proc& mu_p)
{
mu_msg_processed = mu_true;
{
  mu_1__type_2& mu_pstate = mu_Procs[mu_p].mu_state;
{
  mu_1_Value& mu_pvalue = mu_Procs[mu_p].mu_value;
{
  mu_1_AckCount& mu_pcnt = mu_Procs[mu_p].mu_ack_cnt;
switch ((int) mu_pstate) {
case mu_Proc_I:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_Send ( mu_InvAck, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_IS_D:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_Send ( mu_InvAck, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_pstate = mu_Proc_IS_DP;
break;
case mu_Data:
bool mu__boolexpr16;
bool mu__boolexpr17;
  if (!((mu_msg.mu_ack_cnt) == (0))) mu__boolexpr17 = FALSE ;
  else {
  mu__boolexpr17 = ((mu_msg.mu_src) == (mu_Directory)) ; 
}
  if (mu__boolexpr17) mu__boolexpr16 = TRUE ;
  else {
  mu__boolexpr16 = ((mu_DirNode.mu_owner) == (mu_msg.mu_src)) ; 
}
if ( mu__boolexpr16 )
{
mu_pstate = mu_Proc_S;
}
mu_pvalue = mu_msg.mu_value;
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_IS_DP:
switch ((int) mu_msg.mu_mtype) {
case mu_Data:
mu_pstate = mu_Proc_I;
mu_pvalue.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_IM_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_FwdGetS:
mu_msg_processed = mu_false;
break;
case mu_FwdGetM:
mu_msg_processed = mu_false;
break;
case mu_Data:
if ( (mu_msg.mu_src) == (mu_Directory) )
{
if ( (mu_msg.mu_ack_cnt) == (0) )
{
mu_pstate = mu_Proc_M;
}
else
{
if ( !((mu_pcnt) <= (0)) ) Error.Error("Assertion failed: error at Proc_IM_AD, ack_cnt > 0.");
mu_pcnt = (mu_pcnt) + (mu_msg.mu_ack_cnt);
if ( (mu_pcnt) == (0) )
{
mu_pstate = mu_Proc_M;
mu_Send ( mu_InvAllAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
}
else
{
mu_pstate = mu_Proc_IM_A;
}
}
}
else
{
mu_pstate = mu_Proc_M;
}
mu_pvalue = mu_msg.mu_value;
break;
case mu_InvAck:
mu_pcnt = (mu_pcnt) - (1);
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_IM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_FwdGetS:
mu_msg_processed = mu_false;
break;
case mu_FwdGetM:
mu_msg_processed = mu_false;
break;
case mu_InvAck:
mu_pcnt = (mu_pcnt) - (1);
if ( (mu_pcnt) == (0) )
{
mu_pstate = mu_Proc_M;
mu_Send ( mu_InvAllAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_S:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_pstate = mu_Proc_I;
mu_Send ( mu_InvAck, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_pvalue.undefine();
break;
case mu_PutAck:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_SM_AD:
switch ((int) mu_msg.mu_mtype) {
case mu_FwdGetS:
mu_msg_processed = mu_false;
break;
case mu_FwdGetM:
mu_msg_processed = mu_false;
break;
case mu_Inv:
mu_pstate = mu_Proc_IM_AD;
mu_Send ( mu_InvAck, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
case mu_Data:
if ( !((mu_msg.mu_src) == (mu_Directory)) ) Error.Error("Assertion failed: error at Proc_SM_AD, Data not from dir.");
if ( (mu_msg.mu_ack_cnt) == (0) )
{
mu_pstate = mu_Proc_M;
}
else
{
if ( !((mu_pcnt) <= (0)) ) Error.Error("Assertion failed: error at Proc_SM_AD, ack_cnt > 0.");
mu_pcnt = (mu_pcnt) + (mu_msg.mu_ack_cnt);
if ( (mu_pcnt) == (0) )
{
mu_pstate = mu_Proc_M;
mu_Send ( mu_InvAllAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
}
else
{
mu_pstate = mu_Proc_SM_A;
}
}
mu_pvalue = mu_msg.mu_value;
break;
case mu_InvAck:
mu_pcnt = (mu_pcnt) - (1);
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_SM_A:
switch ((int) mu_msg.mu_mtype) {
case mu_FwdGetS:
mu_msg_processed = mu_false;
break;
case mu_FwdGetM:
mu_msg_processed = mu_false;
break;
case mu_InvAck:
mu_pcnt = (mu_pcnt) - (1);
if ( (mu_pcnt) == (0) )
{
mu_pstate = mu_Proc_M;
mu_Send ( mu_InvAllAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
}
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_M:
switch ((int) mu_msg.mu_mtype) {
case mu_FwdGetS:
mu_pstate = mu_Proc_S;
mu_Send ( mu_FwdGetSAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_pvalue, mu_1_Node_undefined_var, 0 );
mu_Send ( mu_Data, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_pvalue, mu_1_Node_undefined_var, 0 );
break;
case mu_FwdGetM:
mu_pstate = mu_Proc_I;
mu_Send ( mu_Data, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_pvalue, mu_1_Node_undefined_var, 0 );
mu_Send ( mu_FwdGetMAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_pvalue.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_MI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_FwdGetS:
mu_pstate = mu_Proc_SI_A;
mu_Send ( mu_FwdGetSAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_pvalue, mu_1_Node_undefined_var, 0 );
mu_Send ( mu_Data, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_pvalue, mu_1_Node_undefined_var, 0 );
break;
case mu_FwdGetM:
mu_pstate = mu_Proc_II_A;
mu_Send ( mu_Data, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_pvalue, mu_1_Node_undefined_var, 0 );
mu_Send ( mu_FwdGetMAck, (int)mu_Directory, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
case mu_PutAck:
mu_pstate = mu_Proc_I;
mu_pvalue.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_SI_A:
switch ((int) mu_msg.mu_mtype) {
case mu_Inv:
mu_pstate = mu_Proc_II_A;
mu_Send ( mu_InvAck, mu_msg.mu_fwd_to, (int)mu_p, mu_ResponseChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
break;
case mu_PutAck:
mu_pstate = mu_Proc_I;
mu_pvalue.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
case mu_Proc_II_A:
switch ((int) mu_msg.mu_mtype) {
case mu_PutAck:
mu_pstate = mu_Proc_I;
mu_pvalue.undefine();
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_p );
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
}
}
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_DirNode.clear();
  mu_Procs.clear();
  mu_Net.clear();
  mu_InBox.clear();
  mu_msg_processed.clear();
  mu_LastWrite.clear();
}
void world_class::undefine()
{
  mu_DirNode.undefine();
  mu_Procs.undefine();
  mu_Net.undefine();
  mu_InBox.undefine();
  mu_msg_processed.undefine();
  mu_LastWrite.undefine();
}
void world_class::reset()
{
  mu_DirNode.reset();
  mu_Procs.reset();
  mu_Net.reset();
  mu_InBox.reset();
  mu_msg_processed.reset();
  mu_LastWrite.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_DirNode.print();
  mu_Procs.print();
  mu_Net.print();
  mu_InBox.print();
  mu_msg_processed.print();
  mu_LastWrite.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_DirNode.print_statistic();
  mu_Procs.print_statistic();
  mu_Net.print_statistic();
  mu_InBox.print_statistic();
  mu_msg_processed.print_statistic();
  mu_LastWrite.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_DirNode.print_diff(prevstate);
    mu_Procs.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
    mu_InBox.print_diff(prevstate);
    mu_msg_processed.print_diff(prevstate);
    mu_LastWrite.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_DirNode.to_state( newstate );
  mu_Procs.to_state( newstate );
  mu_Net.to_state( newstate );
  mu_InBox.to_state( newstate );
  mu_msg_processed.to_state( newstate );
  mu_LastWrite.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    return tsprintf("receive-blocked-vc, vc:%s, n:%s", mu_vc.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  return !(mu_InBox[mu_n][mu_vc].mu_mtype.isundefined());
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 12 )
      {
        if ( ( TRUE  ) ) {
              if (!(mu_InBox[mu_n][mu_vc].mu_mtype.isundefined())) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 0;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    mu_n.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_VCType mu_vc;
    mu_vc.value((r % 3) + 0);
    r = r / 3;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
if ( (mu_n>=6 && mu_n<=6) )
{
mu_DirReceive ( mu_InBox[mu_n][mu_vc] );
}
else
{
mu_ProcReceive ( mu_InBox[mu_n][mu_vc], (int)mu_n );
}
if ( mu_msg_processed )
{
mu_InBox[mu_n][mu_vc].undefine();
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_4_id mu_msg_idx;
    mu_msg_idx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    return tsprintf("receive-net, msg_idx:%s, n:%s", mu_msg_idx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_4_id mu_msg_idx;
    mu_msg_idx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  if (!mu_Net[mu_n].in(mu_msg_idx)) { return FALSE; }
  mu_1__type_4& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_msg_idx];
  mu_1__type_6& mu_box = mu_InBox[mu_n];
  return mu_box[mu_msg.mu_vc].mu_mtype.isundefined();
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 12;
    static mu_1__type_4_id mu_msg_idx;
    mu_msg_idx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 28 && mu_msg_idx.value()<4 )
      {
        if ( ( TRUE && mu_Net[mu_n].in(mu_msg_idx) ) ) {
  mu_1__type_4& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_msg_idx];
  mu_1__type_6& mu_box = mu_InBox[mu_n];
              if (mu_box[mu_msg.mu_vc].mu_mtype.isundefined()) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 12;
    mu_msg_idx.value((r % 4) + 0);
    r = r / 4;
    mu_n.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_4_id mu_msg_idx;
    mu_msg_idx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  mu_1__type_4& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_msg_idx];
  mu_1__type_6& mu_box = mu_InBox[mu_n];
if ( (mu_n>=6 && mu_n<=6) )
{
mu_DirReceive ( mu_msg );
}
else
{
mu_ProcReceive ( mu_msg, (int)mu_n );
}
if ( !(mu_msg_processed) )
{
mu_box[mu_msg.mu_vc] = mu_msg;
}
mu_chan.multisetremove(mu_msg_idx);
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("I ==(load)==> S, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_Proc_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 28;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 31 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_Proc_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 28;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_GetS, (int)mu_Directory, (int)mu_n, mu_RequestChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_p.mu_state = mu_Proc_IS_D;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("I ==(store)==> M, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_Proc_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 31;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 34 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_Proc_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 31;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_GetM, (int)mu_Directory, (int)mu_n, mu_RequestChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_p.mu_state = mu_Proc_IM_AD;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("S ==(store)==> M, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_Proc_S);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 34;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 37 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_Proc_S)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 34;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_GetM, (int)mu_Directory, (int)mu_n, mu_RequestChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_p.mu_state = mu_Proc_SM_AD;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("S ==(evict)==> I, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_Proc_S);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 37;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 40 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_Proc_S)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 37;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_PutS, (int)mu_Directory, (int)mu_n, mu_RequestChannel, mu_1_Value_undefined_var, mu_1_Node_undefined_var, 0 );
mu_p.mu_state = mu_Proc_SI_A;
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("M ==(evict)==> I, n:%s", mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
  return (mu_p.mu_state) == (mu_Proc_M);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 40;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 43 )
      {
        if ( ( TRUE  ) ) {
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
              if ((mu_p.mu_state) == (mu_Proc_M)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 40;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_ProcState& mu_p = mu_Procs[mu_n];
mu_Send ( mu_PutM, (int)mu_Directory, (int)mu_n, mu_RequestChannel, mu_p.mu_value, mu_1_Node_undefined_var, 0 );
mu_p.mu_state = mu_Proc_MI_A;
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<12)
    { R0.NextRule(what_rule);
      if (what_rule<12) return; }
  if (what_rule>=12 && what_rule<28)
    { R1.NextRule(what_rule);
      if (what_rule<28) return; }
  if (what_rule>=28 && what_rule<31)
    { R2.NextRule(what_rule);
      if (what_rule<31) return; }
  if (what_rule>=31 && what_rule<34)
    { R3.NextRule(what_rule);
      if (what_rule<34) return; }
  if (what_rule>=34 && what_rule<37)
    { R4.NextRule(what_rule);
      if (what_rule<37) return; }
  if (what_rule>=37 && what_rule<40)
    { R5.NextRule(what_rule);
      if (what_rule<40) return; }
  if (what_rule>=40 && what_rule<43)
    { R6.NextRule(what_rule);
      if (what_rule<43) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=11) return R0.Condition(r-0);
  if (r>=12 && r<=27) return R1.Condition(r-12);
  if (r>=28 && r<=30) return R2.Condition(r-28);
  if (r>=31 && r<=33) return R3.Condition(r-31);
  if (r>=34 && r<=36) return R4.Condition(r-34);
  if (r>=37 && r<=39) return R5.Condition(r-37);
  if (r>=40 && r<=42) return R6.Condition(r-40);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=11) { R0.Code(r-0); return; } 
  if (r>=12 && r<=27) { R1.Code(r-12); return; } 
  if (r>=28 && r<=30) { R2.Code(r-28); return; } 
  if (r>=31 && r<=33) { R3.Code(r-31); return; } 
  if (r>=34 && r<=36) { R4.Code(r-34); return; } 
  if (r>=37 && r<=39) { R5.Code(r-37); return; } 
  if (r>=40 && r<=42) { R6.Code(r-40); return; } 
}
int Priority(unsigned short r)
{
  if (r<=11) { return R0.Priority(); } 
  if (r>=12 && r<=27) { return R1.Priority(); } 
  if (r>=28 && r<=30) { return R2.Priority(); } 
  if (r>=31 && r<=33) { return R3.Priority(); } 
  if (r>=34 && r<=36) { return R4.Priority(); } 
  if (r>=37 && r<=39) { return R5.Priority(); } 
  if (r>=40 && r<=42) { return R6.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=11) return R0.Name(r-0);
  if (r>=12 && r<=27) return R1.Name(r-12);
  if (r>=28 && r<=30) return R2.Name(r-28);
  if (r>=31 && r<=33) return R3.Name(r-31);
  if (r>=34 && r<=36) return R4.Name(r-34);
  if (r>=37 && r<=39) return R5.Name(r-37);
  if (r>=40 && r<=42) return R6.Name(r-40);
  return NULL;
}
};
const unsigned numrules = 43;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 43


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
mu_DirNode.mu_state = mu_Dir_I;
mu_DirNode.mu_owner = mu_Directory;
mu_DirNode.mu_sharers.undefine();
{
for(int mu_v = 4; mu_v <= 5; mu_v++) {
mu_DirNode.mu_value = mu_v;
};
};
mu_LastWrite = mu_DirNode.mu_value;
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_Procs[mu_i].mu_state = mu_Proc_I;
mu_Procs[mu_i].mu_ack_cnt = 0;
mu_Procs[mu_i].mu_value.undefine();
};
};
mu_Net.undefine();
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_18() // Invariant "Invalid Processors are not present on Sharer's List"
{
bool mu__quant19; 
mu__quant19 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr20;
  if (!((mu_Procs[mu_n].mu_state) == (mu_Proc_I))) mu__boolexpr20 = TRUE ;
  else {
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr21 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( (mu_DirNode.mu_sharers[mu_i]) == (mu_n) ) mu__intexpr21++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
  mu__boolexpr20 = ((mu__intexpr21) == (0)) ; 
}
if ( !(mu__boolexpr20) )
  { mu__quant19 = FALSE; break; }
};
};
return mu__quant19;
};

bool mu__condition_22() // Condition for Rule "Invalid Processors are not present on Sharer's List"
{
  return mu__invariant_18( );
}

/**** end rule declaration ****/

int mu__invariant_23() // Invariant "If processor is in Modified state, there are no Sharers"
{
bool mu__quant24; 
mu__quant24 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__quant25; 
mu__quant25 = TRUE;
{
for(int mu_m = 1; mu_m <= 3; mu_m++) {
bool mu__boolexpr26;
bool mu__boolexpr27;
  if (!((mu_Procs[mu_n].mu_state) == (mu_Proc_M))) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_n) != (mu_m)) ; 
}
  if (!(mu__boolexpr27)) mu__boolexpr26 = TRUE ;
  else {
bool mu__boolexpr28;
  if (!((mu_Procs[mu_m].mu_state) != (mu_Proc_S))) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_Procs[mu_m].mu_state) != (mu_Proc_M)) ; 
}
  mu__boolexpr26 = (mu__boolexpr28) ; 
}
if ( !(mu__boolexpr26) )
  { mu__quant25 = FALSE; break; }
};
};
if ( !(mu__quant25) )
  { mu__quant24 = FALSE; break; }
};
};
return mu__quant24;
};

bool mu__condition_29() // Condition for Rule "If processor is in Modified state, there are no Sharers"
{
  return mu__invariant_23( );
}

/**** end rule declaration ****/

int mu__invariant_30() // Invariant "Processors in a valid state (S or M) match last write"
{
bool mu__quant31; 
mu__quant31 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr32;
bool mu__boolexpr33;
  if ((mu_Procs[mu_n].mu_state) == (mu_Proc_S)) mu__boolexpr33 = TRUE ;
  else {
  mu__boolexpr33 = ((mu_Procs[mu_n].mu_state) == (mu_Proc_M)) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = TRUE ;
  else {
  mu__boolexpr32 = ((mu_Procs[mu_n].mu_value) == (mu_LastWrite)) ; 
}
if ( !(mu__boolexpr32) )
  { mu__quant31 = FALSE; break; }
};
};
return mu__quant31;
};

bool mu__condition_34() // Condition for Rule "Processors in a valid state (S or M) match last write"
{
  return mu__invariant_30( );
}

/**** end rule declaration ****/

int mu__invariant_35() // Invariant "Values in memory matches value of last write, when shared or invalid"
{
bool mu__quant36; 
mu__quant36 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr37;
bool mu__boolexpr38;
  if ((mu_DirNode.mu_state) == (mu_Dir_S)) mu__boolexpr38 = TRUE ;
  else {
  mu__boolexpr38 = ((mu_DirNode.mu_state) == (mu_Dir_I)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = TRUE ;
  else {
  mu__boolexpr37 = ((mu_DirNode.mu_value) == (mu_LastWrite)) ; 
}
if ( !(mu__boolexpr37) )
  { mu__quant36 = FALSE; break; }
};
};
return mu__quant36;
};

bool mu__condition_39() // Condition for Rule "Values in memory matches value of last write, when shared or invalid"
{
  return mu__invariant_35( );
}

/**** end rule declaration ****/

int mu__invariant_40() // Invariant "Processor in I state implies the value is undefined"
{
bool mu__quant41; 
mu__quant41 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr42;
  if (!((mu_Procs[mu_n].mu_state) == (mu_Proc_I))) mu__boolexpr42 = TRUE ;
  else {
  mu__boolexpr42 = (mu_Procs[mu_n].mu_value.isundefined()) ; 
}
if ( !(mu__boolexpr42) )
  { mu__quant41 = FALSE; break; }
};
};
return mu__quant41;
};

bool mu__condition_43() // Condition for Rule "Processor in I state implies the value is undefined"
{
  return mu__invariant_40( );
}

/**** end rule declaration ****/

int mu__invariant_44() // Invariant "Processor in S state implies the value match memory"
{
bool mu__quant45; 
mu__quant45 = TRUE;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
bool mu__boolexpr46;
bool mu__boolexpr47;
  if (!((mu_DirNode.mu_state) == (mu_Dir_S))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_Procs[mu_n].mu_state) == (mu_Proc_S)) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = TRUE ;
  else {
  mu__boolexpr46 = ((mu_DirNode.mu_value) == (mu_Procs[mu_n].mu_value)) ; 
}
if ( !(mu__boolexpr46) )
  { mu__quant45 = FALSE; break; }
};
};
return mu__quant45;
};

bool mu__condition_48() // Condition for Rule "Processor in S state implies the value match memory"
{
  return mu__invariant_44( );
}

/**** end rule declaration ****/

int mu__invariant_49() // Invariant "Directory in S state implies non-empty sharer list"
{
bool mu__boolexpr50;
  if (!((mu_DirNode.mu_state) == (mu_Dir_S))) mu__boolexpr50 = TRUE ;
  else {
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr51 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr51++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
  mu__boolexpr50 = ((mu__intexpr51) > (0)) ; 
}
return mu__boolexpr50;
};

bool mu__condition_52() // Condition for Rule "Directory in S state implies non-empty sharer list"
{
  return mu__invariant_49( );
}

/**** end rule declaration ****/

int mu__invariant_53() // Invariant "Directory in I or M state implies empty sharer list"
{
bool mu__boolexpr54;
bool mu__boolexpr55;
  if ((mu_DirNode.mu_state) == (mu_Dir_I)) mu__boolexpr55 = TRUE ;
  else {
  mu__boolexpr55 = ((mu_DirNode.mu_state) == (mu_Dir_M)) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = TRUE ;
  else {
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr56 = 0;
  {
  mu_1__type_1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_DirNode.mu_sharers.valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr56++;
        }
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
  mu__boolexpr54 = ((mu__intexpr56) == (0)) ; 
}
return mu__boolexpr54;
};

bool mu__condition_57() // Condition for Rule "Directory in I or M state implies empty sharer list"
{
  return mu__invariant_53( );
}

/**** end rule declaration ****/

int mu__invariant_58() // Invariant "Directory in M state implies owner exists"
{
bool mu__boolexpr59;
  if (!((mu_DirNode.mu_state) == (mu_Dir_M))) mu__boolexpr59 = TRUE ;
  else {
  mu__boolexpr59 = ((mu_DirNode.mu_owner) != (mu_Directory)) ; 
}
return mu__boolexpr59;
};

bool mu__condition_60() // Condition for Rule "Directory in M state implies owner exists"
{
  return mu__invariant_58( );
}

/**** end rule declaration ****/

int mu__invariant_61() // Invariant "Directory in I or S state implies empty owner"
{
bool mu__boolexpr62;
bool mu__boolexpr63;
  if ((mu_DirNode.mu_state) == (mu_Dir_I)) mu__boolexpr63 = TRUE ;
  else {
  mu__boolexpr63 = ((mu_DirNode.mu_state) == (mu_Dir_S)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = TRUE ;
  else {
  mu__boolexpr62 = ((mu_DirNode.mu_owner) == (mu_Directory)) ; 
}
return mu__boolexpr62;
};

bool mu__condition_64() // Condition for Rule "Directory in I or S state implies empty owner"
{
  return mu__invariant_61( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Directory in I or S state implies empty owner", &mu__condition_64, NULL, FALSE},
{"Directory in M state implies owner exists", &mu__condition_60, NULL, FALSE},
{"Directory in I or M state implies empty sharer list", &mu__condition_57, NULL, FALSE},
{"Directory in S state implies non-empty sharer list", &mu__condition_52, NULL, FALSE},
{"Processor in S state implies the value match memory", &mu__condition_48, NULL, FALSE},
{"Processor in I state implies the value is undefined", &mu__condition_43, NULL, FALSE},
{"Values in memory matches value of last write, when shared or invalid", &mu__condition_39, NULL, FALSE},
{"Processors in a valid state (S or M) match last write", &mu__condition_34, NULL, FALSE},
{"If processor is in Modified state, there are no Sharers", &mu__condition_29, NULL, FALSE},
{"Invalid Processors are not present on Sharer's List", &mu__condition_22, NULL, FALSE},
};
const unsigned short numinvariants = 10;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
msg_processed:NoScalarset
LastWrite:ScalarsetVariable
Procs:ScalarsetArrayOfScalarset
InBox:ScalarsetArrayOfScalarset
Net:Complex
DirNode:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_Value[2];
  int undefined_class_mu_1_Value;// has the highest class number

  void Print_class_mu_1_Value();
  bool OnlyOneRemain_mu_1_Value;
  bool MTO_class_mu_1_Value()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Value)
      return FALSE;
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Value = TRUE;
    return FALSE;
  }
  int class_mu_1_Proc[3];
  int undefined_class_mu_1_Proc;// has the highest class number

  void Print_class_mu_1_Proc();
  bool OnlyOneRemain_mu_1_Proc;
  bool MTO_class_mu_1_Proc()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Proc)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Proc = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_Value;
  typedef int arr_mu_1_Value[2];
  arr_mu_1_Value * perm_mu_1_Value;
  arr_mu_1_Value * revperm_mu_1_Value;

  int size_mu_1_Value[2];
  bool reversed_sorted_mu_1_Value(int start, int end);
  void reverse_reversed_mu_1_Value(int start, int end);

  int * in_mu_1_Proc;
  typedef int arr_mu_1_Proc[3];
  arr_mu_1_Proc * perm_mu_1_Proc;
  arr_mu_1_Proc * revperm_mu_1_Proc;

  int size_mu_1_Proc[3];
  bool reversed_sorted_mu_1_Proc(int start, int end);
  void reverse_reversed_mu_1_Proc(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Value* perm, int size, mu_1_Value k);
  void GenPerm0(mu_1_Value* perm, int size, unsigned long& index);

  bool ok1(mu_1_Proc* perm, int size, mu_1_Proc k);
  void GenPerm1(mu_1_Proc* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Value()
{
  cout << "class_mu_1_Value:\t";
  for (int i=0; i<2; i++)
    cout << class_mu_1_Value[i];
  cout << " " << undefined_class_mu_1_Value << "\n";
}
void PermSet::Print_class_mu_1_Proc()
{
  cout << "class_mu_1_Proc:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_Proc[i];
  cout << " " << undefined_class_mu_1_Proc << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<2; i++)
      for (j=0; j<2; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Value Perm0[2];
    mu_1_Proc Perm1[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[12];
 in_mu_1_Value = new int[12];
 perm_mu_1_Value = new arr_mu_1_Value[2];
 revperm_mu_1_Value = new arr_mu_1_Value[2];
 in_mu_1_Proc = new int[12];
 perm_mu_1_Proc = new arr_mu_1_Proc[6];
 revperm_mu_1_Proc = new arr_mu_1_Proc[6];

    // Set perm and revperm
    count = 0;
    for (i=4; i<=5; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=2)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<2; i++)
      for (j=4; j<=5; j++)
        for (k=4; k<=5; k++)
          if (revperm_mu_1_Value[i][k-4]==j)   // k - base 
            perm_mu_1_Value[i][j-4]=k; // j - base 
    count = 0;
    for (i=1; i<=3; i++)
      {
        Perm1[0].value(i);
        GenPerm1(Perm1, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=1; j<=3; j++)
        for (k=1; k<=3; k++)
          if (revperm_mu_1_Proc[i][k-1]==j)   // k - base 
            perm_mu_1_Proc[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Value = 0;
    int i_mu_1_Proc = 0;
    size = 12;
    count = 12;
    for (i=0; i<12; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Value[i] = i_mu_1_Value;
      i_mu_1_Value += carry;
      if (i_mu_1_Value >= 2) { i_mu_1_Value = 0; carry = 1; } 
      else { carry = 0; } 
      in_mu_1_Proc[i] = i_mu_1_Proc;
      i_mu_1_Proc += carry;
      if (i_mu_1_Proc >= 6) { i_mu_1_Proc = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Value = new int[1];
 perm_mu_1_Value = new arr_mu_1_Value[1];
 revperm_mu_1_Value = new arr_mu_1_Value[1];
 in_mu_1_Proc = new int[1];
 perm_mu_1_Proc = new arr_mu_1_Proc[1];
 revperm_mu_1_Proc = new arr_mu_1_Proc[1];
  in[0] = TRUE;
    in_mu_1_Value[0] = 0;
    in_mu_1_Proc[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<2; i++)
    class_mu_1_Value[i]=0;
  undefined_class_mu_1_Value=0;
  OnlyOneRemain_mu_1_Value = FALSE;
  for (i=0; i<3; i++)
    class_mu_1_Proc[i]=0;
  undefined_class_mu_1_Proc=0;
  OnlyOneRemain_mu_1_Proc = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<12; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Value[2];
  int size_mu_1_Value[2];
  bool should_be_in_mu_1_Value[2];
  int start_mu_1_Proc[3];
  int size_mu_1_Proc[3];
  bool should_be_in_mu_1_Proc[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	    start_mu_1_Value[k] = start;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	    start_mu_1_Proc[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<2; i++) // set up
    should_be_in_mu_1_Value[i] = TRUE;
  for (i=0; i<2; i++) // to be in or not to be
    for (k=0; k<2; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Value[i][k]-4 >=start_mu_1_Value[k] 
	     && perm_mu_1_Value[i][k]-4 < start_mu_1_Value[k] + size_mu_1_Value[k]) )
  	    {
	      should_be_in_mu_1_Value[i] = FALSE;
	      break;
	    }
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_Proc[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Proc[i][k]-1 >=start_mu_1_Proc[k] 
	     && perm_mu_1_Proc[i][k]-1 < start_mu_1_Proc[k] + size_mu_1_Proc[k]) )
  	    {
	      should_be_in_mu_1_Proc[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<12; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Value[in_mu_1_Value[i]]) in[i] = FALSE;
      if (in[i] && !should_be_in_mu_1_Proc[in_mu_1_Proc[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      for (k=0; k<2; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Value[k]==j)
	      revperm_mu_1_Value[0][start++] = k+4;
    }
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Value[0][k]==j+4)
        perm_mu_1_Value[0][j]=k+4;
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Proc[k]==j)
	      revperm_mu_1_Proc[0][start++] = k+1;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)
        perm_mu_1_Proc[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Value* Perm, int size, mu_1_Value k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Value* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=2)
    {
      for (i=4; i<=5; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=4; i<=5; i++)
        revperm_mu_1_Value[count][i-4]=Perm[i-4].value();// i - base
      count++;
    }
}
bool PermSet::ok1(mu_1_Proc* Perm, int size, mu_1_Proc k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm1(mu_1_Proc* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=1; i<=3; i++)
        if(ok1(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm1(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=3; i++)
        revperm_mu_1_Proc[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Value(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Value[0][i]<revperm_mu_1_Value[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Value(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Value[0][j];
      revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][i];
      revperm_mu_1_Value[0][i] = temp;
    }
}
bool PermSet::reversed_sorted_mu_1_Proc(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Proc[0][i]<revperm_mu_1_Proc[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Proc(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Proc[0][j];
      revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][i];
      revperm_mu_1_Proc[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 2; )
    {
      end = start-1+size_mu_1_Value[revperm_mu_1_Value[0][start]-4];
      if (reversed_sorted_mu_1_Value(start,end))
	       {
	  reverse_reversed_mu_1_Value(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Value(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Value[0][j]<revperm_mu_1_Value[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Value[0][j];
			  revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][k];
			  revperm_mu_1_Value[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Value(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) {
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_Proc[revperm_mu_1_Proc[0][start]-1];
      if (reversed_sorted_mu_1_Proc(start,end))
	       {
	  reverse_reversed_mu_1_Proc(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Proc(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Proc[0][j]<revperm_mu_1_Proc[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Proc[0][j];
			  revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][k];
			  revperm_mu_1_Proc[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Proc(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
}
if (!nexted) return FALSE;
  for (j=0; j<2; j++)
    for (k=0; k<2; k++)
      if (revperm_mu_1_Value[0][k]==j+4)   // k - base 
	perm_mu_1_Value[0][j]=k+4; // j - base 
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)   // k - base 
	perm_mu_1_Proc[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_msg_processed.MultisetSort();
        mu_LastWrite.MultisetSort();
        mu_Procs.MultisetSort();
        mu_InBox.MultisetSort();
        mu_Net.MultisetSort();
        mu_DirNode.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]); // value - base
};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        value(1 + Perm.undefined_class_mu_1_Proc++);
      }
    else 
      {
        value(Perm.class_mu_1_Proc[value()-1]+1);
      }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        Perm.undefined_class_mu_1_Proc++;
      }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Value[Perm.in_mu_1_Value[i]][value()-4]); // value - base
};
void mu_1_Value::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-4]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-4)
            Perm.class_mu_1_Value[i]++;
        value(4 + Perm.undefined_class_mu_1_Value++);
      }
    else 
      {
        value(Perm.class_mu_1_Value[value()-4]+4);
      }
}
void mu_1_Value::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Value::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-4]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<2; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-4)
            Perm.class_mu_1_Value[i]++;
        Perm.undefined_class_mu_1_Value++;
      }
}
void mu_1_Value::ArrayLimit(PermSet& Perm) {}
void mu_1_Value::Limit(PermSet& Perm) {}
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Dir::Permute(PermSet& Perm, int i) {};
void mu_1_Dir::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Dir::Canonicalize(PermSet& Perm) {};
void mu_1_Dir::SimpleLimit(PermSet& Perm) {};
void mu_1_Dir::ArrayLimit(PermSet& Perm) {};
void mu_1_Dir::Limit(PermSet& Perm) {};
void mu_1_Dir::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]+(0)); // value - base
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      {
        if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
              if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
                Perm.class_mu_1_Proc[i]++;
            value(1 + Perm.undefined_class_mu_1_Proc++);
          }
        else 
          {
            value(Perm.class_mu_1_Proc[value()-1]+1);
          }
      }
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
            if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
              Perm.class_mu_1_Proc[i]++;
          Perm.undefined_class_mu_1_Proc++;
        }
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_VCType::Permute(PermSet& Perm, int i) {};
void mu_1_VCType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_VCType::Canonicalize(PermSet& Perm) {};
void mu_1_VCType::SimpleLimit(PermSet& Perm) {};
void mu_1_VCType::ArrayLimit(PermSet& Perm) {};
void mu_1_VCType::Limit(PermSet& Perm) {};
void mu_1_VCType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_AckCount::Permute(PermSet& Perm, int i) {};
void mu_1_AckCount::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_AckCount::Canonicalize(PermSet& Perm) {};
void mu_1_AckCount::SimpleLimit(PermSet& Perm) {};
void mu_1_AckCount::ArrayLimit(PermSet& Perm) {};
void mu_1_AckCount::Limit(PermSet& Perm) {};
void mu_1_AckCount::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
  mu_value.Permute(Perm,i);
  mu_fwd_to.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_value.SimpleCanonicalize(Perm);
  mu_fwd_to.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_value.SimpleLimit(Perm);
  mu_fwd_to.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Node value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[3][3];
  bool goodset_multisetindex[3];
  mu_1_Node temp;

  // compact
  for (i = 0, j = 0; i < 3; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 3; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 3; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].isundefined())
                && (*this)[k]>=1
                && (*this)[k]<=3)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].isundefined()
                          && (*this)[k]>=1
                          && (*this)[k]<=3
                          && pos_mu_1_Proc[j][(*this)[k]-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k]-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1_DirState::Permute(PermSet& Perm, int i)
{
  mu_owner.Permute(Perm,i);
  mu_value.Permute(Perm,i);
  mu_sharers.Permute(Perm,i);
};
void mu_1_DirState::SimpleCanonicalize(PermSet& Perm)
{
  mu_owner.SimpleCanonicalize(Perm);
  mu_value.SimpleCanonicalize(Perm);
};
void mu_1_DirState::Canonicalize(PermSet& Perm)
{
};
void mu_1_DirState::SimpleLimit(PermSet& Perm)
{
  mu_owner.SimpleLimit(Perm);
  mu_value.SimpleLimit(Perm);
};
void mu_1_DirState::ArrayLimit(PermSet& Perm){}
void mu_1_DirState::Limit(PermSet& Perm)
{
  mu_sharers.Limit(Perm);
};
void mu_1_DirState::MultisetLimit(PermSet& Perm)
{
  mu_sharers.MultisetLimit(Perm);
};
void mu_1__type_2::Permute(PermSet& Perm, int i) {};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_2::Canonicalize(PermSet& Perm) {};
void mu_1__type_2::SimpleLimit(PermSet& Perm) {};
void mu_1__type_2::ArrayLimit(PermSet& Perm) {};
void mu_1__type_2::Limit(PermSet& Perm) {};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_ProcState::Permute(PermSet& Perm, int i)
{
  mu_value.Permute(Perm,i);
};
void mu_1_ProcState::SimpleCanonicalize(PermSet& Perm)
{
  mu_value.SimpleCanonicalize(Perm);
};
void mu_1_ProcState::Canonicalize(PermSet& Perm)
{
};
void mu_1_ProcState::SimpleLimit(PermSet& Perm)
{
  mu_value.SimpleLimit(Perm);
};
void mu_1_ProcState::ArrayLimit(PermSet& Perm){}
void mu_1_ProcState::Limit(PermSet& Perm)
{
};
void mu_1_ProcState::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_ProcState value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[3];
  bool pos_mu_1_Proc[3][3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_3::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_ProcState value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[2][2];
  bool goodset_mu_1_Value[2];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2);
  while ( while_guard )
    {
      oldcount_mu_1_Proc = count_mu_1_Proc;
      oldcount_mu_1_Value = count_mu_1_Value;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1].mu_value.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1].mu_value.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1].mu_value-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1].mu_value-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard || count_mu_1_Value<2;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_4::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[2][2];
  bool goodset_mu_1_Value[2];
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[4][4];
  bool goodset_multisetindex[4];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 4; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 4; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 4; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Value = count_mu_1_Value;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_src.isundefined())
                && (*this)[k].mu_src>=1
                && (*this)[k].mu_src<=3)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && (*this)[k].mu_src>=1
                          && (*this)[k].mu_src<=3
                          && pos_mu_1_Proc[j][(*this)[k].mu_src-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_src-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_value.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_value.isundefined()
                          && pos_mu_1_Value[j][(*this)[k].mu_value-4])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k].mu_value-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_fwd_to.isundefined())
                && (*this)[k].mu_fwd_to>=1
                && (*this)[k].mu_fwd_to<=3)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_fwd_to.isundefined()
                          && (*this)[k].mu_fwd_to>=1
                          && (*this)[k].mu_fwd_to<=3
                          && pos_mu_1_Proc[j][(*this)[k].mu_fwd_to-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_fwd_to-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Value<2;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_4 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i)
{
  static mu_1__type_6 temp("Permute_mu_1__type_6",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_6::Canonicalize(PermSet& Perm){};
void mu_1__type_6::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_6::ArrayLimit(PermSet& Perm) {}
void mu_1__type_6::Limit(PermSet& Perm){}
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm){};
void mu_1__type_7::SimpleLimit(PermSet& Perm){}
void mu_1__type_7::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_6 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_7::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_6 value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[2][2];
  bool goodset_mu_1_Value[2];
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  // initializing pos array
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<2; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1][i0].mu_src.isundefined()
            ||(*this)[k+1][i0].mu_src!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1][i0].mu_src.isundefined()
                    && (*this)[k+1][i0].mu_src==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1][i0].mu_fwd_to.isundefined()
            ||(*this)[k+1][i0].mu_fwd_to!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1][i0].mu_fwd_to.isundefined()
                    && (*this)[k+1][i0].mu_fwd_to==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while ( while_guard )
    {
      oldcount_mu_1_Value = count_mu_1_Value;
      oldcount_mu_1_Proc = count_mu_1_Proc;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1][i0].mu_src.isundefined()
                &&(*this)[k+1][i0].mu_src!=k+1
                &&(*this)[k+1][i0].mu_src>=1
                &&(*this)[k+1][i0].mu_src<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1][i0].mu_src.isundefined()
                            && (*this)[k+1][i0].mu_src!=k+1
                            && (*this)[k+1][i0].mu_src>=1
                            && (*this)[k+1][i0].mu_src<=3
                            && pos_mu_1_Proc[j][(*this)[k+1][i0].mu_src-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1][i0].mu_fwd_to.isundefined()
                &&(*this)[k+1][i0].mu_fwd_to!=k+1
                &&(*this)[k+1][i0].mu_fwd_to>=1
                &&(*this)[k+1][i0].mu_fwd_to<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1][i0].mu_fwd_to.isundefined()
                            && (*this)[k+1][i0].mu_fwd_to!=k+1
                            && (*this)[k+1][i0].mu_fwd_to>=1
                            && (*this)[k+1][i0].mu_fwd_to<=3
                            && pos_mu_1_Proc[j][(*this)[k+1][i0].mu_fwd_to-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<2) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1][i0].mu_value.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<2; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1][i0].mu_value.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1][i0].mu_value-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1][i0].mu_value-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<2; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<2; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<2; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Value<2;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<2; i++)
        for (j=0; j<2; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<2; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
}
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_8::Permute(PermSet& Perm, int i) {};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_8::Canonicalize(PermSet& Perm) {};
void mu_1__type_8::SimpleLimit(PermSet& Perm) {};
void mu_1__type_8::ArrayLimit(PermSet& Perm) {};
void mu_1__type_8::Limit(PermSet& Perm) {};
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_msg_processed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_LastWrite.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_Procs.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_InBox.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_Net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
              mu_DirNode.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_DirNode.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_msg_processed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_msg_processed.MultisetSort();
          mu_LastWrite.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LastWrite.MultisetSort();
          mu_Procs.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Procs.MultisetSort();
          mu_InBox.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_InBox.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
          mu_DirNode.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_DirNode.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_msg_processed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_LastWrite.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_Procs.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Procs.MultisetSort();
              mu_InBox.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_Net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
              mu_DirNode.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_DirNode.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_msg_processed.MultisetSort();
      mu_LastWrite.MultisetSort();
      mu_Procs.MultisetSort();
      mu_InBox.MultisetSort();
      mu_Net.MultisetSort();
      mu_DirNode.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_msg_processed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_msg_processed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LastWrite.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LastWrite.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_DirNode.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_DirNode.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_LastWrite.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_DirNode.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_DirNode.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Procs.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Procs.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_DirNode.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_DirNode.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_LastWrite.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_DirNode.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_DirNode.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();
  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();
  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();
  mu_DirNode.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_DirNode.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_Procs.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Procs.MultisetSort();
      mu_InBox.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_InBox.MultisetSort();
      mu_Net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Net.MultisetSort();
      mu_DirNode.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_DirNode.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_LastWrite.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_DirNode.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_Procs.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_Procs.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Procs.MultisetSort();

  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();

  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();

  mu_DirNode.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_DirNode.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
