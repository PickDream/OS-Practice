MAKEFLAGS = -sR
MKDIR = mkdir
RMDIR = rmdir
CP = cp
CD = cd
DD = dd
RM = rm

ASM = nasm
CC = gcc
LD = ld
OBJCOPY = objcopy

# asm参数
ASMBFLAGS	= -f elf -w-orphan-labels
# gcc参数
CFLAGS		= -c -Os -std=c99 -m32 -Wall -Wshadow -W -Wconversion -Wno-sign-conversion  -fno-stack-protector -fomit-frame-pointer -fno-builtin -fno-common  -ffreestanding  -Wno-unused-parameter -Wunused-variable
# ld参数
LDFLAGS		= -s -static -T hello.lds -n -Map HelloOS.map 
# objcopy参数
OJCYFLAGS	= -S -O binary

# 关于赋值的相关资料 https://www.cnblogs.com/zgq0/p/8716150.html
# = 是最基本的赋值
# ?= 是如果之前没有值的条件下进行赋值，如果有则无视赋值语句
# += 是append操作
# := 是覆盖之前的值,注意和=的区别，其区别如下
# ":="表示变量的值决定于它在makefile中的位置，而不是整个makefile展开后的最终值。
# "=" 表示make会将整个makefile展开后，再决定变量的值。也就是说，变量的值将会是整个makefile中最后被指定的值
HELLOOS_OBJS :=
HELLOOS_OBJS += entry.o main.o vgastr.o
HELLOOS_ELF = HelloOS.elf
HELLOOS_BIN = HelloOS.bin

.PHONY : build clean all link bin

# 顺序是 clean build link bin
all: clean build link bin

# 移除所有的中间以及生成文件
clean:
	$(RM) -f *.o *.bin *.elf

# 检查依赖
build: $(HELLOOS_OBJS)

# 执行链接过程
link: $(HELLOOS_ELF)
$(HELLOOS_ELF): $(HELLOOS_OBJS)
	$(LD) $(LDFLAGS) -o $@ $(HELLOOS_OBJS)

# 最终生成真正的二进制的过程
bin: $(HELLOOS_BIN)
$(HELLOOS_BIN): $(HELLOOS_ELF)
	$(OBJCOPY) $(OJCYFLAGS) $< $@

# % 表示通配符
# $@ 代表所有的结果 $<代表所有的依赖项
# 所有的ASM要转化为 .o文件
%.o : %.asm
	$(ASM) $(ASMBFLAGS) -o $@ $<
# 所有的c文件要转化为.o文件
%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<