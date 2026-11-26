# Using Interrupt Control across targets

The only project dependency is the matching `interrupt-contract`. Keep its API revision aligned with this Core.

The guard's restoration policy is portable because it uses one atomic capability and the exact returned state. Its protection covers the represented gate only. Verify the concrete context, hardware ordering and timing before treating the scope as safe for a particular shared resource.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
