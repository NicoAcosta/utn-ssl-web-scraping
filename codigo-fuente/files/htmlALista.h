char    archivoHTML[]   = "lideres-bcba_limpio.html";
char    url[]           = "https://52.67.80.139/test/lideres-bcba_limpio.html";
char    encabezados[]   = "<td>Especie</td><td>Vto.</td><td>Cant. Nominal</td><td>Precio Compra</td><td>Precio Venta</td><td>Cant. Nominal</td><td>Último</td><td>Variación %</td><td>Apertura</td><td>Máximo</td><td>Mínimo</td><td>Cierre Ant.</td><td>Vol. Nominal</td><td>Monto Operado ($)</td><td>Cant. Ope.</td><td>Hora Cotización</td>";


accion * linea_HTML_A_Nodo (char linea[]) {

    accion * nodo = malloc(sizeof(accion));
    
    const char delimitador[] = "</td>";

    char *token = strtok(linea, delimitador);
    strcpy(nodo->especie, token);
    
    token = strtok(NULL, delimitador);
    strcpy(nodo->vto, token);
    
    token = strtok(NULL, delimitador);
    nodo->compra_cantidadNominal = stringAInt(token);
    
    token = strtok(NULL, delimitador);
    nodo->compra_precio = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->venta_precio = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->venta_cantidadNominal = stringAInt(token);
    
    token = strtok(NULL, delimitador);
    nodo->ultimo = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->variacion = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->apertura = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->maximo = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->minimo = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->cierreAnterior = stringAFloat(token);
    
    token = strtok(NULL, delimitador);
    nodo->volumenNominal = stringAInt(token);
    
    token = strtok(NULL, delimitador);
    nodo->montoOperado = stringAInt(token);
    
    token = strtok(NULL, delimitador);
    nodo->cantidadOperaciones = stringAInt(token);
    
    token = strtok(NULL, delimitador);
    strcpy(nodo->horaCotizacion, token);
    
    nodo->sgte = NULL;

    return nodo;

}


accion *tabla_HTML_A_Lista () {
    
    FILE* archivo = fopen(archivoHTML, "r");

    irALaTabla(archivo, encabezados);

    char linea[340];

    accion* lista = NULL;

    fgets(linea, sizeof(linea), archivo);
    lista = linea_HTML_A_Nodo(linea);
    fgets(linea, sizeof(linea), archivo);
    fgets(linea, sizeof(linea), archivo);

    accion* aux1 = lista;

    while (!finDeTabla(linea)) {
        
        accion *nuevo = malloc(sizeof(accion));
        
        fgets(linea, sizeof(linea), archivo);
        nuevo = linea_HTML_A_Nodo(linea);
        fgets(linea, sizeof(linea), archivo);
        fgets(linea, sizeof(linea), archivo);

        aux1->sgte = nuevo;
        aux1 = nuevo;

    }

    fclose(archivo);

    return lista;
}


accion * init (){

    descargarPagina(url);
//      Descarga el archivo de texto html dada una url utilizando el comando wget y popen.
    
    accion *listaDeAcciones = tabla_HTML_A_Lista();
    /*
     -  Abre el archivo html descargado en modo “r”
     -  Avanza hasta encontrar los encabezados ( irALaTabla en funcionesArchivos.h )
     -  Hasta encontrar el fin de tabla, va cargando cada linea html que contiene información en un nodo acción *.
     (linea_HTML_A_Nodo en htmlALista.h ) Utilizando strtok y “</ td>” como delimitador para serparar los datos. (1)
     -  Cierra el archivo html
     -  Devuelve la lista de acciones.
     */

    int del = remove(archivoHTML);
//      Elimina el archivo html una vez que ya se cargaron los datos en la lista

    return listaDeAcciones;
//      Devuelve la lista de acciones
}
