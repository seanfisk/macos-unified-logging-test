#include <os/log.h>

#include <stdio.h>
#include <stdlib.h>

void test_level(os_log_t log_object, os_log_type_t type, char *name) {
	char *answer;
	if (os_log_type_enabled(log_object, type)) {
		answer = "Yes";
	} else {
		answer = "No";
	}
	printf("Can write to %s level: %s\n", name, answer);
	printf("Logging to %s level\n", name);
	// https://developer.apple.com/documentation/os/os_log_with_type
	os_log_with_type(log_object, type, "Testing %{public} level", name);
}

int main(int argc, char *argv[]) {
	puts("Creating log object");
	// https://developer.apple.com/documentation/os/1643744-os_log_create
	os_log_t log_object = os_log_create(/*subsystem=*/"com.seanfisk.macos-unified-logging-test", /*category=*/"General");

	test_level(log_object, OS_LOG_TYPE_FAULT, "fault");

	puts("Freeing log object");
	free(log_object);

	return 0;
}
