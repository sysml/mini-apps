STUBDOM_NAME		:= $(notdir $(realpath .))
STUBDOM_ROOT		:= $(realpath .)

stub: script

.PHONY: script
script: path=$(subst /,\/,$(realpath .)/build/iws_x86_64)
script:
	$(call verbose_cmd, sed -i -e "s/\(kernel[ 	]*=\).*$$/\1 '$(path)'/",'SED', iws.cfg)

include $(MINIOS_ROOT)/stub.mk
