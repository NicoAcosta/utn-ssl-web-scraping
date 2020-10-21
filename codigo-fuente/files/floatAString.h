bool esNumeroPuntoComaOMenos (char c) {
    return  (   c == '1'  ||  c == '2'  ||  c == '3'  ||    c == '4'  ||  c == '5'  ||
                c == '6'  ||  c == '7'  ||  c == '8'  ||    c == '9'  ||  c == '0'  ||
                c == '-'  ||  c == '.'  ||  c == ','   );

}


void floatAString(float numero, char* destino) {
    
    char inicio[20];
    char final[20];

    sprintf(inicio, "%f", numero);
    
    char *token = strtok(inicio, ".");
    strcpy(final, token);
    strcat(final, ",");
    token = strtok (NULL, "\0");
    strcat(final, token);

    strcpy(destino, final);
}