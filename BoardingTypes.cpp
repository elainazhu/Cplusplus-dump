#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
const int ttl = 1000;
ii a[ttl];
vector<iii> inplane;
void randomshuf(int xxxx){
    for(int i=2; i<=34; i++){
        for(int j=1; j<=6; j++){
            a[(i-2)*6+j]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 33*6+1,default_random_engine(xxxx));
    return;
}
void wilma(int xxxx){
    int did=0;
    for(int i=2; i<=34; i++){
        did++;
        a[did]=ii(i,1);
        did++;
        a[did]=ii(i,6);
    }
    shuffle(a+1, a+33*2+1, default_random_engine(xxxx));
    for(int i=2; i<=34; i++){
        did++;
        a[did]=ii(i,2);
        did++;
        a[did]=ii(i,5);
    }
    shuffle(a+33*2+1, a+33*4+1, default_random_engine(xxxx));
    for(int i=2; i<=34; i++){
        did++;
        a[did]=ii(i,3);
        did++;
        a[did]=ii(i,4);
    }
    shuffle(a+33*4+1, a+33*6+1, default_random_engine(xxxx));
    return;
}
void optimal(){
    int did=0;
    for(int i=34; i>=2; i--){
        did++;
        a[did]=ii(i,1);}
    for(int i=34; i>=2; i--){
        did++;
        a[did]=ii(i,6);
    }
    for(int i=34; i>=2; i--){
        did++;
        a[did]=ii(i,2);}
    for(int i=34; i>=2; i--){
        did++;
        a[did]=ii(i,5);
    }
    for(int i=34; i>=2; i--){
        did++;
        a[did]=ii(i,3);}
    for(int i=34; i>=2; i--){
        did++;
        a[did]=ii(i,4);
    }
    
    return;
}
void fronttobacksections(int xxxx){

    int did=0;
    for(int i=2; i<=12; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 11*6+1,default_random_engine(xxxx));
    for(int i=13; i<=23; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+11*6+1, a + 22*6+1,default_random_engine(xxxx));
    for(int i=24; i<=34; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+22*6+1, a + 33*6+1,default_random_engine(xxxx));
}
void backtofrontsections(int xxxx){
    int did=0;
    for(int i=24; i<=34; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 11*6+1,default_random_engine(xxxx));
    for(int i=13; i<=23; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+11*6+1, a + 22*6+1,default_random_engine(xxxx));
    for(int i=2; i<=12; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+22*6+1, a + 33*6+1,default_random_engine(xxxx));
}
void sections312(int xxxx){
    int did=0;
    for(int i=24; i<=34; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 11*6+1,default_random_engine(xxxx));
    for(int i=2; i<=12; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+11*6+1, a + 22*6+1,default_random_engine(xxxx));
    for(int i=13; i<=23; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+22*6+1, a + 33*6+1,default_random_engine(xxxx));
}
void sections213(int xxxx){
    int did=0;
    for(int i=13; i<=23; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 11*6+1,default_random_engine(xxxx));
    for(int i=2; i<=12; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+11*6+1, a + 22*6+1,default_random_engine(xxxx));
    for(int i=24; i<=34; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+22*6+1, a + 33*6+1,default_random_engine(xxxx));
}
void sections231(int xxxx){
    int did=0;
    for(int i=13; i<=23; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 11*6+1,default_random_engine(xxxx));
    for(int i=24; i<=34; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+11*6+1, a + 22*6+1,default_random_engine(xxxx));
    for(int i=2; i<=12; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+22*6+1, a + 33*6+1,default_random_engine(xxxx));
}
void sections132(int xxxx){
    int did=0;
    for(int i=2; i<=12; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+1, a + 11*6+1,default_random_engine(xxxx));
    for(int i=24; i<=34; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+11*6+1, a + 22*6+1,default_random_engine(xxxx));
    for(int i=13; i<=23; i++){
        for(int j=1; j<=6; j++){
            did++;
            a[did]=ii(i,j);
            //printf("a[%d]= (%d, %d)\n",(i-2)*6+j, i,j);
        }
    }
    shuffle(a+22*6+1, a + 33*6+1,default_random_engine(xxxx));
}
void steffen(){
    int did=0;
    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,1);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,1);
    }
    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,6);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,6);
    }

    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,2);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,2);
    }
    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,5);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,5);
    }

    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,3);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,3);
    }
    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,4);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,4);
    }
}
void steffenmodified(){
    int did=0;
    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,1);
        did++;
        a[did]=ii(i,2);
        did++;
        a[did]=ii(i,3);
    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,1);
        did++;
        a[did]=ii(i,2);
        did++;
        a[did]=ii(i,3);
    }
    for(int i=34; i>=2; i-=2){
        did++;
        a[did]=ii(i,6);
        did++;
        a[did]=ii(i,5);
        did++;
        a[did]=ii(i,4);

    }
    for(int i=33; i>=2; i-=2){
        did++;
        a[did]=ii(i,6);
        did++;
        a[did]=ii(i,5);
        did++;
        a[did]=ii(i,4);
    }
}