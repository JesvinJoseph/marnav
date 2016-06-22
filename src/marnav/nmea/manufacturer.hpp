#ifndef __NMEA__MANUFACTURER__HPP__
#define __NMEA__MANUFACTURER__HPP__

#include <string>
#include <vector>

namespace marnav
{
namespace nmea
{
/// Enumeration of manufacturer IDs.
enum class manufacturer_id {
	UNKNOWN,
	NMEA,
	_3SN,
	AAR,
	ACE,
	ACR,
	ACS,
	ACT,
	ADI,
	ADN,
	AGI,
	AHA,
	AIP,
	ALD,
	AMC,
	AMI,
	AMR,
	AMT,
	AND,
	ANI,
	ANS,
	ANX,
	ANZ,
	AOB,
	APC,
	APN,
	APW,
	APX,
	AQC,
	AQD,
	AQM,
	ARL,
	ARV,
	ASH,
	ASP,
	ATC,
	ATE,
	ATM,
	ATR,
	ATV,
	AVN,
	AWA,
	AXN,
	BBG,
	BBL,
	BBR,
	BDV,
	BEC,
	BFA,
	BGG,
	BGS,
	BGT,
	BHE,
	BHR,
	BLB,
	BMC,
	BME,
	BMS,
	BMT,
	BNI,
	BNS,
	BRM,
	BRO,
	BRY,
	BTH,
	BTK,
	BTS,
	BVE,
	BXA,
	CAI,
	CAT,
	CBN,
	CCA,
	CCC,
	CCL,
	CCM,
	CDC,
	CDI,
	CDL,
	CEC,
	CEI,
	CFS,
	CHI,
	CIN,
	CKM,
	CLR,
	CMA,
	CMC,
	CME,
	CML,
	CMN,
	CMP,
	CMS,
	CMV,
	CNI,
	CNS,
	CNV,
	CNX,
	CPL,
	CPN,
	CPS,
	CPT,
	CRE,
	CRO,
	CRY,
	CSI,
	CSM,
	CSR,
	CSS,
	CST,
	CSV,
	CTA,
	CTB,
	CTC,
	CTE,
	CTL,
	CTS,
	CUS,
	CWD,
	CWV,
	CYZ,
	DAS,
	DBM,
	DCC,
	DEB,
	DEC,
	DFI,
	DGC,
	DGY,
	DGP,
	DME,
	DMI,
	DNS,
	DNT,
	DOI,
	DPS,
	DRL,
	DSC,
	DTN,
	DYN,
	DYT,
	EAN,
	EBC,
	ECR,
	ECT,
	EDO,
	EEV,
	EFC,
	EKC,
	ELA,
	ELD,
	ELM,
	EMC,
	EMR,
	EMS,
	ENA,
	ENC,
	EPM,
	EPT,
	ERC,
	ERD,
	ESA,
	ESC,
	ESY,
	FDN,
	FEC,
	FHE,
	FJN,
	FLA,
	FLO,
	FMM,
	FMS,
	FNT,
	FRC,
	FST,
	FTG,
	FTT,
	FUJ,
	FUR,
	FWG,
	GAM,
	GCA,
	GEC,
	GES,
	GFC,
	GFV,
	GIL,
	GIS,
	GNV,
	GPI,
	GPP,
	GPR,
	GRF,
	GRM,
	GSC,
	GTI,
	GTO,
	GVE,
	GVT,
	HAI,
	HAL,
	HAR,
	HHS,
	HIG,
	HIL,
	HIT,
	HMS,
	HOM,
	HPK,
	HRC,
	HRT,
	HTI,
	HUL,
	HWM,
	IBM,
	ICO,
	ICG,
	IDS,
	IFD,
	IFI,
	IME,
	IMI,
	IMM,
	IMP,
	IMR,
	IMT,
	INM,
	INT,
	IRT,
	IST,
	ITM,
	ITR,
	IWW,
	IXB,
	JAN,
	JAS,
	JFR,
	JMT,
	JPI,
	JRC,
	JRI,
	JTC,
	JTR,
	KBE,
	KBM,
	KEL,
	KHU,
	KLA,
	KME,
	KML,
	KMO,
	KMR,
	KNC,
	KNG,
	KOD,
	KRA,
	KRP,
	KST,
	KVH,
	KYI,
	L3A,
	LAT,
	L3I,
	LCI,
	LEC,
	LEI,
	LIT,
	LMM,
	LRD,
	LSE,
	LSP,
	LST,
	LTH,
	LTF,
	LTI,
	LWR,
	MCA,
	MCI,
	MCL,
	MDL,
	MDS,
	MEC,
	MEG,
	MES,
	MEW,
	MFR,
	MFW,
	MGN,
	MGS,
	MIE,
	MIM,
	MLE,
	MLN,
	MLP,
	MLT,
	MMB,
	MME,
	MMI,
	MMP,
	MMS,
	MMT,
	MNI,
	MNT,
	MNX,
	MOT,
	MPI,
	MPN,
	MQS,
	MRC,
	MRE,
	MRP,
	MRR,
	MRS,
	MSB,
	MSF,
	MSE,
	MSM,
	MST,
	MTA,
	MTD,
	MTG,
	MTI,
	MTK,
	MTR,
	MTS,
	MUR,
	MVX,
	MXS,
	MXX,
	NAG,
	NAT,
	NAU,
	NAV,
	NCT,
	NEF,
	NGC,
	NGS,
	NIX,
	NMR,
	NOM,
	NOR,
	NOV,
	NSI,
	NSL,
	NSM,
	NTI,
	NTK,
	NTS,
	NUT,
	NVC,
	NVG,
	NVL,
	NVO,
	NVS,
	NVT,
	NWC,
	OAR,
	OBS,
	ODE,
	ODN,
	OHB,
	OIN,
	OKI,
	OLY,
	OMN,
	OMT,
	ONI,
	ORB,
	ORE,
	OSI,
	OSL,
	OSS,
	OTK,
	PCE,
	PCM,
	PDC,
	PDM,
	RHM,
	PLA,
	PLI,
	PMI,
	PMP,
	PNI,
	PNL,
	PPL,
	PRK,
	PSM,
	PST,
	PTC,
	PTG,
	PTH,
	PVS,
	QWE,
	Q2N,
	RAC,
	RAE,
	RAF,
	RAK,
	RAY,
	RCA,
	RCH,
	RCI,
	RDC,
	RDI,
	RDM,
	REC,
	RFP,
	RGC,
	RGL,
	RGY,
	RHO,
	RLK,
	RME,
	RMR,
	RSL,
	RSM,
	RTH,
	RTN,
	RWC,
	RWI,
	SAA,
	SAE,
	SAF,
	SAI,
	SAJ,
	SAM,
	SAL,
	SAP,
	SAT,
	SBG,
	SBR,
	SCL,
	SCM,
	SCO,
	SCR,
	SDN,
	SEA,
	SEC,
	SEE,
	SEM,
	SEP,
	SER,
	SFN,
	SGC,
	SGN,
	SHI,
	SIG,
	SIM,
	SKA,
	SKP,
	SLI,
	SMD,
	SME,
	SMF,
	SMI,
	SML,
	SMT,
	SNP,
	SNV,
	SNY,
	SOM,
	SON,
	SOV,
	SPL,
	SPT,
	SRC,
	SRD,
	SRF,
	SRS,
	SRT,
	SSC,
	SSD,
	SSE,
	SSI,
	SSN,
	STC,
	STI,
	STK,
	STL,
	STM,
	STO,
	STT,
	SVY,
	SWI,
	SYN,
	TBB,
	TCN,
	TDI,
	TDL,
	TEL,
	TES,
	THR,
	TKI,
	TLS,
	TMS,
	TMT,
	TNL,
	TOP,
	TRC,
	TRS,
	TSI,
	TTK,
	TTS,
	TYC,
	TWC,
	TWS,
	TXI,
	UBX,
	UCG,
	UEL,
	UME,
	UNF,
	UNI,
	UNP,
	URS,
	VAN,
	VAR,
	VCM,
	VEC,
	VEX,
	VIS,
	VMR,
	VSP,
	VXS,
	WAL,
	WBE,
	WBG,
	WBR,
	WEC,
	WCI,
	WDC,
	WHA,
	WMM,
	WMR,
	WNG,
	WSE,
	WST,
	WTC,
	XEL,
	YAS,
	YDK,
	YSH,
	ZNS,
};

class sentence; // forward declaration

manufacturer_id get_manufacturer_id(const std::string & tag);
manufacturer_id get_manufacturer_id(const sentence & s);

std::string get_manufacturer_tag(manufacturer_id id);
std::string get_manufacturer_name(manufacturer_id id);

std::vector<manufacturer_id> get_supported_manufacturer_id();
}
}

#endif
