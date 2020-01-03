#ifndef COUNTER_H
#define COUNTER_H

class Counter{
  private:
    int n1 = 0;
  public:
    Counter() = default;
    Counter(int n1v) : n1(n1v){};
    int value();
};

#endif
