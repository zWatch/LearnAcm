#pragma once
inline int quick_logi32(unsigned int q){
    int ret=0;
    if(q&0xFFFF0000){ret+=16;q>>=16;}
    if(q&0xFF00){ret+=8;q>>=8;}
    if(q&0xF0){ret+=4;q>>=4;}
    if(q&0xC){ret+=2;q>>=2;}
    if(q&0x2){ret+=1;q>>=1;}
    return ret;
}
