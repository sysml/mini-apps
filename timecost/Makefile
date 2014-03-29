STUBDOM_NAME		:= $(notdir $(realpath .))
STUBDOM_ROOT		:= $(realpath .)

ifeq ($(USE_NOW),y)
STUB_CFLAGS			+= -DUSE_NOW
endif

include $(MINIOS_ROOT)/stub.mk
