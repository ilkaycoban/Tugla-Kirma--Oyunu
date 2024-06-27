#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define EKRAN_BOYUTU 64
#define EKRAN_ENI 128

Adafruit_SSD1306 display(EKRAN_ENI, EKRAN_BOYUTU, &Wire, -1);

#define POTANSIYOMETRE_GIRIS A0
#define CAN1 13
#define CAN2 12
#define CAN3 11
#define yukari A3
#define asagi A2

class Palet {
  private:
    int x;
    int palet_eni;
    int palet_boyutu;

  public:
    Palet(int x, int palet_eni, int palet_boyutu) : x(x), palet_eni(palet_eni), palet_boyutu(palet_boyutu) {}

    void ciz() 
    {
      display.drawRect(x, EKRAN_BOYUTU - palet_boyutu-2, palet_eni, palet_boyutu, WHITE);
    }

    void setX(int as) 
    {
      x = as;
    }

    int getX() 
    {
      return x;
    }

    int getPalet_eni() 
    {
    return palet_eni;
    }
};


class Palet2 {
  private:
    int x;
    int y;
    int palet_eni;
    int palet_boyutu;

  public:
    Palet2(int x, int y,int palet_eni, int palet_boyutu) : x(x), y(y),palet_eni(palet_eni), palet_boyutu(palet_boyutu) {}

    void ciz() 
    {
      display.drawRect(x, y, palet_eni, palet_boyutu, WHITE);
    }

    void setX(int as) 
    {
      x = as;
    }
    void setY(int as) 
    {
      y = as;
    }

    int getX() 
    {
      return x;
    }

        int getY() 
    {
      return y;
    }

    int getPalet_eni() 
    {
    return palet_eni;
    }
};


class Kutu {
  private:
    int x;
    int y;

  public:
    Kutu(int x, int y) : x(x), y(y) {}

    void ciz() 
    {
      display.drawRect(x, y , 2, 2, WHITE);
    }

    void setX(int as) 
    {
      x = as;
    }
    
    void setY(int as) 
    {
      y = as;
    }

    int getX() 
    {
      return x;
    }

    int getY() 
    {
      return y;
    }

    void in()
    {
      setY(getY()+1);
    }

};

class Top {
  private:
    int x;
    int y;

  public:
    Top(int x, int y) : x(x), y(y) {}

    void ciz() 
    {
      display.fillCircle(x, y, 2, WHITE);
    }

    void sil() 
    {
      display.fillCircle(x, y, 2, BLACK);
    }

    void setX(int newX) 
    {
      x = newX;
    }

    void setY(int newY) 
    {
      y = newY;
    }

    int getX() 
    {
      return x;
    }

    int getY() 
    {
      return y;
    }

    void kuzeyBati() 
    {
      setX(getX() - 1);
      setY(getY() - 1);
    }

    void kuzeyDogu() 
    {
      setX(getX() + 1);
      setY(getY() - 1);
    }

    void guneyBati() 
    {
      setX(getX() - 1);
      setY(getY() + 1);
    }

    void guneyDogu() 
    {
      setX(getX() + 1);
      setY(getY() + 1);
    }

};

class Tugla {
  private:
    int x;
    int y;
    int en;
    int boyut;

  public:
    Tugla() {}

    Tugla(int x, int y, int en, int boyut) : x(x), y(y), en(en), boyut(boyut) {}

    void ciz() {
      display.fillRect(x, y, en, boyut, WHITE);
    }

    int getX() {
      return x;
    }

    int getY() {
      return y;
    }

    int getEn() {
      return en;
    }

    int getBoyut() {
      return boyut;
    }
    
};
 Tugla dizi1[2];
 Tugla dizi2[6];
 Tugla dizi3[8];
 Tugla dizi4[12];
 Tugla dizi5[6];


 int sayac1=0;
 int can=3;
 int i1=2;
 int i2=6;
 int i3=8;
 int i4=12;
 int i5=6;
 int puan = 0;
 int puant = 0;
 int esma = 0;
 int esma1 = 0; 
 int esma2 = 0;
 int hiz = 16; 


void setup() {
  Wire.begin();
  Serial.begin(9600);


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Oled yansitilamadi"));
    while(true);
  }


   randomSeed(analogRead(0));



  pinMode(yukari, INPUT);
  pinMode(asagi, INPUT_PULLUP);
  pinMode(CAN1, OUTPUT);
  pinMode(CAN2, OUTPUT);
  pinMode(CAN3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

//
 dizi1[0] = Tugla(43,1,20,7);
 dizi1[1] = Tugla(64,1,20,7);


//
 dizi2[0] = Tugla(1,1,20,7);
 dizi2[1] = Tugla(1,9,20,7);
 dizi2[2] = Tugla(22,1,20,7);
 dizi2[3] = Tugla(85,1,20,7);
 dizi2[4] = Tugla(106,1,20,7);
 dizi2[5] = Tugla(106,9,20,7);


//
 dizi3[0] = Tugla(1,1,20,7);
 dizi3[1] = Tugla(1,9,20,7);
 dizi3[2] = Tugla(22,1,20,7);
 dizi3[3] = Tugla(85,1,20,7);
 dizi3[4] = Tugla(106,1,20,7);
 dizi3[5] = Tugla(106,9,20,7);
 dizi3[6] = Tugla(22,9,20,7);
 dizi3[7] = Tugla(85,9,20,7);


 //
 dizi4[0] = Tugla(1,1,20,7);
 dizi4[1] = Tugla(43,9,20,7);
 dizi4[2] = Tugla(22,1,20,7);
 dizi4[3] = Tugla(85,1,20,7);
 dizi4[4] = Tugla(106,1,20,7);
 dizi4[5] = Tugla(64,9,20,7);
 dizi4[6] = Tugla(43,1,20,7);
 dizi4[7] = Tugla(64,1,20,7);
 dizi4[8] = Tugla(22,9,20,7);
 dizi4[9] = Tugla(85,9,20,7);
 dizi4[10] = Tugla(43,17,20,7);
 dizi4[11] = Tugla(64,17,20,7);



//
 dizi5[0] = Tugla(53,1,20,7);
 dizi5[1] = Tugla(32,9,20,7);
 dizi5[2] = Tugla(74,9,20,7);
 dizi5[3] = Tugla(53,17,20,7);
 dizi5[4] = Tugla(32,25,20,7);
 dizi5[5] = Tugla(74,25,20,7);



  display.clearDisplay();
}

int ali=0;
int bittimi=0;
int kontrol=-1;
int esmam1=0;
int esmam2=0;
int esmam3=0;
int esmam4=0;
Palet2 palet2(50,27, 30, 1);

 Top top(7,EKRAN_BOYUTU - 6);
 Kutu kutu(0,0);
void loop() {


if(ali==2)
{
   display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println(F("Oyunumuza Gosterdiginiz Ilgi Icin Tesekkur Ederiz."));

   display.display();

}



if(ali==0)
{
   display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(50, 20);  
  display.println(F("Basla"));
  display.setCursor(50, 37);
  display.println(F("Cikis"));

 
 int durum = digitalRead(yukari);
 int durum2 = digitalRead(asagi);
 if(durum2==LOW && palet2.getY()==47){
    ali=2;
 }


palet2.ciz();
 
  if(durum==1){
    
    palet2.setY(29);

  }else{
    
    palet2.setY(47);
  }
 if(durum2==LOW && palet2.getY()==29){
 bittimi=0;
 
 dizi1[0] = Tugla(43,1,20,7);
 dizi1[1] = Tugla(64,1,20,7);


//
 dizi2[0] = Tugla(1,1,20,7);
 dizi2[1] = Tugla(1,9,20,7);
 dizi2[2] = Tugla(22,1,20,7);
 dizi2[3] = Tugla(85,1,20,7);
 dizi2[4] = Tugla(106,1,20,7);
 dizi2[5] = Tugla(106,9,20,7);
//
 dizi3[0] = Tugla(1,1,20,7);
 dizi3[1] = Tugla(1,9,20,7);
 dizi3[2] = Tugla(22,1,20,7);
 dizi3[3] = Tugla(85,1,20,7);
 dizi3[4] = Tugla(106,1,20,7);
 dizi3[5] = Tugla(106,9,20,7);
 dizi3[6] = Tugla(22,9,20,7);
 dizi3[7] = Tugla(85,9,20,7);
 //
 dizi4[0] = Tugla(1,1,20,7);
 dizi4[1] = Tugla(43,9,20,7);
 dizi4[2] = Tugla(22,1,20,7);
 dizi4[3] = Tugla(85,1,20,7);
 dizi4[4] = Tugla(106,1,20,7);
 dizi4[5] = Tugla(64,9,20,7);
 dizi4[6] = Tugla(43,1,20,7);
 dizi4[7] = Tugla(64,1,20,7);
 dizi4[8] = Tugla(22,9,20,7);
 dizi4[9] = Tugla(85,9,20,7);
 dizi4[10] = Tugla(43,17,20,7);
 dizi4[11] = Tugla(64,17,20,7);
//
 dizi5[0] = Tugla(53,1,20,7);
 dizi5[1] = Tugla(32,9,20,7);
 dizi5[2] = Tugla(74,9,20,7);
 dizi5[3] = Tugla(53,17,20,7);
 dizi5[4] = Tugla(32,25,20,7);
 dizi5[5] = Tugla(74,25,20,7);



 sayac1=0; 
 can=3; 
 i1=2; 
 i2=6; 
 i3=8; 
 i4=12; 
 i5=6; 
 puan = 0; 
 esma =0; 
 esma1 = 0; 
 esma2 = 0;
 hiz = 16; 
 }
 
if(durum2==LOW && palet2.getY()==29&& bittimi==0)
{
  ali=1;
  durum2=0;  
}

  display.display();  

}

if(ali==1)
{
  esma = random(1, 6);


  display.clearDisplay();
  int p = analogRead(POTANSIYOMETRE_GIRIS);
  int paletX = map(p, 0, 1023, 0, EKRAN_ENI - 20);
  paletX = constrain(paletX, 0, EKRAN_ENI - 20);
  Palet palet(paletX, 20, 1);

  if(puan==2)
{
  if(esmam1==0&&top.getY()==57)
  {
    esmam1==1;
    delay(5000);
  }
}
  if(puan==8)
{
  if(esmam2==0&&top.getY()==57)
  {
    esmam2==1;
    delay(5000);
  }
}
  if(puan==16)
{
  if(esmam3==0&&top.getY()==57)
  {
    esmam3==1;
    delay(5000);
  }
}
  if(puan==28)
{
  if(esmam4==0&&top.getY()==57)
  {
    esmam4==1;
    delay(5000);
  }
}


  for (int j = 0; j < i1; j++) {
    dizi1[j].ciz();
  }

  if(i1==0)
  {
    for (int j = 0; j < i2; j++) {
    dizi2[j].ciz();
  }

  }

    if(i2==0)
  {
    for (int j = 0; j < i3; j++) {
    dizi3[j].ciz();
  }

  }
    if(i3==0)
  {
    for (int j = 0; j < i4; j++) {
    dizi4[j].ciz();
  }

  }
    if(i4==0)
  {
    for (int j = 0; j < i5; j++) {
    dizi5[j].ciz();
  }
  }

  int eskiX = top.getX();
  int eskiY = top.getY();

  if(sayac1==0)
  {
  top.kuzeyDogu();
  }
  if(sayac1==1)
  {
  top.guneyDogu();
  }
  if(sayac1==2)
  {
  top.guneyBati();
  }
  if(sayac1==3)
  {
  top.kuzeyBati();
  }


// dizi1 için blokları kontrol et
if(i2==6)
{
for (int j = 0; j < i1; j++) 
{
  //alttan çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi1[j].getY()==9)
    {
      if(top.getX()==dizi1[j].getX()+n)
      {
        if(eskiX>top.getX())
        {
          sayac1=2;
        }
        else
        {
        sayac1=1;
        }
        
        if(esma==1)
        {
          esma1=dizi1[j].getX();
          esma2=dizi1[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i1=i1-1;
        if(i1==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi1)/sizeof(dizi1[0]);
        int index=j;
        Tugla gecici = dizi1[index];
        for (int i = index; i <boyut; i++)
        {
        dizi1[i] = dizi1[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//sağdan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi1[j].getX()==22)
    {
      if(top.getY()==dizi1[j].getY()+n)
      {
        if(eskiY<top.getY())
        {
          sayac1=1;
        }
        else
        {
          sayac1=0;
        }

        if(esma==1)
        {
          esma1=dizi1[j].getX();
          esma2=dizi1[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i1=i1-1;
        if(i1==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi1)/sizeof(dizi1[0]);
        int index=j;
        Tugla gecici = dizi1[index];
        for (int i = index; i <boyut; i++)
        {
        dizi1[i] = dizi1[i+1];
        }
        puan=puan+1;

      }
    }
  }

  //üstten çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi1[j].getY()==-2)
    {
      if(top.getX()==dizi1[j].getX()+n)
      {
        if(eskiX<top.getX())
        {
          sayac1=0;
        }
        else
        {
        sayac1=3;
        }
        
        if(esma==1)
        {
          esma1=dizi1[j].getX();
          esma2=dizi1[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i1=i1-1;
        if(i1==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi1)/sizeof(dizi1[0]);
        int index=j;
        Tugla gecici = dizi1[index];
        for (int i = index; i <boyut; i++)
        {
        dizi1[i] = dizi1[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//soldan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi1[j].getX()==-2)
    {
      if(top.getY()==dizi1[j].getY()+n)
      {
        if(eskiY>top.getY())
        {
          sayac1=3;
        }
        else
        {
          sayac1=2;
        }

        if(esma==1)
        {
          esma1=dizi1[j].getX();
          esma2=dizi1[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i1=i1-1;
        if(i1==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi1)/sizeof(dizi1[0]);
        int index=j;
        Tugla gecici = dizi1[index];
        for (int i = index; i <boyut; i++)
        {
        dizi1[i] = dizi1[i+1];
        }
        puan=puan+1;
      }
    }
  }
}
}

// dizi2 için blokları kontrol et
if(i1==0&&i3==8)
{
for (int j = 0; j < i2; j++) 
{
  //alttan çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi2[j].getY()==9)
    {
      if(top.getX()==dizi2[j].getX()+n)
      {
        if(eskiX>top.getX())
        {
          sayac1=2;
        }
        else
        {
        sayac1=1;
        }
        
        if(esma==1)
        {
          esma1=dizi2[j].getX();
          esma2=dizi2[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i2=i2-1;
        if(i2==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi2)/sizeof(dizi2[0]);
        int index=j;
        Tugla gecici = dizi2[index];
        for (int i = index; i <boyut; i++)
        {
        dizi2[i] = dizi2[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//sağdan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi2[j].getX()==22)
    {
      if(top.getY()==dizi2[j].getY()+n)
      {
        if(eskiY<top.getY())
        {
          sayac1=1;
        }
        else
        {
          sayac1=0;
        }

        if(esma==1)
        {
          esma1=dizi2[j].getX();
          esma2=dizi2[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i2=i2-1;
        if(i2==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi2)/sizeof(dizi2[0]);
        int index=j;
        Tugla gecici = dizi2[index];
        for (int i = index; i <boyut; i++)
        {
        dizi2[i] = dizi2[i+1];
        }
        puan=puan+1;

      }
    }
  }

  //üstten çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi2[j].getY()==-2)
    {
      if(top.getX()==dizi2[j].getX()+n)
      {
        if(eskiX<top.getX())
        {
          sayac1=0;
        }
        else
        {
        sayac1=3;
        }

        if(esma==1)
        {
          esma1=dizi2[j].getX();
          esma2=dizi2[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i2=i2-1;
        if(i2==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi2)/sizeof(dizi2[0]);
        int index=j;
        Tugla gecici = dizi2[index];
        for (int i = index; i <boyut; i++)
        {
        dizi2[i] = dizi2[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//soldan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi2[j].getX()==-2)
    {
      if(top.getY()==dizi2[j].getY()+n)
      {
        if(eskiY>top.getY())
        {
          sayac1=3;
        }
        else
        {
          sayac1=2;
        }

        if(esma==1)
        {
          esma1=dizi2[j].getX();
          esma2=dizi2[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i2=i2-1;
        if(i2==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi2)/sizeof(dizi2[0]);
        int index=j;
        Tugla gecici = dizi2[index];
        for (int i = index; i <boyut; i++)
        {
        dizi2[i] = dizi2[i+1];
        }
        puan=puan+1;
      }
    }
  }
}
}

// dizi3 için blokları kontrol et
if(i2==0&&i4==12)
{
for (int j = 0; j < i3; j++) 
{
  //alttan çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi3[j].getY()==9)
    {
      if(top.getX()==dizi3[j].getX()+n)
      {
        if(eskiX>top.getX())
        {
          sayac1=2;
        }
        else
        {
        sayac1=1;
        }

        if(esma==1)
        {
          esma1=dizi3[j].getX();
          esma2=dizi3[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i3=i3-1;
        if(i3==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi3)/sizeof(dizi3[0]);
        int index=j;
        Tugla gecici = dizi3[index];
        for (int i = index; i <boyut; i++)
        {
        dizi3[i] = dizi3[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//sağdan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi3[j].getX()==22)
    {
      if(top.getY()==dizi3[j].getY()+n)
      {
        if(eskiY<top.getY())
        {
          sayac1=1;
        }
        else
        {
          sayac1=0;
        }

        if(esma==1)
        {
          esma1=dizi3[j].getX();
          esma2=dizi3[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i3=i3-1;
        if(i3==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi3)/sizeof(dizi3[0]);
        int index=j;
        Tugla gecici = dizi3[index];
        for (int i = index; i <boyut; i++)
        {
        dizi3[i] = dizi3[i+1];
        }
        puan=puan+1;

      }
    }
  }

  //üstten çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi3[j].getY()==-2)
    {
      if(top.getX()==dizi3[j].getX()+n)
      {
        if(eskiX<top.getX())
        {
          sayac1=0;
        }
        else
        {
        sayac1=3;
        }

        if(esma==1)
        {
          esma1=dizi3[j].getX();
          esma2=dizi3[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i3=i3-1;
        if(i3==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi3)/sizeof(dizi3[0]);
        int index=j;
        Tugla gecici = dizi3[index];
        for (int i = index; i <boyut; i++)
        {
        dizi3[i] = dizi3[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//soldan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi3[j].getX()==-2)
    {
      if(top.getY()==dizi3[j].getY()+n)
      {
        if(eskiY>top.getY())
        {
          sayac1=3;
        }
        else
        {
          sayac1=2;
        }

        if(esma==1)
        {
          esma1=dizi3[j].getX();
          esma2=dizi3[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i3=i3-1;
        if(i3==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi3)/sizeof(dizi3[0]);
        int index=j;
        Tugla gecici = dizi3[index];
        for (int i = index; i <boyut; i++)
        {
        dizi3[i] = dizi3[i+1];
        }
        puan=puan+1;
      }
    }
  }
}
}

// dizi4 için blokları kontrol et
if(i3==0&&i5==6)
{
for (int j = 0; j < i4; j++) 
{
  //alttan çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi4[j].getY()==9)
    {
      if(top.getX()==dizi4[j].getX()+n)
      {
        if(eskiX>top.getX())
        {
          sayac1=2;
        }
        else
        {
        sayac1=1;
        }

        if(esma==1)
        {
          esma1=dizi4[j].getX();
          esma2=dizi4[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i4=i4-1;
        if(i4==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi4)/sizeof(dizi4[0]);
        int index=j;
        Tugla gecici = dizi4[index];
        for (int i = index; i <boyut; i++)
        {
        dizi4[i] = dizi4[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//sağdan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi4[j].getX()==22)
    {
      if(top.getY()==dizi4[j].getY()+n)
      {
        if(eskiY<top.getY())
        {
          sayac1=1;
        }
        else
        {
          sayac1=0;
        }

        if(esma==1)
        {
          esma1=dizi4[j].getX();
          esma2=dizi4[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i4=i4-1;
        if(i4==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi4)/sizeof(dizi4[0]);
        int index=j;
        Tugla gecici = dizi4[index];
        for (int i = index; i <boyut; i++)
        {
        dizi4[i] = dizi4[i+1];
        }
        puan=puan+1;

      }
    }
  }

  //üstten çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi4[j].getY()==-2)
    {
      if(top.getX()==dizi4[j].getX()+n)
      {
        if(eskiX<top.getX())
        {
          sayac1=0;
        }
        else
        {
        sayac1=3;
        }

        if(esma==1)
        {
          esma1=dizi4[j].getX();
          esma2=dizi4[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i4=i4-1;
        if(i4==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi4)/sizeof(dizi4[0]);
        int index=j;
        Tugla gecici = dizi4[index];
        for (int i = index; i <boyut; i++)
        {
        dizi4[i] = dizi4[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//soldan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi4[j].getX()==-2)
    {
      if(top.getY()==dizi4[j].getY()+n)
      {
        if(eskiY>top.getY())
        {
          sayac1=3;
        }
        else
        {
          sayac1=2;
        }

        if(esma==1)
        {
          esma1=dizi4[j].getX();
          esma2=dizi4[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i4=i4-1;
        if(i4==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi4)/sizeof(dizi4[0]);
        int index=j;
        Tugla gecici = dizi4[index];
        for (int i = index; i <boyut; i++)
        {
        dizi4[i] = dizi4[i+1];
        }
        puan=puan+1;
      }
    }
  }
}
}

// dizi5 için blokları kontrol et
if(i4==0)
{
for (int j = 0; j < i5; j++) 
{
  //alttan çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi5[j].getY()==9)
    {
      if(top.getX()==dizi5[j].getX()+n)
      {
        if(eskiX>top.getX())
        {
          sayac1=2;
        }
        else
        {
        sayac1=1;
        }

        if(esma==1)
        {
          esma1=dizi5[j].getX();
          esma2=dizi5[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i5=i5-1;
        if(i5==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi5)/sizeof(dizi5[0]);
        int index=j;
        Tugla gecici = dizi5[index];
        for (int i = index; i <boyut; i++)
        {
        dizi5[i] = dizi5[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//sağdan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi5[j].getX()==22)
    {
      if(top.getY()==dizi5[j].getY()+n)
      {
        if(eskiY<top.getY())
        {
          sayac1=1;
        }
        else
        {
          sayac1=0;
        }

        if(esma==1)
        {
          esma1=dizi5[j].getX();
          esma2=dizi5[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i5=i5-1;
        if(i5==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi5)/sizeof(dizi5[0]);
        int index=j;
        Tugla gecici = dizi5[index];
        for (int i = index; i <boyut; i++)
        {
        dizi5[i] = dizi5[i+1];
        }
        puan=puan+1;

      }
    }
  }

  //üstten çarpma
  for(int n =-2; n< 23;n++)
  {
    if (top.getY()-dizi5[j].getY()==-2)
    {
      if(top.getX()==dizi5[j].getX()+n)
      {
        if(eskiX<top.getX())
        {
          sayac1=0;
        }
        else
        {
        sayac1=3;
        }

        if(esma==1)
        {
          esma1=dizi5[j].getX();
          esma2=dizi5[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }        
        i5=i5-1;
        if(i5==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi5)/sizeof(dizi5[0]);
        int index=j;
        Tugla gecici = dizi5[index];
        for (int i = index; i <boyut; i++)
        {
        dizi5[i] = dizi5[i+1];
        }
        puan=puan+1;

      }
    } 
  } 
//soldan çarpma  
  for(int n=-1;n<10;n++)
  {
    if(top.getX()-dizi5[j].getX()==-2)
    {
      if(top.getY()==dizi5[j].getY()+n)
      {
        if(eskiY>top.getY())
        {
          sayac1=3;
        }
        else
        {
          sayac1=2;
        }

        if(esma==1)
        {
          esma1=dizi5[j].getX();
          esma2=dizi5[j].getY();
          kutu.setX(esma1);
          kutu.setY(esma2);
        }
        i5=i5-1;
        if(i5==0)
        {
          top.setX(palet.getX()+8);
          top.setY(EKRAN_BOYUTU - 6);
        }
        int boyut = sizeof(dizi5)/sizeof(dizi5[0]);
        int index=j;
        Tugla gecici = dizi5[index];
        for (int i = index; i <boyut; i++)
        {
        dizi5[i] = dizi5[i+1];
        }
        puan=puan+1;
      }
    }
  }
}
}


if(i5==0)
{
sayac1=4;
}

if(esma1>0||esma2>0)
{

  if(kutu.getY()==EKRAN_BOYUTU-2 && (kutu.getX()>=palet.getX()-1 && kutu.getX()-palet.getX()<22))
  {
    esma1==0;
    esma2==0;
    if(can<3)
    {
    can=can+1;
    }
  }  
  kutu.in();
  if(!(kutu.getY()>EKRAN_BOYUTU-4))
  {
  kutu.ciz();
  }
}

  //ekranın kenarlarından dönme muhabbeti
  if(top.getX() >= EKRAN_ENI - 2)
  {
    if(eskiY<top.getY())
    {
      sayac1=2;
    }
    else
    {
      sayac1=3;
    }
  }

  if(top.getY() <= 2)
  {
    if(eskiX>top.getX())
    {
      sayac1=2;
    }
    else
    {
      sayac1=1;
    }
  }

  if(top.getX() <= 2)
  {
    if(eskiY<top.getY())
    {
      sayac1=1;
    }
    else
    {
      sayac1=0;
    }
  }

    if(top.getY() >= EKRAN_BOYUTU - 5)
  {
    if(top.getX()>palet.getX()&&top.getX()-palet.getX()<20)
    {
    if(eskiX>top.getX())
    {
      sayac1=3;
    }
    else
    {
      sayac1=0;
    } 
    }
  }

  if(top.getY() >= EKRAN_BOYUTU - 2)
  {
  
  top.setX(palet.getX()+8);
  top.setY(EKRAN_BOYUTU - 6);

  sayac1=0;
  can=can-1;
  if(can==0)
  {
    sayac1=4;

    ali=0;
    bittimi=1;

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(25, 20);
    display.println("Oyun bitti!");
    display.display();

  delay(3000);
  }
  }
  palet.ciz();
  top.ciz();

  
  eskiX = top.getX();
  eskiY = top.getY();
  display.display();
  if (can == 3) {
    digitalWrite(CAN1, 1);
    digitalWrite(CAN2, 1);
    digitalWrite(CAN3, 1);
  } else if (can == 2) {
    digitalWrite(CAN2, 1);
    digitalWrite(CAN1, 1);
    digitalWrite(CAN3, 0);
  } else if (can == 1) {
    digitalWrite(CAN3, 0);
    digitalWrite(CAN1, 1);
    digitalWrite(CAN2, 0);
  } else if (can == 0) {
    digitalWrite(CAN3, 0);
    digitalWrite(CAN1, 0);
    digitalWrite(CAN2, 0);
  }
if(i1==0)
{
hiz=14;
}
if(i2==0)
{
hiz=12;
}
if(i3==0)
{
hiz=10;
}
if(i4==0)
{
hiz=8;
}



//
puant=puan;
puan=puan%10;

  if(puan==0)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
    }

    if(puan==1)
    {
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
    }

    if(puan==2)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 0);
    }

    if(puan==3)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 0);
    }

    if(puan==4)
    {
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
    }

    if(puan==5)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
    }

    if(puan==6)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
    }

    if(puan==7)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
    }

    if(puan==8)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
    }

    if(puan==9)
    {
      digitalWrite(2, 0);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
    }
    puan=puant;
//


 if(i5==0)
 {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(25, 20);
    display.println("Oyun Bitti!");

     
    display.setCursor(25, 35);
    display.println("Menu..");
    display.display();
    sayac1=4;



   delay(5000);
   ali=0; 
}
 delay(hiz);
}

}
