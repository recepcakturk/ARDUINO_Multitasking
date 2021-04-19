//ARDUINO ile Multitasking (Çoklu İşlemler) Yöntemi

/* Arduinomuza bağlı bir kırmızı, mavi ledler ve buton var.Şimdi kırmızı ledimiz 1 saniye aralıklarla yanıp 
sönsünerken kendi kendine(*BLİNK), biz ise butona basarak mavi ledi yakıp söndürüyoruz.
AMA Arduinomuzdaki işlemci tekbir işlem yapabilmektedir(çoklu işlemler yapamamakta). 
İşte bu yüzden  MULTİTASKİNG (ÇOKLU GÖREV) yöntemi kodları devriyeye giriyor .*/

#define KIRMIZI_LED 8  //KIRMIZI LED ARDUİNO'NUN 8. PİNİNE BAĞLI
#define MAVI_LED 7 //MAVİ LED ARDUİNO'NUN 7. PİNİNE BAĞLI
#define BUTON 2 //BUTON ARDUİNO'NUN 2. PİNİNE BAĞLI

bool ledDurum = true;

unsigned long eskiZaman = 0;// bu değişken olay gerçeklişti zamanı kaydeden fonks

void setup() 
{

 pinMode(KIRMIZI_LED,OUTPUT);
 pinMode(MAVI_LED,OUTPUT);
 pinMode(BUTON, INPUT_PULLUP);// INPUT_PULLUP = arduinonun içindeki direncleri aktif ederek butona direnc bağlamıyoruz 
 
}
void loop() 
{
  
if(millis() - eskiZaman > 1000)// şu anki zaman = milis() // önceki zaman = eskiZaman
{// ŞUAN Kİ ZAMANLA ESKİ ZAMAN ARASINDA Kİ FARK 1 SANİYEDEN FAZLA İSE ŞUANKİ ZAMANLA ESKİ ZAMANI EŞİTLE DEMEK
  eskiZaman = millis();//bu işlemin olduğu zamanı kaydet ve 1 saniye geçmesini bekle
  ledDurum= !ledDurum;// LED DURUMUNU TERSLE
  digitalWrite(KIRMIZI_LED, ledDurum);// TRUE İSE LED YANACAK FALSE İSE LED SÖNECEK
  
}

// short if :
digitalRead(BUTON)? digitalWrite(MAVI_LED, LOW):digitalWrite(MAVI_LED, HIGH);

}
