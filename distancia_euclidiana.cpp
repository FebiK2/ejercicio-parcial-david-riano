#include <iostream>
#include <cmath>
#include <cstdlib> //Se incluye para usar la función exit()

// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
/*Como puede modificar la declaración de la función para que sea mas eficiente en el manejo de memoria?
Teniendo en cuenta que solo necesita leer los valores, pero no modificarlos*/
double calcularDistancia(Point p1, Point p2)
{       
    // Completar: Usar la fórmula de distancia euclidiana
    // sugerencia: puede hacer uso de funcionines como sqrt y pow
    double primer_termino = ((p2.x - p1.x)*(p2.x - p1.x));
    double segundo_termino = ((p2.y - p1.y)*(p2.y - p1.y));
    double suma_cuadrados = primer_termino + segundo_termino;
    return sqrt(suma_cuadrados);
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char coma;
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    // Leer la respuesta del usuario
    std::cin >> respuesta;

    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == 's' || respuesta == 'S')
    {
        // Completar: Leer las coordenadas de cada punto
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> coma >> puntos[i].y;
            if (coma != ','){
                std::cout << "Por favor ingrese los datos con el formato (x, y)" << std::endl;
            }
                
            } 
        }
    
    else
    {
        // Si la cantidad de puntos es diferente de 4, entonces se retorna un mensaje de instrucción de uso y se termina el programa.
        if (n == 4){    
        // Usar puntos predeterminados
            std::cout << "Usando puntos predeterminados...\n" << std::endl;
            puntos[0] = {0, 0};  // Punto 1 (0, 0)
            puntos[1] = {3, 4};  // Punto 2 (3, 4)
            puntos[2] = {6, 8};  // Punto 3 (6, 8)
            puntos[3] = {9, 12}; // Punto 4 (9, 12)
        }
        else{
            std::cout << "Si va a usar los datos predeterminados, su longitud debe ser igual a 4" << std::endl;
            exit(1);
        }
    }
}


// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    double distancia_i; 
    double distanciaMinima = calcularDistancia(puntos[0],pUsuario);
    Point p1;

    for(int i = 1; i < n; i++){
        p1 = puntos[i];
        distancia_i = calcularDistancia(p1,pUsuario);
        if (distanciaMinima > distancia_i){
            distanciaMinima = distancia_i;
            indiceMasCercano = i;
        }
    }

    return distanciaMinima;
}

/*BONO:
Escribir una función que reciba un arreglo de puntos y devuelva la distancia total de los puntos que conforman el arreglo si estos fueran recorridos en orden.
*/
double arregloPuntos(Point puntos[], int n){

    double distancia_total = 0.0;
    double temp;
    for(int i = 0; i < n-1; i++){
        temp = calcularDistancia(puntos[i], puntos[i+1]);
        distancia_total += temp;
        
    }
    return distancia_total;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main()
{
    int n;

    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    // Leer el número de puntos
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        exit(1);
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)
    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);


    char coma;
    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    
    std::cin >> pUsuario.x >> coma >> pUsuario.y;
    if (coma != ','){
        std::cout << "Por favor ingrese los datos con el formato (x, y)" << std::endl;

    }

    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);

    char respuesta_bono;
    std::cout << "(Bono) ¿Desea calcular la distancia total de los puntos que conforman el arreglo si estos fueran recorridos en orden?(s/n): ";
    std::cin >> respuesta_bono;
    if (respuesta_bono == 's' || respuesta_bono == 'S'){
        std::cout << arregloPuntos(puntos,n) << std::endl;
    }

    return 0;
}