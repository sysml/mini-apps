STUBDOM_NAME		:= $(notdir $(realpath .))
STUBDOM_ROOT		:= $(realpath .)
STUB_APP_OBJS0		:= main.o daytime.o

CONFIG_LWIP := y
CONFIG_START_NETWORK := y
CONFIG_NETFRONT_GSO := n
CONFIG_NOXS ?= y
CONFIG_DEBUG_NOXS ?= n
CONFIG_SELECT_POLL ?= y
CONFIG_LWIP_SELECT_TIMEOUT := 86400

stub: $(STUBDOM_NAME).cfg daytime.c

daytime.c:
	ln -s $(MINIOS_ROOT)/daytime.c daytime.c

$(STUBDOM_NAME).cfg:
	@echo "name        = '$(STUBDOM_NAME)'" >> $@
	@echo "" >> $@
	@echo "kernel      = '$(STUB_APP_IMG)'" >> $@
	@echo "" >> $@
	@echo "vcpus       = '1'" >> $@
	@echo "memory      = '8'" >> $@
	@echo "" >> $@
	@echo "on_crash    = 'preserve'" >> $@
	$(call verbose_cmd,$(TOUCH),'CREATE',$@)

distclean: clean-cfg

.PHONY: clean-cfg
clean-cfg:
	$(call verbose_cmd,$(RM),'CLN',$(STUBDOM_NAME).cfg)

include $(MINIOS_ROOT)/stub.mk
