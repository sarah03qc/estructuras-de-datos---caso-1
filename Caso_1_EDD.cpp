

// Caso #1

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct fragmento {
    int numerodefrag; //una especie de identificador
    int color;   //representados por 1(rojo) 2(verde) 3(azul) y 4(amarillo)
}   uno, dos, tres, cuatro, cinco;


struct adyac {
    fragmento adyacentes[4]; //su longitud depende de la cantidad de fragmentos, para que sean suficientes, aunque sobren. Estos son los adyacentes
}   one, two, three, four, five;

struct mapa {
    adyac ady[5];
    int cantidad_frag;   //cantidad de fragmentos
    fragmento map[5];     //array de fragmentos para representar el mapa, en este caso son 5 fragmentos
}   mapa1;


void comprobar_teorema(mapa mapita) {
    //Funcion que asigna los colores y comprueba la validez del mapa de acuerdo al teorema
    //Recibe como parametro el mapa
    //Primero hacemos un ciclo que reciba los colores deseados para hacerlo interactivo y flexible
    int quantity = 0;   //este contador nos servira en la condicion de parada
    while (quantity < mapita.cantidad_frag) {
        //la vamos a ir incrementando 
        int colour;    //variable para guardar color
        cout << "1(rojo) 2(verde) 3(azul) y 4(amarillo)" << endl;
        cout << "Ingrese el color deseado para fragmento " << quantity + 1 << ": ";
        cin >> colour;   //recibimos el color
        mapita.map[quantity].color = colour;   //se lo asignamos al fragmento actual
        quantity++;   //incrementamos
    }
    //Lo anterior no le da color a los adyacentes, entonces lo hacemos nosotros
    for (int fragm = 0; fragm < 5; ++fragm) {
        for (int adyacen = 0; adyacen < 4; ++adyacen) {
            //Iteramos brevemente en los adyacentes, para darle color al mismo que su equivalente
            //Debido a que un numero jamas sera adyacente de si mismo debemos hacer una tercera 
            //iteracion para asi comparar cada adyacente con cada fragmento
            for (int fragm3 = 0; fragm3 < 5; ++fragm3) {
                //esta es la tercera iteracion
                int num_frag = mapita.map[fragm3].numerodefrag;
                int num_adya = mapita.ady[fragm].adyacentes[adyacen].numerodefrag; 
                if (num_frag == num_adya) {
                    //Si numero de frag es igual a numero identificador de adya significa
                    //que son el mismo, pero el array de adyacentes también debe tener color para 
                    //la verificacion futura del teorema, entonces le asignamos el color al fragmento 
                    //actual, desde una perspectiva donde es adyacente de otros 
                    mapita.ady[fragm].adyacentes[adyacen].color = mapita.map[fragm3].color;
                }
            }
        }
        
    }
    
    //Despues de haber asigando colores, revisaremos la validez del mapa de acuerdo con el teorema
    bool resultado = true;   //esta variable booleana se asume true hasta revisar cada adyacente
    //En caso de encontrar repeticiones de color en adyacentes se convierte en false 
    for (int frag = 0; frag < 5; ++frag) {
        //Iteramos en los fragmentos
        for (int adya = 0; adya < 4; ++adya) {
            //Iteramos en los adyacentes de cada fragmento
            int color_adya = mapita.ady[frag].adyacentes[adya].color;
            int color_frag_actual = mapita.map[frag].color;
            //Los hacemos variables para reconocerlos con mayor facilidad
            if (color_adya == color_frag_actual) {
                //Si el color del adyacente es igual al del fragmento actual, sin importar cual
                //sea cual, es automaticamente falso nuestro valor booleano
                resultado = false;
            }
        }
    }
    if (resultado == true) {
        //Si el valor booleano contiene true, esto significa que no tuvo modificaciones, por lo
        //tanto, los fragmentos no comparten color con ninguno de sus adyacentes
        cout << "El mapa es válido, de acuerdo al teorema de los 4 colores" << endl;
    } else {
        //Si el valor booleano contiene false, esto significa que tuvo modificaciones, por lo
        //tanto, los fragmentos si comparten color con al menos uno de sus adyacentes
        cout << "El mapa no es válido, de acuerdo al teorema de los 4 colores" << endl;
    } 
    
};  


int main ()
{
  uno.numerodefrag = 1;    //creamos los cinco fagmentos y les otorgamos numero respectivo
  dos.numerodefrag = 2;    //dicho entero otorgado es acorde con su nombre
  tres.numerodefrag = 3;
  cuatro.numerodefrag = 4;
  cinco.numerodefrag = 5;

  mapa1.map[0] = uno;     //ponemos cada fragmento en un lugar del array, en el mapa
  mapa1.map[1] = dos;
  mapa1.map[2] = tres;
  mapa1.map[3] = cuatro;
  mapa1.map[4] = cinco;
  
  
  //le otorgamos la cantidad de fragmentos que deseamos a la variable
  mapa1.cantidad_frag = 5;


  //lo siguientes adyacentes se basan en el numero respectivo otorgado previamente

  //es decir, en este primer fragmento los adyacentes son los fragmentos dos, tres y cuatro
  one.adyacentes[0] = dos;
  one.adyacentes[1] = tres;     //le proporcionamos los adyacentes al primer fragmento
  one.adyacentes[2] = cuatro;
 
  two.adyacentes[0] = uno;
  two.adyacentes[1] = tres;     //le proporcionamos los adyacentes al segundo fragmento
  two.adyacentes[2] = cuatro;
  two.adyacentes[3] = cinco;
 
  three.adyacentes[0] = uno;
  three.adyacentes[1] = dos;     //le proporcionamos los adyacentes al tercer fragmento
  three.adyacentes[2] = cuatro;
  three.adyacentes[3] = cinco;
 
  four.adyacentes[0] = uno;
  four.adyacentes[1] = dos;     //le proporcionamos los adyacentes al cuarto fragmento
  four.adyacentes[2] = tres;
  four.adyacentes[3] = cinco;
 
  five.adyacentes[0] = dos;
  five.adyacentes[1] = tres;     //le proporcionamos los adyacentes al quinto fragmento
  five.adyacentes[2] = cuatro;


  
  //Damos datos que ocupamos para acceder a todo en la Funcion, estos son como un "puente"
  mapa1.ady[0] = one;
  mapa1.ady[1] = two;
  mapa1.ady[2] = three;
  mapa1.ady[3] = four;
  mapa1.ady[4] = five;

  comprobar_teorema(mapa1);    //llamamos la funcion 

   
  return 0;
}
