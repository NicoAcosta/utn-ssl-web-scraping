char const separador = '.';

int stringAInt (char *array) {
    int i = 0, j = 0;
    char numero[20];
    while ( esNumeroPuntoComaOMenos ( array[i] ) ) {
        if ( array [i] == separador)
            i++;
        else {
            numero[j] = array[i];
            i++;
            j++;
        }
    }
    numero[j] = '\0';
    return atoi(numero);
}
