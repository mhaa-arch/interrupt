# Interrupt Control Core guide

A gate may be local to one CPU core. A one-bit snapshot represents that gate's prior state.

Read the scope of the gate and the requirements for restoration before using a guard.

- [Use the facade](api.md) for construction, results and optional capabilities.
- [Run the example](examples.md) to see the same API with a simulated resource.
- [Check portability](compatibility.md) for assumptions that belong to the target.
