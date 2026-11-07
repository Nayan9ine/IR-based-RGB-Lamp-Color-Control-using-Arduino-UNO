# Controlling-RGB-Lamp-via-IR-using-Arduino-UNO
Had an old RGB lamp with included IR remote which was broken. So made a custom one using Arduino UNO. <br>

## About Remote
Did continuity test on remote's PCB and found no error. Since 2 columns were non-operational. Concluded that the COB (chip on board) was either broken or just not programmed for the 2 columns. In my other repository I have reverse engineered the schematic and drawn a crude PCB design on KiCad. (https://github.com/Nayan9ine/RGB-light-Controller-Remote-) 

## Project Details

### IR Receiver
Some buttons on remote still worked so I needed to find their codes to guess the non-working ones. For that I needed a receiver.
Had an old TV setup box and remote with IR reciever and transmitter respectively. De-soldered them and used reciever to find the codes.


<img width="3376" height="4815" alt="ir receiver" src="https://github.com/user-attachments/assets/cf44afc7-de83-464c-8c4e-0272cd426c1e" />
<img width="1920" height="1080" alt="IR received commands" src="https://github.com/user-attachments/assets/99df7a3f-b5aa-402e-92dd-8b1651007abc" />
Used Arduino-IRremote Library (https://github.com/Arduino-IRremote/Arduino-IRremote).Noticed address of 0x00 was universal for all the buttons and only the comnmands were used. 

Protocol=NEC Address=0x0, Command=0x18, Raw-Data=0xE718FF00, 32 bits, LSB first, Gap=3276750us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x18, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x18, Repeat, Gap=39600us, Duration=11700us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x4, Raw-Data=0xFB04FF00, 32 bits, LSB first, Gap=3257100us, Duration=67500us
Send with: IrSender.sendNEC(0x0, 0x4, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x4, Repeat, Gap=39600us, Duration=11800us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x8, Raw-Data=0xF708FF00, 32 bits, LSB first, Gap=1972400us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x8, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x8, Repeat, Gap=39600us, Duration=11700us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0xC, Raw-Data=0xF30CFF00, 32 bits, LSB first, Gap=1527200us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0xC, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0xC, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x10, Raw-Data=0xEF10FF00, 32 bits, LSB first, Gap=2146300us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x10, <numberOfRepeats>);

Received command 0x10.
Protocol=NEC Address=0x0, Command=0x10, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x14, Raw-Data=0xEB14FF00, 32 bits, LSB first, Gap=2975450us, Duration=67600us
Send with: IrSender.sendNEC(0x0, 0x14, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x14, Repeat, Gap=39550us, Duration=11700us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x19, Raw-Data=0xE619FF00, 32 bits, LSB first, Gap=3276750us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x19, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x19, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x5, Raw-Data=0xFA05FF00, 32 bits, LSB first, Gap=1627600us, Duration=67500us
Send with: IrSender.sendNEC(0x0, 0x5, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x5, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x9, Raw-Data=0xF609FF00, 32 bits, LSB first, Gap=1352050us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x9, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x9, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0xD, Raw-Data=0xF20DFF00, 32 bits, LSB first, Gap=2357200us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0xD, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0xD, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x11, Raw-Data=0xEE11FF00, 32 bits, LSB first, Gap=3035050us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x11, <numberOfRepeats>);

Received command 0x11.
Protocol=NEC Address=0x0, Command=0x11, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x15, Raw-Data=0xEA15FF00, 32 bits, LSB first, Gap=3276750us, Duration=67500us
Send with: IrSender.sendNEC(0x0, 0x15, <numberOfRepeats>);

Protocol=NEC Address=0x0, Command=0x15, Repeat, Gap=39600us, Duration=11750us

Repeat received. Here you can repeat the same action as before.

### IR Transmitter
<img width="4312" height="5760" alt="remote pcb" src="https://github.com/user-attachments/assets/65066b29-139d-41e2-a52f-20e78b59c2f6" />
<img width="4312" height="5760" alt="tx desolder" src="https://github.com/user-attachments/assets/363568e6-266c-44f5-9745-ca0cae7034e2" />
<img width="4312" height="5760" alt="desoldered TX" src="https://github.com/user-attachments/assets/889fd963-ed9c-4ade-98fd-1a99674fc573" />
Setting up IR Transmitter circuit was complex as it needs around 20-100mA or more sometimes and have a voltage drop of 1.0 to 2.0v. Each digital pin can transmit upto 20mA only. 

Tried without BJT by applying 220Ohm resistor as in fig



### Getting Remote Codes


