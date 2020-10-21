void menu() {
    
    char caracter;
        
        printf("\n\n\n---------------------------------------------------------------\n\n\n");
        printf("Ingrese el número correspondiente a la opción deseada y presione Enter:\n\n");

        printf("1   -   Mostrar acciones líderes\n");
        printf("2   -   Reporte A\n");
        printf("3   -   Reporte B\n");
        printf("4   -   Reporte C\n");
        printf("5   -   Salir\n\n\n");

        fflush(stdin);
        caracter = getchar();

        switch (caracter)
        {
        case '1':
            mostrarTodasLasAcciones();
            break;
        case '2':
            reporteA();
            break;
    
        case '3':
            reporteB();
            break;

        case '4':
            reporteC();
            break;

        case '5':
            exit(0);
            break;

        default:
            printf("Presione una tecla adecuada.");
            break;
        }


}
