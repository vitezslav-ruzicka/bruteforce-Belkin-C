#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void nextPlace(char login[], char count[], int place[]) {
    int x = 1;

    for (int i = 0; i < x; i++) {

        if (login[i] == count[61]) {
            login[i] = count[0];
            place[i] = 0;
            x++;
        } else {
            login[i] = count[place[i] + 1];
            place[i]++;
        }
    }
}

void setup(char login[], char count[], int place[]) {

    for (int i = 0; i < 12; i++) {
        place[i] = -1;
        login[i] = 0;
    }
    login[0] = count[0];
    place[0] = 0;
}

int main() {
    //abeceda
    char count[63]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\0 '};

    //umisteni
    int place[12];
    char login[12];

    setup(login, count, place);

    while (1) {
        nextPlace(login, count, place);
        printf("%s\n", login);
    }
    return 0;
}
