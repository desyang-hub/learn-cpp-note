#include <iostream>

using namespace std;

class TrackerBase {
public:
    void track() {
        cout << "base track" << endl;
    };

protected:
    virtual void trackImpl() = 0;
};

class Tracker : public TrackerBase {
protected: 
    void trackImpl() override {
        cout << "Tracker Implement." << endl;
    }
};

int main() {

    Tracker tracker;
    tracker.track();

    return 0;
}