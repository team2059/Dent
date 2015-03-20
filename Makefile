REMOTEIP=10.20.59.2
CC=arm-frc-linux-gnueabi-g++
CFLAGS=-std=c++11 -O0 -g3 -Wall -c -fmessage-length=0
LDFLAGS=-Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a
SOURCES=$(shell find -type f -name "*.cpp")
OBJECTS=$(SOURCES:.cpp=.o)
WPILIB=/var/frc/wpilib
EXEC=bin/FRCUserProgram
CLEANSER=rm -f
READER=$(shell which pv||which cat)

all : $(OBJECTS)
	if [ ! -d bin ];then mkdir bin; fi
	$(CC) -L$(WPILIB)/lib $(LDFLAGS) -o $(EXEC) $(OBJECTS) -lwpi

%.o : %.cpp
	$(CC) $(CFLAGS) -I$(WPILIB)/include $^ -o $@

clean:
	$(CLEANSER) $(OBJECTS) bin/FRCUserProgram

deploy:
		@$(READER) bin/FRCUserProgram | ssh admin@$(REMOTEIP) '(rm /home/lvuser/FRCUserProgram)</dev/null;cat > /home/lvuser/FRCUserProgram;chmod a+x /home/lvuser/FRCUserProgram && /usr/local/frc/bin/frcKillRobot.sh -r -t'

debug:
		@$(READER) bin/FRCUserProgram | ssh admin@$(REMOTEIP) '(rm /home/lvuser/FRCUserProgram)</dev/null;cat > /home/lvuser/FRCUserProgram;chmod a+x /home/lvuser/FRCUserProgram;/home/lvuser/run.sh'

putkey:
	@test -d ~/.ssh||mkdir ~/.ssh;test -f ~/.ssh/id_rsa||ssh-keygen -t rsa -f ~/.ssh/id_rsa -b 4096 -q -N '';cat ~/.ssh/id_rsa.pub|ssh -v admin@$(REMOTEIP) 'cat >> /tmp/key;mkdir -p ~/.ssh;cat /tmp/key >> ~/.ssh/authorized_keys;rm /tmp/key'
