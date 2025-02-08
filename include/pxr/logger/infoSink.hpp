#pragma once

#include "pxr/logger/message.hpp"
#include "pxr/logger/baseSink.hpp"

namespace pxr {
/**
 * @brief Sink for sending messages to the terminal.
 *
 * This is the primary way of interacting with pxr's logging implementation. This sink is used for printing useful
 * information to the user's terminal.
 * <h3> Example Usage </h3>
 * @code
 * pxr::infoSink()->setLowestLevel(pxr::Level::INFO);
 * pxr::infoSink()->info("info: {}!", "my cool info here");
 * // Specify the order or placeholders
 * pxr::infoSink()->debug("{1} {0}!","world", "hello");
 * // Specify the precision of floating point numbers
 * pxr::infoSink()->warn("Thingy exceeded value: {:.2f}!", 93.1234);
 * @endcode
 */
class InfoSink : public BaseSink {
    public:
        /**
         * @brief Construct a new Info Sink object
         */
        InfoSink();
    private:
        /**
         * @brief Log the given message
         *
         * @param message
         */
        void sendMessage(const Message& message) override;
};
} // namespace pxr
