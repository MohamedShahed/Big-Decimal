#include "bigint.h"

int main(){
    bigint x("-10"), y("100"),z;
    z=x.sub(y);
    cout<<z<<endl;



    return 0;
}