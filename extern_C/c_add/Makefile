all: part
	gcc -shared -o libadd.so add.o

# 👇 修改这里：添加 -ladd 并在最后链接
part:
	gcc -fPIC -c add.c -o add.o