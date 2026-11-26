#ifndef MHAA_INTERRUPT_SCOPED_DISABLE_HPP
#define MHAA_INTERRUPT_SCOPED_DISABLE_HPP

#include <interrupt/mask_control.hpp>

namespace mhaa
{
    namespace interrupt
    {
        /** @brief Atomically saves and masks on entry, then restores on scope exit. */
        class ScopedDisable
        {
        public:
            explicit ScopedDisable(MaskControl &control) noexcept
                : control_(control), was_enabled_(control.save_and_disable()) {}

            ~ScopedDisable() { control_.restore(was_enabled_); }

            ScopedDisable(const ScopedDisable &) = delete;
            ScopedDisable &operator=(const ScopedDisable &) = delete;

        private:
            MaskControl &control_;
            const bool was_enabled_;
        };
    }
}

#endif
