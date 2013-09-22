################################################################################
# Makefile
# History:
#     2013/09/22 Dennis Create
################################################################################

include ./Make.defines

#subdirs := $(sort $(subst /,,$(dir $(wildcard */*))))
subdirs := lib server

all:
	$(foreach N,$(subdirs),make -C $(N);)

.PHONY: clean
clean:
	$(foreach N,$(subdirs),make -C $(N) clean;)
		rm -f $(CLEANFILES)
