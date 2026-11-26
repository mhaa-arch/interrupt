#ifndef MHAA_INTERRUPT_EXAMPLE_FAKE_HPP
#define MHAA_INTERRUPT_EXAMPLE_FAKE_HPP

#include <interrupt/controller.hpp>
#include <interrupt/mask_control.hpp>

namespace example
{
    using namespace mhaa::interrupt;

    class Fake final : public MaskControl
    {
    public:
        void enable() override { enabled_ = true; }
        void disable() override
        {
            enabled_ = false;
            ++separate_masks;
        }
        bool enabled() const override { return enabled_; }
        bool save_and_disable() noexcept override
        {
            ++atomic_masks;
            const bool old = enabled_;
            enabled_ = false;
            return old;
        }
        void restore(bool enabled) noexcept override
        {
            enabled_ = enabled;
            ++restores;
        }

        unsigned atomic_masks = 0;
        unsigned separate_masks = 0;
        unsigned restores = 0;

    private:
        bool enabled_ = true;
    };
}

#endif
