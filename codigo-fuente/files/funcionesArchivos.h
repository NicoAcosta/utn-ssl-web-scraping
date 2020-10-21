FILE *popen(const char *command, const char *type);
int pclose(FILE *stream);

void descargarPagina(char *url){
    
    char cmd[200];
    strcpy(cmd, "wget ");
    strcat(cmd, url);
    strcat(cmd, " --no-check-certificate");
    
    FILE *pagina;
    pagina = popen(cmd,"r");
    pclose (pagina);

}

bool finDeTabla (char *linea){

    char *comparacion = strstr (linea, "</table>");
    if (comparacion == NULL)
        return false;
    else
        return true;

}

bool encabezadoDeTabla (char *linea, char *encabezado){

    char *comparacion = strstr (linea, encabezado);
    if (comparacion == NULL)
        return false;
    else
        return true;

}

void irALaTabla(FILE* archivo, char *encabezado) {

    char linea[340] = "";
    while (!encabezadoDeTabla(linea, encabezado)) {
        fgets(linea, sizeof(linea), archivo);
    }
    fgets(linea, sizeof(linea), archivo);
    fgets(linea, sizeof(linea), archivo);

}

void leerLinea (FILE *archivo, char *linea) {
    fgets(linea, sizeof(linea), archivo);
}
