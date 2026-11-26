#include <interrupt/interrupt.hpp>
#include <interrupt/scoped_disable.hpp>
#include "../examples/fake.hpp"

#include <cassert>
#include <type_traits>

using namespace mhaa::interrupt;
using namespace example;

int main()
{
    static_assert(!std::is_copy_constructible<ScopedDisable>::value, "One restore per guard");
    static_assert(!std::is_move_constructible<ScopedDisable>::value, "Stay in original scope");
    static_assert(!std::is_constructible<ScopedDisable, Controller &>::value,
                  "Atomic capability is required");
    Fake controller;
    {
        ScopedDisable outer(controller);
        assert(!controller.enabled());
        {
            ScopedDisable inner(controller);
            assert(!controller.enabled());
            controller.enable();
        }
        assert(!controller.enabled() && controller.restores == 1);
    }
    assert(controller.enabled() && controller.restores == 2);
    assert(controller.atomic_masks == 2 && controller.separate_masks == 0);
    controller.disable();
    {
        ScopedDisable guard(controller);
    }
    assert(!controller.enabled() && controller.restores == 3);

    Interrupts interrupts(controller);
    assert(!interrupts.enabled());
    interrupts.enable();
    assert(interrupts.enabled());
    interrupts.disable();
    assert(!interrupts.enabled());
}
