#include <stddef.h>
#include <EthIf_cfg.h>


// This file is autogenerated, any hand modifications will be lost!



const EthIfGeneralCfgType EthIfGenConfigs = {
	.max_trcvs = 2,
	.dev_error_detect = TRUE,
	.en_rx_int = FALSE,
	.en_tx_int = FALSE,
	.version_info_api = FALSE,
	.version_info_api_macro = FALSE,
	.lnk_st_ch_mn_reload = 1,
	.mn_fn_period_ms = 10,
	.rx_ind_itrtn = 0,
	.get_rst_meas_data_api = FALSE,
	.start_auto_neg = TRUE,
	.get_baud_rate = FALSE,
	.counter_state = FALSE,
	.gl_time_supp = FALSE,
	.wake_supp = TRUE,
	.trcv_wakemode_api = FALSE,
	.swt_off_port_delay_ms = 10,
	.port_startup_activ_ms = 10,
	.mn_fn_state_period_ms = 10,
	.set_fwd_mode_api = FALSE,
	.verify_cfg_api = FALSE,
	.swt_mgmt_supp = FALSE,
	.get_ctrl_idx_lst = FALSE,
	.get_vlan_id_supp = FALSE,
	.en_weth_api = FALSE,
	.en_sig_qual_api = FALSE,
	.sig_qual_chk_ms = 10,
	.en_sec_evt_report = FALSE,
	.sec_evt_ref = NULL
};


const EthIf_ConfigType EthIfConfigs = {
        .general = EthIfGenConfigs,
};
