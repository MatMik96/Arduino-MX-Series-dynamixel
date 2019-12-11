#ifndef Functions_h
#define Functions_h

#define HEADER     0xFF             //Defining Header 1 and 2
#define HEADER_3   0xFD             //Defining Header 3
#define RESERVED   0x00             //4. bytes is allways reserved
#define SERVO_SET_Baudrate  57600  //Baudrate is set to the right number
#define READ_INSTRUCTION    0x02    //Read instruct is always 2
#define WRITE_INSTRUCTION   0x03    //Write instruct is always 3
#define PACKET_LENGTH_H     0x00    //Almost allways 0
#define TORQUE_ENABLE       0x40
#define RESERVED_BYTE       0x00 


#include <Arduino.h> //Standard Arduino libary




class FunctionsClass
{
  public:
  int Reference_Pin = 2;
  bool onOff = true;


  
  FunctionsClass();
void setTorquePacket(unsigned char ID, bool torque_status);
void SetPGain(unsigned char ID, int Pgain);
void setGoalVelocityPacket(int velocity, unsigned char ID);
void rebootDynamixelPacket(unsigned char  ID);
void ReadTemp(unsigned char ID);
void setGoalPositionPacket(int positionByte, unsigned char ID);
void transmitInstructionPacket(unsigned char* var1, int var2);
void readStatusPacket();
void readStatusPacket1();
unsigned short update_crc(unsigned short crc_accum, unsigned char* data_blk_ptr, unsigned short data_blk_size);

  
  unsigned char Status_Packet[15];
  unsigned char Status_Packet1[11];
};




#endif
