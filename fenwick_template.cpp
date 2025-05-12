// normal fenwick PURQ
int fw[N];
void upd(int x, int v){
    for(; x<N; x+=x&-x)fw[x]+=v;
}
int sum(int x){
    int ret=0; 
    for(; x; x-=x&-x)ret+=fw[x];
    return ret;
}

// RUPQ
void UPD(int x, int y, int v){
    upd(x,v);
    upd(y+1,-v);
}

// binary search

int sum = 0, index = 0;
for (k = MSB_OF_N; k; k >>= 1) {
    if ((index + k <= N) && !some_condition(f[index + k])) {
        index += k;
        sum += f[index];
    }
}


