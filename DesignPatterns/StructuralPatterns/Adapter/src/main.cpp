// Adapter is a very simple concept: it allows you to adapt the interface you
// have to the interface you need.The only real issue with adapters is that, in
// the process of adaptation, you sometimes end up generating temporary
// data so as to satisfy some other representation of data.And when this
// happens, turn to caching : ensuring that new data is only generated when
// necessary.Oh, and you�ll need to do a bit more work if you want to clean
// up stale data when the cached objects have changed.
// Another concern that we haven�t really addressed is laziness : the
// current adapter implementation performs the conversion as soon as it
// is created.What if you only want the work to be done when the adapter
// is actually used ? This is rather easy to do and is left as an exercise for the
// reader

#include <iostream>
#include "Adapter.hpp"


int main()
{

    std::vector<std::shared_ptr<VectorObject>> vectorObjects
    {
       std::make_shared<VectorRectangle>(10,10,100,100),
       std::make_shared<VectorRectangle>(30,30,60,60)
    };

    for (auto& obj : vectorObjects)
    {
        for (auto& line : *obj)
        {
            LineToPointAdapter lpo(line);
            //DrawPoints(dc, lpo.begin(), lpo.end());
        }
    }
}

