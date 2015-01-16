CC=arm-frc-linux-gnueabi-g++
CFLAGS=-std=c++11 -O0 -g3 -Wall -c -fmessage-length=0
LDFLAGS=-Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a
SOURCES=$(shell find -type f -name "*.cpp")
OBJECTS=$(SOURCES:.cpp=.o)
WPILIB=/var/frc/wpilib
EXEC=bin/FRCUserProgram
CLEANSER=rm -r
REMOTEIP=10.0.1.31

all : $(OBJECTS)
	$(CC) -L$(WPILIB)/lib $(LDFLAGS) -o $(EXEC) $(OBJECTS) -lwpi

%.o : %.cpp
	$(CC) $(CFLAGS) -I$(WPILIB)/include $^ -o $@

clean:
	$(CLEANSER) $(OBJECTS)

deploy:
	@ssh -v admin@$(REMOTEIP) "rm /home/lvuser/FRCUserProgram"
	@scp bin/FRCUserProgram admin@$(REMOTEIP)
	@ssh -v admin@$(REMOTEIP) "/etc/profile.d/natinst-path.sh; chmod a+x /home/lvuser/FRCUserProgram; /usr/local/frc/bin/frcKillRobot.sh -t -r"

putkey:
	@test -d ~/.ssh||mkdir ~/.ssh;test -f ~/.ssh/id_rsa||ssh-keygen -t rsa -f ~/.ssh/id_rsa -b 4096 -q -N '';cat ~/.ssh/id_rsa.pub|ssh -v admin@$(REMOTEIP) 'cat >> /tmp/key;mkdir -p ~/.ssh;cat /tmp/key >> ~/.ssh/authorized_keys;rm /tmp/key'

updatemakefile:
	@curl -s https://raw.githubusercontent.com/int0x191f2/nameless/master/configure.sh | sh
