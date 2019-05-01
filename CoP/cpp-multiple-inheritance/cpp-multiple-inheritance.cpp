#include <iostream>
using namespace std;

class MusicalInstrument {
public:
    virtual void play() { cout << "Playing instrument ... " << endl; }
    virtual void reset() { cout << "Resetting instrument ... " << endl; }
    virtual ~MusicalInstrument() {};
};

class Machine {
public:
    virtual void start() { cout << "Starting machine ... " << endl; }
    virtual void reset() { cout << "Resetting machine ..." << endl; }
    virtual ~Machine() {};
};

class Synthesizer : public Machine, public MusicalInstrument {
public:
    virtual ~Synthesizer() {};
};

int main()
{
    Synthesizer* pSynth = new Synthesizer();

    // can call functions from both Machine and MusicalInstrument classes
    pSynth->play();
    pSynth->start();

    // doesn't work because there are two identical reset()
    //pSynth->reset();

    // calls the MusicalInstrument reset()
    pSynth->MusicalInstrument::reset();

    // calls the Machine reset()
    pSynth->Machine::reset();

    delete pSynth;

    return 0;
}