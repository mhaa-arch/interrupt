#ifndef MHAA_INTERRUPT_HPP
#define MHAA_INTERRUPT_HPP

#include <interrupt/controller.hpp>

namespace mhaa
{
    namespace interrupt
    {
        /** @brief Controls maskable interrupt delivery in the borrowed execution context. */
        class Interrupts
        {
        public:
            explicit Interrupts(Controller &controller) : controller_(controller) {}

            void enable() { controller_.enable(); }
            void disable() { controller_.disable(); }
            bool enabled() const { return controller_.enabled(); }

        private:
            Controller &controller_;
        };
    }
}

#endif
