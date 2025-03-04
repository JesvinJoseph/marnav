#ifndef MARNAV_NMEA_ZFO_HPP
#define MARNAV_NMEA_ZFO_HPP

#include <marnav/nmea/sentence.hpp>
#include <marnav/nmea/time.hpp>
#include <marnav/nmea/waypoint.hpp>
#include <optional>

namespace marnav
{
namespace nmea
{
/// @brief ZFO - UTC & Time from origin Waypoint
///
/// @code
///        1         2         3
///        |         |         |
/// $--ZFO,hhmmss.ss,hhmmss.ss,c--c*hh<CR><LF>
/// @endcode
///
/// Field Number:
/// 1. Universal Time Coordinated (UTC)
/// 2. Elapsed Time
/// 3. Origin Waypoint ID
///
class zfo : public sentence
{
	friend class detail::factory;

public:
	constexpr static sentence_id ID = sentence_id::ZFO;
	constexpr static const char * TAG = "ZFO";

	zfo();
	zfo(const zfo &) = default;
	zfo & operator=(const zfo &) = default;
	zfo(zfo &&) = default;
	zfo & operator=(zfo &&) = default;

protected:
	zfo(talker talk, fields::const_iterator first, fields::const_iterator last);
	virtual void append_data_to(std::string &, const version &) const override;

private:
	std::optional<nmea::time> time_utc_;
	std::optional<nmea::duration> time_elapsed_;
	std::optional<waypoint> waypoint_id_;

public:
	std::optional<nmea::time> get_time_utc() const { return time_utc_; }
	std::optional<nmea::duration> get_time_elapsed() const { return time_elapsed_; }
	std::optional<waypoint> get_waypoint_id() const { return waypoint_id_; }

	void set_time_utc(const nmea::time & t) noexcept { time_utc_ = t; }
	void set_time_elapsed(const nmea::duration & t) noexcept { time_elapsed_ = t; }
	void set_waypoint_id(const waypoint & id) { waypoint_id_ = id; }
};
}
}

#endif
