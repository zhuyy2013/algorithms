#ifndef ALGORITHMS_INCLUDE_ASTACK_H_
#define ALGORITHMS_INCLUDE_ASTACK_H_

const int ASTACK_extend_LENGTH = 16;
const int NA = -1;

class Astack {
 public:
  Astack();
  Astack(int n);
  ~Astack();
  void push(int val);
  int pop();
  int top();

 private:
  void extend_storage();

  int *data;
  int size;
  int current_top;
}

Astack::Astack() {
  current_top = -1;
  size = 0;
  extend_storage();
}

Astack::Astack(int n) {
  int m = (n + 16) / 16 * 16;
  if(m != 0) {
    current_top = -1;
    data = new int[m];
    size = m;
  } else {
    this->Astack();
  }
}

void Astack::push(int val) {
  if(current_top >= n - 1)
    extend_storage(); 
  data[current_top + 1] = val;
  ++current_top;
}

int Astack::top() {
  if(current_top >= 0)
    return data[current_top];
  else 
    return NA; 
}

int Astack::pop() {
  if(current_top >= 0) {
    current_top -= 1;
    return data[current_top + 1];
  } else {
    return NA;
  }
}
void Astack::extend_storage() {
  int *new_data = new int[n + ASTACK_EXTEND_LENGTH];  
  if(n > 0) {
    memcpy(new_data,data,sizeof(int) * n);
    free data[];
  }
  n += ASTACK_EXTEND_LENGTH;
  data = new_data;
}

#endif
