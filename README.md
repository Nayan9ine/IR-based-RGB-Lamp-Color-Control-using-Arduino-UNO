# Controlling-RGB-Lamp-via-IR-using-Arduino-UNO
Had an old RGB lamp with included IR remote which was broken. So made a custom one using Arduino UNO. <br>

## About Remote
Did continuity test on remote's PCB and found no error. Since 2 columns were non-operational. Concluded that the COB (chip on board) was either broken or just not programmed for the 2 columns. In my other repository I have reverse engineered the schematic and drawn a crude PCB design on KiCad. (https://github.com/Nayan9ine/RGB-light-Controller-Remote-) 

## Project Details

### IR Receiver
<table>
  <tr>
    <td>
      <img width="5760" height="4312" alt="soldering setup" src="https://github.com/user-attachments/assets/0a47111b-9699-4a80-b572-90bc97f1c617" />
      <div align="center"><sub><i>Fig:1 Solder Setup</i></sub></div>
    </td>
    <td><img width="3376" height="4815" alt="ir receiver" src="https://github.com/user-attachments/assets/cf44afc7-de83-464c-8c4e-0272cd426c1e" />
      <div align="center"><sub><i>Fig:2 IR Receiver</i></sub></div>
    </td>
    <td><img width="1920" height="1080" alt="IR received commands" src="https://github.com/user-attachments/assets/99df7a3f-b5aa-402e-92dd-8b1651007abc" />
      <div align="center"><sub><i>Fig:3 IR Receiver Program</i></sub></div>
    </td>
  </tr>
</table>

Some buttons on remote still worked so I needed to find their codes to guess the non-working ones. For that I needed a receiver.
Had an old TV setup box and remote with IR reciever and transmitter respectively. De-soldered them and used reciever to find the codes.

Used Arduino-IRremote Library's (https://github.com/Arduino-IRremote/Arduino-IRremote) simple receiver example to detect the signals. Baud rate set at 152000 in order to catch high frequency signal. Observed that NEC protocol was followed, 0x00 address was universal for all the buttons and commands were unique. 

IDE O/P of 1st Two Columns:<br>

<sub>Protocol=NEC Address=0x0, Command=0x18, Raw-Data=0xE718FF00, 32 bits, LSB first, Gap=3276750us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x18, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x18, Repeat, Gap=39600us, Duration=11700us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x4, Raw-Data=0xFB04FF00, 32 bits, LSB first, Gap=3257100us, Duration=67500us
Send with: IrSender.sendNEC(0x0, 0x4, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x4, Repeat, Gap=39600us, Duration=11800us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x8, Raw-Data=0xF708FF00, 32 bits, LSB first, Gap=1972400us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x8, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x8, Repeat, Gap=39600us, Duration=11700us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0xC, Raw-Data=0xF30CFF00, 32 bits, LSB first, Gap=1527200us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0xC, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0xC, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x10, Raw-Data=0xEF10FF00, 32 bits, LSB first, Gap=2146300us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x10, <numberOfRepeats>);

<sub>Received command 0x10.
Protocol=NEC Address=0x0, Command=0x10, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x14, Raw-Data=0xEB14FF00, 32 bits, LSB first, Gap=2975450us, Duration=67600us
Send with: IrSender.sendNEC(0x0, 0x14, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x14, Repeat, Gap=39550us, Duration=11700us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x19, Raw-Data=0xE619FF00, 32 bits, LSB first, Gap=3276750us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x19, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x19, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x5, Raw-Data=0xFA05FF00, 32 bits, LSB first, Gap=1627600us, Duration=67500us
Send with: IrSender.sendNEC(0x0, 0x5, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x5, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x9, Raw-Data=0xF609FF00, 32 bits, LSB first, Gap=1352050us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x9, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x9, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0xD, Raw-Data=0xF20DFF00, 32 bits, LSB first, Gap=2357200us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0xD, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0xD, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x11, Raw-Data=0xEE11FF00, 32 bits, LSB first, Gap=3035050us, Duration=67550us
Send with: IrSender.sendNEC(0x0, 0x11, <numberOfRepeats>);

<sub>Received command 0x11.
Protocol=NEC Address=0x0, Command=0x11, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
Protocol=NEC Address=0x0, Command=0x15, Raw-Data=0xEA15FF00, 32 bits, LSB first, Gap=3276750us, Duration=67500us
Send with: IrSender.sendNEC(0x0, 0x15, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x15, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.

### IR Transmitter
Using the IR transmitter example from the library, I created a program fed with a list of working commands that were signalled continously in a loop with a gap of about 3 seconds. Repeat signal set to 3 as its the standard.  
<img width="1920" height="1080" alt="transmitter code" src="https://github.com/user-attachments/assets/74675a8d-6ad4-4ec7-ad89-6962d4a881bb" />

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
Utilized BC547 B with absoulte maximum Ic=100mA and electrical characteristics were: Vce= 90-200mV (sat); Vbe= 700-900 mV (sat),660 mV (ON); Gain (Ic/Ib) = 200-450 for B class (https://cdn.sparkfun.com/assets/d/5/e/5/d/BC547.pdf)

##### Calculation:
With Ic assumed=50mA, gain=200, Vbe=0.7V, Vce=0.2mV
I got Rc=72 Ohm and Rb=18k Ohm ( four 67K in parallel and 1k in series = 17970 Ohm)
<img width="4588" height="4070" alt="bjt 17k base ohm" src="https://github.com/user-attachments/assets/e667d629-3a53-4e46-9c12-47d42b12bb52" />
<br>
Result: Worked but resulting IR signals were very weak. So they weren't effective for slightly longer distance 
(https://drive.google.com/file/d/1yKxyMbIhAzy9gKmQ9HroFnUobWQBn7yZ/view?usp=sharing)

--> Due to low tolerance to temperature the bjt can have highly fluctuation gain so I assumed the gain of this particular BJT was very low so I redid the calculations taking gain =100.
Got Rb=8.6K Ohm ((5x1k)+(470x6)), reduced Rc to 66 ohm.
Result: Still IR strength was very weak but the range was improved.

insert table here IR STRENGTH CHART
Rb= 7.2kOhm distance of working=53inch  Doesnt switch after white
6.79kOhm                     93 inch     nothing after white
6.3k                      white works at 60 inch

Rb=4k; Ib=1.075mA; Ic=107.5mA Brightness increased but still not strong enough
Used in Saturation mode so that channel will be opened fully and max current be pushed through collector.
##### Calculation
Forced Gain=20; Ic=70mA; Ib=3.5mA; Rb=1.228 kOhm; Vir=1.5v; Rc=47 Ohm.
Result: Range increased to 80 inches with it still working after white lighting.

### Getting Unknown Remote Codes
14  buttons were unknown with 2 buttons for ON and OFF , 5 buttons of 4th column for brightness and last 2 buttons of 7th row as Set and Manual. 
<img width="1278" height="2315" alt="unknown buttons" src="https://github.com/user-attachments/assets/12e03dd5-da35-413d-a570-1fa715b8d92d" />

From the known commands I noticed a pattern that showed increasing hex value along the row. 
So if row 1 and row 2 had 18 and 19 respectively I tried 0x20 then 0x21, using this I found only rows 3,5,6 and 7th worked. In which I had to to independently test The brightness, manual and set buttons by writing separate programs.

To find other button values I had to dive deeper into understanding how hex value is represented. 
I realized 0x10 does not follow after 0x9 as 0x10 is (16^0*0)+(16^1*1)=17. 0xA comes after it.
This way I found value of 4th row as well. For ON and OFF button I had to do some hit and trial by using long arrays of random command values and ultimately found them to be 0x1E and 0x1F.

### Integrating Remote
For remote I used 4x4 keypad membrane (16 buttons), with help of keypad library by Mark Stanley.It makes use of array written in char data type which stores the value of buttons.
Instead of writing multiple if else statments to define each button press,comparing it to my array of commands and then transmitting it, I made use of known concept that is values stored in charare put under quotations then output is stored in it's corresponding ASCII value and if stored in integer or hex format then output stored in corresponding BYTE form ((0 to 255 integers).For eg storing 0X1F will be stored as 31 & 20 as 20 but 'A' will be stored as 65. So directly mapped the keypad button array to desired command values and converted the output to HEX value during transmission. 

<img width="4312" height="5760" alt="final setup (1)" src="https://github.com/user-attachments/assets/8a9ff81a-6291-4f3a-99b5-bc3e8c7a583c" />
