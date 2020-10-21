typedef struct accion accion;

struct accion {
    char    especie[6];
    char    vto[6];
    int     compra_cantidadNominal;
    float   compra_precio;
    float   venta_precio;
    int     venta_cantidadNominal;
    float   ultimo;
    float   variacion;
    float   apertura;
    float   maximo;
    float   minimo;
    float   cierreAnterior;
    int     volumenNominal;
    int     montoOperado;
    int     cantidadOperaciones;
    char    horaCotizacion[9];
    accion  *sgte;
};

void mostrarAccion (accion *unaAccion) {
        char aux[20];
        printf("Especie:                %s\n",      unaAccion->especie);
        printf("Vto.:                   %s\n",      unaAccion->vto);
        printf("Cant. Nominal Compra:   %d\n",      unaAccion->compra_cantidadNominal);
        floatAString(unaAccion->compra_precio, aux);
        printf("Precio Compra:          %s\n",      aux);
        floatAString(unaAccion->venta_precio, aux);
        printf("Precio Venta:           %s\n",      aux);
        printf("Cant. Nominal Venta:    %d\n",      unaAccion->venta_cantidadNominal);
        floatAString(unaAccion->ultimo, aux);
        printf("Último:                 %s\n",      aux);
        floatAString(unaAccion->variacion, aux);
        printf("Variación:              %s\n",      aux);
        floatAString(unaAccion->apertura, aux);
        printf("Apertura:               %s\n",      aux);
        floatAString(unaAccion->maximo, aux);
        printf("Máximo:                 %s\n",      aux);
        floatAString(unaAccion->minimo, aux);
        printf("Mínimo:                 %s\n",      aux);
        floatAString(unaAccion->cierreAnterior, aux);
        printf("Cierre Ant.:            %s\n",      aux);
        printf("Vol. Nominal:           %d\n",      unaAccion->volumenNominal);
        printf("Monto Operado:          %d\n",      unaAccion->montoOperado);
        printf("Cant. Ope.:             %d\n",      unaAccion->cantidadOperaciones);
        printf("Hora Cotización:        %s\n\n",    unaAccion->horaCotizacion);

}

void mostrarListaDeAcciones (accion *lista) {
    accion *aux = lista;
    while (aux) {
        mostrarAccion(aux);
        aux = aux->sgte;
    }
}

void liberarMemoriaDeLista(accion* lista) {

    accion *aux1 = lista;
    accion *aux2 = lista->sgte; 

    free(aux1);

    while (aux2) {
        aux1 = aux2;
        free(aux1);
        aux2 = aux2->sgte;
    }

}
