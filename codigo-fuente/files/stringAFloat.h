const char delimitador = ',';

struct parteEnteraYSigno {
    float parteEntera;
    char signo;
};

typedef struct parteEnteraYSigno parteEnteraYSigno;

parteEnteraYSigno pEnteraYSigno (char *array) {
    int i = 0, j = 0;
    char pEntera[20];
    parteEnteraYSigno resultado;
    if (array[0] == '-'){
        resultado.signo = '-';
        i++;
    } else {
        resultado.signo = '+';
    }
    while (array[i] != delimitador) {
        pEntera[j] = array[i];
        i++;
        j++;
    }
    pEntera[j] = '\0';
    resultado.parteEntera = (float)atoi(pEntera);
    return resultado;
}

float potenciasDe10 (int exponente) {
    float n = 1;
    for (int i = exponente; i > 0; i--)
        n *= 10;
    return n;
}

float pFraccionaria (char *array){
    int i = 0, j = 1;
    float parteFrac = 0;
    while (array[i] != delimitador)
        i++;
    i++;
    while (esNumeroPuntoComaOMenos (array[i])) {
        parteFrac += ((float) array[i] - '0') / potenciasDe10(j);
        i++;
        j++;
    }
    return parteFrac;
}

float stringAFloat (char *array) {    
    if (pEnteraYSigno(array).signo == '-')
        return - ( pEnteraYSigno(array).parteEntera + pFraccionaria(array) );
    else
        return pEnteraYSigno(array).parteEntera + pFraccionaria(array);
}
