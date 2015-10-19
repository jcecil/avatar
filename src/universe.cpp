#import "universe.h"

Universe* Universe::mInstance = nullptr;

Universe* Universe::Instance()
{
    if (!mInstance)   // Only allow one instance of class to be generated.
        mInstance = new Universe();
    return mInstance;
}

