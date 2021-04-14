#ifndef BIGINT_H_INCLUDED
#define BIGINT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std ;

class bigint{
private:
    vector<char>v;
public:
    bigint(){};
    bigint(string input);
    bigint(int x);
    void operator=(const bigint&B);
    int siz();
    void print();
    bigint add(const bigint&P);
    bigint sub(const bigint &P);
    bigint operator+(const bigint&P);
    friend ostream&operator<<(ostream&out, const bigint&P);

};
ostream&operator<<(ostream&out, const bigint&P);


#endif // BIGINT_H_INCLUDED