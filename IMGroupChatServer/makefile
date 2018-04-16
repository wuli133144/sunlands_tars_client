
#-----------------------------------------------------------------------

APP       := IMGroupChatApp
TARGET    := IMGroupChatServer
CONFIG    := 
STRIP_FLAG:= N
TARS2CPP_FLAG:= 



INCLUDE   += -I./utils -I./utils/slog  -I./business -I./model  -I./
LIB       +=  -L./utils/slog/ -L./utils/slog/lib/  -L./business  -L./model -L./   -llog4cxx -lslog

LOCAL_SRC   += $(sort $(wildcard *.cpp *.c ./model/*.cpp ./business/*.cpp ./utils/*.cpp ./utils/*.c))

LOCAL_OBJ   += $(patsubst %.cpp,%.o, $(patsubst %.c,%.o, $(LOCAL_SRC)))

DEP_FILE    := $(foreach obj, $(LOCAL_OBJ), $(dir $(obj)).$(basename $(notdir $(obj))).d)


#-----------------------------------------------------------------------

include /usr/local/tars/cpp/makefile/makefile.tars

#-----------------------------------------------------------------------
