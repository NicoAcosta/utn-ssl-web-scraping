FILE* crearCSV () {
    FILE *csv;
    csv = fopen("reporteB.csv","w");
    return csv;
}

char encabezadosCSV[] = "Especie;Precio de compra;Precio de venta;Apertura;Precio Maximo;Precio Minimo\n";

void escribirEncabezadosEnCSV(FILE *archivo, char *encabezado) {
    fprintf(archivo, "%s", encabezadosCSV);
}

void escribirAccionEnCSV(FILE* archivo, accion *nodo) {

    char compra_precio[20];
    char venta_precio[20];
    char apertura[20];
    char maximo[20];
    char minimo[20];
    floatAString(nodo->compra_precio, compra_precio);
    floatAString(nodo->venta_precio, venta_precio);
    floatAString(nodo->apertura, apertura);
    floatAString(nodo->maximo, maximo);
    floatAString(nodo->minimo, minimo);

    fprintf(archivo, "%s;%s;%s;%s;%s;%s\n", nodo->especie, compra_precio, venta_precio, apertura, maximo, minimo);
}

void escribirAccionesEnCSV(FILE *archivo, accion*lista) {
    escribirEncabezadosEnCSV(archivo, encabezadosCSV);
    accion *aux = lista;
    while (aux) {
        escribirAccionEnCSV(archivo, aux);
        aux = aux->sgte;
    }
}

void reporteB () {

    accion *listaDeAcciones = init();
    
    printf("\n\n\n\t\t\t\tReporte B:\n\n\n");

    FILE *csv = crearCSV();
     /*
      -   crea el archivo reporteB.csv
      -   devuelve el FILE * al archivo abierto en modo “w”
      */
    
    escribirAccionesEnCSV(csv, listaDeAcciones); 
    /*
     -   escribe los encabezados separados por ";"
     -   recorre la lista escribiendo cada accion en una línea,
     con los datos separados por ";"
     */
    
    fclose(csv);

    printf("\n\nEl reporte se encuentra dentro del directorio de su usuario en el archivo \"reporteB.csv\"\n\n");

    liberarMemoriaDeLista(listaDeAcciones);
    
}
