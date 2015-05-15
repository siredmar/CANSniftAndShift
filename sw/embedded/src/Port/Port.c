#include "Port.h"
#include "Port_Cfg.h"
#include "Port_Lcfg.h"

const Port_RegisterAddresstype Port_RegisterAdress_as[PORT_NUMBER_OF_PORTS] =
{
        {
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GPER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GPERS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GPERC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GPERT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR0_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR1_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR2_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR2S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR2C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PMR2T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODERS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODERC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODERT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_OVR_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_OVRS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_OVRC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_OVRT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PVR_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PUER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PUERS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PUERC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PUERT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PDER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PDERS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PDERC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PDERT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IERS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IERC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IERT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR0_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR1_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GFER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GFERS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GFERC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_GFERT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IFR_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_IFRC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR0_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR0S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR0C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR0T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR1_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR1S_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR1C_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ODCR1T_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_LOCK_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_LOCKS_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_LOCKC_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_LOCKT_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_UNLOCK_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_ASR_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_PARAMETER_REGISTER_OFFSET),
                (uint32*) (PORT_A_REGISTER_OFFSET + PORT_VERSION_REGISTER_OFFSET),
        },
        {
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GPER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GPERS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GPERC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GPERT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR0_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR1_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR2_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR2S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR2C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PMR2T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODERS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODERC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODERT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_OVR_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_OVRS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_OVRC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_OVRT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PVR_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PUER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PUERS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PUERC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PUERT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PDER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PDERS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PDERC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PDERT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IERS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IERC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IERT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR0_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR1_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GFER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GFERS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GFERC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_GFERT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IFR_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_IFRC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR0_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR0S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR0C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR0T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR1_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR1S_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR1C_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ODCR1T_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_LOCK_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_LOCKS_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_LOCKC_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_LOCKT_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_UNLOCK_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_ASR_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_PARAMETER_REGISTER_OFFSET),
                (uint32*) (PORT_B_REGISTER_OFFSET + PORT_VERSION_REGISTER_OFFSET),
        },
        {
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GPER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GPERS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GPERC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GPERT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR0_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR1_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR2_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR2S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR2C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PMR2T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODERS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODERC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODERT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_OVR_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_OVRS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_OVRC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_OVRT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PVR_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PUER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PUERS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PUERC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PUERT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PDER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PDERS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PDERC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PDERT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IERS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IERC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IERT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR0_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR1_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GFER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GFERS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GFERC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_GFERT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IFR_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_IFRC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR0_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR0S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR0C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR0T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR1_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR1S_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR1C_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ODCR1T_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_LOCK_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_LOCKS_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_LOCKC_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_LOCKT_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_UNLOCK_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_ASR_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_PARAMETER_REGISTER_OFFSET),
                (uint32*) (PORT_C_REGISTER_OFFSET + PORT_VERSION_REGISTER_OFFSET),
        },
        {
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GPER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GPERS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GPERC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GPERT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR0_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR1_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR2_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR2S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR2C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PMR2T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODERS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODERC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODERT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_OVR_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_OVRS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_OVRC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_OVRT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PVR_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PUER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PUERS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PUERC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PUERT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PDER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PDERS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PDERC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PDERT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IERS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IERC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IERT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR0_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR0S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR0C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR0T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR1_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR1S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR1C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IMR1T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GFER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GFERS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GFERC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_GFERT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IFR_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_IFRC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR0_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR0S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR0C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR0T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR1_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR1S_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR1C_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ODCR1T_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_LOCK_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_LOCKS_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_LOCKC_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_LOCKT_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_UNLOCK_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_ASR_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_PARAMETER_REGISTER_OFFSET),
                (uint32*) (PORT_D_REGISTER_OFFSET + PORT_VERSION_REGISTER_OFFSET),
        }
};


void Port_Init(void)
{
    uint8 PortCounter_ui8;
    uint8 forCounter2_ui8;
    Port_ConfigType *localConfig;

    Port_PeripheralFunctionType PeripheralMode_e;

    Port_PinInOutType Port_PinInOut_e;
    Port_PullUpTypeType Port_PullUpDown_e;
    Port_InterruptModeType Port_Interrupt_Mode_e;
    Port_GlitchFilterType Port_GlitchFilterState_e;
    Port_OutputDrivingCapabilityType Port_OutputDriver_e;
    Port_PinInitialStateType PortPinInitialState_e;


    uint8 PinNumber_ui8;

    /* TODO: const on whole Lcfg types */
    localConfig = (Port_ConfigType*) Port_GetLcfgData();

    *(Port_RegisterAdress_as[PortCounter_ui8].Port_GpioEnableRegister_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PeripheralMux0Register_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PeripheralMux1Register_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PeripheralMux2Register_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputDriverEnableRegister_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputValueRegister_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PullDownEnableRegister_pui32) = 0;
    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PullUpEnableRegister_pui32) = 0;


    if(localConfig != NULL_PTR)
    {
        for(PortCounter_ui8 = 0; PortCounter_ui8 < PORT_MAX_NUMBER_OF_PINS; PortCounter_ui8++)
        {
            //         PortNumber_ui8 = (uint8)(PortPin_e >> 8);
            PinNumber_ui8 = (uint8)(((localConfig->Pin[PortCounter_ui8].Port_PortPin_e) & 0xFF));


            /* Set GPIO - Peripheral mode for selected Pin */
            if(localConfig->Pin[PortCounter_ui8].Port_PeripheralMode_e == GPIO_MODE)
            {
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_GpioEnableRegister_pui32) |= 1 << PinNumber_ui8;
            }
            else
            {
                PeripheralMode_e = localConfig->Pin[PortCounter_ui8].Port_PeripheralMode_e;
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_PeripheralMux0Register_pui32) |= (uint32)((PeripheralMode_e & 0b001) << PinNumber_ui8);
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_PeripheralMux1Register_pui32) |= (uint32)(((PeripheralMode_e >> 1) & 0b001) << PinNumber_ui8);
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_PeripheralMux2Register_pui32) |= (uint32)(((PeripheralMode_e >> 2) & 0b001) << PinNumber_ui8);
            }

            /* Set Input/Output mode for selected Pin */
            Port_PinInOut_e = localConfig->Pin[PortCounter_ui8].Port_PinInOut_e;
            if(Port_PinInOut_e == PIN_OUTPUT)
            {
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputDriverEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);

                /* Set initial Output for selected Pin */
                PortPinInitialState_e = localConfig->Pin[PortCounter_ui8].Port_PinInitialState_e;
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputValueRegister_pui32) |= (uint32)(((uint8)PortPinInitialState_e) << PinNumber_ui8);
            }
            else
            {
                /* do nothing for Input */
            }

            /* Set Pullup/Pulldown/Floating for selected Pin */
            Port_PullUpDown_e = localConfig->Pin[PortCounter_ui8].Port_PullUpDown_e;
            switch(Port_PullUpDown_e)
            {
                case NO_PULLUP_PULLDOWN:
                {
                    /* do nothing for disabled PullUp/PullDown */
                    break;
                }
                case PULLDOWN_ENABLED:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PullDownEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                case PULLUP_ENABLED:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PullUpEnableRegister_pui32)   |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                case BUSKEEPER_ENABLED:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PullDownEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_PullUpEnableRegister_pui32)   |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                default:
                    break;
            }

            /* Set Interrupt mode for selected Pin */
            Port_Interrupt_Mode_e = localConfig->Pin[PortCounter_ui8].Port_Interrupt_Mode_e;
            switch(Port_Interrupt_Mode_e)
            {
                case INTERRUPT_DISABLED:
                {
                    /* do nothing for disabled PullUp/PullDown */
                    break;
                }
                case INTERRUPT_PIN_CHANGE:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_InterruptEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                case INTERRUPT_RISING_EDGE:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_InterruptMode0Register_pui32)  |= (uint32)(1 << PinNumber_ui8);
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_InterruptEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                case INTERRUPT_FALLING_EDGE:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_InterruptMode1Register_pui32)  |= (uint32)(1 << PinNumber_ui8);
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_InterruptEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                default:
                    break;
            }

            /* Set Glitch Filter Enable/Disable for selected Pin */
            Port_GlitchFilterState_e = localConfig->Pin[PortCounter_ui8].Port_GlitchFilterState_e;
            if(Port_GlitchFilterState_e == GLITCH_FILTER_ENABLED)
            {
                *(Port_RegisterAdress_as[PortCounter_ui8].Port_GlitchFilterEnableRegister_pui32) |= (uint32)(1 << PinNumber_ui8);
            }

            /* Set Output driver strenght for selected Pin */
            Port_OutputDriver_e = localConfig->Pin[PortCounter_ui8].Port_OutputDriver_e;
            switch(Port_OutputDriver_e)
            {
                case OUTPUT_DRIVING_LOW:
                {
                    /* do nothing for disabled PullUp/PullDown */
                    break;
                }
                case OUTPUT_DRIVING_LOW_MID:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputDriverCapa0Register_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                case OUTPUT_DRIVING_HIGH_MID:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputDriverCapa1Register_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                case OUTPUT_DRIVING_HIGH:
                {
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputDriverCapa0Register_pui32) |= (uint32)(1 << PinNumber_ui8);
                    *(Port_RegisterAdress_as[PortCounter_ui8].Port_OutputDriverCapa1Register_pui32) |= (uint32)(1 << PinNumber_ui8);
                    break;
                }
                default:
                    break;
            }
        }
    }
    else
    {
        /* no configuration found */
    }
}
