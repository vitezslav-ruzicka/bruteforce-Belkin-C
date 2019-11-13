#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void loginPlace (char login[], char count[], int position[]) {
    //int *position = malloc(12);

    //projede kazdou pozici pole
    for (int i=0; i<12; i++) {
        //pohleda cely Count
        for (int x=0; x<62; x++) {
            //pokud se to bude rovnat tak se to ulozi
            if (login[i]==count[x]) {
                position[i]=x;
                //printf("%c %d - %d\n",login[i],x, position[i]);
            }
        }
    }
}

void nextPlace (char login[], char count[], int lenghtOfLogin, int lenghtOfCount) {
    //pomocna promenna -> pokud se predesle cislo rovna 61 (posledni znak)
    //tak aura se bude rovnat 1 -> posune rad v dalsim posunu loginu
    int aura=0;
    int place[lenghtOfLogin];

    loginPlace(login,count,place);

    for (int i=0; i<lenghtOfLogin; i++) {
        //pokud je i rovno 0
        //hlavni cast -> furt se toci dokola
        if (i==0) {
            if (login[i]==count[lenghtOfCount -1]) {
                login[i]=count[0];
                aura=1;

            } else {
                login[0]=count[place[0] +1];
            }
        }
            //pokud je i vetsi nez 0
            //mene dulezita cast
        else if (i>0) {
            //pokud je Login na miste i stejny jako
            //posledni znak v Count na poslednim miste
            if (login[i]==count[lenghtOfCount -1]) {
                login[i]=count[0];
                aura=1;
            }
                //pokud bylo byl predesly znak v Loginu stejnny jako
                //posledni znak v Count tak se aura zvetsi o 1
                //a to je znaeni posunout pristi Login o jedno vic
            else if (aura==1) {
                login[i]=count[place[i] +1];
                aura=0;
            } else {}
        }
    }
}

int main() {
    //abeceda
    char count[63]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0','/0'};

    //umisteni
    int place[12];
    char login[12];

    for(int e=0; e<13; ++e) {
        login[e]=0;
    }
    login[0]='b';


    while(1){
        nextPlace(login,count,12,63);
        for (int c=0; c<12; c++) {
            printf("%c", login[c]);
        }
        //sleep(1);
        printf("\n");
    }

    return 0;
}