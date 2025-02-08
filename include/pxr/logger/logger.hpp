#pragma once

#include <memory>
#include <array>

#define FMT_HEADER_ONLY
#include "fmt/core.h"

#include "pxr/logger/baseSink.hpp"
#include "pxr/logger/infoSink.hpp"
#include "pxr/logger/telemetrySink.hpp"

namespace pxr {

/**
 * @brief Get the info sink.
 * @return std::shared_ptr<InfoSink>
 */
std::shared_ptr<InfoSink> infoSink();

/**
 * @brief Get the telemetry sink.
 * @return std::shared_ptr<TelemetrySink>
 */
std::shared_ptr<TelemetrySink> telemetrySink();
} // namespace pxr
