#include <stdio.h>
#include <string.h>

/*FILE *stdin, *stdout;
    sono definiti questi puntatori a file, dichiarati in stdio.h
    stdin: puntatore allo stream collegato alla tastiera
    stdout: puntatore allo streaem collegato allo schermo

*/

#define MAXS 30

int main(){

    int i;
    char str[MAXS + 1];

    fscanf(stdin, "%d", &i);
    printf(stdout, "%d\n", i);

    /*se volessimo leggere una stringa potremmo usare fgets(stringa, dimensione(con '\0'), buffer di lettura(quindi anche i file. non scarta \n);  )*/
    fgets(str, MAXS + 1, stdin);
    /*così elimino il \n che si salva quando schiaccio invio*/
    str[strlen(str) - 1] = '\0';
    
    printf("%s\n", str);
    return 0;
}