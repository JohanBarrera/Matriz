#include<iostream>

const int MAX=100; /*Tamaño Maximo de la Matriz*/

/*Definiendo una clase para la matriz*/

class Matriz{
    private:
/* Los atributos de la matriz sera privados*/
        int filas, columnas;
        int matriz[MAX][MAX];

    public:
    /* Generando el codigo constructor*/
    Matriz(int filas, int columnas):filas(filas), columnas(columnas){
        /* Debemos inicializarlo, ya que el objeto debe quedar con algo.*/
        for(int i=0; i<filas; ++i){
            // EL for va a ir inicializando cada elemento de la matriz a 0
            for(int j=0; j<columnas; ++j){
                matriz[i][j]= 0;
            }
        }
    }
/* Metodo para leer la matriz*/

    void leerMatriz(){
        std::cout<<"Introducir elementos de la matriz("<<filas<<"x"<<columnas<<"):\n";
            for(int i=0; i<filas; ++i){
            // EL for va a ir inicializando cada elemento de la matriz a los valores que determine el usuario
                for(int j=0; j<columnas; ++j){ //Modificar el atributo de Matriz, dandole valores al arreglo matriz.

                    std::cin>>matriz[i][j];
            }
        }
    }

    /* Metodo para Imprimir la matriz*/

    void ImprimirMatriz() const{ // Leera la matriz generada pero no alterara nada, ya que el const no lo permitira.
        std::cout<<"La matriz es:\n";
            for(int i=0; i<filas; ++i){
                for(int j=0; j<columnas; ++j){

                    std::cout<<matriz[i][j]<<"\t"; /*Va mostrando la matriz y luego salta de linea
a la siguiente y sigue mostrando.*/
            }
            std::cout<<std::endl;
        }
    }
    //Metodos de suma, resta, multiplicación 
    Matriz SumaMatriz(const Matriz &otra)const{ /* Las operaciones que se realicen me retornaran un objeto matriz
    de la clase Matriz, osea los valores que retornen de aui, tambien deben ser parte de la estructura de la clase 
    Matriz, el &otra genera una copia del onjeto con las mismas propiedades del onjeto inicial*/
    Matriz resultado(filas, columnas);/* Se instancia un objeto de la clase matriz, dandole sus valores de filas
    y columnas*/
    for (int i=0; i<filas; ++i){
       
        for (int j=0; j<columnas; ++j){/* el .matriz es la forma de acceder a el ultimo atributo que se necesitaba para 
        utilizar la clase Matriz*/
            resultado.matriz[i][j]=matriz[i][j]+otra.matriz[i][j]; /* otra.matriz genera una nueva matriz con los mismos atributos
            motivo por el cual esta terminara pidiendo al igual que la matriz inicial valores para contener.*/
        }
    }

    return resultado; // Devuelve un elemento matriz
}

    Matriz RestaMatriz(const Matriz &otra)const{ /* Las operaciones que se realicen me retornaran un objeto matriz
    de la clase Matriz, osea los valores que retornen de aui, tambien deben ser parte de la estructura de la clase 
    Matriz, el &otra genera una referencia a un objeto del tipo matriz, ese objeto se creara posteriormente en el main*/
    Matriz resultado(filas, columnas);/* Se instancia un objeto de la clase matriz, dandole sus valores de filas
    y columnas*/
    for (int i=0; i<filas; ++i){
       
        for (int j=0; j<columnas; ++j){/* el .matriz es la forma de acceder a el ultimo atributo que se necesitaba para 
        utilizar la clase Matriz*/
            resultado.matriz[i][j]=matriz[i][j]-otra.matriz[i][j]; /* otra.matriz genera una nueva matriz con los mismos atributos
            motivo por el cual esta terminara pidiendo al igual que la matriz inicial valores para contener.*/
        }
    }

    return resultado; // Devuelve un elemento matriz
}

Matriz ProductoMatriz(const Matriz &otra)const{
    Matriz resultado(filas, otra.columnas); //Genera en base a las columnas necesitadas otra copia.
    for (int i=0; i<filas; ++i){
       
        for (int j=0; j<otra.columnas; ++j){
                for(int k=0; k<columnas; ++k){
                    resultado.matriz[i][j]+=matriz[i][k]*otra.matriz[k][j];
                }
        }

    }
    return resultado;
}



    int getFilas() const{return filas;} /*Se utiliza para poder utilizar los valores
     de privado en cualquier clase afuera de ella.*/
    int getColumnas() const{return columnas;}



};



class Calculadora{
    public:
    void ejecutar(){
        int filasA, columnasA, filasB, columnasB;

        std::cout<<"Introduzca el numero de filas y columnas de la matriz A:"<<std::endl;
        std::cin>> filasA, columnasA;
        Matriz A(filasA, columnasA);

        A.leerMatriz();

        std::cout<<"Introduzca el numero de filas y columnas de la matriz B:"<<std::endl;
        std::cin>> filasB, columnasB;
        Matriz B(filasB, columnasB);

        B.leerMatriz();

        if(filasA==filasB && columnasA==columnasB){
            Matriz SumaMatriz1=A.SumaMatriz(B);
            std::cout<<"La suma es: \n";
            SumaMatriz1.ImprimirMatriz();

            Matriz RestaMatriz1=A.RestaMatriz(B);
            std::cout<<"La resta es: \n";
            RestaMatriz1.ImprimirMatriz();

        }else{
            std::cout<<"Las matrices no se pueden sumar"<<std::endl;
        }
    

    // Producto
    if(columnasA==filasB){
        Matriz resultado=A.ProductoMatriz(B);
        std::cout<<"El producto es: \n";
        resultado.ImprimirMatriz();
    }
    else{
        std::cout<<"error \n";
    }
    }

};

int main(){
    Calculadora MiCalculadora;
    MiCalculadora.ejecutar();
    return 0;
}
