STUBDOM_NAME		:= $(notdir $(realpath .))
STUBDOM_ROOT		:= $(realpath .)
STUB_APP_OBJS0		:= main.o

ifeq ($(USE_NOW),y)
STUB_CFLAGS			+= -DUSE_NOW
endif


stub: $(STUBDOM_NAME).cfg

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
