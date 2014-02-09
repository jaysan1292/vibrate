#include <CoreFoundation/CoreFoundation.h>
#include <AudioToolbox/AudioToolbox.h>

#define kDefaultVibrateCount 1
#define kDefaultVibrateDelay 500

void usage() {
    printf("Usage: vibrate [dn]\n");
    printf("  -d <delay>   The delay, in milliseconds, between vibrations. Default is 500ms.\n");
    printf("  -n <amount>  The number of times to vibrate. If not specified, vibrate once.\n");
    printf("  -?           Print this help.\n");
}

int main (int argc, const char * argv[]) {
    // command argument stuff
    int count;
    int delay;
    char* countval = NULL;
    char* delayval = NULL;
    
    // getopt flags
    int c;
    bool n = false;
    bool d = false;
    while ((c = getopt(argc, argv, "d:n:?")) != -1) {
        switch (c) {
            case 'n':
                n = true;
                countval = optarg;
                break;
            case 'd':
                d = true;
                delayval = optarg;
                break;
            case '?':
                usage();
                return 0;
        }
        
    }
    
    if (d) delay = atoi(delayval);
    else   delay = kDefaultVibrateDelay;

    if (n) count = atoi(countval);
    else   count = kDefaultVibrateCount;
    
    for (int i = 0; i < count; i++) {
        AudioServicesPlayAlertSound(kSystemSoundID_Vibrate);
        usleep(delay*1000);
    }
    
	return 0;
}

