# Run the Interrupt Control Core example

The simulated gate starts enabled. Constructing the guard disables it for the block, and leaving the block restores the enabled state. The behavior program adds nested guards and a gate that was already disabled. It also checks that a base-only Controller cannot construct the guard.

## Example program

The [program](../examples/example.cpp) uses the [local fake](../examples/fake.hpp) to demonstrate injection. A concrete Adapter implementing the same Contract can be supplied to the same facade.

```cpp
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
```

## Build and run

Build from this repository root. Set `contract_include` to the matching Contract's `include/` directory. The value below applies to the MHAA development workspace. Both programs exit with status 0 on success and print no output. On Windows execute `example.exe` and `behavior.exe`.

```sh
contract_include=../../contracts/interrupt-contract/include
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" examples/example.cpp -o example
./example
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" tests/behavior.cpp -o behavior
./behavior
```

See the [behavior test](../tests/behavior.cpp) for the additional cases described above.
