#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

static char text[TXT];
static char mila[WORD];
int wordsize;


int sumWord(char word[], int size) {

    int sum = 0;

    for (int i = 0; i < size; i++) {

        if (word[i] >= 65 && word[i] <= 90) {
            sum = sum + (word[i] - 64);
        }
        if (word[i] >= 97 && word[i] <= 122) {
            sum = sum + (word[i] - 96);
        }
    }
    return sum;
}


int geoValue(char c) {

    if (c >= 65 && c <= 90) {
        return (c - 64);
    }
    if (c >= 97 && c <= 122) {
        return (c - 96);
    } else return 0;
}


int help(char text[], int i, int sum) {
    int j = 0;
    int sumcheck = 0;
    while (sumcheck < sum && i < strlen(text)) {
        int isdig = text[i];
        if ((isdig >= 97 && isdig <= 122) || (isdig >= 65 && isdig <= 90)) {
            isdig = geoValue(text[i]);
            sumcheck = sumcheck + isdig;
        }
        if (sumcheck == sum) {
            return j;
        }
        j++;
        i++;

    }

    return -1;
}


int comp(char text[], char atbash[], int i, int wordsize) {
    int otheri = 0;
    int ansindex = 0;
    while (otheri < wordsize && (text[i] == 32 || text[i] == atbash[otheri])) {
        if (text[i] != 32) {
            otheri++;

        }
        ansindex++;
        i++;

    }

    if (otheri == wordsize) {
        return ansindex;
    }
    return 0;
}


void sameCharacters(char word[], int sizeArrWord, char text[], int sizeArrText) {
    printf("\n");
    printf("Anagram Sequences: ");

    int ans = 0;
    char temp[TXT] = " ";

    for (int i = 0; i < sizeArrText; i++) {

        if (text[i] < 65 || (text[i] > 90 && text[i] < 97) || text[i] > 122) {
            continue;
        }

        char string[TXT] = " ";
        int start = 0;
        int counter = sizeArrWord;
        strcpy(temp, word);

        int flag = 0;
        while (counter > 0) {

            if (flag == 1) {

                break;
            }

            for (int j = i; j < sizeArrText; j++) {

                if (flag == 1) {
                    break;
                }

                char c = text[j];

                for (int t = 0; t < sizeof(temp); t++) {

                    if (c == 32 && counter != 0) {

                        string[start++] = 32;
                        break;
                    }

                    if (temp[t] == c) {


                        string[start++] = c;
                        temp[t] = 0;
                        counter--;
                        break;
                    }

                    if (t == sizeof(temp) - 1) {
                        flag = 1;

                        break;
                    }
                }

            }
        }

        if (counter == 0) {
            if (ans == 1) {

                printf("~");

            }
            printf("%s", string);
            ans = 1;

        }

    }
}

int main() {
    //char tempo;
    //for(int i=0;i<WORD;i++){
    //if(tempo==' ')break;
    //scanf("%c",&tempo);
    //mila[i]=tempo;
    //}
    scanf("%s", mila);
    mila[strlen(mila)] = '\0';

    for (int i = 0; i < TXT; i++) {
        char temp;
        scanf("%c", &temp);
        if (temp == '~') {
            text[i] = '\0';
            break;
        }

        text[i] = temp;

    }

    int sum = sumWord(mila, WORD);
    int i = 0;
    int pa = 0;
    printf("Gematria Sequences: ");
    while (i < strlen(text)) {
        int isdig = text[i];
        int counter = -1;
        if ((isdig >= 97 && isdig <= 122) || (isdig >= 65 && isdig <= 90)) {
            counter = help(text, i, sum);
        }
        if (counter != -1) {
            if (pa == 0) {
                pa++;
            } else {
                printf("~");
            }
            for (int start = i; start <= i + counter; start++) {
                printf("%c", text[start]);
            }
        }
        i++;
    }

    char atbash[strlen(mila)];
    for (int i = 0; i < strlen(mila); i++) {
        int isdig = mila[i];
        int changed;
        if ((isdig >= 97 && isdig <= 122) || (isdig >= 65 && isdig <= 90)) {
            if ((isdig >= 97 && isdig <= 122)) {
                int dis = isdig - 97;
                changed = 122 - dis;
            } else {
                int d = isdig - 65;
                changed = 90 - d;
            }
            atbash[i] = changed;
        }
        atbash[i + 1] = '\0';
    }

    printf("\nAtbash Sequences: ");
    char rev[strlen(atbash)];
    int n = strlen(atbash) - 1;
    for (int i = 0; i < strlen(atbash); i++) {
        rev[n] = atbash[i];
        n--;
    }

    int pb = 0;
    for (int i = 0; i < strlen(text); i++) {

        char one = text[i];
        char two = atbash[0];
        char three = rev[0];
        int j = 0;
        int jj = 0;
        if (one == two) {

            j = comp(text, atbash, i, strlen(atbash));
        }
        if (one == three) {
            jj = comp(text, rev, i, sizeof(rev));
        }

        // if (j==strlen(atbash)||jj==sizeof(atbash)){
        if (j != 0 || jj != 0) {

            if (pb == 0) {
                pb++;
            } else { printf("~"); }
            if (j != 0) {
                for (int start = i; start < i + j; start++) {
                    printf("%c", text[start]);
                }
            } else if (jj != 0) {
                for (int start = i; start < i + jj; start++) {
                    printf("%c", text[start]);
                }
            }
        }
    }
//    printf("%d",strlen(mila));
    //      printf("%d",strlen(text));

    //sameCharacters(mila,countM,text,countT);
    sameCharacters(mila, strlen(mila), text, strlen(text));


    return 0;
}
