#pragma once

#include "pxr/logger/baseSink.hpp"

namespace pxr {
/**
 * @brief Sink for sending telemetry data.
 *
 * This is the primary way of interacting with the telemetry portion of pxr's logging implementation. This sink is
 * used for sending data that is not meant to be viewed by the user, but will still be used by something else, like a
 * data visualization tool. Messages sent through this sink will not be cleared from the terminal and not be visible to
 * the user.

 * <h3> Example Usage </h3>
 * @code
 * pxr::telemetrySink()->setLowestLevel(pxr::Level::INFO);
 * pxr::telemetrySink()->info("{},{}", motor1.get_temperature(), motor2.get_temperature());
 * @endcode
 */
class TelemetrySink : public BaseSink {
    public:
        /**
         * @brief Construct a new Telemetry Sink object
         */
        TelemetrySink();
    private:
        /**
         * @brief Log the given message
         *
         * @param message
         */
        void sendMessage(const Message& message) override;
};
} // namespace pxr
