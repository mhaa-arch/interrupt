#include <interrupt/scoped_disable.hpp>
#include "fake.hpp"

using namespace mhaa::interrupt;
using namespace example;

int main()
{
    Fake controller;
    {
        ScopedDisable guard(controller);
        if (controller.enabled())
        {
            return 1;
        }
    }
    return controller.enabled() ? 0 : 1;
}
