#include <iostream>
using namespace std;

/*
Se le ha encargado la tarea de realizar una tienda de alimentos virtuales. Para eso, debe crear la 
clase alimento, la cual cuenta con un nombre, precio y stock (4 para todos). Cree tres objetos en
el main. fruta ($5), snack ($4) y pastel ($7). Cree una clase carro. En este se almacenara un 
arreglo de alimentos, con una capacidad maxima de 10. Mediante una interfaz:
- Agregar algun alimento elegido de los 3 al carro (debe tener stock y espacio en mi carro)
- Obtener todo el dinero hasta ahora del carro
- Mostrar todos los alimentos del carro
. Mostrar el alimento mas caro
- COmparar un alimento con otro (precio) -> no debe ser opcion de interfaz
- Opcion salir*/

class Alimento{
    private:
        string nombre;
        int precio;
        int stock;
    public:
        Alimento(){}
        Alimento(string nombre, int precio){
            this->nombre = nombre;
            this->precio = precio;
            this->stock = 4;
        }
        // get
        string getNombre(){
            return nombre;
        }
        int getPrecio(){
            return precio;
        }
        int getStock(){
            return stock;
        }

        // set
        void setNombre(string nombre){
            this->nombre = nombre;
        }
        void setPrecio(int precio){
            this->precio = precio;
        }
        void setStock(int stock){
            this->stock = stock;
        }

        //Mostrar toda la informacion

        void mostrarInfoCarro(){
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Precio: "<<precio<<endl;
        }

        // Funcion que retorna 1 si el objeto que recibi es menor
        bool esMenorPrecio(Alimento al){
            if(precio < al.precio){
                return 0;
            } else if( precio > al.precio){
                return 1;
            }
        }
};

class Carrito{
    private:
        Alimento alimentos[10];
        int n=0;
    public:
        Carrito(){this->n = 0;}

        int getCantidadAlimentos(){
            return this->n;
        }

        //Metodo agregar alimentos
        void agregarAlimentos(Alimento a){
            alimentos[n] = a;
            n++;
        }

        //Metodo sumar costo
        void sumarCosto(){
            int total = 0;
            for(int i=0; i<n; i++){
                total = total + alimentos[i].getPrecio();
            }
            cout<<"Dinero acumulado de mi carrito: "<<total<<endl;
        }

        //Imprimir todo
        void mostrarAlimentos(){
            for(int i=0; i<n; i++){
                alimentos[i].mostrarInfoCarro();
                cout<<endl;
            }
        }

        void alimentoCaro(){
            if(n<1){
                cout<<"NO hay alimentos. "<<endl;
            }else{
                int referencia = alimentos[0].getPrecio();
                string nombre = alimentos[0].getNombre();
                for(int i=0; i<n; i++){
                    if(referencia < alimentos[i].getPrecio()){
                        referencia = alimentos[i].getPrecio();
                        nombre = alimentos[i].getNombre();
                    }
                } 
                cout<<"El alimento " <<nombre<<" es el mas caro, de "<<referencia<<endl;
                
            }
        }
};
int main(){

    Alimento fruta("fruta",4);
    Alimento snack("snack",4);
    Alimento pastel("pastel",7);

    Carrito compra = Carrito();
    int opcion;

    while(true){
        system("cls");
        cout<<"--------SUPERMERCADO---------"<<endl;
        cout<<"Digite su opcion"<<endl;
        cout<<"1) Comprar un alimento."<<endl;
        cout<<"2) Consultar total"<<endl;
        cout<<"3) Alimento mas caro del carrito"<<endl;
        cout<<"0) Salir." <<endl;
        cin>>opcion;

        if(opcion==0){
            break;
        }

        if(opcion ==1){
            system("cls");
            int eleccion;
            cout<<"Alimentos disponibles: "<<endl;
            cout<<"1- FRUTA("<<fruta.getStock()<<")"<<endl;
            cout<<"2- SNACK("<<snack.getStock()<<")"<<endl;
            cout<<"3- PASTEL("<<snack.getStock()<<")"<<endl;
            cin>>eleccion;

            if (eleccion == 1){
                if(fruta.getStock() > 0 && compra.getCantidadAlimentos()<10){
                    compra.agregarAlimentos(fruta);
                    fruta.setStock(fruta.getStock()-1);
                }else{
                    cout<<"No es posible realizar esta accion."<<endl;
                    system("pause");
                }
            }else if(eleccion == 2){
                if(snack.getStock() > 0 && compra.getCantidadAlimentos()<10){
                    compra.agregarAlimentos(snack);
                    snack.setStock(snack.getStock()-1);

                }else{
                    cout<<"No es posible realizar esta accion."<<endl;
                    system("pause");

                }
            }else if(eleccion == 3){
                if(pastel.getStock() > 0 && compra.getCantidadAlimentos()<10){
                    compra.agregarAlimentos(pastel);
                    pastel.setStock(pastel.getStock()-1);
                }else{
                    cout<<"No es posible realizar esta accion."<<endl;
                    system("pause");
                }
            }else{
                cout<<"Seleccion no valida"<<endl;
            }
        }

        else if(opcion ==2){
            compra.sumarCosto();
            system("pause");

        }
        else if(opcion==3){
            compra.alimentoCaro();
            system("pause");

        }
    } 
    return 0;
}