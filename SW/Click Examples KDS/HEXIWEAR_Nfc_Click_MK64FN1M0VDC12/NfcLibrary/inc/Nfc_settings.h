/***** NFC dedicated setting ****************************************/

/* Following definitions specifies which settings will apply when NxpNci_ConfigureSettings()
 * API is called from the application
 */
#define NXP_CORE_CONF 		0
#define NXP_CORE_CONF_EXTN	1
#define NXP_CORE_STANDBY 	1
#define NXP_CLK_CONF	 	1
#define NXP_TVDD_CONF	 	1
#define NXP_RF_CONF		 	1

#if NXP_CORE_CONF
/* NCI standard dedicated settings
 * Refer to NFC Forum NCI standard for more details
 */
uint8_t NxpNci_CORE_CONF[]={0x20, 0x02, 0x07, 0x01, 		/* CORE_SET_CONFIG_CMD */
	0x33, 0x04, 0x04, 0x03, 0x02, 0x01,						/* LA_NFCID1 */
};
#endif


#if NXP_CORE_CONF_EXTN
/* NXP-NCI extension dedicated setting
 * Refer to NFC controller User Manual for more details
 */
uint8_t NxpNci_CORE_CONF_EXTN[]={0x20, 0x02, 0x0D, 0x03,	/* CORE_SET_CONFIG_CMD */
    0xA0, 0x40, 0x01, 0x00,									/* TAG_DETECTOR_CFG */
    0xA0, 0x41, 0x01, 0x04,									/* TAG_DETECTOR_THRESHOLD_CFG */
    0xA0, 0x43, 0x01, 0x00									/* TAG_DETECTOR_FALLBACK_CNT_CFG*/
};
#endif


#if NXP_CORE_STANDBY
/* NXP-NCI standby enable setting
 * Refer to NFC controller User Manual for more details
 */
uint8_t NxpNci_CORE_STANDBY[]={0x2F, 0x00, 0x01, 0x01};	/* last byte indicates enable/disable */
#endif


#if NXP_CLK_CONF
/* NXP-NCI CLOCK configuration
 * Refer to NFC controller Hardware Design Guide document for more details
 */
 #if 1
  /* Xtal configuration */
  uint8_t NxpNci_CLK_CONF[]={0x20, 0x02, 0x05, 0x01,		/* CORE_SET_CONFIG_CMD */
    0xA0, 0x03, 0x01, 0x08									/* CLOCK_SEL_CFG */
  };
  #else
  /* PLL configuration */
  uint8_t NxpNci_CLK_CONF[]={0x20, 0x02, 0x09, 0x02,		/* CORE_SET_CONFIG_CMD */
    0xA0, 0x03, 0x01, 0x11,									/* CLOCK_SEL_CFG */
	0xA0, 0x04, 0x01, 0x01									/* CLOCK_TO_CFG */
  };
  #endif
#endif


#if NXP_TVDD_CONF
/* NXP-NCI TVDD configuration
 * Refer to NFC controller Hardware Design Guide document for more details
 */
/* RF configuration related to 1st generation of NXP-NCI controller (e.g PN7120) */
uint8_t NxpNci_TVDD_CONF_1stGen[]={};

/* RF configuration related to 1st generation of NXP-NCI controller (e.g PN7150)*/
 #if 1
 /* CFG1: Vbat is used to generate the VDD(TX) through TXLDO */
 uint8_t NxpNci_TVDD_CONF_2ndGen[]={0x20, 0x02, 0x07, 0x01, 0xA0, 0x0E, 0x03, 0x02, 0x09, 0x00};
 #else
 /* CFG2: external 5V is used to generate the VDD(TX) through TXLDO */
 uint8_t NxpNci_TVDD_CONF_2ndGen[]={0x20, 0x02, 0x07, 0x01, 0xA0, 0x0E, 0x03, 0x06, 0x64, 0x00};
 #endif
#endif


#if NXP_RF_CONF
/* NXP-NCI RF configuration
 * Refer to NFC controller Antenna Design and Tuning Guidelines document for more details
 */
/* RF configuration related to 1st generation of NXP-NCI controller (e.g PN7120) */
uint8_t NxpNci_RF_CONF_1stGen[]={};

/* RF configuration related to 2nd generation of NXP-NCI controller (e.g PN7150)*/
/* Following configuration relates to performance optimization of OM5578/PN7150 NFC Controller demo kit */
uint8_t NxpNci_RF_CONF_2ndGen[]={0x20, 0x02, 0xB7, 0x14,
	0xA0, 0x0D, 0x06, 0x04, 0x35, 0x90, 0x01, 0xF4, 0x01,  	/* RF_CLIF_CFG_INITIATOR        CLIF_AGC_INPUT_REG */
	0xA0, 0x0D, 0x06, 0x06, 0x44, 0x01, 0x90, 0x03, 0x00,	/* RF_CLIF_CFG_TARGET           CLIF_ANA_RX_REG */
	0xA0, 0x0D, 0x06, 0x06, 0x30, 0xB0, 0x01, 0x10, 0x00,	/* RF_CLIF_CFG_TARGET           CLIF_SIGPRO_ADCBCM_THRESHOLD_REG */
	0xA0, 0x0D, 0x06, 0x06, 0x42, 0x02, 0x00, 0xFF, 0xFF,	/* RF_CLIF_CFG_TARGET           CLIF_ANA_TX_AMPLITUDE_REG */
	0xA0, 0x0D, 0x03, 0x06, 0x3F, 0x06,						/* RF_CLIF_CFG_TARGET           CLIF_TEST_CONTROL_REG */
	0xA0, 0x0D, 0x06, 0x20, 0x42, 0x88, 0x00, 0xFF, 0xFF,	/* RF_CLIF_CFG_TECHNO_I_TX15693 CLIF_ANA_TX_AMPLITUDE_REG */
	0xA0, 0x0D, 0x04, 0x22, 0x44, 0x22, 0x00,				/* RF_CLIF_CFG_TECHNO_I_RX15693 CLIF_ANA_RX_REG */
	0xA0, 0x0D, 0x06, 0x22, 0x2D, 0x50, 0x34, 0x0C, 0x00,	/* RF_CLIF_CFG_TECHNO_I_RX15693 CLIF_SIGPRO_RM_CONFIG1_REG */
	0xA0, 0x0D, 0x06, 0x32, 0x42, 0xF8, 0x00, 0xFF, 0xFF,	/* RF_CLIF_CFG_BR_106_I_TXA     CLIF_ANA_TX_AMPLITUDE_REG */
	0xA0, 0x0D, 0x06, 0x34, 0x2D, 0x24, 0x37, 0x0C, 0x00,	/* RF_CLIF_CFG_BR_106_I_RXA_P   CLIF_SIGPRO_RM_CONFIG1_REG */
	0xA0, 0x0D, 0x06, 0x34, 0x33, 0x86, 0x80, 0x00, 0x70,	/* RF_CLIF_CFG_BR_106_I_RXA_P   CLIF_AGC_CONFIG0_REG */
	0xA0, 0x0D, 0x04, 0x34, 0x44, 0x22, 0x00,				/* RF_CLIF_CFG_BR_106_I_RXA_P   CLIF_ANA_RX_REG */
	0xA0, 0x0D, 0x06, 0x42, 0x2D, 0x15, 0x45, 0x0D, 0x00,	/* RF_CLIF_CFG_BR_848_I_RXA     CLIF_SIGPRO_RM_CONFIG1_REG */
	0xA0, 0x0D, 0x04, 0x46, 0x44, 0x22, 0x00,				/* RF_CLIF_CFG_BR_106_I_RXB     CLIF_ANA_RX_REG */
	0xA0, 0x0D, 0x06, 0x46, 0x2D, 0x05, 0x59, 0x0E, 0x00,	/* RF_CLIF_CFG_BR_106_I_RXB     CLIF_SIGPRO_RM_CONFIG1_REG */
	0xA0, 0x0D, 0x06, 0x44, 0x42, 0x88, 0x00, 0xFF, 0xFF,	/* RF_CLIF_CFG_BR_106_I_TXB     CLIF_ANA_TX_AMPLITUDE_REG */
	0xA0, 0x0D, 0x06, 0x56, 0x2D, 0x05, 0x9F, 0x0C, 0x00,	/* RF_CLIF_CFG_BR_212_I_RXF_P   CLIF_SIGPRO_RM_CONFIG1_REG */
	0xA0, 0x0D, 0x06, 0x54, 0x42, 0x88, 0x00, 0xFF, 0xFF,	/* RF_CLIF_CFG_BR_212_I_TXF     CLIF_ANA_TX_AMPLITUDE_REG */
	0xA0, 0x0D, 0x06, 0x0A, 0x33, 0x80, 0x86, 0x00, 0x70,	/* RF_CLIF_CFG_I_ACTIVE         CLIF_AGC_CONFIG0_REG */
	0xA0, 0x1D, 0x11, 0x57, 0x33, 0x14, 0x17, 0x00, 0xAA, 0x85, 0x00, 0x80, 0x55, 0x2A, 0x04, 0x00, 0x63, 0x00, 0x00, 0x00
};
#endif
