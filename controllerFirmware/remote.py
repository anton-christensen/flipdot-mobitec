#!/usr/bin/python3
import socket
# import getch

class _Getch:
    """Gets a single character from standard input.  Does not echo to the
screen."""
    def __init__(self):
        try:
            self.impl = _GetchWindows()
        except ImportError:
            self.impl = _GetchUnix()

    def __call__(self): return self.impl()


class _GetchUnix:
    def __init__(self):
        import tty, sys

    def __call__(self):
        import sys, tty, termios
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return ch

class _GetchWindows:
    def __init__(self):
        import msvcrt

    def __call__(self):
        import msvcrt
        return msvcrt.getch()

getch = _Getch()


UDP_IP = socket.gethostbyname("flipdot.local")
# UDP_IP = socket.gethostbyname("esp32-30aea403d9ec.local")
UDP_PORT = 12345

def command(msg):
    sock = socket.socket(socket.AF_INET, # Internet
                         socket.SOCK_DGRAM) # UDP
    sock.sendto(msg.encode(), (UDP_IP, UDP_PORT))

def main():
    print("Ready")
    running = True
    while running:
        while True:
            k = getch()
            if k != '':
                break
                
        print(k+" ", end='')
        print(ord(k))

        if ord(k) == 127:
            command("backspace")
        elif ord(k) == 3: # CTRL + c
            running = False
        elif ord(k) == 13: # CTRL + c
            command("\n")
        elif ord(k) == 17: # CTRL + q
            command("quit")
        elif ord(k) == 18: # CTRL + r
            command("redraw")
        elif k =='\x1b' and getch() == '[':
            k = getch()
            if k == 'A':
                command("up")
            elif k =='B':
                command("down")
            elif k=='C':
                command("right")
            elif k=='D':
                command("left")
            else:
                print("unknown escape char \x1b["+k)
        else:
            command(k)

if __name__=='__main__':
    main()
