bool condicionReporteA(accion *nodo) {
    return (nodo->variacion > 0.5);
}

void mostrarEspecieYVariacion (accion *nodo) {
    char aux[20];
    floatAString(nodo->variacion, aux);
    printf("\tEspecie:\t%s  \t\tVariación:\t%s\n\n", nodo->especie, aux);
}

void reporteA () {
    
    accion *listaDeAcciones = init();
    
    accion *aux = listaDeAcciones; // Puntero auxiliar para ir recorriendo la lista

    printf("\n\n\n\t\t\t\tReporte A:\n\n\n");

    while (aux) {
        if (condicionReporteA (aux))
            mostrarEspecieYVariacion (aux);
        aux = aux->sgte;
    }
//      Recorre la lista mostrando las acciones que cumplan con la condición.

    liberarMemoriaDeLista(listaDeAcciones);

}
