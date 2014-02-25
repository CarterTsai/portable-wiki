EXECUTABLE = portablewiki

# Toolchain configurations
CC = $(CROSS_COMPILE)gcc

CFLAGS = -O0 -g3
CFLAGS += -std=c99
CFLAGS += -Wall
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Wl,--gc-sections
CFLAGS += -fno-common
CFLAGS += --param max-inline-insns-single=1000

# project starts here
CFLAGS += -I.

OBJS = \
	http.o \
	util.o \
	wikiashtml.o \
	wiki.o \
	wikichanges.o \
	wikientries.o \
	main.o

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXECUTABLE)
	rm -f $(OBJS)
.PHONY: clean
