#include <marnav/ais/message_21.hpp>
#include <marnav/ais/angle.hpp>
#include <algorithm>

namespace marnav
{
namespace ais
{
constexpr message_id message_21::ID;
constexpr std::size_t message_21::SIZE_BITS_MIN;
constexpr std::size_t message_21::SIZE_BITS_MAX;

message_21::message_21()
	: message(ID)
	, name("@@@@@@@@@@@@@@@@@@@@")
{
}

message_21::message_21(const raw & bits)
	: message(ID)
	, name("@@@@@@@@@@@@@@@@@@@@")
{
	if ((bits.size() < SIZE_BITS_MIN) || (bits.size() > SIZE_BITS_MAX))
		throw std::invalid_argument{"invalid number of bits in message_21"};
	read_data(bits);
}

void message_21::read_data(const raw & bits)
{
	get(bits, repeat_indicator);
	get(bits, mmsi);
	get(bits, aid_type);
	get(bits, name);
	get(bits, position_accuracy);
	get(bits, longitude_minutes);
	get(bits, latitude_minutes);
	get(bits, to_bow);
	get(bits, to_stern);
	get(bits, to_port);
	get(bits, to_starboard);
	get(bits, epfd_fix);
	get(bits, utc_second);
	get(bits, off_position);
	get(bits, regional);
	get(bits, raim);
	get(bits, virtual_aid_flag);
	get(bits, assigned);

	auto rest = bits.size() - SIZE_BITS_MIN;
	if (rest > 0) {
		rest = std::min(rest, SIZE_BITS_MAX - SIZE_BITS_MIN);
		name_extension = read_string(bits, 272, rest / 6);
	}
}

raw message_21::get_data() const
{
	raw bits(SIZE_BITS_MIN);

	bits.set(type(), 0, 6);
	set(bits, repeat_indicator);
	set(bits, mmsi);
	set(bits, aid_type);
	set(bits, name);
	set(bits, position_accuracy);
	set(bits, longitude_minutes);
	set(bits, latitude_minutes);
	set(bits, to_bow);
	set(bits, to_stern);
	set(bits, to_port);
	set(bits, to_starboard);
	set(bits, epfd_fix);
	set(bits, utc_second);
	set(bits, off_position);
	set(bits, regional);
	set(bits, raim);
	set(bits, virtual_aid_flag);
	set(bits, assigned);

	if (name_extension.size() > 0) {
		// compute number of bits, must be on a 8-bit boundary
		auto size = name_extension.size() * 6;
		if ((size % 8) != 0)
			size += 8 - (size % 8);

		if (size <= SIZE_BITS_MAX - SIZE_BITS_MIN) {
			// append a temporary bitset to the real one
			raw t(size);
			write_string(t, 0, name_extension.size(), name_extension);
			bits.append(t);
		}
	}

	return bits;
}

std::string message_21::get_name() const
{
	return trim_ais_string(name);
}

void message_21::set_name(const std::string & t)
{
	if (t.size() > 20) {
		name = t.substr(0, 20);
	} else {
		name = t;
	}
}

std::string message_21::get_name_extension() const
{
	return trim_ais_string(name_extension);
}

void message_21::set_name_extension(const std::string & t)
{
	// 88 bits with 6-bit encoding are 14 characters
	if (t.size() > 14) {
		name_extension = t.substr(0, 14);
	} else {
		name_extension = t;
	}
}

std::optional<geo::longitude> message_21::get_lon() const
{
	if (longitude_minutes == longitude_not_available)
		return std::make_optional<geo::longitude>();
	return to_geo_longitude(longitude_minutes, longitude_minutes.count, angle_scale::I4);
}

std::optional<geo::latitude> message_21::get_lat() const
{
	if (latitude_minutes == latitude_not_available)
		return std::make_optional<geo::latitude>();
	return to_geo_latitude(latitude_minutes, latitude_minutes.count, angle_scale::I4);
}

void message_21::set_lon_unavailable()
{
	longitude_minutes = longitude_not_available;
}

void message_21::set_lat_unavailable()
{
	latitude_minutes = latitude_not_available;
}

void message_21::set_lon(const geo::longitude & t)
{
	longitude_minutes = to_longitude_minutes(t, longitude_minutes.count, angle_scale::I4);
}

void message_21::set_lat(const geo::latitude & t)
{
	latitude_minutes = to_latitude_minutes(t, latitude_minutes.count, angle_scale::I4);
}

vessel_dimension message_21::get_vessel_dimension() const noexcept
{
	return vessel_dimension(to_bow, to_stern, to_port, to_starboard);
}

void message_21::set_vessel_dimension(const vessel_dimension & t)
{
	to_bow = t.get_raw_to_bow();
	to_stern = t.get_raw_to_stern();
	to_port = t.get_raw_to_port();
	to_starboard = t.get_raw_to_starboard();
}
}
}
