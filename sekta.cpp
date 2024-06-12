#include <cstdio>
#include <vector>
using namespace std;

vector<long long> circle;
long long n;
long long k;

void sect(){
    //Wyczyszczenie poprzedniego wektora
    circle.clear();

    //Utworzenie aktualnego kręgu
    for(long long i=0; i<n; i++){
        circle.push_back(i+1);
    }
    
    //Osoba sprawdzana
    long long index = 1;

    //Licznik co 2 osoby
    int i = 0;
    
    //Pozycja zabitego
    long long killedPos = 0;

    //Szukamy osoby do odstarzłu
    while(k>0){        
        //Jezeli zrobilismy przeskok o 2 miejsca to zabijamy dana osobe i zapisujemy ostatnio zabita, jak o 1 to skaczemy dalej
        if(i%2==0){
            k--;
            killedPos = circle[index];
            circle.erase(circle.begin() + index);
        }else{
            index++;
        }
        i++; 

        //sprawdzamy czy zaczynamy nowe kolko 
        if ( index >= circle.size()){
            index=0;
        }       
    }
    //Wypisz osobe zabita 
    printf("%lld \n",killedPos);
}
void sect1stRound(){
    //Jeżeli osoba do odstrzału jest w pierwszym okrążeniu to mamy jej miejsce od razu
    printf("%lld \n",k*2);
}
void sortK(){
    if (k<0){ 
        k=k+1+n;
    } 
}
int msbIndex(unsigned long long number){
    int msb = 0;
    while (number != 0) {
        number >>= 1;
        msb++;
    }
    return msb - 1;
}
void sectBit(unsigned long long number){
    //przesuniecie bitowe w lewo
    number = number<<1;
    //zamiana msb na 0 i lsb na 1 = otrzymujemy nasze bezpieczne miejsce 
    number = number^(1ULL<<msbIndex(number));
    number = number^(1ULL<<0);
    printf("%lld\n",number);
}

int main(){
    long long m;
    scanf("%lld",&m);
    //Sprawdzenie czy podano odpowiednią ilość wierszy
    if(m<=0){
        printf("liczba wprowadzonych wierszy nie jest dodatnia, m=%lld",m);
        return 0;
    }

    //Wywołanie sekty dla każdego wiersza    
    for(long long i=0;i<m;i++){
        
        scanf("%lld %lld",&n,&k);

        sortK();

        if(k>n || n<=0){
            printf("zle wprowadzone argumenty dla sekty\n");   
        }
        else if(n==k){
            sectBit(n);
        }
        else if(k<=n/2){
            sect1stRound();
        }
        else{
            sect();
        }     
    }
    return 0;
}
