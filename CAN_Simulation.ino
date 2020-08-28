// demo: CAN-BUS Shield, receive data with check mode
// send data coming to fast, such as less than 10ms, you can use this way
// loovee, 2014-6-13

#include <SPI.h>
#include "mcp_can.h"

// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
const int SPI_CS_PIN = 10;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);
    
    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 250k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println("Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
}


void loop()
{
    unsigned char len = 0;
    unsigned char buf[20];
    char myname[]=" HRITVIK";
    char concatinated[20];

    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned long canId = CAN.getCanId();

        Serial.println("-----------------------------");
        Serial.println("get data from ID: 0x");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(char(buf[i]));
            
            concatinated[i]=buf[i];

        }//H R I T V I K
        for(int i=len; i<len+8; i++)
        {
          Serial.print(myname[(i-len)]);
          concatinated[i]=myname[i-len];
        }
        Serial.println();
    }
    for(int i=0; i<len+8; i++)
    { Serial.print(concatinated[i]);}
    CAN.sendMsgBuf(0x80, 0, len+8, concatinated);
    delay(1000);                       // send data once per second
}

//END FILE
