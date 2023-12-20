#include <iostream>
#include <mpg123.h>
#include <fftw3.h>

int main() {
    mpg123_handle *mh;
    mh = mpg123_new(NULL, NULL);

    if (mpg123_open(mh, "test.mp3") != MPG123_OK) {
        std::cerr << "Could not open MP3 file." << std::endl;
        return 1;
    }

    int encoding;
    mpg123_getformat(mh, NULL, &encoding, NULL);
    mpg123_format_none(mh);
    mpg123_format(mh, 44100, MPG123_STEREO, MPG123_ENC_SIGNED_16);
    size_t buffer_size = mpg123_outblock(mh);
    unsigned char *buffer = (unsigned char*)malloc(buffer_size);
    size_t size;
    int channels, encoding_out;
    long rate;
    
    while(mpg123_read(mh, buffer, buffer_size, &size) == MPG123_OK){
        mpg123_getformat(mh, &rate, &channels, &encoding_out);
        //Using the decoded samples buffer, create an array of samples based on seconds for now, beats in the future.
        //For each of the samples we have to then use FFT to find the frequency.
        //Based on the frequency then find a matching pitch.
        std::cout << "Decoded samples size: " << size << " bytes" << std::endl;
    }

    free(buffer);

    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();

    return 0;
}
