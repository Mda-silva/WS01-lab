#include <iostream>
#include "io.h"
#include "graph.h"



    void samplesFirst();
    using namespace std;
    using namespace seneca;

    const int MAX_NO_OF_SAMPLES = 20;

    

    int main() {
        int noOfSamples = 0;
        int samples[MAX_NO_OF_SAMPLES] = { 0 };
        bool done = false;
        seneca::labelLine(33, "Welcome to SeneGraph");
        while (!done) {
            switch (seneca::menu(noOfSamples)) {
            case 1:
                cout << "Enter number of available samples: ";
                noOfSamples = seneca::getInt(1, MAX_NO_OF_SAMPLES);
                break;
            case 2:
                if (noOfSamples == 0) {
                    samplesFirst();
                }
                else {
                    cout << "Please enter the sample values: " << endl;
                    seneca::getSamples(samples, noOfSamples);
                }
                break;
            case 3:
                if (noOfSamples == 0) {
                    samplesFirst();
                }
                else if (samples[0] == 0) {
                    cout << "Samples missing. Please enter the sample values!" << endl;
                }
                else {
                    seneca::printGraph(samples, noOfSamples, " SeneGraph ");
                }
                break;
            case 0:
                cout << "Thanks for using SeneGraph" << endl;
                done = true;
            }
        }
        return 0;
    }

    void samplesFirst() {

        cout << "Number of Samples must be set first!" << endl;
    }
