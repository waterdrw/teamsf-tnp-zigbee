#include "Zigbee.h"
#include <fcntl.h>
#include <unistd.h>

void writeBuf(unsigned short dest, unsigned char cmd) {

	int fd = open("/dev/ttyS1", O_WRONLY | O_SYNC);
	if(fd <= 0) { return; }

	unsigned char buf[7];

	buf[0] = 0x0F;
	buf[1] = 0x04;
	buf[2] = (unsigned char) ( (0xFF00 & dest) >> 8 );
	buf[3] = (unsigned char) (0x00FF & dest);
	buf[4] = cmd;

	unsigned char checksum = buf[2] + buf[3] + buf[4];
	checksum = ~checksum + 0x01;
	buf[5] = checksum;

	buf[6] = 0xF0;

	write(fd, buf, sizeof(buf) );

	close(fd);
}

JNIEXPORT void JNICALL Java_com_teamsf_zigbeetest_Zigbee_onLEDNative (JNIEnv *env, jclass zigbee, jchar jDest) {
	unsigned short dest = (unsigned short) jDest;
	unsigned char cmd = 0x01;

	writeBuf(dest, cmd);
}

JNIEXPORT void JNICALL Java_com_teamsf_zigbeetest_Zigbee_offLEDNative (JNIEnv *env, jclass zigbee, jchar jDest) {
	unsigned short dest = (unsigned short) jDest;
	unsigned char cmd = 0x00;

	writeBuf(dest, cmd);
}

JNIEXPORT void JNICALL Java_com_teamsf_zigbeetest_Zigbee_upDimNative (JNIEnv *env, jclass zigbee, jchar jDest) {
	unsigned short dest = (unsigned short) jDest;
	unsigned char cmd = 0x02;

	writeBuf(dest, cmd);
}

JNIEXPORT void JNICALL Java_com_teamsf_zigbeetest_Zigbee_downDimNative (JNIEnv *env, jclass zigbee, jchar jDest) {
	unsigned short dest = (unsigned short) jDest;
	unsigned char cmd = 0x03;

	writeBuf(dest, cmd);
}
