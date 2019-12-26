// рабочая программа
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h> // библиотека "RFID".
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;  // для храниения номера метки в десятичном формате
Servo servo;
void setup() {
  Serial.begin(9600);
  Serial.println("Waiting for card...");
  SPI.begin();  //  инициализация SPI / Init SPI bus.
  mfrc522.PCD_Init();     // инициализация MFRC522 / Init MFRC522 card.
  servo.attach(6);
  servo.write(0);  // устанавливаем серву в закрытое сосотояние
}
void loop() {
  // Поиск новой метки
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Выбор метки
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  uidDec = 0;
  // Выдача серийного номера метки.
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }
  Serial.println("Card UID: ");
  Serial.println(uidDec); // Выводим UID метки в консоль.


  Serial.print("UID=");
  
  view_data(mfrc522.uid.uidByte, mfrc522.uid.size);
  
  Serial.println();
  
  Serial.print("type=");
  
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  
  Serial.print(mfrc522.PICC_GetTypeName(piccType));

  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

void view_data (byte *buf, byte size) {

  for (byte j = 0; j < size; j++) {
  
  Serial.print(buf [j]);
  
  Serial.print(buf [j], HEX);
  
  }

}
