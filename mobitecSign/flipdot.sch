EESchema Schematic File Version 4
LIBS:flipdot-cache
EELAYER 26 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L flipdot-rescue:74HC4514 DR1
U 1 1 5AB0F8AD
P 2950 6250
F 0 "DR1" V 2900 5950 60  0000 C CNN
F 1 "74HC4514" V 2900 5550 60  0000 C CNN
F 2 "" H 2950 6250 60  0000 C CNN
F 3 "" H 2950 6250 60  0000 C CNN
	1    2950 6250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:74HC4514 DC1
U 1 1 5AB10351
P 8200 1600
F 0 "DC1" V 8150 1300 60  0000 C CNN
F 1 "74HC4514" V 8150 900 60  0000 C CNN
F 2 "" H 8200 1600 60  0000 C CNN
F 3 "" H 8200 1600 60  0000 C CNN
	1    8200 1600
	0    -1   1    0   
$EndComp
$Comp
L flipdot-rescue:ULN2003A U?
U 1 1 5AB10929
P 9050 2900
F 0 "U?" H 9050 3425 50  0001 C CNN
F 1 "ULN2003A" H 9050 3350 50  0000 C CNN
F 2 "" H 9100 2250 50  0001 L CNN
F 3 "" H 9150 2800 50  0001 C CNN
	1    9050 2900
	0    -1   1    0   
$EndComp
$Comp
L flipdot-rescue:TD62783 U?
U 1 1 5AB10B67
P 6650 2900
F 0 "U?" H 6650 2350 50  0001 C CNN
F 1 "TD62783" H 6650 3450 50  0000 C CNN
F 2 "" H 6650 2900 60  0000 C CNN
F 3 "" H 6650 2900 60  0000 C CNN
	1    6650 2900
	0    -1   1    0   
$EndComp
Text GLabel 800  5100 0    39   Input ~ 0
Color
$Comp
L flipdot-rescue:TD62783 U?
U 1 1 5AB11B8D
P 4200 7200
F 0 "U?" H 4200 6650 50  0001 C CNN
F 1 "TD62783" H 4200 7750 50  0000 C CNN
F 2 "" H 4200 7200 60  0000 C CNN
F 3 "" H 4200 7200 60  0000 C CNN
	1    4200 7200
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:ULN2003A U?
U 1 1 5AB11D3F
P 4200 5550
F 0 "U?" H 4200 6075 50  0001 C CNN
F 1 "ULN2003A" H 4200 6000 50  0000 C CNN
F 2 "" H 4250 4900 50  0001 L CNN
F 3 "" H 4300 5450 50  0001 C CNN
	1    4200 5550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:+5V #PWR01
U 1 1 5AB1307B
P 3000 5200
F 0 "#PWR01" H 3000 5050 50  0001 C CNN
F 1 "+5V" H 3000 5340 50  0000 C CNN
F 2 "" H 3000 5200 50  0001 C CNN
F 3 "" H 3000 5200 50  0001 C CNN
	1    3000 5200
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:+5V #PWR02
U 1 1 5AB130B1
P 7150 1650
F 0 "#PWR02" H 7150 1500 50  0001 C CNN
F 1 "+5V" H 7150 1790 50  0000 C CNN
F 2 "" H 7150 1650 50  0001 C CNN
F 3 "" H 7150 1650 50  0001 C CNN
	1    7150 1650
	0    -1   -1   0   
$EndComp
Text GLabel 1650 6450 0    39   Input ~ 0
R0
Text GLabel 1650 6550 0    39   Input ~ 0
R1
Text GLabel 1650 6650 0    39   Input ~ 0
R2
Text GLabel 8500 800  1    39   Input ~ 0
C1
Text GLabel 8600 800  1    39   Input ~ 0
C2
Text GLabel 8400 800  1    39   Input ~ 0
C0
$Comp
L flipdot-rescue:Earth #PWR03
U 1 1 5AB13897
P 7500 1350
F 0 "#PWR03" H 7500 1100 50  0001 C CNN
F 1 "Earth" H 7500 1200 50  0001 C CNN
F 2 "" H 7500 1350 50  0001 C CNN
F 3 "" H 7500 1350 50  0001 C CNN
	1    7500 1350
	-1   0    0    1   
$EndComp
$Comp
L flipdot-rescue:Earth #PWR04
U 1 1 5AB138BD
P 2650 5550
F 0 "#PWR04" H 2650 5300 50  0001 C CNN
F 1 "Earth" H 2650 5400 50  0001 C CNN
F 2 "" H 2650 5550 50  0001 C CNN
F 3 "" H 2650 5550 50  0001 C CNN
	1    2650 5550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:+24V #PWR05
U 1 1 5AB13A52
P 4600 6250
F 0 "#PWR05" H 4600 6100 50  0001 C CNN
F 1 "+24V" H 4600 6390 50  0000 C CNN
F 2 "" H 4600 6250 50  0001 C CNN
F 3 "" H 4600 6250 50  0001 C CNN
	1    4600 6250
	-1   0    0    1   
$EndComp
$Comp
L flipdot-rescue:+24V #PWR06
U 1 1 5AB13AEF
P 3650 7700
F 0 "#PWR06" H 3650 7550 50  0001 C CNN
F 1 "+24V" H 3650 7840 50  0000 C CNN
F 2 "" H 3650 7700 50  0001 C CNN
F 3 "" H 3650 7700 50  0001 C CNN
	1    3650 7700
	-1   0    0    1   
$EndComp
$Comp
L flipdot-rescue:Earth #PWR07
U 1 1 5AB13B87
P 4800 7750
F 0 "#PWR07" H 4800 7500 50  0001 C CNN
F 1 "Earth" H 4800 7600 50  0001 C CNN
F 2 "" H 4800 7750 50  0001 C CNN
F 3 "" H 4800 7750 50  0001 C CNN
	1    4800 7750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Earth #PWR08
U 1 1 5AB13D4A
P 4200 6350
F 0 "#PWR08" H 4200 6100 50  0001 C CNN
F 1 "Earth" H 4200 6200 50  0001 C CNN
F 2 "" H 4200 6350 50  0001 C CNN
F 3 "" H 4200 6350 50  0001 C CNN
	1    4200 6350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Earth #PWR09
U 1 1 5AB13E00
P 9900 2900
F 0 "#PWR09" H 9900 2650 50  0001 C CNN
F 1 "Earth" H 9900 2750 50  0001 C CNN
F 2 "" H 9900 2900 50  0001 C CNN
F 3 "" H 9900 2900 50  0001 C CNN
	1    9900 2900
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:+24V #PWR010
U 1 1 5AB13E9C
P 9550 3300
F 0 "#PWR010" H 9550 3150 50  0001 C CNN
F 1 "+24V" H 9550 3440 50  0000 C CNN
F 2 "" H 9550 3300 50  0001 C CNN
F 3 "" H 9550 3300 50  0001 C CNN
	1    9550 3300
	-1   0    0    1   
$EndComp
$Comp
L flipdot-rescue:Earth #PWR011
U 1 1 5AB13F39
P 7050 3400
F 0 "#PWR011" H 7050 3150 50  0001 C CNN
F 1 "Earth" H 7050 3250 50  0001 C CNN
F 2 "" H 7050 3400 50  0001 C CNN
F 3 "" H 7050 3400 50  0001 C CNN
	1    7050 3400
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:+24V #PWR012
U 1 1 5AB13FD7
P 7300 2500
F 0 "#PWR012" H 7300 2350 50  0001 C CNN
F 1 "+24V" H 7300 2640 50  0000 C CNN
F 2 "" H 7300 2500 50  0001 C CNN
F 3 "" H 7300 2500 50  0001 C CNN
	1    7300 2500
	-1   0    0    1   
$EndComp
NoConn ~ 6950 3300
NoConn ~ 4600 7500
NoConn ~ 3800 7500
NoConn ~ 6950 2500
NoConn ~ 8650 2050
NoConn ~ 7850 2050
NoConn ~ 3400 6700
NoConn ~ 3400 5900
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3108E
P 6500 9350
F 0 "L?" H 6550 9500 50  0001 L CNN
F 1 "DotCoil" H 6550 9300 50  0001 L CNN
F 2 "" V 6475 9450 50  0001 C CNN
F 3 "" V 6475 9450 50  0001 C CNN
	1    6500 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31095
P 6500 8950
F 0 "D?" H 6550 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 9050 50  0001 C CNN
F 2 "" H 6500 8950 50  0001 C CNN
F 3 "" H 6500 8950 50  0001 C CNN
	1    6500 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3109C
P 6500 8650
F 0 "L?" H 6550 8800 50  0001 L CNN
F 1 "DotCoil" H 6550 8600 50  0001 L CNN
F 2 "" V 6475 8750 50  0001 C CNN
F 3 "" V 6475 8750 50  0001 C CNN
	1    6500 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310A3
P 6500 8250
F 0 "D?" H 6550 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 8350 50  0001 C CNN
F 2 "" H 6500 8250 50  0001 C CNN
F 3 "" H 6500 8250 50  0001 C CNN
	1    6500 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310AA
P 7300 9350
F 0 "L?" H 7350 9500 50  0001 L CNN
F 1 "DotCoil" H 7350 9300 50  0001 L CNN
F 2 "" V 7275 9450 50  0001 C CNN
F 3 "" V 7275 9450 50  0001 C CNN
	1    7300 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310B1
P 7300 8950
F 0 "D?" H 7350 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 9050 50  0001 C CNN
F 2 "" H 7300 8950 50  0001 C CNN
F 3 "" H 7300 8950 50  0001 C CNN
	1    7300 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310B8
P 7300 8250
F 0 "D?" H 7350 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 8350 50  0001 C CNN
F 2 "" H 7300 8250 50  0001 C CNN
F 3 "" H 7300 8250 50  0001 C CNN
	1    7300 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310BF
P 7300 8650
F 0 "L?" H 7350 8800 50  0001 L CNN
F 1 "DotCoil" H 7350 8600 50  0001 L CNN
F 2 "" V 7275 8750 50  0001 C CNN
F 3 "" V 7275 8750 50  0001 C CNN
	1    7300 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310C6
P 6500 7950
F 0 "L?" H 6550 8100 50  0001 L CNN
F 1 "DotCoil" H 6550 7900 50  0001 L CNN
F 2 "" V 6475 8050 50  0001 C CNN
F 3 "" V 6475 8050 50  0001 C CNN
	1    6500 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310CD
P 6500 7550
F 0 "D?" H 6550 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 7650 50  0001 C CNN
F 2 "" H 6500 7550 50  0001 C CNN
F 3 "" H 6500 7550 50  0001 C CNN
	1    6500 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310D4
P 6500 7250
F 0 "L?" H 6550 7400 50  0001 L CNN
F 1 "DotCoil" H 6550 7200 50  0001 L CNN
F 2 "" V 6475 7350 50  0001 C CNN
F 3 "" V 6475 7350 50  0001 C CNN
	1    6500 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310DB
P 6500 6850
F 0 "D?" H 6550 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 6950 50  0001 C CNN
F 2 "" H 6500 6850 50  0001 C CNN
F 3 "" H 6500 6850 50  0001 C CNN
	1    6500 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310E2
P 7300 7950
F 0 "L?" H 7350 8100 50  0001 L CNN
F 1 "DotCoil" H 7350 7900 50  0001 L CNN
F 2 "" V 7275 8050 50  0001 C CNN
F 3 "" V 7275 8050 50  0001 C CNN
	1    7300 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310E9
P 7300 7550
F 0 "D?" H 7350 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 7650 50  0001 C CNN
F 2 "" H 7300 7550 50  0001 C CNN
F 3 "" H 7300 7550 50  0001 C CNN
	1    7300 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB310F0
P 7300 6850
F 0 "D?" H 7350 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 6950 50  0001 C CNN
F 2 "" H 7300 6850 50  0001 C CNN
F 3 "" H 7300 6850 50  0001 C CNN
	1    7300 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310F7
P 7300 7250
F 0 "L?" H 7350 7400 50  0001 L CNN
F 1 "DotCoil" H 7350 7200 50  0001 L CNN
F 2 "" V 7275 7350 50  0001 C CNN
F 3 "" V 7275 7350 50  0001 C CNN
	1    7300 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB310FE
P 8100 9350
F 0 "L?" H 8150 9500 50  0001 L CNN
F 1 "DotCoil" H 8150 9300 50  0001 L CNN
F 2 "" V 8075 9450 50  0001 C CNN
F 3 "" V 8075 9450 50  0001 C CNN
	1    8100 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31105
P 8100 8950
F 0 "D?" H 8150 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 9050 50  0001 C CNN
F 2 "" H 8100 8950 50  0001 C CNN
F 3 "" H 8100 8950 50  0001 C CNN
	1    8100 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3110C
P 8100 8650
F 0 "L?" H 8150 8800 50  0001 L CNN
F 1 "DotCoil" H 8150 8600 50  0001 L CNN
F 2 "" V 8075 8750 50  0001 C CNN
F 3 "" V 8075 8750 50  0001 C CNN
	1    8100 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31113
P 8100 8250
F 0 "D?" H 8150 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 8350 50  0001 C CNN
F 2 "" H 8100 8250 50  0001 C CNN
F 3 "" H 8100 8250 50  0001 C CNN
	1    8100 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3111A
P 8900 9350
F 0 "L?" H 8950 9500 50  0001 L CNN
F 1 "DotCoil" H 8950 9300 50  0001 L CNN
F 2 "" V 8875 9450 50  0001 C CNN
F 3 "" V 8875 9450 50  0001 C CNN
	1    8900 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31121
P 8900 8950
F 0 "D?" H 8950 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 9050 50  0001 C CNN
F 2 "" H 8900 8950 50  0001 C CNN
F 3 "" H 8900 8950 50  0001 C CNN
	1    8900 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31128
P 8900 8250
F 0 "D?" H 8950 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 8350 50  0001 C CNN
F 2 "" H 8900 8250 50  0001 C CNN
F 3 "" H 8900 8250 50  0001 C CNN
	1    8900 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3112F
P 8900 8650
F 0 "L?" H 8950 8800 50  0001 L CNN
F 1 "DotCoil" H 8950 8600 50  0001 L CNN
F 2 "" V 8875 8750 50  0001 C CNN
F 3 "" V 8875 8750 50  0001 C CNN
	1    8900 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31136
P 8100 7950
F 0 "L?" H 8150 8100 50  0001 L CNN
F 1 "DotCoil" H 8150 7900 50  0001 L CNN
F 2 "" V 8075 8050 50  0001 C CNN
F 3 "" V 8075 8050 50  0001 C CNN
	1    8100 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3113D
P 8100 7550
F 0 "D?" H 8150 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 7650 50  0001 C CNN
F 2 "" H 8100 7550 50  0001 C CNN
F 3 "" H 8100 7550 50  0001 C CNN
	1    8100 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31144
P 8100 7250
F 0 "L?" H 8150 7400 50  0001 L CNN
F 1 "DotCoil" H 8150 7200 50  0001 L CNN
F 2 "" V 8075 7350 50  0001 C CNN
F 3 "" V 8075 7350 50  0001 C CNN
	1    8100 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3114B
P 8100 6850
F 0 "D?" H 8150 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 6950 50  0001 C CNN
F 2 "" H 8100 6850 50  0001 C CNN
F 3 "" H 8100 6850 50  0001 C CNN
	1    8100 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31152
P 8900 7950
F 0 "L?" H 8950 8100 50  0001 L CNN
F 1 "DotCoil" H 8950 7900 50  0001 L CNN
F 2 "" V 8875 8050 50  0001 C CNN
F 3 "" V 8875 8050 50  0001 C CNN
	1    8900 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31159
P 8900 7550
F 0 "D?" H 8950 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 7650 50  0001 C CNN
F 2 "" H 8900 7550 50  0001 C CNN
F 3 "" H 8900 7550 50  0001 C CNN
	1    8900 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31160
P 8900 6850
F 0 "D?" H 8950 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 6950 50  0001 C CNN
F 2 "" H 8900 6850 50  0001 C CNN
F 3 "" H 8900 6850 50  0001 C CNN
	1    8900 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31167
P 8900 7250
F 0 "L?" H 8950 7400 50  0001 L CNN
F 1 "DotCoil" H 8950 7200 50  0001 L CNN
F 2 "" V 8875 7350 50  0001 C CNN
F 3 "" V 8875 7350 50  0001 C CNN
	1    8900 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3116E
P 9700 9350
F 0 "L?" H 9750 9500 50  0001 L CNN
F 1 "DotCoil" H 9750 9300 50  0001 L CNN
F 2 "" V 9675 9450 50  0001 C CNN
F 3 "" V 9675 9450 50  0001 C CNN
	1    9700 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31175
P 9700 8950
F 0 "D?" H 9750 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 9050 50  0001 C CNN
F 2 "" H 9700 8950 50  0001 C CNN
F 3 "" H 9700 8950 50  0001 C CNN
	1    9700 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3117C
P 9700 8650
F 0 "L?" H 9750 8800 50  0001 L CNN
F 1 "DotCoil" H 9750 8600 50  0001 L CNN
F 2 "" V 9675 8750 50  0001 C CNN
F 3 "" V 9675 8750 50  0001 C CNN
	1    9700 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31183
P 9700 8250
F 0 "D?" H 9750 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 8350 50  0001 C CNN
F 2 "" H 9700 8250 50  0001 C CNN
F 3 "" H 9700 8250 50  0001 C CNN
	1    9700 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3118A
P 10500 9350
F 0 "L?" H 10550 9500 50  0001 L CNN
F 1 "DotCoil" H 10550 9300 50  0001 L CNN
F 2 "" V 10475 9450 50  0001 C CNN
F 3 "" V 10475 9450 50  0001 C CNN
	1    10500 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31191
P 10500 8950
F 0 "D?" H 10550 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 9050 50  0001 C CNN
F 2 "" H 10500 8950 50  0001 C CNN
F 3 "" H 10500 8950 50  0001 C CNN
	1    10500 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31198
P 10500 8250
F 0 "D?" H 10550 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 8350 50  0001 C CNN
F 2 "" H 10500 8250 50  0001 C CNN
F 3 "" H 10500 8250 50  0001 C CNN
	1    10500 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3119F
P 10500 8650
F 0 "L?" H 10550 8800 50  0001 L CNN
F 1 "DotCoil" H 10550 8600 50  0001 L CNN
F 2 "" V 10475 8750 50  0001 C CNN
F 3 "" V 10475 8750 50  0001 C CNN
	1    10500 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311A6
P 9700 7950
F 0 "L?" H 9750 8100 50  0001 L CNN
F 1 "DotCoil" H 9750 7900 50  0001 L CNN
F 2 "" V 9675 8050 50  0001 C CNN
F 3 "" V 9675 8050 50  0001 C CNN
	1    9700 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB311AD
P 9700 7550
F 0 "D?" H 9750 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 7650 50  0001 C CNN
F 2 "" H 9700 7550 50  0001 C CNN
F 3 "" H 9700 7550 50  0001 C CNN
	1    9700 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311B4
P 9700 7250
F 0 "L?" H 9750 7400 50  0001 L CNN
F 1 "DotCoil" H 9750 7200 50  0001 L CNN
F 2 "" V 9675 7350 50  0001 C CNN
F 3 "" V 9675 7350 50  0001 C CNN
	1    9700 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB311BB
P 9700 6850
F 0 "D?" H 9750 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 6950 50  0001 C CNN
F 2 "" H 9700 6850 50  0001 C CNN
F 3 "" H 9700 6850 50  0001 C CNN
	1    9700 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311C2
P 10500 7950
F 0 "L?" H 10550 8100 50  0001 L CNN
F 1 "DotCoil" H 10550 7900 50  0001 L CNN
F 2 "" V 10475 8050 50  0001 C CNN
F 3 "" V 10475 8050 50  0001 C CNN
	1    10500 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB311C9
P 10500 7550
F 0 "D?" H 10550 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 7650 50  0001 C CNN
F 2 "" H 10500 7550 50  0001 C CNN
F 3 "" H 10500 7550 50  0001 C CNN
	1    10500 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB311D0
P 10500 6850
F 0 "D?" H 10550 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 6950 50  0001 C CNN
F 2 "" H 10500 6850 50  0001 C CNN
F 3 "" H 10500 6850 50  0001 C CNN
	1    10500 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311D7
P 10500 7250
F 0 "L?" H 10550 7400 50  0001 L CNN
F 1 "DotCoil" H 10550 7200 50  0001 L CNN
F 2 "" V 10475 7350 50  0001 C CNN
F 3 "" V 10475 7350 50  0001 C CNN
	1    10500 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311DE
P 11300 9350
F 0 "L?" H 11350 9500 50  0001 L CNN
F 1 "DotCoil" H 11350 9300 50  0001 L CNN
F 2 "" V 11275 9450 50  0001 C CNN
F 3 "" V 11275 9450 50  0001 C CNN
	1    11300 9350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB311E5
P 11300 8950
F 0 "D?" H 11350 8850 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 9050 50  0001 C CNN
F 2 "" H 11300 8950 50  0001 C CNN
F 3 "" H 11300 8950 50  0001 C CNN
	1    11300 8950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311EC
P 11300 8650
F 0 "L?" H 11350 8800 50  0001 L CNN
F 1 "DotCoil" H 11350 8600 50  0001 L CNN
F 2 "" V 11275 8750 50  0001 C CNN
F 3 "" V 11275 8750 50  0001 C CNN
	1    11300 8650
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB311F3
P 11300 8250
F 0 "D?" H 11350 8150 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 8350 50  0001 C CNN
F 2 "" H 11300 8250 50  0001 C CNN
F 3 "" H 11300 8250 50  0001 C CNN
	1    11300 8250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB311FA
P 11300 7950
F 0 "L?" H 11350 8100 50  0001 L CNN
F 1 "DotCoil" H 11350 7900 50  0001 L CNN
F 2 "" V 11275 8050 50  0001 C CNN
F 3 "" V 11275 8050 50  0001 C CNN
	1    11300 7950
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31201
P 11300 7550
F 0 "D?" H 11350 7450 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 7650 50  0001 C CNN
F 2 "" H 11300 7550 50  0001 C CNN
F 3 "" H 11300 7550 50  0001 C CNN
	1    11300 7550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31208
P 11300 7250
F 0 "L?" H 11350 7400 50  0001 L CNN
F 1 "DotCoil" H 11350 7200 50  0001 L CNN
F 2 "" V 11275 7350 50  0001 C CNN
F 3 "" V 11275 7350 50  0001 C CNN
	1    11300 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3120F
P 11300 6850
F 0 "D?" H 11350 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 6950 50  0001 C CNN
F 2 "" H 11300 6850 50  0001 C CNN
F 3 "" H 11300 6850 50  0001 C CNN
	1    11300 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31216
P 6500 7250
F 0 "L?" H 6550 7400 50  0001 L CNN
F 1 "DotCoil" H 6550 7200 50  0001 L CNN
F 2 "" V 6475 7350 50  0001 C CNN
F 3 "" V 6475 7350 50  0001 C CNN
	1    6500 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3121D
P 6500 6850
F 0 "D?" H 6550 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 6950 50  0001 C CNN
F 2 "" H 6500 6850 50  0001 C CNN
F 3 "" H 6500 6850 50  0001 C CNN
	1    6500 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31224
P 6500 6550
F 0 "L?" H 6550 6700 50  0001 L CNN
F 1 "DotCoil" H 6550 6500 50  0001 L CNN
F 2 "" V 6475 6650 50  0001 C CNN
F 3 "" V 6475 6650 50  0001 C CNN
	1    6500 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3122B
P 6500 6150
F 0 "D?" H 6550 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 6250 50  0001 C CNN
F 2 "" H 6500 6150 50  0001 C CNN
F 3 "" H 6500 6150 50  0001 C CNN
	1    6500 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31232
P 7300 7250
F 0 "L?" H 7350 7400 50  0001 L CNN
F 1 "DotCoil" H 7350 7200 50  0001 L CNN
F 2 "" V 7275 7350 50  0001 C CNN
F 3 "" V 7275 7350 50  0001 C CNN
	1    7300 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31239
P 7300 6850
F 0 "D?" H 7350 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 6950 50  0001 C CNN
F 2 "" H 7300 6850 50  0001 C CNN
F 3 "" H 7300 6850 50  0001 C CNN
	1    7300 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31240
P 7300 6150
F 0 "D?" H 7350 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 6250 50  0001 C CNN
F 2 "" H 7300 6150 50  0001 C CNN
F 3 "" H 7300 6150 50  0001 C CNN
	1    7300 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31247
P 7300 6550
F 0 "L?" H 7350 6700 50  0001 L CNN
F 1 "DotCoil" H 7350 6500 50  0001 L CNN
F 2 "" V 7275 6650 50  0001 C CNN
F 3 "" V 7275 6650 50  0001 C CNN
	1    7300 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3124E
P 6500 5850
F 0 "L?" H 6550 6000 50  0001 L CNN
F 1 "DotCoil" H 6550 5800 50  0001 L CNN
F 2 "" V 6475 5950 50  0001 C CNN
F 3 "" V 6475 5950 50  0001 C CNN
	1    6500 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31255
P 6500 5450
F 0 "D?" H 6550 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 5550 50  0001 C CNN
F 2 "" H 6500 5450 50  0001 C CNN
F 3 "" H 6500 5450 50  0001 C CNN
	1    6500 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3125C
P 6500 5150
F 0 "L?" H 6550 5300 50  0001 L CNN
F 1 "DotCoil" H 6550 5100 50  0001 L CNN
F 2 "" V 6475 5250 50  0001 C CNN
F 3 "" V 6475 5250 50  0001 C CNN
	1    6500 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31263
P 6500 4750
F 0 "D?" H 6550 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 6500 4850 50  0001 C CNN
F 2 "" H 6500 4750 50  0001 C CNN
F 3 "" H 6500 4750 50  0001 C CNN
	1    6500 4750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3126A
P 7300 5850
F 0 "L?" H 7350 6000 50  0001 L CNN
F 1 "DotCoil" H 7350 5800 50  0001 L CNN
F 2 "" V 7275 5950 50  0001 C CNN
F 3 "" V 7275 5950 50  0001 C CNN
	1    7300 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31271
P 7300 5450
F 0 "D?" H 7350 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 5550 50  0001 C CNN
F 2 "" H 7300 5450 50  0001 C CNN
F 3 "" H 7300 5450 50  0001 C CNN
	1    7300 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31278
P 7300 4750
F 0 "D?" H 7350 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 7300 4850 50  0001 C CNN
F 2 "" H 7300 4750 50  0001 C CNN
F 3 "" H 7300 4750 50  0001 C CNN
	1    7300 4750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3127F
P 7300 5150
F 0 "L?" H 7350 5300 50  0001 L CNN
F 1 "DotCoil" H 7350 5100 50  0001 L CNN
F 2 "" V 7275 5250 50  0001 C CNN
F 3 "" V 7275 5250 50  0001 C CNN
	1    7300 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31286
P 8100 7250
F 0 "L?" H 8150 7400 50  0001 L CNN
F 1 "DotCoil" H 8150 7200 50  0001 L CNN
F 2 "" V 8075 7350 50  0001 C CNN
F 3 "" V 8075 7350 50  0001 C CNN
	1    8100 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3128D
P 8100 6850
F 0 "D?" H 8150 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 6950 50  0001 C CNN
F 2 "" H 8100 6850 50  0001 C CNN
F 3 "" H 8100 6850 50  0001 C CNN
	1    8100 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31294
P 8100 6550
F 0 "L?" H 8150 6700 50  0001 L CNN
F 1 "DotCoil" H 8150 6500 50  0001 L CNN
F 2 "" V 8075 6650 50  0001 C CNN
F 3 "" V 8075 6650 50  0001 C CNN
	1    8100 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3129B
P 8100 6150
F 0 "D?" H 8150 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 6250 50  0001 C CNN
F 2 "" H 8100 6150 50  0001 C CNN
F 3 "" H 8100 6150 50  0001 C CNN
	1    8100 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312A2
P 8900 7250
F 0 "L?" H 8950 7400 50  0001 L CNN
F 1 "DotCoil" H 8950 7200 50  0001 L CNN
F 2 "" V 8875 7350 50  0001 C CNN
F 3 "" V 8875 7350 50  0001 C CNN
	1    8900 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312A9
P 8900 6850
F 0 "D?" H 8950 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 6950 50  0001 C CNN
F 2 "" H 8900 6850 50  0001 C CNN
F 3 "" H 8900 6850 50  0001 C CNN
	1    8900 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312B0
P 8900 6150
F 0 "D?" H 8950 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 6250 50  0001 C CNN
F 2 "" H 8900 6150 50  0001 C CNN
F 3 "" H 8900 6150 50  0001 C CNN
	1    8900 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312B7
P 8900 6550
F 0 "L?" H 8950 6700 50  0001 L CNN
F 1 "DotCoil" H 8950 6500 50  0001 L CNN
F 2 "" V 8875 6650 50  0001 C CNN
F 3 "" V 8875 6650 50  0001 C CNN
	1    8900 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312BE
P 8100 5850
F 0 "L?" H 8150 6000 50  0001 L CNN
F 1 "DotCoil" H 8150 5800 50  0001 L CNN
F 2 "" V 8075 5950 50  0001 C CNN
F 3 "" V 8075 5950 50  0001 C CNN
	1    8100 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312C5
P 8100 5450
F 0 "D?" H 8150 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 5550 50  0001 C CNN
F 2 "" H 8100 5450 50  0001 C CNN
F 3 "" H 8100 5450 50  0001 C CNN
	1    8100 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312CC
P 8100 5150
F 0 "L?" H 8150 5300 50  0001 L CNN
F 1 "DotCoil" H 8150 5100 50  0001 L CNN
F 2 "" V 8075 5250 50  0001 C CNN
F 3 "" V 8075 5250 50  0001 C CNN
	1    8100 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312D3
P 8100 4750
F 0 "D?" H 8150 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8100 4850 50  0001 C CNN
F 2 "" H 8100 4750 50  0001 C CNN
F 3 "" H 8100 4750 50  0001 C CNN
	1    8100 4750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312DA
P 8900 5850
F 0 "L?" H 8950 6000 50  0001 L CNN
F 1 "DotCoil" H 8950 5800 50  0001 L CNN
F 2 "" V 8875 5950 50  0001 C CNN
F 3 "" V 8875 5950 50  0001 C CNN
	1    8900 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312E1
P 8900 5450
F 0 "D?" H 8950 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 5550 50  0001 C CNN
F 2 "" H 8900 5450 50  0001 C CNN
F 3 "" H 8900 5450 50  0001 C CNN
	1    8900 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312E8
P 8900 4750
F 0 "D?" H 8950 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 8900 4850 50  0001 C CNN
F 2 "" H 8900 4750 50  0001 C CNN
F 3 "" H 8900 4750 50  0001 C CNN
	1    8900 4750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312EF
P 8900 5150
F 0 "L?" H 8950 5300 50  0001 L CNN
F 1 "DotCoil" H 8950 5100 50  0001 L CNN
F 2 "" V 8875 5250 50  0001 C CNN
F 3 "" V 8875 5250 50  0001 C CNN
	1    8900 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB312F6
P 9700 7250
F 0 "L?" H 9750 7400 50  0001 L CNN
F 1 "DotCoil" H 9750 7200 50  0001 L CNN
F 2 "" V 9675 7350 50  0001 C CNN
F 3 "" V 9675 7350 50  0001 C CNN
	1    9700 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB312FD
P 9700 6850
F 0 "D?" H 9750 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 6950 50  0001 C CNN
F 2 "" H 9700 6850 50  0001 C CNN
F 3 "" H 9700 6850 50  0001 C CNN
	1    9700 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31304
P 9700 6550
F 0 "L?" H 9750 6700 50  0001 L CNN
F 1 "DotCoil" H 9750 6500 50  0001 L CNN
F 2 "" V 9675 6650 50  0001 C CNN
F 3 "" V 9675 6650 50  0001 C CNN
	1    9700 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3130B
P 9700 6150
F 0 "D?" H 9750 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 6250 50  0001 C CNN
F 2 "" H 9700 6150 50  0001 C CNN
F 3 "" H 9700 6150 50  0001 C CNN
	1    9700 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31312
P 10500 7250
F 0 "L?" H 10550 7400 50  0001 L CNN
F 1 "DotCoil" H 10550 7200 50  0001 L CNN
F 2 "" V 10475 7350 50  0001 C CNN
F 3 "" V 10475 7350 50  0001 C CNN
	1    10500 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31319
P 10500 6850
F 0 "D?" H 10550 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 6950 50  0001 C CNN
F 2 "" H 10500 6850 50  0001 C CNN
F 3 "" H 10500 6850 50  0001 C CNN
	1    10500 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31320
P 10500 6150
F 0 "D?" H 10550 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 6250 50  0001 C CNN
F 2 "" H 10500 6150 50  0001 C CNN
F 3 "" H 10500 6150 50  0001 C CNN
	1    10500 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31327
P 10500 6550
F 0 "L?" H 10550 6700 50  0001 L CNN
F 1 "DotCoil" H 10550 6500 50  0001 L CNN
F 2 "" V 10475 6650 50  0001 C CNN
F 3 "" V 10475 6650 50  0001 C CNN
	1    10500 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3132E
P 9700 5850
F 0 "L?" H 9750 6000 50  0001 L CNN
F 1 "DotCoil" H 9750 5800 50  0001 L CNN
F 2 "" V 9675 5950 50  0001 C CNN
F 3 "" V 9675 5950 50  0001 C CNN
	1    9700 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31335
P 9700 5450
F 0 "D?" H 9750 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 5550 50  0001 C CNN
F 2 "" H 9700 5450 50  0001 C CNN
F 3 "" H 9700 5450 50  0001 C CNN
	1    9700 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3133C
P 9700 5150
F 0 "L?" H 9750 5300 50  0001 L CNN
F 1 "DotCoil" H 9750 5100 50  0001 L CNN
F 2 "" V 9675 5250 50  0001 C CNN
F 3 "" V 9675 5250 50  0001 C CNN
	1    9700 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31343
P 9700 4750
F 0 "D?" H 9750 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 9700 4850 50  0001 C CNN
F 2 "" H 9700 4750 50  0001 C CNN
F 3 "" H 9700 4750 50  0001 C CNN
	1    9700 4750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3134A
P 10500 5850
F 0 "L?" H 10550 6000 50  0001 L CNN
F 1 "DotCoil" H 10550 5800 50  0001 L CNN
F 2 "" V 10475 5950 50  0001 C CNN
F 3 "" V 10475 5950 50  0001 C CNN
	1    10500 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31351
P 10500 5450
F 0 "D?" H 10550 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 5550 50  0001 C CNN
F 2 "" H 10500 5450 50  0001 C CNN
F 3 "" H 10500 5450 50  0001 C CNN
	1    10500 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31358
P 10500 4750
F 0 "D?" H 10550 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 10500 4850 50  0001 C CNN
F 2 "" H 10500 4750 50  0001 C CNN
F 3 "" H 10500 4750 50  0001 C CNN
	1    10500 4750
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB3135F
P 10500 5150
F 0 "L?" H 10550 5300 50  0001 L CNN
F 1 "DotCoil" H 10550 5100 50  0001 L CNN
F 2 "" V 10475 5250 50  0001 C CNN
F 3 "" V 10475 5250 50  0001 C CNN
	1    10500 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31366
P 11300 7250
F 0 "L?" H 11350 7400 50  0001 L CNN
F 1 "DotCoil" H 11350 7200 50  0001 L CNN
F 2 "" V 11275 7350 50  0001 C CNN
F 3 "" V 11275 7350 50  0001 C CNN
	1    11300 7250
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3136D
P 11300 6850
F 0 "D?" H 11350 6750 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 6950 50  0001 C CNN
F 2 "" H 11300 6850 50  0001 C CNN
F 3 "" H 11300 6850 50  0001 C CNN
	1    11300 6850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31374
P 11300 6550
F 0 "L?" H 11350 6700 50  0001 L CNN
F 1 "DotCoil" H 11350 6500 50  0001 L CNN
F 2 "" V 11275 6650 50  0001 C CNN
F 3 "" V 11275 6650 50  0001 C CNN
	1    11300 6550
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB3137B
P 11300 6150
F 0 "D?" H 11350 6050 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 6250 50  0001 C CNN
F 2 "" H 11300 6150 50  0001 C CNN
F 3 "" H 11300 6150 50  0001 C CNN
	1    11300 6150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31382
P 11300 5850
F 0 "L?" H 11350 6000 50  0001 L CNN
F 1 "DotCoil" H 11350 5800 50  0001 L CNN
F 2 "" V 11275 5950 50  0001 C CNN
F 3 "" V 11275 5950 50  0001 C CNN
	1    11300 5850
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31389
P 11300 5450
F 0 "D?" H 11350 5350 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 5550 50  0001 C CNN
F 2 "" H 11300 5450 50  0001 C CNN
F 3 "" H 11300 5450 50  0001 C CNN
	1    11300 5450
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Electromagnetic_Actor L?
U 1 1 5AB31390
P 11300 5150
F 0 "L?" H 11350 5300 50  0001 L CNN
F 1 "DotCoil" H 11350 5100 50  0001 L CNN
F 2 "" V 11275 5250 50  0001 C CNN
F 3 "" V 11275 5250 50  0001 C CNN
	1    11300 5150
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:D_x2_Serial_AKC D?
U 1 1 5AB31397
P 11300 4750
F 0 "D?" H 11350 4650 50  0001 C CNN
F 1 "D_x2_Serial_AKC" H 11300 4850 50  0001 C CNN
F 2 "" H 11300 4750 50  0001 C CNN
F 3 "" H 11300 4750 50  0001 C CNN
	1    11300 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 6000 3450 6000
Wire Wire Line
	3450 6000 3450 5250
Wire Wire Line
	3450 5250 3800 5250
Wire Wire Line
	4600 5250 5650 5250
Wire Wire Line
	5650 6800 4600 6800
Wire Wire Line
	2200 950  2200 5100
Wire Wire Line
	2200 6750 2500 6750
Connection ~ 2200 5100
Wire Wire Line
	3400 6800 3800 6800
Wire Wire Line
	3400 7400 3800 7400
Wire Wire Line
	3800 5350 3500 5350
Wire Wire Line
	3500 5350 3500 6100
Wire Wire Line
	3500 6100 3400 6100
Wire Wire Line
	3800 5450 3550 5450
Wire Wire Line
	3550 5450 3550 6200
Wire Wire Line
	3550 6200 3400 6200
Wire Wire Line
	3800 5550 3600 5550
Wire Wire Line
	3600 5550 3600 6300
Wire Wire Line
	3600 6300 3400 6300
Wire Wire Line
	3800 5650 3650 5650
Wire Wire Line
	3650 5650 3650 6400
Wire Wire Line
	3650 6400 3400 6400
Wire Wire Line
	3400 6500 3700 6500
Wire Wire Line
	3700 6500 3700 5750
Wire Wire Line
	3700 5750 3800 5750
Wire Wire Line
	3800 5850 3750 5850
Wire Wire Line
	3750 5850 3750 6600
Wire Wire Line
	3750 6600 3400 6600
Wire Wire Line
	3800 6900 3400 6900
Wire Wire Line
	3400 7000 3800 7000
Wire Wire Line
	3800 7100 3400 7100
Wire Wire Line
	3400 7200 3800 7200
Wire Wire Line
	3800 7300 3400 7300
Wire Wire Line
	9350 2050 9350 2500
Wire Wire Line
	9250 2050 9250 2500
Wire Wire Line
	9150 2050 9150 2500
Wire Wire Line
	9050 2050 9050 2500
Wire Wire Line
	8950 2050 8950 2500
Wire Wire Line
	8850 2050 8850 2500
Wire Wire Line
	8750 2050 8750 2500
Wire Wire Line
	2200 950  8700 950 
Wire Wire Line
	8700 950  8700 1150
Wire Wire Line
	8000 1150 7300 1150
Wire Wire Line
	7300 1150 7300 1650
Wire Wire Line
	7150 1650 7300 1650
Wire Wire Line
	2500 6050 2500 5300
Wire Wire Line
	2500 5300 3000 5300
Wire Wire Line
	3000 5200 3000 5300
Connection ~ 3000 5300
Connection ~ 7300 1650
Wire Wire Line
	8400 800  8400 1150
Wire Wire Line
	8500 800  8500 1150
Wire Wire Line
	8600 800  8600 1150
Wire Wire Line
	1650 6450 2500 6450
Wire Wire Line
	1650 6550 2500 6550
Wire Wire Line
	1650 6650 2500 6650
Wire Wire Line
	2650 5550 2650 5500
Wire Wire Line
	2650 5500 2850 5500
Wire Wire Line
	2850 5500 2850 5550
Wire Wire Line
	4600 6250 4600 6050
Wire Wire Line
	3650 7700 3650 7600
Wire Wire Line
	3650 7600 3800 7600
Wire Wire Line
	4800 7600 4600 7600
Wire Wire Line
	4800 7600 4800 7750
Wire Wire Line
	4200 6350 4200 6250
Wire Wire Line
	9900 2900 9750 2900
Wire Wire Line
	7050 3400 7050 3300
Wire Wire Line
	7300 2500 7050 2500
Wire Wire Line
	4600 5350 5550 5350
Wire Wire Line
	4600 5450 5450 5450
Wire Wire Line
	4600 5550 5350 5550
Wire Wire Line
	4600 5650 5250 5650
Wire Wire Line
	4600 5750 5150 5750
Wire Wire Line
	4600 5850 5050 5850
Wire Wire Line
	5650 6900 4600 6900
Wire Wire Line
	5450 7000 4600 7000
Wire Wire Line
	4600 7100 5350 7100
Wire Wire Line
	4600 7200 5250 7200
Wire Wire Line
	4600 7300 5150 7300
Wire Wire Line
	4600 7400 5050 7400
Wire Wire Line
	6350 3300 6350 4200
Wire Wire Line
	6450 3300 6450 4250
Wire Wire Line
	6550 3300 6550 4300
Wire Wire Line
	6650 3300 6650 4350
Wire Wire Line
	6750 3300 6750 4400
Wire Wire Line
	6850 3300 6850 4450
Wire Wire Line
	8850 3300 8850 3750
Wire Wire Line
	8950 3300 8950 3800
Wire Wire Line
	9050 3300 9050 3850
Wire Wire Line
	9150 3300 9150 3900
Wire Wire Line
	9250 3300 9250 3950
Wire Wire Line
	11600 4000 11600 4750
Wire Wire Line
	2100 5100 2200 5100
Wire Wire Line
	6800 3700 6800 4750
Wire Wire Line
	6200 4150 6200 4750
Wire Wire Line
	5150 8750 6500 8750
Wire Wire Line
	5050 9450 6500 9450
Connection ~ 6500 9450
Connection ~ 6500 8750
Wire Wire Line
	7000 4200 7000 4750
Wire Wire Line
	7600 3750 7600 4750
Wire Wire Line
	5350 7350 6500 7350
Wire Wire Line
	5250 8050 6500 8050
Connection ~ 6500 8050
Connection ~ 6500 7350
Connection ~ 6200 8250
Connection ~ 6200 7550
Connection ~ 6800 7550
Connection ~ 6800 8250
Connection ~ 7600 8250
Connection ~ 7600 7550
Connection ~ 7000 7550
Connection ~ 7000 8250
Wire Wire Line
	8400 3800 8400 4750
Wire Wire Line
	7800 4250 7800 4750
Connection ~ 8100 9450
Connection ~ 8100 8750
Wire Wire Line
	8600 4300 8600 4750
Wire Wire Line
	9200 3850 9200 4750
Connection ~ 8100 8050
Connection ~ 8100 7350
Connection ~ 7800 8250
Connection ~ 7800 7550
Connection ~ 8400 7550
Connection ~ 8400 8250
Connection ~ 9200 8250
Connection ~ 9200 7550
Connection ~ 8600 7550
Connection ~ 8600 8250
Connection ~ 7300 9450
Connection ~ 7300 8750
Connection ~ 7300 8050
Connection ~ 7300 7350
Wire Wire Line
	10000 3900 10000 4750
Wire Wire Line
	9400 4350 9400 4750
Connection ~ 9700 9450
Connection ~ 9700 8750
Wire Wire Line
	10200 4400 10200 4750
Wire Wire Line
	10800 3950 10800 4750
Connection ~ 9700 8050
Connection ~ 9700 7350
Connection ~ 9400 8250
Connection ~ 9400 7550
Connection ~ 10000 7550
Connection ~ 10000 8250
Connection ~ 10800 8250
Connection ~ 10800 7550
Connection ~ 10200 7550
Connection ~ 10200 8250
Wire Wire Line
	11000 4450 11000 4750
Connection ~ 11000 8250
Connection ~ 11000 7550
Connection ~ 11600 7550
Connection ~ 11600 8250
Connection ~ 10500 9450
Connection ~ 10500 8750
Connection ~ 10500 8050
Connection ~ 10500 7350
Connection ~ 8900 7350
Connection ~ 8900 8050
Connection ~ 8900 8750
Connection ~ 8900 9450
Wire Wire Line
	5450 6650 6500 6650
Wire Wire Line
	6500 7350 7300 7350
Connection ~ 6500 6650
Wire Wire Line
	5550 5950 6500 5950
Connection ~ 6500 5950
Connection ~ 6500 5250
Connection ~ 6200 6150
Connection ~ 6200 5450
Connection ~ 6800 5450
Connection ~ 6800 6150
Connection ~ 7600 6150
Connection ~ 7600 5450
Connection ~ 7000 5450
Connection ~ 7000 6150
Connection ~ 8100 6650
Connection ~ 8100 5950
Connection ~ 8100 5250
Connection ~ 7800 6150
Connection ~ 7800 5450
Connection ~ 8400 5450
Connection ~ 8400 6150
Connection ~ 9200 6150
Connection ~ 9200 5450
Connection ~ 8600 5450
Connection ~ 8600 6150
Connection ~ 7300 6650
Connection ~ 7300 5950
Connection ~ 7300 5250
Connection ~ 9700 6650
Connection ~ 9700 5950
Connection ~ 9700 5250
Connection ~ 9400 6150
Connection ~ 9400 5450
Connection ~ 10000 5450
Connection ~ 10000 6150
Connection ~ 10800 6150
Connection ~ 10800 5450
Connection ~ 10200 5450
Connection ~ 10200 6150
Connection ~ 11000 6150
Connection ~ 11000 5450
Connection ~ 11600 5450
Connection ~ 11600 6150
Connection ~ 10500 6650
Connection ~ 10500 5950
Connection ~ 10500 5250
Connection ~ 8900 5250
Connection ~ 8900 5950
Connection ~ 8900 6650
Connection ~ 11600 6850
Connection ~ 11000 6850
Connection ~ 10800 6850
Connection ~ 10200 6850
Connection ~ 9400 6850
Connection ~ 10000 6850
Connection ~ 9200 6850
Connection ~ 8600 6850
Connection ~ 8400 6850
Connection ~ 7800 6850
Connection ~ 7600 6850
Connection ~ 7000 6850
Connection ~ 6800 6850
Connection ~ 6200 6850
Connection ~ 6200 4750
Connection ~ 6800 4750
Connection ~ 7000 4750
Connection ~ 7600 4750
Connection ~ 7800 4750
Connection ~ 8400 4750
Connection ~ 8600 4750
Connection ~ 9200 4750
Connection ~ 9400 4750
Connection ~ 10000 4750
Connection ~ 10200 4750
Connection ~ 10800 4750
Connection ~ 11000 4750
Connection ~ 11600 4750
Wire Wire Line
	6350 4200 7000 4200
Wire Wire Line
	6450 4250 7800 4250
Wire Wire Line
	6550 4300 8600 4300
Wire Wire Line
	6650 4350 9400 4350
Wire Wire Line
	6750 4400 10200 4400
Wire Wire Line
	6850 4450 11000 4450
Wire Wire Line
	8750 3300 8750 3700
Wire Wire Line
	8750 3700 6800 3700
Wire Wire Line
	8850 3750 7600 3750
Wire Wire Line
	8950 3800 8400 3800
Wire Wire Line
	9050 3850 9200 3850
Wire Wire Line
	9150 3900 10000 3900
Wire Wire Line
	9250 3950 10800 3950
Wire Wire Line
	9350 4000 11600 4000
Wire Wire Line
	6250 3300 6250 4150
Wire Wire Line
	6250 4150 6200 4150
Wire Wire Line
	7950 2050 7950 2100
Wire Wire Line
	7950 2100 6250 2100
Wire Wire Line
	6250 2100 6250 2500
Wire Wire Line
	6350 2500 6350 2150
Wire Wire Line
	6350 2150 8050 2150
Wire Wire Line
	8050 2150 8050 2050
Wire Wire Line
	8150 2050 8150 2200
Wire Wire Line
	8150 2200 6450 2200
Wire Wire Line
	6450 2200 6450 2500
Wire Wire Line
	6550 2500 6550 2250
Wire Wire Line
	6550 2250 8250 2250
Wire Wire Line
	8250 2250 8250 2050
Wire Wire Line
	6650 2500 6650 2300
Wire Wire Line
	6650 2300 8350 2300
Wire Wire Line
	8350 2300 8350 2050
Wire Wire Line
	8450 2050 8450 2350
Wire Wire Line
	8450 2350 6750 2350
Wire Wire Line
	6750 2350 6750 2500
Wire Wire Line
	6850 2500 6850 2400
Wire Wire Line
	6850 2400 8550 2400
Wire Wire Line
	8550 2400 8550 2050
Wire Wire Line
	9350 3300 9350 4000
Wire Wire Line
	5550 5350 5550 5950
Wire Wire Line
	5450 5450 5450 6650
Wire Wire Line
	5350 5550 5350 7100
Wire Wire Line
	5250 5650 5250 7200
Wire Wire Line
	5150 5750 5150 7300
Wire Wire Line
	5050 5850 5050 7400
Wire Wire Line
	5650 5250 5650 6800
Connection ~ 5650 5250
Connection ~ 5050 7400
Connection ~ 5150 7300
Connection ~ 5250 7200
Connection ~ 5350 7100
Connection ~ 5450 6650
Connection ~ 5650 6800
$Comp
L flipdot-rescue:74LS139 U?
U 1 1 5AB48CDD
P 4650 4350
F 0 "U?" H 4650 4450 50  0001 C CNN
F 1 "74LS139" H 4650 4250 50  0000 C CNN
F 2 "" H 4650 4350 50  0001 C CNN
F 3 "" H 4650 4350 50  0001 C CNN
	1    4650 4350
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:74LS139 U?
U 2 1 5AB490F6
P 4650 1600
F 0 "U?" H 4650 1700 50  0001 C CNN
F 1 "74LS139" H 4650 1500 50  0000 C CNN
F 2 "" H 4650 1600 50  0001 C CNN
F 3 "" H 4650 1600 50  0001 C CNN
	2    4650 1600
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:7402 U?
U 1 1 5AB4BBE7
P 1500 5100
F 0 "U?" H 1500 5150 50  0001 C CNN
F 1 "7402" H 1550 5050 50  0000 C CNN
F 2 "" H 1500 5100 50  0001 C CNN
F 3 "" H 1500 5100 50  0001 C CNN
	1    1500 5100
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:7402 U?
U 2 1 5AB4BEA8
P 3200 4600
F 0 "U?" H 3200 4650 50  0001 C CNN
F 1 "7402" H 3250 4550 50  0000 C CNN
F 2 "" H 3200 4600 50  0001 C CNN
F 3 "" H 3200 4600 50  0001 C CNN
	2    3200 4600
	1    0    0    -1  
$EndComp
Text GLabel 2600 4500 0    39   Input ~ 0
RE1
Text GLabel 2600 4700 0    39   Input ~ 0
RE2
Text GLabel 3800 4100 0    39   Input ~ 0
R4
Text GLabel 3800 4250 0    39   Input ~ 0
R3
Text GLabel 2500 7200 0    39   Input ~ 0
~ER1~
Text GLabel 5500 4050 2    39   Output ~ 0
~ER1~
Text GLabel 5500 4250 2    39   Output ~ 0
~ER2~
Text GLabel 5500 4450 2    39   Output ~ 0
~ER3~
Text GLabel 5500 4650 2    39   Output ~ 0
~ER4~
Wire Wire Line
	900  5000 900  5100
Wire Wire Line
	900  5100 800  5100
Connection ~ 900  5100
Text GLabel 9150 1150 1    39   Input ~ 0
~EC1~
Text GLabel 5500 1300 2    39   Output ~ 0
~EC1~
Text GLabel 5500 1500 2    39   Output ~ 0
~EC2~
Text GLabel 5500 1700 2    39   Output ~ 0
~EC3~
Text GLabel 5500 1900 2    39   Output ~ 0
~EC4~
Text GLabel 3800 1350 0    39   Input ~ 0
C4
Text GLabel 3800 1500 0    39   Input ~ 0
C3
$Comp
L flipdot-rescue:C_Small C?
U 1 1 5AB55C76
P 3500 1850
F 0 "C?" H 3510 1920 50  0001 L CNN
F 1 "C" H 3510 1770 50  0000 L CNN
F 2 "" H 3500 1850 50  0001 C CNN
F 3 "" H 3500 1850 50  0001 C CNN
	1    3500 1850
	0    -1   -1   0   
$EndComp
$Comp
L flipdot-rescue:R R?
U 1 1 5AB56BD7
P 3700 2100
F 0 "R?" V 3780 2100 50  0001 C CNN
F 1 "R" V 3700 2100 50  0000 C CNN
F 2 "" V 3630 2100 50  0001 C CNN
F 3 "" H 3700 2100 50  0001 C CNN
	1    3700 2100
	1    0    0    -1  
$EndComp
$Comp
L flipdot-rescue:Earth #PWR?
U 1 1 5AB56D84
P 3700 2250
F 0 "#PWR?" H 3700 2000 50  0001 C CNN
F 1 "Earth" H 3700 2100 50  0001 C CNN
F 2 "" H 3700 2250 50  0001 C CNN
F 3 "" H 3700 2250 50  0001 C CNN
	1    3700 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1950 3700 1850
Wire Wire Line
	3600 1850 3700 1850
Connection ~ 3700 1850
Wire Wire Line
	3400 1850 3300 1850
Text GLabel 3300 1850 0    39   Input ~ 0
P1
Wire Wire Line
	7500 1500 7500 1350
$Comp
L flipdot-rescue:Conn_02x13_Odd_Even J?
U 1 1 5AB140E3
P 1250 2000
F 0 "J?" H 1300 2700 50  0001 C CNN
F 1 "Conn_02x13" H 1300 1300 50  0000 C CNN
F 2 "" H 1250 2000 50  0001 C CNN
F 3 "" H 1250 2000 50  0001 C CNN
	1    1250 2000
	1    0    0    1   
$EndComp
Text GLabel 1550 2400 2    39   Output ~ 0
R0
Text GLabel 1550 2300 2    39   Output ~ 0
R1
Text GLabel 1050 2400 0    39   Output ~ 0
R2
Text GLabel 1050 2300 0    39   Output ~ 0
R3
Text GLabel 1550 2200 2    39   Output ~ 0
R4
Text GLabel 1050 2200 0    39   Output ~ 0
~ER1~
Text GLabel 1550 2100 2    39   Output ~ 0
~ER2~
$Comp
L flipdot-rescue:Earth #PWR?
U 1 1 5AB1432F
P 1550 2600
F 0 "#PWR?" H 1550 2350 50  0001 C CNN
F 1 "Earth" H 1550 2450 50  0001 C CNN
F 2 "" H 1550 2600 50  0001 C CNN
F 3 "" H 1550 2600 50  0001 C CNN
	1    1550 2600
	0    -1   -1   0   
$EndComp
$Comp
L flipdot-rescue:Earth #PWR?
U 1 1 5AB1434A
P 1050 2600
F 0 "#PWR?" H 1050 2350 50  0001 C CNN
F 1 "Earth" H 1050 2450 50  0001 C CNN
F 2 "" H 1050 2600 50  0001 C CNN
F 3 "" H 1050 2600 50  0001 C CNN
	1    1050 2600
	0    1    1    0   
$EndComp
$Comp
L flipdot-rescue:+5V #PWR?
U 1 1 5AB14370
P 1650 2500
F 0 "#PWR?" H 1650 2350 50  0001 C CNN
F 1 "+5V" H 1650 2640 50  0000 C CNN
F 2 "" H 1650 2500 50  0001 C CNN
F 3 "" H 1650 2500 50  0001 C CNN
	1    1650 2500
	0    1    1    0   
$EndComp
NoConn ~ 1050 2500
NoConn ~ 1050 2100
Text GLabel 1550 2000 2    39   Output ~ 0
C0
Text GLabel 1550 1900 2    39   Output ~ 0
C2
Text GLabel 1050 2000 0    39   Output ~ 0
C1
Text GLabel 1050 1900 0    39   Output ~ 0
C3
Text GLabel 1550 1800 2    39   Output ~ 0
C4
Text GLabel 1050 1800 0    39   Output ~ 0
Color
Text GLabel 1550 1600 2    39   Output ~ 0
P1
Text GLabel 1050 1600 0    39   Output ~ 0
P2
Text GLabel 1550 1500 2    39   Output ~ 0
P3
Text GLabel 1050 1500 0    39   Output ~ 0
P4
NoConn ~ 1550 1400
$Comp
L flipdot-rescue:+24V #PWR?
U 1 1 5AB1449B
P 950 1400
F 0 "#PWR?" H 950 1250 50  0001 C CNN
F 1 "+24V" H 950 1540 50  0000 C CNN
F 2 "" H 950 1400 50  0001 C CNN
F 3 "" H 950 1400 50  0001 C CNN
	1    950  1400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	950  1400 1050 1400
Wire Wire Line
	1650 2500 1550 2500
NoConn ~ 1550 1700
NoConn ~ 1050 1700
Wire Wire Line
	2200 5100 2200 6750
Wire Wire Line
	3000 5300 3000 5550
Wire Wire Line
	7300 1650 7500 1650
Wire Wire Line
	6500 9450 7300 9450
Wire Wire Line
	6500 8750 7300 8750
Wire Wire Line
	6500 8050 7300 8050
Wire Wire Line
	6200 8250 6200 8950
Wire Wire Line
	6200 7550 6200 8250
Wire Wire Line
	6800 7550 6800 8250
Wire Wire Line
	6800 8250 6800 8950
Wire Wire Line
	7600 8250 7600 8950
Wire Wire Line
	7600 7550 7600 8250
Wire Wire Line
	7000 7550 7000 8250
Wire Wire Line
	7000 8250 7000 8950
Wire Wire Line
	8100 9450 8900 9450
Wire Wire Line
	8100 8750 8900 8750
Wire Wire Line
	8100 8050 8900 8050
Wire Wire Line
	8100 7350 8900 7350
Wire Wire Line
	7800 8250 7800 8950
Wire Wire Line
	7800 7550 7800 8250
Wire Wire Line
	8400 7550 8400 8250
Wire Wire Line
	8400 8250 8400 8950
Wire Wire Line
	9200 8250 9200 8950
Wire Wire Line
	9200 7550 9200 8250
Wire Wire Line
	8600 7550 8600 8250
Wire Wire Line
	8600 8250 8600 8950
Wire Wire Line
	7300 9450 8100 9450
Wire Wire Line
	7300 8750 8100 8750
Wire Wire Line
	7300 8050 8100 8050
Wire Wire Line
	7300 7350 8100 7350
Wire Wire Line
	9700 9450 10500 9450
Wire Wire Line
	9700 8750 10500 8750
Wire Wire Line
	9700 8050 10500 8050
Wire Wire Line
	9700 7350 10500 7350
Wire Wire Line
	9400 8250 9400 8950
Wire Wire Line
	9400 7550 9400 8250
Wire Wire Line
	10000 7550 10000 8250
Wire Wire Line
	10000 8250 10000 8950
Wire Wire Line
	10800 8250 10800 8950
Wire Wire Line
	10800 7550 10800 8250
Wire Wire Line
	10200 7550 10200 8250
Wire Wire Line
	10200 8250 10200 8950
Wire Wire Line
	11000 8250 11000 8950
Wire Wire Line
	11000 7550 11000 8250
Wire Wire Line
	11600 7550 11600 8250
Wire Wire Line
	11600 8250 11600 8950
Wire Wire Line
	10500 9450 11300 9450
Wire Wire Line
	10500 8750 11300 8750
Wire Wire Line
	10500 8050 11300 8050
Wire Wire Line
	10500 7350 11300 7350
Wire Wire Line
	8900 7350 9700 7350
Wire Wire Line
	8900 8050 9700 8050
Wire Wire Line
	8900 8750 9700 8750
Wire Wire Line
	8900 9450 9700 9450
Wire Wire Line
	6500 6650 7300 6650
Wire Wire Line
	6500 5950 7300 5950
Wire Wire Line
	6500 5250 7300 5250
Wire Wire Line
	6200 6150 6200 6850
Wire Wire Line
	6200 5450 6200 6150
Wire Wire Line
	6800 5450 6800 6150
Wire Wire Line
	6800 6150 6800 6850
Wire Wire Line
	7600 6150 7600 6850
Wire Wire Line
	7600 5450 7600 6150
Wire Wire Line
	7000 5450 7000 6150
Wire Wire Line
	7000 6150 7000 6850
Wire Wire Line
	8100 6650 8900 6650
Wire Wire Line
	8100 5950 8900 5950
Wire Wire Line
	8100 5250 8900 5250
Wire Wire Line
	7800 6150 7800 6850
Wire Wire Line
	7800 5450 7800 6150
Wire Wire Line
	8400 5450 8400 6150
Wire Wire Line
	8400 6150 8400 6850
Wire Wire Line
	9200 6150 9200 6850
Wire Wire Line
	9200 5450 9200 6150
Wire Wire Line
	8600 5450 8600 6150
Wire Wire Line
	8600 6150 8600 6850
Wire Wire Line
	7300 6650 8100 6650
Wire Wire Line
	7300 5950 8100 5950
Wire Wire Line
	7300 5250 8100 5250
Wire Wire Line
	9700 6650 10500 6650
Wire Wire Line
	9700 5950 10500 5950
Wire Wire Line
	9700 5250 10500 5250
Wire Wire Line
	9400 6150 9400 6850
Wire Wire Line
	9400 5450 9400 6150
Wire Wire Line
	10000 5450 10000 6150
Wire Wire Line
	10000 6150 10000 6850
Wire Wire Line
	10800 6150 10800 6850
Wire Wire Line
	10800 5450 10800 6150
Wire Wire Line
	10200 5450 10200 6150
Wire Wire Line
	10200 6150 10200 6850
Wire Wire Line
	11000 6150 11000 6850
Wire Wire Line
	11000 5450 11000 6150
Wire Wire Line
	11600 5450 11600 6150
Wire Wire Line
	11600 6150 11600 6850
Wire Wire Line
	10500 6650 11300 6650
Wire Wire Line
	10500 5950 11300 5950
Wire Wire Line
	10500 5250 11300 5250
Wire Wire Line
	8900 5250 9700 5250
Wire Wire Line
	8900 5950 9700 5950
Wire Wire Line
	8900 6650 9700 6650
Wire Wire Line
	11600 6850 11600 7550
Wire Wire Line
	11000 6850 11000 7550
Wire Wire Line
	10800 6850 10800 7550
Wire Wire Line
	10200 6850 10200 7550
Wire Wire Line
	9400 6850 9400 7550
Wire Wire Line
	10000 6850 10000 7550
Wire Wire Line
	9200 6850 9200 7550
Wire Wire Line
	8600 6850 8600 7550
Wire Wire Line
	8400 6850 8400 7550
Wire Wire Line
	7800 6850 7800 7550
Wire Wire Line
	7600 6850 7600 7550
Wire Wire Line
	7000 6850 7000 7550
Wire Wire Line
	6800 6850 6800 7550
Wire Wire Line
	6200 6850 6200 7550
Wire Wire Line
	6200 4750 6200 5450
Wire Wire Line
	6800 4750 6800 5450
Wire Wire Line
	7000 4750 7000 5450
Wire Wire Line
	7600 4750 7600 5450
Wire Wire Line
	7800 4750 7800 5450
Wire Wire Line
	8400 4750 8400 5450
Wire Wire Line
	8600 4750 8600 5450
Wire Wire Line
	9200 4750 9200 5450
Wire Wire Line
	9400 4750 9400 5450
Wire Wire Line
	10000 4750 10000 5450
Wire Wire Line
	10200 4750 10200 5450
Wire Wire Line
	10800 4750 10800 5450
Wire Wire Line
	11000 4750 11000 5450
Wire Wire Line
	11600 4750 11600 5450
Wire Wire Line
	5650 5250 6500 5250
Wire Wire Line
	5050 7400 5050 9450
Wire Wire Line
	5150 7300 5150 8750
Wire Wire Line
	5250 7200 5250 8050
Wire Wire Line
	5350 7100 5350 7350
Wire Wire Line
	5450 6650 5450 7000
Wire Wire Line
	5650 6800 5650 6900
Wire Wire Line
	900  5100 900  5200
Wire Wire Line
	3700 1850 3800 1850
$EndSCHEMATC
