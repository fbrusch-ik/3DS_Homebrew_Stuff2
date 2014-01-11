#!/usr/bin/python

import sys
import os
import ftplib


BASE_ADDRESS = 0x080C3EE0
CC = "arm-none-eabi-gcc"
CP = "arm-none-eabi-g++"
OC = "arm-none-eabi-objcopy" 
LD = "arm-none-eabi-ld"


def run(cmd):
	#print cmd
	os.system(cmd)

def upload(filename):
	session = ftplib.FTP('192.168.2.29')
	file = open(filename,"rb") 
	session.storbinary('STOR '+filename, file) 
	file.close()                                 
	session.quit()

cwd = os.getcwd() 
run("del obj\\*.o")
run(CC+" -g source/*.c -c -mcpu=mpcore -march=armv6k -mlittle-endian");
run(CC+" -g source/*.s -c -mcpu=mpcore -march=armv6k -mlittle-endian");
run("xcopy *.o obj\\ >NUL")
run(LD+" -T 3ds.ld *.o")
run("copy a.out bin\\homebrew.elf >NUL")
run(OC+" -O binary a.out payload.bin")
run(cwd+"\\lib\\p3ds\\3dsploit.py "+cwd+"\\payload.bin > NUL")
#run("copy Launcher.dat E:\\Launcher.dat > NUL")
upload("Launcher.dat")
run("del *.o")
run("del *.out")
run("del payload.bin")
