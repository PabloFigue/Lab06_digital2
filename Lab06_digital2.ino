#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // Espera a que se abra el puerto serial
  }
  SPI.setModule(0);
  // Inicializa la tarjeta SD
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(12, OUTPUT);

  if (!SD.begin(12)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //empieza el menu
  Serial.println("Laboratorio 6 - Manejo de memoria SD");
  Serial.println("1. Mostrar archivo 1");
  Serial.println("2. Mostrar archivo 2");
  Serial.println("3. Mostrar archivo 3");
  Serial.println("Seleccione una opcion:");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readString();
    int opcion = data.toInt();
//    Serial.println(nombre);

    if (opcion == 1){
      Serial.println("Mostrando archivo 1...");
        myFile = SD.open("mario.txt");
          if (myFile) {
            Serial.println("mario.txt:");
        
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              Serial.write(myFile.  read());
            }
            // close the file:
            myFile.close();
          } else {
            // if the file didn't open, print an error:
            Serial.println("error opening mario.txt");
          }
    }else if (opcion == 2){
      Serial.println("Mostrando archivo 2...");
        myFile = SD.open("tod.txt");
          if (myFile) {
            Serial.println("tod.txt:");
        
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              Serial.write(myFile.read());
            }
            // close the file:
            myFile.close();
          } else {
            // if the file didn't open, print an error:
            Serial.println("error opening tod.txt");
          }
    }else if (opcion == 3){
      Serial.println("Mostrando archivo 3...");
        myFile = SD.open("yoshi.txt");
          if (myFile) {
            Serial.println("yoshi.txt:");
        
            // read from the file until there's nothing else in it:
            while (myFile.available()) {
              Serial.write(myFile.read());
            }
            // close the file:
            myFile.close();
          } else {
            // if the file didn't open, print an error:
            Serial.println("error opening yoshi.txt");
          }
    }else{
       Serial.println("Quieres guardar lo que introdujiste o abrir las imágenes guardadas?"); 
       Serial.println("Presiona 1 === Si quieres guardar"); 
       Serial.println("Presiona 2 === Si quieres abrir lo guardado"); 
       int bandera = 0;
       while (bandera == 0){
         String data2 = Serial.readString();
         opcion = data2.toInt();
         if (opcion == 1){
            Serial.println("Seleccionaste la funcion GUARDAR");
            int banderaS = 0;
            /*Serial.println("Porfavor ingresa el nombre con el que lo deseas guardar:");
            while (banderaS == 0){
              if (Serial.available()){
                 String nombre = Serial.readString();
                 banderaS = 1;
                 
                 SD.open(*
              }
            }*/            
            myFile = SD.open("save.txt", FILE_WRITE);
              if (myFile) {
              Serial.print("Writing to save.txt...");
              myFile.println(data); // imprimimos el string inicial
              myFile.println(""); //dejamos una linea de por medio
              // close the file:
              myFile.close();
              Serial.println("done.");
            } else {
              // if the file didn't open, print an error:
              Serial.println("error opening");
            }
            bandera = 1;
         }else if (opcion == 2){
            Serial.println("Seleccionaste la funcion ABRIR");
              myFile = SD.open("save.txt");
                if (myFile) {
                  Serial.println("save.txt:");
              
                  // read from the file until there's nothing else in it:
                  while (myFile.available()) {
                    Serial.write(myFile.read());
                  }
                  // close the file:
                  myFile.close();
                } else {
                  // if the file didn't open, print an error:
                  Serial.println("error opening save.txt");
                }
            bandera = 1;
         }
      }
    }
    
    delay(10);
    // Vuelve a mostrar el menú
    Serial.println("1. Mostrar archivo 1");
    Serial.println("2. Mostrar archivo 2");
    Serial.println("3. Mostrar archivo 3");
    Serial.println("Seleccione una opcion:");
  }
}
