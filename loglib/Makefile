CC       = gcc
AR       = ar

ENABLE_LOG ?= 0

CPPFLAGS += -DENABLE_LOG=$(ENABLE_LOG)
CFLAGS   = -Wall -Wextra

LOG_CONFIG := .log-config

.PHONY: all clean enable-log disable-log FORCE

all: liblogs.a

liblogs.o: log.c log.h $(LOG_CONFIG)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c log.c -o liblogs.o

liblogs.a: liblogs.o
	$(AR) rcs liblogs.a liblogs.o

$(LOG_CONFIG): FORCE
	@test "$$(cat $@ 2>/dev/null)" = "$(ENABLE_LOG)" || echo "$(ENABLE_LOG)" > $@

enable-log:
	$(MAKE) clean
	$(MAKE) ENABLE_LOG=1

disable-log:
	$(MAKE) clean
	$(MAKE) ENABLE_LOG=0

clean:
	rm -f liblogs.a liblogs.o $(LOG_CONFIG)

FORCE:
