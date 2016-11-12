#include <IRremote.h>

int IRRecvPin = 12;

IRsend irsend;
IRrecv irrecv(IRRecvPin);
decode_results results;

static const long teclasDelControl[21] =
{
16753245, // 0 on              
16736925, // 1 off
16769565, // 2 mute
16720605, // 3 <-
16712445, // 4 ->
16761405, // 5 play pausa
16769055, // 6 -
16754775, // 7 +
16748655, // 8 eq
16738455, // 9 0
16750695, // 10 100+
16756815, // 11 enter
16724175, // 12 1
16718055, // 13 2
16743045, // 14 3
16716015, // 15 4
16726215, // 16 5
16734885, // 17 6
16728765, // 18 7
16730805, // 19 8
16732845, // 20 9
};

void iniciarControlRemoto()
{
    irrecv.enableIRIn();
}

char getTeclaControl()
{
  if ((irrecv.decode(&results)))   {
    long valor = results.value;
    //LcdString(String(" " + String(valor)));
    irrecv.resume(); 

    for (unsigned char i = 0; i < 21; i++)
      if (teclasDelControl[i] == valor)
         return i;
  }
  return -1;
}
