#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int wfd, rfd, wn, rn;
	char buf[20] = "hello world";
	char rbuf[20];
	wfd = open("/dev/scullc", O_RDWR);
	if (!wfd) {
		printf("can't open /dev/scullc to write\n");
		return 1;
	}
    wn = write(wfd, buf, sizeof(buf));
	if (!wn) {
		printf("write error\n");
	} else {
		printf("write %d\n", wn);
	}
	rfd = open("/dev/scullc", O_RDWR);
	if (!rfd) {
		printf("can't open /dev/scullc to read\n");
		return 1;
	}
	rn = read(rfd, rbuf, sizeof(buf));
	if (!rn) {
		printf("no char\n");
	} else {
		printf("read %d: %s\n", rn, rbuf);
	}
	return 0;
}
