#include <cstdio>
#include <vector>
using namespace std;

vector<long long> arr;
vector<long long> :: iterator it;
long long n,k;
void sekta(){
    //wyczysc pprzedni wektor
    arr.clear();
    //utworzenie nowego wektoru
    for(long long i=0;i<n;i++){
        arr.push_back(i+1);
    }
    
    //poczatekowa osoba
    it = arr.begin()+1;
    int i =0;
    long long recentlyKilled = -1;
    if(k<=n/2){
        recentlyKilled=k*2;
    }
    else{
        while(k>0){        
            //jezeli zrobilismy przeskok o 2 miejsca to zabijamy dana osobe i zapisujemy ostatnio zabita jak o 1 to skaczemy dalej
            if(i%2==0){
                k--;
                recentlyKilled = *it;
                it = arr.erase(it);
            }else{
                ++it;
            }
            i++; 

            //sprawdzamy czy zaczynamy nowe kolko 
            if ( it == arr.end()){
                it = arr.begin();
            }       
        }
    }
    //wypisz osobe zabita na miejscu k
    printf("%lld \n",recentlyKilled);
}
long long minPow2(){
    long long pow=1;
    while(pow<k){
        pow*=2;
    }
    return pow;
}
void sortK(){
    if (k<0){ 
        k=k+1+n;
    } 
}
// void sekta(){
//     long long t;
//     if (k>0){ 
//         t=k;
//     } 
//     else{
//         t=k+1+n;
//     } 
//     long long p = minPow2();
// }
int msbIndex(unsigned long long n){
    int msb = 0;
    while (n != 0) {
        n >>= 1;
        msb++;
    }
    return msb - 1;
}
void sektaBit(unsigned long long n){
    //przesuniecie bitowe w lewo
    n = n<<1;
    //zamiana msb na 0 i lsb na 1 = otrzymujemy nasze bezpieczne miejsce 
    n = n^(1ULL<<msbIndex(n));
    n = n^(1ULL<<0);
    printf("%llu\n",n);
}

int main(){
    long long m;
    scanf("%lld",&m);
    if(m<=0){
        printf("liczba wprowadzonych wierszy nie jest dodatnia, m=%lld",m);
        return 0;
    }
        
    for(long long i=0;i<m;i++){
        
        scanf("%lld %lld",&n,&k);

        sortK();

        if(k>n || n<=0){
            printf("zle wprowadzone argumenty dla sekty\n");   
        }else if(n==k){
            sektaBit((unsigned long long)n);
        }
        else{
            sekta();
        }
        
    }
    return 0;
}
