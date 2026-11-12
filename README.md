# Controlling-RGB-Lamp-via-IR-using-Arduino-UNO
Had an old RGB lamp with included IR remote which was broken. So made a custom one using Arduino UNO. <br>

## About Remote
<div align= "center"><img width="200" height="370" alt="Remote" src="https://github.com/user-attachments/assets/3c5ed012-334e-4a94-9eb9-72ebe3e05022" />

  <br><sub><i>Fig 1 : Faulty Remote</i></sub>
</div>
Did continuity test on remote's PCB and found no error. Rightmost 2 columns were non-operable. Concluded that the COB (chip on board) was either broken or just not programmed for the 2 columns. In my other repository I have reverse engineered the schematic and drawn a crude PCB design on KiCad. (https://github.com/Nayan9ine/RGB-light-Controller-Remote-) 

## Project Details

### IR Receiver
<table>
  <tr>
    <td>
      <img width="1000" height="749" alt="soldering setup" src="https://github.com/user-attachments/assets/8bcb7cdd-7ce0-49c0-b2d4-c5c2d43d8809" />
      <div align="center"><sub><i>Fig 2: Solder Setup</i></sub></div>
    </td>
    <td><img width="800" height="1141" alt="ir receiver" src="https://github.com/user-attachments/assets/8c59f3bb-86bb-4fc7-aefa-f98bed870ade" />
      <div align="center"><sub><i>Fig 3: IR Receiver</i></sub></div>
    </td>
    <td><img width="1000" height="563" alt="IR received commands" src="https://github.com/user-attachments/assets/f2b7aeab-36ba-475e-91ca-4003cf776db5" />
    <div align="center"><sub><i>Fig 4: IR Receiver Program</i></sub></div>
    </td>
  </tr>
</table>

1st two columns of remote worked so I needed to find their codes to guess the non-working ones. For that I needed a receiver.
Had an old TV setup box and remote with IR reciever and transmitter respectively. De-soldered them and used reciever to find the codes.

Used Arduino-IRremote Library's (https://github.com/Arduino-IRremote/Arduino-IRremote) simple receiver example to detect the signals. Baud rate set at 152000 in order to catch high frequency signal. Observed that NEC protocol was followed, 0x00 address was universal for all the buttons and commands were unique. 

IDE O/P of 1st Two Columns:<br>

<sub>Protocol=NEC Address=0x0, Command=0x18, Raw-Data=0xE718FF00, 32 bits, LSB first, Gap=3276750us, Duration=67550us<br>
Send with: IrSender.sendNEC(0x0, 0x18, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x18, Repeat, Gap=39600us, Duration=11700us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x4, Raw-Data=0xFB04FF00, 32 bits, LSB first, Gap=3257100us, Duration=67500us
<br>Send with: IrSender.sendNEC(0x0, 0x4, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x4, Repeat, Gap=39600us, Duration=11800us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x8, Raw-Data=0xF708FF00, 32 bits, LSB first, Gap=1972400us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0x8, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x8, Repeat, Gap=39600us, Duration=11700us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0xC, Raw-Data=0xF30CFF00, 32 bits, LSB first, Gap=1527200us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0xC, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0xC, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x10, Raw-Data=0xEF10FF00, 32 bits, LSB first, Gap=2146300us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0x10, <numberOfRepeats>);

<sub>Received command 0x10.
Protocol=NEC Address=0x0, Command=0x10, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x14, Raw-Data=0xEB14FF00, 32 bits, LSB first, Gap=2975450us, Duration=67600us
<br>Send with: IrSender.sendNEC(0x0, 0x14, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x14, Repeat, Gap=39550us, Duration=11700us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x19, Raw-Data=0xE619FF00, 32 bits, LSB first, Gap=3276750us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0x19, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x19, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x5, Raw-Data=0xFA05FF00, 32 bits, LSB first, Gap=1627600us, Duration=67500us
<br>Send with: IrSender.sendNEC(0x0, 0x5, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x5, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x9, Raw-Data=0xF609FF00, 32 bits, LSB first, Gap=1352050us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0x9, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x9, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0xD, Raw-Data=0xF20DFF00, 32 bits, LSB first, Gap=2357200us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0xD, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0xD, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x11, Raw-Data=0xEE11FF00, 32 bits, LSB first, Gap=3035050us, Duration=67550us
<br>Send with: IrSender.sendNEC(0x0, 0x11, <numberOfRepeats>);

<sub>Received command 0x11.
Protocol=NEC Address=0x0, Command=0x11, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.
<br>Protocol=NEC Address=0x0, Command=0x15, Raw-Data=0xEA15FF00, 32 bits, LSB first, Gap=3276750us, Duration=67500us
<br>Send with: IrSender.sendNEC(0x0, 0x15, <numberOfRepeats>);

<sub>Protocol=NEC Address=0x0, Command=0x15, Repeat, Gap=39600us, Duration=11750us

<sub>Repeat received. Here you can repeat the same action as before.

### IR Transmitter
Using the IR transmitter example from the library, I created a program fed with a list of working commands that were signalled continously in a loop with a delay of about 3 seconds. Repeat signal set to 3 as its the standard.
<table>
  <tr>
     <td>
       <div align="center">
      <img width="250" height="461" alt="remote pcb" src="https://github.com/user-attachments/assets/2bee48fc-49f4-4600-a5c5-d66d661ed09d" />
      <div align="center"><sub><i>Fig 5: Spare TV Remote</i></sub></div></div>
    </td>
     <td>
     <div align="center">
      <img width="250" height="461" alt="tx desolder" src="https://github.com/user-attachments/assets/339f1df4-bc81-44b1-8229-c48becf2d869" />
      <div align="center"><sub><i>Fig 6: Transmitter on Remote</i></sub></div></div>
    </td>
  </tr>
  <tr>
     <td>
      <img width="500" height="474" alt="desoldered TX" src="https://github.com/user-attachments/assets/a083f132-1fe0-473b-bb70-5f162c9a00da" />
      <div align="center"><sub><i>Fig 7: De-soldered IR Tx</i></sub></div>
    </td>
    <td>
      <img width="1000" height="563" alt="transmitter code" src="https://github.com/user-attachments/assets/e9234bd5-2cf6-4a53-94c8-6a1f52b88a94" />
      <div align="center"><sub><i>Fig 8: IR Tx Program </i></sub></div>
    </td>
  </tr>
</table>

#### Setting Up TX Circuit
<table>
  <tr>
    <td>
      <img width="800" height="356" alt="IR via Camera" src="https://github.com/user-attachments/assets/4d7bb0ed-db9a-4b7a-917f-618efeac955c" />
      <div align="center"><sub><i>Fig 9: IR Flash from camera</i></sub></div>
    </td>
    <td>
     <img width="500" height="269" alt="tx with resistor" src="https://github.com/user-attachments/assets/080072e5-b09b-470e-840f-59278dd58e1e" />
      <div align="center"><sub><i>Fig 10: 220 Ohm</i></sub></div>
    </td>
  </tr>
  <tr>
    <td><img width="500" height="285" alt="tx with pot" src="https://github.com/user-attachments/assets/2a181226-b465-40de-a9c3-5e28be4853ca" />
      <div align="center"><sub><i>Fig 11: Potentiometer</i></sub></div>
    </td>
    <td>
     <img width="500" height="587" alt="Ir tx pot ohm" src="https://github.com/user-attachments/assets/6c6aa93e-3163-47aa-8b75-82b253760ada" />
      <div align="center"><sub><i>Fig 12: 167 Ohm</i></sub></div>
    </td>
 </tr>
</table>
Was complex as it needs around 20-100mA and a voltage drop of 1.2 to 1.8v. Each digital pin can transmit upto 20mA with absolute max of 40mA. 
<br>
<br>
->Tried without BJT by applying 220 Ohm resistor as in fig to see if it works at 20mA

#### Calculation
By KVL: 
$5 - 1.4 - (20x10^{-3}\$ x Rmin) = 0
<br>
Rmin=180 ohm
<br>
By using 220 ohm I should theoretically receive 16.3mA. Since the signal is sent at 38KHz meaning digital pin turns ON and OFF 38,000 times per second, standard multimeter cannot be used to measure either voltage or current in either DC or AC mode. Only way to check is using phone camera that is capable of detecting violet flashes which prove that IR signals are being sent. I didnt see anything, that meant 16.3mA wasn't enough.

->Lowered resistor by placing 1k Ohm pot.
<br>
Set it to 167 Ohm (gives 22 mA) but still received no output.
Realized 20mA isnt enough and need about 50mA atleast so:
<br>
<br>
->Used BJT
<br>
Utilized BC547 B with absoulte maximum Ic=100mA and electrical characteristics were: Vce= 90-200mV (sat); Vbe= 700-900 mV (sat),660 mV (ON); Gain (Ic/Ib) = 200-450 for B class. (https://cdn.sparkfun.com/assets/d/5/e/5/d/BC547.pdf)

#### Calculation:
With Ic assumed=50mA, gain=200, Vbe=0.7V, Vce=0.2mV
I got Rc=72 Ohm and Rb=18k Ohm ( four 67K in parallel and 1k in series = 17970 Ohm)
<br>
Result: Worked but resulting IR signals were very weak.Didn't work after a short distance 
(https://drive.google.com/file/d/1yKxyMbIhAzy9gKmQ9HroFnUobWQBn7yZ/view?usp=sharing)
Due to low tolerance to temperature the bjt can have highly fluctuating gain so I assumed the gain of this particular BJT was very low so I redid the calculations taking gain =100.
<br>
Got Rb=8.6K Ohm $((5 \times 1\text{k}) + (470 \times 6)
)$ , reduced Rc to 66 ohm.
<br>
Result: Still IR strength was very weak but the range was improved.

  
<table>
  <tr>
    <td>
      <img width="500" height="444" alt="bjt 17k base ohm" src="https://github.com/user-attachments/assets/51438a6b-8ec4-436f-9c9c-4e19e047d9b7" />
      <div align="center"><sub><i>Fig 13: BJT with 17.17kOhm</i></sub></div>
    </td>
    <td>
      <img width="500" height="378" alt="strong ir signal (1 2kohm)" src="https://github.com/user-attachments/assets/4f25b13f-4556-445c-b469-79df3199e8d1" />
      <div align="center"><sub><i>Fig 14: Strong IR signal Rb as (1 2kohm)</i></sub></div>
    </td>
    <td>
     <img width="600" height="383" alt="Rb as 1 47 kohm" src="https://github.com/user-attachments/assets/eeb5a225-fdf7-4825-92d3-7ce4d76c28f9" />
      <div align="center"><sub><i>Fig 15: IR Receiver Rb as 1.47 kohm/i></sub></div>
    </td>
  </tr>
</table>

Rb=4k; Ib=1.075mA; Ic=107.5mA Brightness increased but still not strong enough.
<br>
<br>
->BJT as a Switch
<br>
Used in Saturation mode so that channel will be opened fully and max current be pushed through collector.

#### Calculation
Forced Gain=20; Ic=70mA; Ib=3.5mA; Rb=1.228 kOhm; Vir=1.5v; Rc=47 Ohm.
Result: Range increased to 80 inches with it still working after white lighting.
<div align ="center">
 
  <table>
  <tr>
    <td><b>Rb Value (in KOhm)</b></td>
    <td><b>Range (inch)</b></td>
     <td><b>White Color Interferening With IR</b></td>
  </tr>
  <tr>
    <td>7.2</td>
    <td>53</td>
     <td>Yes</td>
  </tr>
  <tr>
    <td>6.7</td>
    <td>60</td>
     <td>Yes</td>
  </tr>
  <tr>
    <td>6.3</td>
    <td>67</td>
     <td>IR resumed working when lamp was at 60 inch</td>
  </tr>
    <tr>
    <td>3.07</td>
    <td>76</td>
     <td>No</td>
  </tr>
    <tr>
    <td>1.228</td>
    <td>85</td>
     <td>No</td>
  </tr>
</table>
</div>

### Getting Unknown Remote Codes
<div align="center">
<img width="200" height="306" alt="unknown buttons" src="https://github.com/user-attachments/assets/3fa4fa7e-0742-46ba-89ef-822ece56bdfd" />
  <br>
  <sub><i>Fig 16: Unknown Last 2 Columns</i></sub>
</div>
<br>
14  buttons were unknown with 2 buttons for ON and OFF , 5 buttons of 4th column for brightness and last 2 buttons of 7th row as Set and Manual.From the known commands I noticed a pattern that showed increasing hex value along the row. So if row 1 and row 2 had 18 and 19 respectively I tried 0x20 then 0x21, using this I found only rows 3,5,6 and 7th worked. In which I had to independently test The brightness, manual and set buttons by writing separate programs.
<br>
To find other button values I had to dive deeper into understanding how hex value is represented. I realized 0x10 does not follow after 0x9 as 0x10 is $$(16^{0} \times 0) + (16^{1} \times 1) = 17$$ .0xA comes after it.This way I found value of 4th row as well. For ON and OFF button I had to do some hit and trial by using long arrays of random command values and ultimately found them to be 0x1E and 0x1F.

### Integrating Remote
<div align="center">
<img width="1241" height="700" alt="final setup (1)" src="https://github.com/user-attachments/assets/7b2f3772-23fd-4467-933b-bf9e5778cfce" />
  <br>
  <sub><i>Fig 17:Final Setup</i></sub>
</div>
<br>

For remote I used 4x4 keypad membrane (16 buttons), with help of keypad library by Mark Stanley.It makes use of array written in char data type which stores the value of buttons.Instead of writing multiple if else statments to define each button press,comparing it to my array of commands and then transmitting it, I made use of known concept that is values stored in charare put under quotations then output is stored in it's corresponding ASCII value and if stored in integer or hex format then output stored in corresponding BYTE form ((0 to 255 integers).
<br>
For eg storing 0X1F will be stored as 31 & 20 as 20 but 'A' will be stored as 65. So directly mapped the keypad button array to desired command values and converted the output to HEX value during transmission. 



