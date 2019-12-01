#include <cmath>
inline int ilog2_kf(int n){
    float q=(float)n;
    return (((*(int*)&q)>>23&31)+1)%32;
}

inline int quick_logi32(unsigned int q){
    int ret=0;
    if(q&0xFFFF0000){ret+=16;q>>=16;}
    if(q&0xFF00){ret+=8;q>>=8;}
    if(q&0xF0){ret+=4;q>>=4;}
    if(q&0xC){ret+=2;q>>=2;}
    if(q&0x2){ret+=1;q>>=1;}
    return ret;
}

#ifndef MAIN
#define MAIN QUICK_LOG
#include <iostream>
void checkEqual(int i){
if(floor(log2(i))!=(ilog2_kf(i))){
            std::cout<<"error:"<<i<<std::endl;
            std::cout<<"floor(log2(i)):"<<floor(log2(i))<<std::endl;
            std::cout<<"ilog2_kf(i):"<<ilog2_kf(i)<<std::endl;
        }
}

void checkEqual2(int i){
if(floor(log2(i))!=(quick_logi32(i))){
            std::cout<<"error:"<<i<<std::endl;
            std::cout<<"floor(log2(i)):"<<floor(log2(i))<<std::endl;
            std::cout<<"quick_logi32(i):"<<quick_logi32(i)<<std::endl;
        }
}


int main(){


    for(int i=1; i<1<<11; i++){
        checkEqual2(i);
    }

    int WaitCheck[]={1<<31, 1<<7, 0xFFFFFFFF};

    for(auto i : WaitCheck){
        checkEqual2(i);
    }
    
    std::cout<<"1:"<<quick_logi32(1)<<std::endl;
    std::cout<<"2:"<<quick_logi32(2)<<std::endl;
    std::cout<<"4:"<<quick_logi32(4)<<std::endl;

    return 0;
}
#endif

