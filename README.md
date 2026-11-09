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
Used Arduino-IRremote Library (https://github.com/Arduino-IRremote/Arduino-IRremote) . 0x00 Address  was universal for all the buttons and realized comnmands were used for controlling. Baud rate set at 152000 in order to catch high frequency signal.

IDE OUTPUT OF 1ST TWO COLUMNS:
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
Setting up IR Transmitter circuit was complex as it needs around 20-50mA or more sometimes and have a voltage drop of 1.2 to 1.8v. Each digital pin can transmit upto 20mA only. 

#### Hit n Trial
->Tried without BJT by applying 220 Ohm resistor as in fig to see if it works at 20mA
<img width="4895" height="2638" alt="tx with resistor" src="https://github.com/user-attachments/assets/1d995e3a-f53a-4952-b65e-7ffad1779b9b" />

##### Calculation
By KVL: 5-1.4-20x10^-3 x Rmin =0
<br>
Rmin=180 ohm
<br>
By using 220 ohm I should theoretically receive 16.3mA
Since the signal is sent at 38KHz meaning digital pin turns ON and OFF 38,000 times per second,Standard multimeter cannot be used to measure either voltage or current in either DC or AC mode. Only way to check was using phone camera that is capable of detecting violet flashes which are IR signals being sent. I didnt see anything, that meant 16.3mA wasn't enough.
<img width="2579" height="1148" alt="IR via Camera" src="https://github.com/user-attachments/assets/b6da534d-f886-47c3-903a-663ebee080c6" />

->Lowered resistor by placing 1k Ohm pot.
<img width="4420" height="2519" alt="tx with pot" src="https://github.com/user-attachments/assets/25d1faa2-f607-405d-89f0-bd991f148cee" />
Set it to 167 Ohm (gives 22 mA) but still received no output.
<img width="3293" height="3867" alt="Ir tx pot ohm" src="https://github.com/user-attachments/assets/610957f6-c60c-4050-b577-d106adcf437b" />

Realized 20mA isnt enough and need about 50mA atleast so:
<br>
->Used BJT
Utilized BC547 B with absoulte maximum Ic=100mA and electrical characteristics were: Vce= 90-200mV (sat); Vbe= 700-900 mV (sat),
### Getting Remote Codes


