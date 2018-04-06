#!/usr/bin/python3
import socket
import getch

UDP_IP = socket.gethostbyname("flipdot.local")
UDP_PORT = 12345

def command(msg):
    sock = socket.socket(socket.AF_INET, # Internet
                         socket.SOCK_DGRAM) # UDP
    sock.sendto(msg.encode(), (UDP_IP, UDP_PORT))

def main():
    running = True
    while running:
        while True:
            k = getch.getch()
            if k != '':
                break
        # print(k)        
        if k == 'Q':
            running = False
        if k =='\x1b' and getch.getch() == '[':
            k = getch.getch()
            if k == 'A':
                command("up")
            elif k =='B':
                command("down")
            elif k=='C':
                command("right")
            elif k=='D':
                command("left")
        else:
            command(k)

if __name__=='__main__':
    main()