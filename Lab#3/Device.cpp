#include <AL/al.h>
#include <AL/alc.h>
#include <cstddef>

int main(int argc, char** argv) {
    // Initialize OpenAL device and context
    ALCdevice* device = alcOpenDevice(NULL);
    if (!device) {
        // Handle error (Failed to open OpenAL device)
        return -1;
    }

    ALCcontext* context = alcCreateContext(device, NULL);
    if (!context) {
        // Handle error (Failed to create OpenAL context)
        alcCloseDevice(device);
        return -1;
    }

    alcMakeContextCurrent(context);

    // ... Your other code ...

    // Close the OpenAL context and device before exiting
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);

    return 0;
}
