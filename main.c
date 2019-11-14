#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
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
*/

void nextPlace (char login[], char count[], int place[], int lenghtOfCount) {
    //pomocna promenna -> pokud se predesle cislo rovna 61 (posledni znak)
    //tak aura se bude rovnat 1 -> posune rad v dalsim posunu loginu
    int aura=0;

    for (int i=11; i>=0; i--) {

        if (i==11) {
            if (login[i]==count[lenghtOfCount-1]) {
                login[i]=count[0];
                place[i]=0;
                aura=1;

            } else {
                login[i]=count[place[i] +1];
                place[i]++;
            }
        }
        else if (aura==1) {
            if (login[i]==count[lenghtOfCount-1]) {
                login[i]=count[0];
                place[i]=0;
                aura=1;

            } else {
                login[i]=count[place[i] +1];
                place[i]++;
            }
        }
    }
}

int main() {
    //abeceda
    char count[63]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0','/0 '};

    //umisteni
    int place[12];
    char login[12];

    for(int e=0; e<13; ++e) {
        login[e]=0;
        place[e]=0;
    }
    login[11]='a';
    place[11]=0;

    while(1){
        nextPlace(login,count,place,63);
        printf("%s\n", login);
        //sleep(1);
    }

    return 0;
}