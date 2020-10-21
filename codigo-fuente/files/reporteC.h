FILE* crearHTML () {
    FILE *html;
    html = fopen("reporteC.html","w");
    return html;
}

char title[] = "\t<title>Acciones Líderes</title>\n";
char estilo[] = "\t<style>\n\t\ttable {\n\t\t\tfont-family: arial, sans-serif;\n\t\t\tborder-collapse: collapse;\n\t\t\twidth: 100%;\n\t\t}\n\t\ttd, th {\n\t\t\tborder: 1px solid #dddddd;\n\t\t\ttext-align: left;\n\t\t\tpadding: 8px;\n\t\t}\n\t\ttr:nth-child(even) {\n\t\t\tbackground-color: #dddddd;\n\t\t}\n\t</style>\n";
char encabezadosHTML[] = "\t\t\t<tr>\n\t\t\t\t<th>Especie</th><th>Vto.</th><th>Cant. Nominal</th><th>Precio de compra</th><th>Precio de venta</th><th>Cant. Nominal</th><th>Último</th><th>Variación %</th><th>Apertura</th><th>Máximo</th><th>Mínimo</th><th>Cierre Ant.</th><th>Vol. Nominal</th><th>Monto Operado ($)</th><th>Cant. Ope.</th><th>Hora Cotización</th>\n\t\t\t</tr>\n";

void escribirStringEnHTML (FILE *archivo, char string[]) {
    fprintf(archivo, "%s", string);
}

bool condicionRojo (accion *nodo) {
    return (nodo->compra_precio > nodo->apertura   &&   nodo->venta_precio > nodo->apertura);
}

void escribirAccionEnHTML (FILE *archivo, accion *nodo) {
    
    char compra_precio[20];
    char venta_precio[20];
    char ultimo[20];
    char variacion[20];
    char apertura[20];
    char maximo[20];
    char minimo[20];
    char cierreAnt[20];
    
    floatAString(nodo->compra_precio, compra_precio);
    floatAString(nodo->venta_precio, venta_precio);
    floatAString(nodo->ultimo, ultimo);
    floatAString(nodo->variacion, variacion);
    floatAString(nodo->apertura, apertura);
    floatAString(nodo->maximo, maximo);
    floatAString(nodo->minimo, minimo);
    floatAString(nodo->cierreAnterior, cierreAnt);
    
    if (condicionRojo(nodo))
        fprintf(archivo, "\t\t\t<tr style=\"color:red;\">\n\t\t\t\t");
    else
        fprintf(archivo, "\t\t\t<tr>\n\t\t\t\t");
    
    fprintf(archivo, "<td>%s</td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%d</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td><td>%d</td><td>%d</td><td>%s</td>\n\t\t\t</tr>\n", nodo->especie, nodo->vto, nodo->compra_cantidadNominal, compra_precio, venta_precio, nodo->venta_cantidadNominal, ultimo, variacion, apertura, maximo, minimo, cierreAnt, nodo->volumenNominal, nodo->montoOperado, nodo->cantidadOperaciones, nodo->horaCotizacion);
}

void escribirAccionesEnHTML (FILE *archivo, accion *lista) {

    accion *aux = lista;
    
    fprintf (archivo, "<html>\n");
    escribirStringEnHTML(archivo, title);
    escribirStringEnHTML(archivo, estilo);
    fprintf (archivo, "\t<body>\n\t\t<table>\n");

    escribirStringEnHTML (archivo, encabezadosHTML);
    
    while (aux) {
        if (condicionReporteA(aux))
            escribirAccionEnHTML (archivo, aux);
        aux = aux->sgte;
    }

    fprintf (archivo, "\t\t</table>\n\t</body>\n</html>");

}


void reporteC() {

    accion *listaDeAcciones = init();

    printf("\n\n\n\t\t\t\tReporte C:\n\n\n");

    FILE *html = crearHTML();
    /*
     -  crea el archivo reporteC.html
     -  devuelve el FILE * al archivo abierto en modo “w”
     */

    escribirAccionesEnHTML (html, listaDeAcciones);
    /*
     -  escribe el titulo de la pagina
     -  escribe el estilo de la tabla
     -  escribe los encabezados
     -  recorre la lista escribiendo cada accion en una fila de la tabla.
     Si la acción cumple con la condición del reporte A, se utiliza el estilo de color rojo.
     Para esto último se debió utilizar CSS porque HTML5
     ya no soporta el tag <font> que permitía cambiar el color utilizando html.
     -  Todo lo anterior se realizó utilizando los tags correspondientes:
     html, body, table, th, tr, td.
     */

    fclose (html);

    printf("\n\nEl reporte se encuentra dentro del directorio de su usuario en el archivo \"reporteC.html\"\n\n");

    liberarMemoriaDeLista (listaDeAcciones);

}
