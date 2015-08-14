#include "vwr.hpp"
#include <marnav/nmea/io.hpp>
#include <marnav/utils/unique.hpp>

namespace marnav
{
namespace nmea
{

constexpr const char * vwr::TAG;

vwr::vwr()
	: sentence(ID, TAG, talker_id::integrated_instrumentation)
{
}

void vwr::set_angle(double angle, side s)
{
	this->angle = angle;
	this->angle_side = s;
}

void vwr::set_speed_knots(double t)
{
	speed_knots = t;
	speed_knots_unit = unit::velocity::KNOT;
}

void vwr::set_speed_mps(double t)
{
	speed_mps = t;
	speed_mps_unit = unit::velocity::MPS;
}

void vwr::set_speed_kmh(double t)
{
	speed_kmh = t;
	speed_kmh_unit = unit::velocity::KMH;
}

std::unique_ptr<sentence> vwr::parse(const std::string & talker,
	const std::vector<std::string> & fields) throw(std::invalid_argument, std::runtime_error)
{
	if (fields.size() != 8)
		throw std::invalid_argument{"invalid number of fields in vwr::parse"};

	std::unique_ptr<sentence> result = utils::make_unique<vwr>();
	result->set_talker(talker);
	vwr & detail = static_cast<vwr &>(*result);

	read(fields[0], detail.angle);
	read(fields[1], detail.angle_side);
	read(fields[2], detail.speed_knots);
	read(fields[3], detail.speed_knots_unit);
	read(fields[4], detail.speed_mps);
	read(fields[5], detail.speed_mps_unit);
	read(fields[6], detail.speed_kmh);
	read(fields[7], detail.speed_kmh_unit);

	return result;
}

std::vector<std::string> vwr::get_data() const
{
	return {to_string(angle), to_string(angle_side), to_string(speed_knots),
		to_string(speed_knots_unit), to_string(speed_mps), to_string(speed_mps_unit),
		to_string(speed_kmh), to_string(speed_kmh_unit)};
}
}
}
